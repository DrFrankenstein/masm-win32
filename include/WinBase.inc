include WinError.inc

MulDiv          proto,
    nNumber:        sdword,
    nNumerator:     sdword,
    nDenominator:   sdword
;ret sdword

;Authorization
;<https://msdn.microsoft.com/en-us/library/windows/desktop/aa375769.aspx>
;Authorization is the right granted an individual to use the system and the data stored on it. Authorization is typically set up by a system administrator and verified by the computer based on some form of user identification, such as a code number or password. 

SECURITY_ATTRIBUTES struct
    nLength                 dword   ?
    lpSecurityDescriptor    LPVOID  ?
    bInheritHandle          BOOL    ?
SECURITY_ATTRIBUTES ends
PSECURITY_ATTRIBUTES    typedef ptr SECURITY_ATTRIBUTES
LPSECURITY_ATTRIBUTES   typedef ptr SECURITY_ATTRIBUTES

;Memory Management
;<https://msdn.microsoft.com/en-us/library/windows/desktop/aa366779.aspx>
;The memory manager implements virtual memory, provides a core set of services such as memory mapped files, copy-on-write memory, large memory support, and underlying support for the cache manager.

HEAP_OPTIMIZE_RESOURCES_INFORMATION struct
    Version ULONG   ?
    Flags   ULONG   ?
HEAP_OPTIMIZE_RESOURCES_INFORMATION ends
PHEAP_OPTIMIZE_RESOURCES_INFORMATION    typedef ptr HEAP_OPTIMIZE_RESOURCES_INFORMATION

MEMORYSTATUS    struct
    dwLength        dword   ?
    dwMemoryLoad    dword   ?
    dwTotalPhys     SIZE_T  ?
    dwAvailPhys     SIZE_T  ?
    dwTotalPageFile SIZE_T  ?
    dwAvailPageFile SIZE_T  ?
    dwTotalVirtual  SIZE_T  ?
    dwAvailVirtual  SIZE_T  ?
MEMORYSTATUS    ends
LPMEMORYSTATUS  typedef ptr MEMORYSTATUS

MEMORYSTATUSEX  struct
    dwLength                dword       ?
    dwMemoryLoad            dword       ?
    ullTotalPhys            DWORDLONG   ?
    ullAvailPhys            DWORDLONG   ?
    ullTotalPageFile        DWORDLONG   ?
    ullAvailPageFile        DWORDLONG   ?
    ullTotalVirtual         DWORDLONG   ?
    ullAvailVirtual         DWORDLONG   ?
    ullAvailExtendedVirtual DWORDLONG   ?
MEMORYSTATUSEX  ends
LPMEMORYSTATUSEX    typedef ptr MEMORYSTATUSEX

PROCESS_HEAP_ENTRY  struct
    lpData          PVOID   ?
    cbData          dword   ?
    cbOverhead      byte    ?
    iRegionIndex    byte    ?
    wFlags          word    ?
    union
        struct Block
            hMem        HANDLE  ?
            dwReserved  dword   3 dup(?)
        ends
        struct Region
            dwCommittedSize     dword   ?
            dwUnCommittedSize   dword   ?
            lpFirstBlock        LPVOID  ?
            lpLastBlock         LPVOID  ?
        ends
    ends
PROCESS_HEAP_ENTRY  ends
LPPROCESS_HEAP_ENTRY    typedef ptr PROCESS_HEAP_ENTRY

PROCESS_HEAP_ENTRY_BUSY         equ 0004h
PROCESS_HEAP_ENTRY_DDESHARE     equ 0020h
PROCESS_HEAP_ENTRY_MOVEABLE     equ 0010h
PROCESS_HEAP_REGION             equ 0001h
PROCESS_HEAP_UNCOMMITTED_RANGE  equ 0002h

WIN32_MEMORY_RANGE_ENTRY    struct
    VirtualAddress  PVOID   ?
    NumberOfBytes   SIZE_T  ?
WIN32_MEMORY_RANGE_ENTRY    ends
PWIN32_MEMORY_RANGE_ENTRY   typedef ptr WIN32_MEMORY_RANGE_ENTRY

;General Memory Functions
;The following functions are used in memory management.
SecureMemoryCacheCallback_t typedef proto CALLBACK,
    _Addr:  PVOID,
    Range:  SIZE_T
;ret BOOLEAN
PSECURE_MEMORY_CACHE_CALLBACK   typedef ptr SecureMemoryCacheCallback_t
AddSecureMemoryCacheCallback    proto WINAPI,
    pfnCallback:    PSECURE_MEMORY_CACHE_CALLBACK
;ret BOOL

RtlCopyMemory   proto c,
    Destination:PVOID,
    Source:     PVOID,
    _Length:    SIZE_T
;ret void
CopyMemory  textequ <RtlCopyMemory>

LowMemoryResourceNotification   equ 0
HighMemoryResourceNotification  equ 1
MEMORY_RESOURCE_NOTIFICATION_TYPE   typedef dword

CreateMemoryResourceNotification    proto WINAPI,
    NotificationType:   MEMORY_RESOURCE_NOTIFICATION_TYPE
;ret HANDLE

RtlFillMemory   proto c,
    Destination:    PVOID,
    _Length:        SIZE_T,
    Fill:           byte
;ret void
FillMemory  textequ <RtlFillMemory>

GetLargePageMinimum proto WINAPI    ;ret SIZE_T

GetPhysicallyInstalledSystemMemory  proto WINAPI,
    TotalMemoryInKilobytes: PULONGLONG
;ret BOOL

GetSystemFileCache  proto WINAPI,
    lpMinimumFileCacheSize: PSIZE_T,
    lpMaximumFileCacheSize: PSIZE_T,
    lpFlags:                PDWORD
;ret BOOL
FILE_CACHE_MAX_HARD_ENABLE  equ 1h
FILE_CACHE_MAX_HARD_DISABLE equ 2h
FILE_CACHE_MIN_HARD_ENABLE  equ 4h
FILE_CACHE_MIN_HARD_DISABLE equ 8h

GetWriteWatch   proto WINAPI,
    dwFlags:        dword,
    lpBaseAddress:  PVOID,
    dwRegionSize:   SIZE_T,
    lpAddresses:    ptr PVOID,
    lpdwCount:      PULONG_PTR,
    lpdwGranularity:PULONG
;ret UINT

GlobalMemoryStatusEx    proto WINAPI,
    lpBuffer:   LPMEMORYSTATUSEX
;ret BOOL

RtlMoveMemory   proto c,
    Destination:    PVOID,
    Source:         PVOID,
    _Length:        SIZE_T
;ret void
MoveMemory  textequ <RtlMoveMemory>

QueryMemoryResourceNotification proto WINAPI,
    ResourceNotificationHandle: HANDLE,
    ResourceState:              PBOOL
;ret BOOL

RemoveSecureMemoryCacheCallback proto WINAPI,
    pfnCallBack:    PSECURE_MEMORY_CACHE_CALLBACK
;ret BOOL

ResetWriteWatch proto WINAPI,
    lpBaseAddress:  LPVOID,
    dwRegionSize:   SIZE_T
;ret UINT

RtlSecureZeroMemory proto c,
    _ptr:   PVOID,
    cnt:    SIZE_T
;ret PVOID
SecureZeroMemory    textequ <RtlSecureZeroMemory>

SetSystemFileCacheSize  proto WINAPI,
    MinimumFileCacheSize:   SIZE_T,
    MaximumFileCacheSize:   SIZE_T,
    Flags:                  dword
;ret BOOL

RtlZeroMemory   proto c,
    Destination:    PVOID,
    _Length:        SIZE_T
;ret void

;Data Execution Prevention Functions
;The following functions are used with Data Execution Prevention (DEP).
GetProcessDEPPolicy proto WINAPI,
    hProcess:   HANDLE,
    lpFlags:    LPDWORD,
    lpPermanent:PBOOL
;ret BOOL

PROCESS_DEP_ENABLE                      equ 00000001h
PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION equ 00000002h

GetSystemDEPPolicy  proto WINAPI    ;ret DEP_SYSTEM_POLICY_TYPE
AlwaysOff   equ 0
AlwaysOn    equ 1
OptIn       equ 2
OptOut      equ 3
DEP_SYSTEM_POLICY_TYPE  typedef dword

SetProcessDEPPolicy proto WINAPI,
    dwFlags:    dword
;ret BOOL

;File Mapping Functions
CreateFileMappingA  proto WINAPI,
    hFile:              HANDLE,
    lpAttributes:       LPSECURITY_ATTRIBUTES,
    flProtect:          dword,
    dwMaximumSizeHigh:  dword,
    dwMaximumSizeLow:   dword,
    lpName:             LPCSTR
;ret HANDLE

CreateFileMappingW  proto WINAPI,
    hFile:              HANDLE,
    lpAttributes:       LPSECURITY_ATTRIBUTES,
    flProtect:          dword,
    dwMaximumSizeHigh:  dword,
    dwMaximumSizeLow:   dword,
    lpName:             LPCWSTR
;ret HANDLE
__AW <CreateFileMapping>

SEC_COMMIT              equ 8000000h
SEC_IMAGE               equ 1000000h
SEC_IMAGE_NO_EXECUTE    equ 11000000h
SEC_LARGE_PAGES         equ 80000000h
SEC_NOCACHE             equ 10000000h
SEC_RESERVE             equ 4000000h
SEC_WRITECOMBINE        equ 40000000h

CreateFileMappingFromApp    proto WINAPI,
    hFile:              HANDLE,
    SecurityAttributes: PSECURITY_ATTRIBUTES,
    PageProtection:     ULONG,
    MaximumSize:        ULONG64,
    _Name:              PCWSTR
;ret HANDLE

CreateFileMappingNumaA  proto WINAPI,
    hfile:                  HANDLE,
    lpFileMappingAttributes:LPSECURITY_ATTRIBUTES,
    flProtect:              dword,
    dwMaximumSizeHigh:      dword,
    dwMaximumSizeLow:       dword,
    lpName:                 LPCSTR,
    nndPreferred:           dword
;ret HANDLE

CreateFileMappingNumaW  proto WINAPI,
    hfile:                  HANDLE,
    lpFileMappingAttributes:LPSECURITY_ATTRIBUTES,
    flProtect:              dword,
    dwMaximumSizeHigh:      dword,
    dwMaximumSizeLow:       dword,
    lpName:                 LPCWSTR,
    nndPreferred:           dword
;ret HANDLE
__AW <CreateFileMappingNuma>

NUMA_NO_PREFERRED_NODE  equ 0ffffffffh

FlushViewOfFile proto WINAPI,
    lpBaseAddress:          LPCVOID,
    dwNumberOfBytesToFlush: SIZE_T
;ret BOOL

MapViewOfFile   proto WINAPI,
    hFileMappingObject:     HANDLE,
    dwDesiredAccess:        dword,
    dwFileOffsetHigh:       dword,
    dwFileOffsetLow:        dword,
    dwNumberOfBytesToMap:   SIZE_T
;ret LPVOID

FILE_MAP_COPY       equ SECTION_QUERY
FILE_MAP_WRITE      equ SECTION_MAP_WRITE
FILE_MAP_READ       equ SECTION_MAP_READ
FILE_MAP_ALL_ACCESS equ SECTION_ALL_ACCESS
FILE_MAP_EXECUTE    equ SECTION_MAP_EXECUTE_EXPLICIT

MapViewOfFileEx proto WINAPI,
    hFileMappingObject:     HANDLE,
    dwDesiredAccess:        dword,
    dwFileOffsetHigh:       dword,
    dwFileOffsetLow:        dword,
    dwNumberOfBytesToMap:   SIZE_T,
    lpBaseAddress:          LPVOID
;ret LPVOID

MapViewOfFileExNuma proto WINAPI,
    hFileMappingObject:     HANDLE,
    dwDesiredAccess:        dword,
    dwFileOffsetHigh:       dword,
    dwFileOffsetLow:        dword,
    dwNumberOfBytesToMap:   SIZE_T,
    lpBaseAddress:          LPVOID,
    nndPreferred:           dword
;ret LPVOID

MapViewOfFileFromApp    proto WINAPI,
    hFileMappingObject: HANDLE,
    DesiredAccess:      ULONG,
    FileOffset:         ULONG64,
    NumberOfBytesToMap: SIZE_T
;ret PVOID

OpenFileMappingA    proto WINAPI,
    dwDesiredAccess:    dword,
    bInheritHandle:     BOOL,
    lpName:             LPCSTR
;ret HANDLE

OpenFileMappingW    proto WINAPI,
    dwDesiredAccess:    dword,
    bInheritHandle:     BOOL,
    lpName:             LPCWSTR
;ret HANDLE
__AW <OpenFileMapping>

UnmapViewOfFile proto WINAPI,
    lpBaseAddress:  LPCVOID
;ret BOOL

;AWE Functions
AllocateUserPhysicalPages   proto WINAPI,
    hProcess:       HANDLE,
    NumberOfPages:  PULONG_PTR,
    UserPfnArray:   PULONG_PTR
;ret BOOL

FreeUserPhysicalPages   proto WINAPI,
    hProcess:       HANDLE,
    NumberOfPages:  PULONG_PTR,
    UserPfnArray:   PULONG_PTR
;ret BOOL

MapUserPhysicalPages    proto WINAPI,
    hProcess:       HANDLE,
    NumberOfPages:  PULONG_PTR,
    UserPfnArray:   PULONG_PTR
;ret BOOL

MapUserPhysicalPageScatter  proto WINAPI,
    VirtualAddresses:   ptr PVOID,
    NumberOfPages:      ULONG_PTR,
    PageArray:          PULONG_PTR
;ret BOOL

;Heap Functions
GetProcessHeap  proto WINAPI    ;ret HANDLE

GetProcessHeaps proto WINAPI,
    NumberOfHeaps:  dword,
    ProcessHeaps:   PHANDLE
;ret dword

HeapAlloc   proto WINAPI,
    hHeap:      HANDLE,
    dwFlags:    dword,
    dwBytes:    SIZE_T
;ret LPVOID

HEAP_GENERATE_EXCEPTIONS    equ 00000004h
HEAP_NO_SERIALIZE           equ 00000001h
HEAP_ZERO_MEMORY            equ 00000008h

HeapCompact proto WINAPI,
    hHeap:  HANDLE,
    dwFlags:dword
;ret SIZE_T

HeapCreate  proto WINAPI,
    flOptions:      dword,
    dwInitialSize:  SIZE_T,
    dwMaximumSize:  SIZE_T
;ret HANDLE

HEAP_CREATE_ENABLE_EXECUTE  equ 00040000h

HeapDestroy proto WINAPI,
    hHeap:  HANDLE
;ret BOOL

HeapFree    proto WINAPI,
    hHeap:  HANDLE,
    dwFlags:dword,
    lpMem:  LPVOID
;ret BOOL

HeapLock    proto WINAPI,
    hHeap:  HANDLE
;ret BOOL

HeapCompatibilityInformation        equ 0
HeapEnableTerminationOnCorruption   equ 1
HeapOptimizeResources               equ 3
HEAP_INFORMATION_CLASS  typedef dword
HeapQueryInformation    proto WINAPI,
    HeapHandle:             HANDLE,
    HeapInformationClass:   HEAP_INFORMATION_CLASS,
    HeapInformation:        PVOID,
    HeapInformationLength:  SIZE_T,
    ReturnLength:           PSIZE_T
;ret BOOL

HeapReAlloc proto WINAPI,
    hHeap:  HANDLE,
    dwFlags:dword,
    lpMem:  LPVOID,
    dwBytes:SIZE_T
;ret LPVOID

HEAP_REALLOC_IN_PLACE_ONLY  equ 00000010h

HeapSetInformation  proto WINAPI,
    HeapHandle:             HANDLE,
    HeapInformationClass:   HEAP_INFORMATION_CLASS,
    HeapInformation:        PVOID,
    HeapInformationLength:  SIZE_T
;ret BOOL

HeapSize    proto WINAPI,
    hHeap:  HANDLE,
    dwFlags:dword,
    lpMem:  LPCVOID
;ret SIZE_T

HeapUnlock  proto WINAPI,
    hHeap:  HANDLE
;ret BOOL

HeapValidate    proto WINAPI,
    hHeap:  HANDLE,
    dwFlags:dword,
    lpMem:  LPCVOID
;ret BOOL

HeapWalk    proto WINAPI,
    hHeap:  HANDLE,
    lpEntry:LPPROCESS_HEAP_ENTRY
;ret BOOL

;Virtual Memory Functions
DiscardVirtual  proto WINAPI,
    VirtualAddress: PVOID,
    _Size:          SIZE_T
;ret dword

VMOfferPriorityVeryLow      equ 00001000h
VMOfferPriorityLow          equ 00002000h
VMOfferPriorityBelowNormal  equ 00002000h
VMOfferPriorityNormal       equ 00002000h
OFFER_PRIORITY  typedef dword

OfferVirtualMemory  proto WINAPI,
    VirtualAddress: PVOID,
    _Size:          SIZE_T,
    Priority:       OFFER_PRIORITY
;ret dword

PrefetchVirtualMemory   proto WINAPI,
    hProcess:           HANDLE,
    NumberOfEntries:    ULONG_PTR,
    VirtualAddresses:   PWIN32_MEMORY_RANGE_ENTRY,
    Flags:              ULONG
;ret BOOL

ReclaimVirtualMemory    proto WINAPI,
    VirtualAddress: PVOID,
    _Size:          SIZE_T
;ret dword

VirtualAlloc    proto WINAPI,
    lpAddress:          LPVOID,
    dwSize:             SIZE_T,
    flAllocationType:   dword,
    flProtect:          dword
;ret LPVOID

MEM_COMMIT      equ 00001000h
MEM_RESERVE     equ 00002000h
MEM_RESET       equ 00080000h
MEM_RESET_UNDO  equ 1000000h
MEM_LARGE_PAGES equ 20000000h
MEM_PHYSICAL    equ 00400000h
MEM_TOP_DOWN    equ 00100000h
MEM_WRITE_WATCH equ 00200000h

VirtualAllocEx  proto WINAPI,
    hProcess:           HANDLE,
    lpAddress:          LPVOID,
    dwSize:             SIZE_T,
    flAllocationType:   dword,
    flProtect:          dword
;ret LPVOID

VirtualAllocExNuma  proto WINAPI,
    hProcess:           HANDLE,
    lpAddress:          LPVOID,
    dwSize:             SIZE_T,
    flAllocationType:   dword,
    flProtect:          dword,
    nndPreferred:       dword
;ret LPVOID

VirtualFree proto WINAPI,
    lpAddress:  LPVOID,
    dwSize:     SIZE_T,
    dwFreeType: dword
;ret BOOL

MEM_DECOMMIT    equ 4000h
MEM_RELEASE     equ 8000h

VirtualFreeEx   proto WINAPI,
    hProcess:   HANDLE,
    lpAddress:  LPVOID,
    dwSize:     SIZE_T,
    dwFreeType: dword
;ret BOOL

VirtualLock proto WINAPI,
    lpAddress:  LPVOID,
    dwSize:     SIZE_T
;ret BOOL

VirtualProtect  proto WINAPI,
    lpAddress:      LPVOID,
    dwSize:         SIZE_T,
    flNewProtect:   dword,
    lpflOldProtect: PDWORD
;ret BOOL

VirtualProtectEx    proto WINAPI,
    hProcess:       HANDLE,
    lpAddress:      LPVOID,
    dwSize:         SIZE_T,
    flNewProtect:   dword,
    lpflOldProtect: PDWORD
;ret BOOL

VirtualQuery    proto WINAPI,
    lpAddress:  LPCVOID,
    lpBuffer:   PMEMORY_BASIC_INFORMATION,
    dwLength:   SIZE_T
;ret SIZE_T

VirtualQueryEx  proto WINAPI,
    hProcess:   HANDLE,
    lpAddress:  LPCVOID,
    lpBuffer:   PMEMORY_BASIC_INFORMATION,
    dwLength:   SIZE_T
;ret SIZE_T

VirtualUnlock   proto WINAPI,
    lpAddress:  LPVOID,
    dwSize:     SIZE_T
;ret BOOL

;Global and Local Functions
;The following are the global and local functions. These functions are provided for compatibility with 16-bit Windows and are used with Dynamic Data Exchange (DDE), 
;the clipboard functions, and OLE data objects. Unless documentation specifically states that a global or local function should be used, new applications should use the
;corresponding heap function with the handle returned by GetProcessHeap. For equivalent functionality to the global or local function, set the heap function's dwFlags
;parameter to 0.

GHND            equ 0042h
GMEM_FIXED      equ 0000h
GMEM_MOVEABLE   equ 0002h
GMEM_ZEROINIT   equ 0040h
GPTR            equ 0040h

LHND            equ 0042h
LMEM_FIXED      equ 0000h
LMEM_MOVEABLE   equ 0002h
LMEM_ZEROINIT   equ 0040h
LPTR            equ 0040h
NONZEROLHND     equ LMEM_MOVEABLE
NONZEROLPTR     equ LMEM_FIXED

GlobalAlloc proto WINAPI,
    uFlags: UINT,
    dwBytes:SIZE_T
;ret HGLOBAL

LocalAlloc  proto WINAPI,
    uFlags: UINT,
    uBytes: SIZE_T
;ret HLOCAL

GlobalDiscard   proto WINAPI,
    hMem:   HGLOBAL
;ret HGLOBAL

LocalDiscard    proto WINAPI,
    hlocMem:HLOCAL
;ret HLOCAL

GlobalFlags proto WINAPI,
    hMem:   HGLOBAL
;ret UINT

LocalFlags  proto WINAPI,
    hMem:   HLOCAL
;ret UINT

GlobalFree  proto WINAPI,
    hMem:   HGLOBAL
;ret HGLOBAL

LocalFree   proto WINAPI,
    hMem:   HLOCAL
;ret HLOCAL

GlobalHandle    proto WINAPI,
    pMem:   LPCVOID
;ret HGLOBAL

LocalHandle proto WINAPI,
    pMem:   LPCVOID
;ret HLOCAL

GlobalLock  proto WINAPI,
    hMem:   HGLOBAL
;ret LPVOID

LocalLock   proto WINAPI,
    hMem:   HLOCAL
;ret LPVOID

GlobalReAlloc   proto WINAPI,
    hMem:   HGLOBAL,
    dwBytes:SIZE_T,
    uFlags: UINT
;ret HGLOBAL

LocalReAlloc    proto WINAPI,
    hMem:   HLOCAL,
    uBytes: SIZE_T,
    uFlags: UINT
;ret HLOCAL

GlobalSize  proto WINAPI,
    hMem:   HGLOBAL
;ret SIZE_T

LocalSize   proto WINAPI,
    hMem:   HLOCAL
;ret UINT

GlobalUnlock    proto WINAPI,
    hMem:   HGLOBAL
;ret BOOL

LocalUnlock proto WINAPI,
    hMem:   HLOCAL
;ret BOOL

;Bad Memory Functions
BadMemoryCallbackRoutine_t      typedef proto WINAPI    ;ret VOID
PBAD_MEMORY_CALLBACK_ROUTINE    typedef ptr BadMemoryCallbackRoutine_t

GetMemoryErrorHandlingCapabilities  proto WINAPI,
    Capabilities:   PULONG
;ret BOOL

MEHC_PATROL_SCRUBBER_PRESENT    equ 1

RegisterBadMemoryNotification   proto WINAPI,
    Callback:   PBAD_MEMORY_CALLBACK_ROUTINE
;ret PVOID

UnregisterBadMemoryNotification proto WINAPI,
    RegistrationHandle: PVOID
;ret BOOL

;Obsolete Functions
;The following functions are provided only for compatibility with 16-bit versions of Windows: 
IsBadCodePtr    proto WINAPI,
    lpfn:   FARPROC
;ret BOOL

IsBadReadPtr    proto WINAPI,
    lp: PVOID,
    ucb:UINT_PTR
;ret BOOL

IsBadStringPtrA proto WINAPI,
    lpsz:   LPCSTR,
    ucchMax:UINT_PTR
;ret BOOL

IsBadStringPtrW proto WINAPI,
    lpsz:   LPCWSTR,
    ucchMax:UINT_PTR
;ret BOOL
__AW <IsBadStringPtr>

IsBadWritePtr   proto WINAPI,
    lp: LPVOID,
    ucb:UINT_PTR
;ret BOOL

GlobalMemoryStatus  proto WINAPI,
    lpBuffer:   LPMEMORYSTATUS
;ret void

;Time
;The date and time functions retrieve and set the date and time for the system and individual files. This overview describes how to use these functions to examine and
;modify dates and times.
FILETIME    struct
    dwLowDateTime   dword   ?
    dwHighDateTime  dword   ?
FILETIME    ends
PFILETIME   typedef ptr FILETIME
LPFILETIME  typedef ptr FILETIME

;File Management
;<https://msdn.microsoft.com/en-us/library/windows/desktop/aa364229.aspx>
;A file object provides a representation of a resource (either a physical device or a resource located on a physical device) that can be managed by the I/O system. Like
;other objects, they enable sharing of the resource, they have names, they are protected by object-based security, and they support synchronization. The I/O system also
;enables reading from or writing to the resource.
OVERLAPPED  struct
    Internal        ULONG_PTR   ?
    InternalHigh    ULONG_PTR   ?
    union
        struct
            _Offset     dword   ?
            OffsetHigh  dword   ?
        ends
        Pointer PVOID   ?
    ends
    hEvent          HANDLE      ?
OVERLAPPED  ends
LPOVERLAPPED    typedef ptr OVERLAPPED

FileIOCompletionRoutine_t   typedef proto CALLBACK,
    dwErrorCode:                dword,
    dwNumberOfBytesTransfered:  dword,
    lpOverlapped:               LPOVERLAPPED
;ret VOID
LPOVERLAPPED_COMPLETION_ROUTINE typedef ptr FileIOCompletionRoutine_t

;Synchronization
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms686353.aspx>

WAIT_OBJECT_0   equ 00000000h
WAIT_TIMEOUT    equ 00000102h

CRITICAL_SECTION    typedef RTL_CRITICAL_SECTION
PCRITICAL_SECTION   typedef PRTL_CRITICAL_SECTION
LPRTL_CRITICAL_SECTION  typedef PRTL_CRITICAL_SECTION

WaitOrTimerCallback_t   typedef proto CALLBACK,
    lpParameter:        PVOID,
    TimerOrWaitFired:   BOOLEAN
;ret VOID
WAITORTIMERCALLBACK typedef ptr WaitOrTimerCallback_t

;Processes and Threads
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms684841.aspx>
;An application consists of one or more processes. A process, in the simplest terms, is an executing program. One or more threads run in the context of the process. A
;thread is the basic unit to which the operating system allocates processor time. A thread can execute any part of the process code, including parts currently being
;executed by another thread. 
;A job object allows groups of processes to be managed as a unit. Job objects are namable, securable, sharable objects that control attributes of the processes associated
;with them. Operations performed on the job object affect all processes associated with the job object.
;A thread pool is a collection of worker threads that efficiently execute asynchronous callbacks on behalf of the application. The thread pool is primarily used to reduce
;the number of application threads and provide management of the worker threads. 
;A fiber is a unit of execution that must be manually scheduled by the application. Fibers run in the context of the threads that schedule them.
;User-mode scheduling (UMS) is a lightweight mechanism that applications can use to schedule their own threads. UMS threads differ from fibers in that each UMS thread has
;its own thread context instead of sharing the thread context of a single thread. 

CREATE_BREAKAWAY_FROM_JOB            equ 01000000h
CREATE_DEFAULT_ERROR_MODE            equ 04000000h
CREATE_NEW_CONSOLE                   equ 00000010h
CREATE_NEW_PROCESS_GROUP             equ 00000200h
CREATE_NO_WINDOW                     equ 08000000h
CREATE_PROTECTED_PROCESS             equ 00040000h
CREATE_PRESERVE_CODE_AUTHZ_LEVEL     equ 02000000h
CREATE_SEPARATE_WOW_VDM              equ 00000800h
CREATE_SHARED_WOW_VDM                equ 00001000h
CREATE_SUSPENDED                     equ 00000004h
CREATE_UNICODE_ENVIRONMENT           equ 00000400h
DEBUG_ONLY_THIS_PROCESS              equ 00000002h
DEBUG_PROCESS                        equ 00000001h
DETACHED_PROCESS                     equ 00000008h
EXTENDED_STARTUPINFO_PRESENT         equ 00080000h
INHERIT_PARENT_AFFINITY              equ 00010000h

;Process and Thread Structures
PROCESS_INFORMATION struct
    hProcess    HANDLE  ?
    hThread     HANDLE  ?
    dwProcessId dword   ?
    dwThreadId  dword   ?
PROCESS_INFORMATION ends
LPPROCESS_INFORMATION   typedef ptr PROCESS_INFORMATION

STARTUPINFOA    struct
    cb              dword   ?
    lpReserved      LPSTR   ?
    lpDesktop       LPSTR   ?
    lpTitle         LPSTR   ?
    dwX             dword   ?
    dwY             dword   ?
    dwXSize         dword   ?
    dwYSize         dword   ?
    dwXCountChars   dword   ?
    dwYCountChars   dword   ?
    dwFillAttribute dword   ?
    dwFlags         dword   ?
    wShowWindow     word    ?
    cbReserved2     word    ?
    lpReserved2     LPBYTE  ?
    hStdInput       HANDLE  ?
    hStdOutput      HANDLE  ?
    hStdError       HANDLE  ?
STARTUPINFOA    ends
STARTUPINFOW    struct
    cb              dword   ?
    lpReserved      LPWSTR  ?
    lpDesktop       LPWSTR  ?
    lpTitle         LPWSTR  ?
    dwX             dword   ?
    dwY             dword   ?
    dwXSize         dword   ?
    dwYSize         dword   ?
    dwXCountChars   dword   ?
    dwYCountChars   dword   ?
    dwFillAttribute dword   ?
    dwFlags         dword   ?
    wShowWindow     word    ?
    cbReserved2     word    ?
    lpReserved2     LPBYTE  ?
    hStdInput       HANDLE  ?
    hStdOutput      HANDLE  ?
    hStdError       HANDLE  ?
STARTUPINFOW    ends
__AW <STARTUPINFO>
LPSTARTUPINFO   typedef ptr STARTUPINFO

STARTF_FORCEONFEEDBACK  equ 00000040h
STARTF_FORCEOFFFEEDBACK equ 00000080h
STARTF_PREVENTPINNING   equ 00002000h
STARTF_RUNFULLSCREEN    equ 00000020h
STARTF_TITLEISAPPID     equ 00001000h
STARTF_TITLEISLINKNAME  equ 00000800h
STARTF_UNTRUSTEDSOURCE  equ 00008000h
STARTF_USECOUNTCHARS    equ 00000008h
STARTF_USEFULLATTRIBUTE equ 00000010h
STARTF_USEHOTKEY        equ 00000200h
STARTF_USEPOSITION      equ 00000004h
STARTF_USESHOWWINDOW    equ 00000001h
STARTF_USESIZE          equ 00000002h
STARTF_USESTDHANDLES    equ 00000100h

PROC_THREAD_ATTRIBUTE_LIST  typedef byte    ;opaque struct
PPROC_THREAD_ATTRIBUTE_LIST typedef ptr PROC_THREAD_ATTRIBUTE_LIST
LPPROC_THREAD_ATTRIBUTE_LIST    typedef ptr PROC_THREAD_ATTRIBUTE_LIST

STARTUPINFOEXA  struct
    StartupInfo     STARTUPINFOA                {}
    lpAttributeList PPROC_THREAD_ATTRIBUTE_LIST ?
STARTUPINFOEXA  ends
STARTUPINFOEXW  struct
    StartupInfo     STARTUPINFOW                {}
    lpAttributeList PPROC_THREAD_ATTRIBUTE_LIST ?
STARTUPINFOEXW  ends
__AW <STARTUPINFOEX>
LPSTARTUPINFOEX typedef ptr STARTUPINFOEX

;User-Mode Scheduling Structures
UMS_COMPLETION_LIST typedef byte    ;opaque struct... apparently.
PUMS_COMPLETION_LIST    typedef ptr UMS_COMPLETION_LIST

UmsSchedulerStartup         equ 0
UmsSchedulerThreadBlocked   equ 1
UmsSchedulerThreadYield     equ 2
UMS_SCHEDULER_REASON    typedef dword

UmsSchedulerProc_t  typedef proto WINAPI,
    Reason:             UMS_SCHEDULER_REASON,
    ActivationPayload:  ULONG_PTR,
    SchedulerParam:     PVOID
;ret VOID
PUMS_SCHEDULER_ENTRY_POINT  typedef ptr UmsSchedulerProc_t

UMS_SCHEDULER_STARTUP_INFO  struct
    UmsVersion      ULONG                       ?
    CompletionList  PUMS_COMPLETION_LIST        ?
    SchedulerProc   PUMS_SCHEDULER_ENTRY_POINT  ?
    SchedulerParam  PVOID                       ?
UMS_SCHEDULER_STARTUP_INFO  ends
PUMS_SCHEDULER_STARTUP_INFO typedef ptr UMS_SCHEDULER_STARTUP_INFO

UMS_SYSTEM_THREAD_INFORMATION   struct
    UmsVersion  ULONG   ?
    struct
        IsUmsSchedulerThread    ULONG   ?
        IsUmsWorkerThread       ULONG   ?
    ends
UMS_SYSTEM_THREAD_INFORMATION   ends
PUMS_SYSTEM_THREAD_INFORMATION  typedef ptr UMS_SYSTEM_THREAD_INFORMATION

;Process Functions
CreateProcessA  proto WINAPI,
    lpApplicationName:      LPCSTR,
    lpCommandLine:          LPSTR,
    lpProcessAttributes:    LPSECURITY_ATTRIBUTES,
    lpThreadAttributes:     LPSECURITY_ATTRIBUTES,
    bInheritHandles:        BOOL,
    dwCreationFlags:        dword,
    lpEnvironment:          LPVOID,
    lpCurrentDirectory:     LPCSTR,
    lpStartupInfo:          LPSTARTUPINFO,
    lpProcessInformation:   LPPROCESS_INFORMATION
;ret BOOL
CreateProcessW  proto WINAPI,
    lpApplicationName:      LPCWSTR,
    lpCommandLine:          LPWSTR,
    lpProcessAttributes:    LPSECURITY_ATTRIBUTES,
    lpThreadAttributes:     LPSECURITY_ATTRIBUTES,
    bInheritHandles:        BOOL,
    dwCreationFlags:        dword,
    lpEnvironment:          LPVOID,
    lpCurrentDirectory:     LPCWSTR,
    lpStartupInfo:          LPSTARTUPINFO,
    lpProcessInformation:   LPPROCESS_INFORMATION
;ret BOOL
__AW <CreateProcess>

CreateProcessAsUserA    proto WINAPI,
    hToken:                 HANDLE,
    lpApplicationName:      LPCSTR,
    lpCommandLine:          LPSTR,
    lpProcessAttributes:    LPSECURITY_ATTRIBUTES,
    lpThreadAttributes:     LPSECURITY_ATTRIBUTES,
    bInheritHandles:        BOOL,
    dwCreationFlags:        dword,
    lpEnvironment:          LPVOID,
    lpCurrentDirectory:     LPCSTR,
    lpStartupInfo:          LPSTARTUPINFO,
    lpProcessInformation:   LPPROCESS_INFORMATION
;ret BOOL
CreateProcessAsUserW    proto WINAPI,
    hToken:                 HANDLE,
    lpApplicationName:      LPCWSTR,
    lpCommandLine:          LPWSTR,
    lpProcessAttributes:    LPSECURITY_ATTRIBUTES,
    lpThreadAttributes:     LPSECURITY_ATTRIBUTES,
    bInheritHandles:        BOOL,
    dwCreationFlags:        dword,
    lpEnvironment:          LPVOID,
    lpCurrentDirectory:     LPCWSTR,
    lpStartupInfo:          LPSTARTUPINFO,
    lpProcessInformation:   LPPROCESS_INFORMATION
;ret BOOL
__AW <CreateProcessAsUser>

CreateProcessWithLogonW proto WINAPI,
    lpUserName:         LPCWSTR,
    lpDomain:           LPCWSTR,
    lpPassword:         LPCWSTR,
    dwLogonFlags:       dword,
    lpApplicationName:  LPCWSTR,
    lpCommandLine:      LPWSTR,
    dwCreationFlags:    dword,
    lpEnvironment:      LPVOID,
    lpCurrentDirectory: LPCWSTR,
    lpStartupInfo:      LPSTARTUPINFO,
    lpProcessInfo:      LPPROCESS_INFORMATION
;ret BOOL

LOGON_WITH_PROFILE          equ 00000001h
LOGON_NETCREDENTIALS_ONLY   equ 00000002h

CreateProcessWithTokenW proto WINAPI,
    hToken:             HANDLE,
    dwLogonFlags:       dword,
    lpApplicationName:  LPCWSTR,
    lpCommandLine:      LPWSTR,
    dwCreationFlags:    dword,
    lpEnvironment:      LPVOID,
    lpCurrentDirectory: LPCWSTR,
    lpStartupInfo:      LPSTARTUPINFO,
    lpProcessInfo:      LPPROCESS_INFORMATION
;ret BOOL

ExitProcess proto WINAPI,
    uExitCode:  UINT
;does not return

FlushProcessWriteBuffers    proto WINAPI    ;ret VOID

FreeEnvironmentStringsA proto WINAPI,
    lpszEnvironmentBlock:   LPSTR
;ret BOOL
FreeEnvironmentStringsW proto WINAPI,
    lpszEnvironmentBlock:   LPWSTR
;ret BOOL
__AW <FreeEnvironmentStrings>

GetCommandLineA proto WINAPI    ;ret LPSTR
GetCommandLineW proto WINAPI    ;ret LPWSTR
__AW <GetCommandLine>

GetCurrentProcess   proto WINAPI    ;ret HANDLE

GetCurrentProcessId proto WINAPI    ;ret dword

GetCurrentProcessorNumber   proto WINAPI    ;ret dword

GetEnvironmentStringsA  proto WINAPI    ;ret LPCHAR
GetEnvironmentStringsW  proto WINAPI    ;ret LPWCHAR
__AW <GetEnvironmentStrings>

GetEnvironmentVariableA proto WINAPI,
    lpName:     LPCSTR,
    lpBuffer:   LPSTR,
    nSize:      dword
;ret dword
GetEnvironmentVariableW proto WINAPI,
    lpName:     LPCWSTR,
    lpBuffer:   LPWSTR,
    nSize:      dword
;ret dword
__AW <GetEnvironmentVariable>

GetExitCodeProcess  proto WINAPI,
    hProcess:   HANDLE,
    lpExitCode: LPDWORD
;ret BOOL

GetLogicalProcessorInformation  proto WINAPI,
    Buffer:         PSYSTEM_LOGICAL_PROCESSOR_INFORMATION,
    ReturnLength:   PDWORD
;ret BOOL

GetPriorityClass    proto WINAPI,
    hProcess:   HANDLE
;ret dword
ABOVE_NORMAL_PRIORITY_CLASS equ 00008000h
BELOW_NORMAL_PRIORITY_CLASS equ 00004000h
HIGH_PRIORITY_CLASS         equ 00000080h
IDLE_PRIORITY_CLASS         equ 00000040h
NORMAL_PRIORITY_CLASS       equ 00000020h
REALTIME_PRIORITY_CLASS     equ 00000100h

GetProcessAffinityMask  proto WINAPI,
    hProcess:               HANDLE,
    lpProcessAffinityMask:  PDWORD_PTR,
    lpSystemAffinityMask:   PDWORD_PTR
;ret BOOL

GetProcessGroupAffinity proto WINAPI,
    hProcess:   HANDLE,
    GroupCount: PUSHORT,
    GroupArray: PUSHORT
;ret BOOL

GetProcessHandleCount   proto WINAPI,
    hProcess:       HANDLE,
    pdwHandleCount: PDWORD
;ret BOOL

GetProcessId    proto WINAPI,
    Process:    HANDLE
;ret dword

GetProcessIdOfThread    proto WINAPI,
    Thread: HANDLE
;ret dword

GetProcessIoCounters    proto WINAPI,
    hProcess:       HANDLE,
    lpIoCounters:   PIO_COUNTERS
;ret BOOL

GetProcessMitigationPolicy  proto WINAPI,
    hProcess:           HANDLE,
    MitigationPolicy:   PROCESS_MITIGATION_POLICY,
    lpBuffer:           PVOID,
    dwLength:           SIZE_T
;ret BOOL

GetProcessPriorityBoost proto WINAPI,
    hProcess:               HANDLE,
    pDisablePriorityBoost:  PBOOL
;ret BOOL

GetProcessShutdownParameters    proto WINAPI,
    lpdwLevel:  LPDWORD,
    lpdwFlags:  LPDWORD
;ret BOOL

SHUTDOWN_NORETRY    equ 00000001h

GetProcessTimes proto WINAPI,
    hProcess:       HANDLE,
    lpCreationTime: LPFILETIME,
    lpExitTime:     LPFILETIME,
    lpKernelTime:   LPFILETIME,
    lpUserTime:     LPFILETIME
;ret BOOL

GetProcessVersion   proto WINAPI,
    ProcessId:  dword
;ret dword

GetProcessWorkingSetSize    proto WINAPI,
    hProcess:               HANDLE,
    lpMinimumWorkingSetSize:PSIZE_T,
    lpMaximumWorkingSetSize:PSIZE_T
;ret BOOL

GetProcessWorkingSetSizeEx  proto WINAPI,
    hProcess:               HANDLE,
    lpMinimumWorkingSetSize:PSIZE_T,
    lpMaximumWorkingSetSize:PSIZE_T,
    Flags:                  PDWORD
;ret BOOL

QUOTA_LIMITS_HARDWS_MIN_DISABLE equ 00000002h
QUOTA_LIMITS_HARDWS_MIN_ENABLE  equ 00000001h
QUOTA_LIMITS_HARDWS_MAX_DISABLE equ 00000008h
QUOTA_LIMITS_HARDWS_MAX_ENABLE  equ 00000004h

GetProcessorSystemCycleTime proto WINAPI,
    _Group:         USHORT,
    Buffer:         PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION,
    ReturnedLength: PDWORD
;ret BOOL

GetStartupInfoA proto WINAPI,
    lpStartupInfo:  LPSTARTUPINFO
;ret VOID
GetStartupInfoW proto WINAPI,
    lpStartupInfo:  LPSTARTUPINFO
;ret VOID
__AW <GetStartupInfo>

NeedCurrentDirectoryForExePathA proto WINAPI,
    ExeName:    LPCSTR
;ret BOOL
NeedCurrentDirectoryForExePathW proto WINAPI,
    ExeName:    LPCWSTR
;ret BOOL
__AW <NeedCurrentDirectoryForExePath>

OpenProcess proto WINAPI,
    dwDesiredAccess:    dword,
    bInheritHandle:     BOOL,
    dwProcessId:        dword
;ret HANDLE

QueryFullProcessImageNameA  proto WINAPI,
    hProcess:   HANDLE,
    dwFlags:    dword,
    lpExeName:  LPSTR,
    lpdwSize:   PDWORD
;ret BOOL
QueryFullProcessImageNameW  proto WINAPI,
    hProcess:   HANDLE,
    dwFlags:    dword,
    lpExeName:  LPWSTR,
    lpdwSize:   PDWORD
;ret BOOL
__AW <QueryFullProcessImageName>

PROCESS_NAME_NATIVE equ 00000001h

QueryProcessAffinityUpdateMode  proto WINAPI,
    ProcessHandle:  HANDLE,
    lpdwFlags:      dword
;ret BOOL

PROCESS_AFFINITY_ENABLE_AUTO_UPDATE equ 00000001h

QueryProcessCycleTime   proto WINAPI,
    ProcessHandle:  HANDLE,
    CycleTime:      PULONG64
;ret BOOL

SetEnvironmentVariableA proto WINAPI,
    lpName: LPCSTR,
    lpValue:LPCSTR
;ret BOOL
SetEnvironmentVariableW proto WINAPI,
    lpName: LPCWSTR,
    lpValue:LPCWSTR
;ret BOOL
__AW <SetEnvironmentVariable>

SetPriorityClass    proto WINAPI,
    hProcess:       HANDLE,
    dwPriorityClass:dword
;ret BOOL

SetProcessAffinityMask  proto WINAPI,
    hProcess:               HANDLE,
    dwProcessAffinityMask:  DWORD_PTR
;ret BOOL

SetProcessAffinityUpdateMode    proto WINAPI,
    ProcessHandle:  HANDLE,
    dwFlags:        dword
;ret bool

SetProcessMitigationPolicy  proto WINAPI,
    MitigationPolicy:   PROCESS_MITIGATION_POLICY,
    lpBuffer:           PVOID,
    dwLength:           SIZE_T
;ret BOOL

SetProcessPriorityBoost proto WINAPI,
    hProcess:               HANDLE,
    DisablePriorityBoost:   BOOL
;ret BOOL

SetProcessShutdownParameters    proto WINAPI,
    dwLevel:    dword,
    dwFlags:    dword
;ret BOOL

SetProcessWorkingSetSize    proto WINAPI,
    hProcess:               HANDLE,
    dwMinimumWorkingSetSize:SIZE_T,
    dwMaximumWorkingSetSize:SIZE_T
;ret BOOL

SetProcessWorkingSetSizeEx  proto WINAPI,
    hProcess:               HANDLE,
    dwMinimumWorkingSetSize:SIZE_T,
    dwMaximumWorkingSetSize:SIZE_T,
    Flags:                  dword
;ret BOOL

TerminateProcess    proto WINAPI,
    hProcess:   HANDLE,
    uExitCode:  UINT
;ret BOOL

;Policy Functions
QueryProtectedPolicy    proto WINAPI,
    PolicyGuid: LPCGUID,
    PolicyValue:PULONG_PTR
;ret BOOL

SetProtectedPolicy  proto WINAPI,
    PolicyGuid:     LPCGUID,
    PolicyValue:    ULONG_PTR,
    OldPolicyValue: PULONG_PTR
;ret BOOL

ThreadProc_t    typedef proto WINAPI,
    lpParameter:    LPVOID
;ret dword
LPTHREAD_START_ROUTINE  typedef ptr ThreadProc_t

CreateRemoteThread  proto WINAPI,
    hProcess:           HANDLE,
    lpThreadAttributes: LPSECURITY_ATTRIBUTES,
    dwStackSize:        SIZE_T,
    lpStartAddress:     LPTHREAD_START_ROUTINE,
    lpParameter:        LPVOID,
    dwCreationFlags:    dword,
    lpThreadId:         LPDWORD
;ret HANDLE

STACK_SIZE_PARAM_IS_A_RESERVATION   equ 00010000h

CreateRemoteThreadEx    proto WINAPI,
    hProcess:           HANDLE,
    lpThreadAttributes: LPSECURITY_ATTRIBUTES,
    dwStackSize:        SIZE_T,
    lpStartAddress:     LPTHREAD_START_ROUTINE,
    lpParameter:        LPVOID,
    dwCreationFlags:    dword,
    lpAttributeList:    LPPROC_THREAD_ATTRIBUTE_LIST,
    lpThreadId:         LPDWORD
;ret HANDLE

CreateThread    proto WINAPI,
    lpThreadAttributes: LPSECURITY_ATTRIBUTES,
    dwStackSize:        SIZE_T,
    lpStartAddress:     LPTHREAD_START_ROUTINE,
    lpParameter:        LPVOID,
    dwCreationFlags:    dword,
    lpThreadId:         LPDWORD
;ret HANDLE

ExitThread  proto WINAPI,
    dwExitCode: dword
;ret VOID

GetCurrentThread    proto WINAPI    ;ret HANDLE
GetCurrentThreadId  proto WINAPI    ;ret dword

GetExitCodeThread   proto WINAPI,
    hThread:    HANDLE,
    lpExitCode: LPDWORD
;BOOL

GetThreadGroupAffinity  proto WINAPI,
    hThread:        HANDLE,
    GroupAffinity:  PGROUP_AFFINITY
;ret BOOL

GetThreadId proto WINAPI,
    Thread: HANDLE
;ret dword

GetThreadIdealProcessorEx   proto WINAPI,
    hThread:            HANDLE,
    lpIdealProcessor:   PPROCESSOR_NUMBER
;ret BOOL

GetThreadIOPendingFlag  proto WINAPI,
    hThread:        HANDLE,
    lpIOIsPending:  PBOOL
;ret BOOL

GetThreadPriority   proto WINAPI,
    hThread:HANDLE
;ret sdword

THREAD_PRIORITY_ABOVE_NORMAL    equ 1
THREAD_PRIORITY_BELOW_NORMAL    equ -1
THREAD_PRIORITY_HIGHEST         equ 2
THREAD_PRIORITY_IDLE            equ -15
THREAD_PRIORITY_LOWEST          equ -2
THREAD_PRIORITY_NORMAL          equ 0
THREAD_PRIORITY_TIME_CRITICAL   equ 15

GetThreadPriorityBoost  proto WINAPI,
    hThread:                HANDLE,
    pDisablePriorityBoost:  PBOOL
;ret BOOL

GetThreadTimes  proto WINAPI,
    hThread:        HANDLE,
    lpCreationTime: LPFILETIME,
    lpExitTime:     LPFILETIME,
    lpKernelTime:   LPFILETIME,
    lpUserTime:     LPFILETIME
;ret BOOL

OpenThread  proto WINAPI,
    dwDesiredAccess:    dword,
    bInheritHandle:     BOOL,
    dwThreadId:         dword
;ret HANDLE

QueryIdleProcessorCycleTime proto WINAPI,
    BufferLength:           PULONG,
    ProcessorIdleCycleTime: PULONG64
;ret BOOL

QueryThreadCycleTime    proto WINAPI,
    ThreadHandle:   HANDLE,
    CycleTime:      PULONG64
;ret BOOL

ResumeThread    proto WINAPI,
    hThread:HANDLE
;ret dword

SetThreadAffinityMask   proto WINAPI,
    hThread:                HANDLE,
    dwThreadAffinityMask:   DWORD_PTR
;ret DWORD_PTR

SetThreadGroupAffinity  proto WINAPI,
    hThread:                HANDLE,
    GroupAffinity:          PGROUP_AFFINITY,
    PreviousGroupAffinity:  PGROUP_AFFINITY
;ret BOOL

SetThreadIdealProcessor proto WINAPI,
    hThread:            HANDLE,
    dwIdealProcessor:   dword
;ret dword

SetThreadIdealProcessorEx   proto WINAPI,
    hThread:                    HANDLE,
    lpIdealProcessor:           PPROCESSOR_NUMBER,
    lpPreviousIdealProcessor:   PPROCESSOR_NUMBER
;ret BOOL

SetThreadPriority   proto WINAPI,
    hThread:    HANDLE,
    nPriority:  sdword
;ret BOOL

THREAD_MODE_BACKGROUND_BEGIN    equ 00010000h
THREAD_MODE_BACKGROUND_END      equ 00020000h

SetThreadPriorityBoost  proto WINAPI,
    hThread:                HANDLE,
    DisablePriorityBoost:   BOOL
;ret BOOL

SetThreadStackGuarantee proto WINAPI,
    StackSizeInBytes:   PULONG
;ret BOOL

Sleep   proto WINAPI,
    dwMilliseconds: dword
;ret VOID

SleepEx proto WINAPI,
    dwMilliseconds: dword,
    bAlertable:     BOOL
;ret dword

SuspendThread   proto WINAPI,
    hThread:HANDLE
;ret dword

SwitchToThread  proto WINAPI    ;ret BOOL

TerminateThread proto WINAPI,
    hThread:    HANDLE,
    dwExitCode: dword
;ret BOOL

TlsAlloc    proto WINAPI    ;ret dword

TlsFree proto WINAPI,
    dwTlsIndex: dword
;ret BOOL

TlsGetValue proto WINAPI,
    dwTlsIndex: dword
;ret LPVOID

TlsSetValue proto WINAPI,
    dwTlsIndex: dword,
    lpTlsValue: LPVOID
;ret BOOL

;Process and Thread Extended Attribute Functions
DeleteProcThreadAttributeList   proto WINAPI,
    lpAttributeList:    LPPROC_THREAD_ATTRIBUTE_LIST
;ret VOID

InitializeProcThreadAttributeList   proto WINAPI,
    lpAttributeList:    LPPROC_THREAD_ATTRIBUTE_LIST,
    dwAttributeCount:   dword,
    dwFlags:            dword,
    lpSize:             PSIZE_T
;ret BOOL

UpdateProcThreadAttribute   proto WINAPI,
    lpAttributeList:    LPPROC_THREAD_ATTRIBUTE_LIST,
    dwFlags:            dword,
    Attribute:          DWORD_PTR,
    lpValue:            PVOID,
    cbSize:             SIZE_T,
    lpPreviousValue:    PVOID,
    lpReturnSize:       PSIZE_T
;ret BOOL

PROC_THREAD_ATTRIBUTE_NUMBER                equ 0000ffffh
PROC_THREAD_ATTRIBUTE_THREAD                equ 00010000h
PROC_THREAD_ATTRIBUTE_INPUT                 equ 00020000h
PROC_THREAD_ATTRIBUTE_ADDITIVE              equ 00040000h
PROC_THREAD_ATTRIBUTE_EXTENDED_FLAGS        equ (PROC_THREAD_ATTRIBUTE_NUMBER and 1) or PROC_THREAD_ATTRIBUTE_INPUT or PROC_THREAD_ATTRIBUTE_ADDITIVE
PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY        equ (PROC_THREAD_ATTRIBUTE_NUMBER and 3) or PROC_THREAD_ATTRIBUTE_THREAD or PROC_THREAD_ATTRIBUTE_INPUT
PROC_THREAD_ATTRIBUTE_HANDLE_LIST           equ (PROC_THREAD_ATTRIBUTE_NUMBER and 2) or PROC_THREAD_ATTRIBUTE_INPUT
PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR       equ (PROC_THREAD_ATTRIBUTE_NUMBER and 5) or PROC_THREAD_ATTRIBUTE_THREAD or PROC_THREAD_ATTRIBUTE_INPUT
PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY     equ (PROC_THREAD_ATTRIBUTE_NUMBER and 7) or PROC_THREAD_ATTRIBUTE_INPUT
PROC_THREAD_ATTRIBUTE_PARENT_PROCESS        equ (PROC_THREAD_ATTRIBUTE_NUMBER and 0) or PROC_THREAD_ATTRIBUTE_INPUT
PROC_THREAD_ATTRIBUTE_PERFERRED_NODE        equ (PROC_THREAD_ATTRIBUTE_NUMBER and 4) or PROC_THREAD_ATTRIBUTE_INPUT
PROC_THREAD_ATTRIBUTE_UMS_THREAD            equ (PROC_THREAD_ATTRIBUTE_NUMBER and 6) or PROC_THREAD_ATTRIBUTE_THREAD or PROC_THREAD_ATTRIBUTE_INPUT
;PROC_THREAD_ATTRIBUTE_SECURITY_CAPABILITIES equ ;TODO I don't have the newer SDK headers handy...
;PROC_THREAD_ATTRIBUTE_PROTECTION_LEVEL      equ ;TODO I don't have the newer SDK headers handy...
PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE                                   equ 00000001h
PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE                         equ 00000002h
PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE                                 equ 00000004h
PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON              equ 00000001h shl 8
PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_OFF             equ 00000002h shl 8
PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON_REQ_RELOCS   equ 00000003h shl 8
PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_ON                     equ 00000001h shl 12
PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINAGE_ALWAYS_OFF                    equ 00000002h shl 12
PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_ON                     equ 00000001h shl 16
PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_OFF                    equ 00000002h shl 16
PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_ON                  equ 00000001h shl 20
PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_OFF                 equ 00000002h shl 20
PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_ON               equ 00000001h shl 24
PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_OFF              equ 00000002h shl 24
PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_ON         equ 00000001h shl 28
PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_OFF        equ 00000002h shl 28
PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_ON            equ 00000001h shl 32    ;FIXME won't fit in a 32-bit constant
PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_OFF           equ 00000002h shl 32    ;FIXME won't fit in a 32-bit constant

;WOW64 Functions
IsWow64Process  proto WINAPI,
    hProcess:       HANDLE,
    Wow64Process:   PBOOL
;ret BOOL

Wow64SuspendThread  proto WINAPI,
    hThread:HANDLE
;ret dword

;Job object functions
AssignProcessToJobObject    proto WINAPI,
    hJob:       HANDLE,
    hProcess:   HANDLE
;ret BOOL

CreateJobObjectA    proto WINAPI,
    lpJobAttributes:LPSECURITY_ATTRIBUTES,
    lpName:         LPCSTR
;ret HANDLE
CreateJobObjectW    proto WINAPI,
    lpJobAttributes:LPSECURITY_ATTRIBUTES,
    lpName:         LPCWSTR
;ret HANDLE
__AW <CreateJobObject>

IsProcessInJob  proto WINAPI,
    ProcessHandle:  HANDLE,
    JobHandle:      HANDLE,
    Result:         PBOOL
;ret BOOL

OpenJobObjectA  proto WINAPI,
    dwDesiredAccess:dword,
    bInheritHandles:BOOL,
    lpName:         LPCSTR
;ret HANDLE
OpenJobObjectW  proto WINAPI,
    dwDesiredAccess:dword,
    bInheritHandles:BOOL,
    lpName:         LPCSTR
;ret HANDLE
__AW <OpenJobObject>

JobObjectBasicAccountingInformation         equ 1
JobObjectBasicAndIoAccountingInformation    equ 8
JobObjectBasicLimitInformation              equ 2
JobObjectBasicProcessIdList                 equ 3
JobObjectBasicUIRestrictions                equ 4
JobObjectCpuRateControlInformation          equ 15
JobObjectEndOfJobTimeInformation            equ 6
JobObjectExtendedLimitInformation           equ 9
JobObjectGroupInformation                   equ 11
JobObjectGroupInformationEx                 equ 14
JobObjectLimitViolationInformation          equ 13
JobObjectLimitViolationInformation2         equ 35
JobObjectNetRateControlInformation          equ 32
JobObjectNotificationLimitInformation       equ 12
JobObjectNotificationLimitInformation2      equ 34
JobObjectSecurityLimitInformation           equ 5
JOBOBJECTINFOCLASS  typedef dword

QueryInformationJobObject   proto WINAPI,
    hJob:                   HANDLE,
    JobObjectInfoClass:     JOBOBJECTINFOCLASS,
    lpJobObjectInfo:        LPVOID,
    cbJobObjectInfoLength:  dword,
    lpReturnLength:         LPDWORD
;ret BOOL

SetInformationJobObject proto WINAPI,
    hJob:                   HANDLE,
    JobObjectInfoClass:     JOBOBJECTINFOCLASS,
    lpJobObjectInfo:        LPVOID,
    cbJobObjectInfoLength:  dword
;ret BOOL

TerminateJobObject  proto WINAPI,
    hJob:       HANDLE,
    uExitCode:  UINT
;ret BOOL

UserHandleGrantAccess   proto WINAPI,
    hUserHandle:HANDLE,
    hJob:       HANDLE,
    bGrant:     BOOL
;ret BOOL

;Thread Pool Functions
CallbackMayRunLong  proto WINAPI,
    pci:PTP_CALLBACK_INSTANCE
;ret BOOL

CancelThreadpoolIo  proto WINAPI,
    pio:PTP_IO
;ret VOID

CloseThreadpool proto WINAPI,
    ptpp:   PTP_POOL
;ret VOID

CloseThreadpoolCleanupGroup proto WINAPI,
    ptpcg:  PTP_CLEANUP_GROUP
;ret VOID

CloseThreadpoolCleanupGroupMembers  proto WINAPI,
    ptpcg:                  PTP_CLEANUP_GROUP,
    fCancelPendingCallbacks:BOOL,
    pvCleanupGroup:         PVOID
;ret VOID

CloseThreadpoolIo   proto WINAPI,
    pio:PTP_IO
;ret VOID

CloseThreadpoolTimer    proto WINAPI,
    pti:PTP_TIMER
;ret VOID

CloseThreadpoolWait proto WINAPI,
    pwa:PTP_WAIT
;ret VOID

CloseThreadpoolWork proto WINAPI,
    pwk:PTP_WORK
;ret VOID

CreateThreadpool    proto WINAPI,
    reserved:   PVOID
;ret PTP_POOL

CreateThreadpoolCleanupGroup    proto WINAPI    ;ret PTP_CLEANUP_GROUP

IoCompletionCallback_t  typedef proto WINAPI,
    Instance:                   ULONG_PTR,
    Context:                    PVOID,
    Overlapped:                 PVOID,
    IoResult:                   ULONG,
    NumberOfBytesTransferred:   ULONG_PTR,
    Io:                         PTP_IO
;ret VOID
PTP_WIN32_IO_CALLBACK   typedef ptr IoCompletionCallback_t

CreateThreadpoolIo  proto WINAPI,
    fl:     HANDLE,
    pfnio:  PTP_WIN32_IO_CALLBACK,
    pv:     PVOID,
    pcbe:   PTP_CALLBACK_ENVIRON
;ret PTP_IO

TimerCallback_t typedef proto CALLBACK,
    Instance:   PTP_CALLBACK_INSTANCE,
    Context:    PVOID,
    Timer:      PTP_TIMER
;ret VOID
PTP_TIMER_CALLBACK  typedef ptr TimerCallback_t

CreateThreadpoolTimer   proto WINAPI,
    pfnti:  PTP_TIMER_CALLBACK,
    pv:     PVOID,
    pcbe:   PTP_CALLBACK_ENVIRON
;ret PTP_TIMER

TP_WAIT_RESULT  typedef dword

WaitCallback_t  typedef proto CALLBACK,
    Instance:   PTP_CALLBACK_INSTANCE,
    Context:    PVOID,
    _Wait:      PTP_WAIT,
    WaitResult: TP_WAIT_RESULT
;ret VOID
PTP_WAIT_CALLBACK   typedef ptr WaitCallback_t

CreateThreadpoolWait    proto WINAPI,
    pfnwa:  PTP_WAIT_CALLBACK,
    pv:     PVOID,
    pcbe:   PTP_CALLBACK_ENVIRON
;ret PTP_WAIT

WorkCallback_t  typedef proto CALLBACK,
    Instance:   PTP_CALLBACK_INSTANCE,
    Context:    PVOID,
    Work:       PTP_WORK
;ret VOID
PTP_WORK_CALLBACK   typedef ptr WorkCallback_t

CreateThreadpoolWork    proto WINAPI,
    pfnwk:  PTP_WORK_CALLBACK,
    pv:     PVOID,
    pcbe:   PTP_CALLBACK_ENVIRON
;ret PTP_WORK

DestroyThreadpoolEnvironment    proto WINAPI,
    pcbe:   PTP_CALLBACK_ENVIRON
;ret VOID

DisassociateCurrentThreadFromCallback   proto WINAPI,
    pci:PTP_CALLBACK_INSTANCE
;ret VOID

FreeLibraryWhenCallbackReturns  proto WINAPI,
    pci:    PTP_CALLBACK_INSTANCE,
    _mod:   HMODULE
;ret VOID

InitializeThreadpoolEnvironment proto WINAPI,
    pcbe:   PTP_CALLBACK_ENVIRON
;ret VOID

IsThreadpoolTimerSet    proto WINAPI,
    pti:PTP_TIMER
;ret BOOL

LeaveCriticalSecionWhenCallbackReturns  proto WINAPI,
    pci:PTP_CALLBACK_INSTANCE,
    pcs:PCRITICAL_SECTION
;ret VOID

QueryThreadpoolStackInformation proto WINAPI,
    ptpp:   PTP_POOL,
    ptpsi:  PTP_POOL_STACK_INFORMATION
;ret BOOL

ReleaseMutexWhenCallbackReturns proto WINAPI,
    pci:PTP_CALLBACK_INSTANCE,
    mut:HANDLE
;ret VOID

ReleaseSemaphoreWhenCallbackReturns proto WINAPI,
    pci:    PTP_CALLBACK_INSTANCE,
    sem:    HANDLE,
    crel:   dword
;ret VOID

SetEventWhenCallbackReturns proto WINAPI,
    pci:PTP_CALLBACK_INSTANCE,
    evt:HANDLE
;ret VOID

SetThreadpoolCallbackCleanupGroup   proto WINAPI,
    pcbe:   PTP_CALLBACK_ENVIRON,
    ptpcg:  PTP_CLEANUP_GROUP,
    pfng:   PTP_CLEANUP_GROUP_CANCEL_CALLBACK
;ret VOID

SetThreadpoolCallbackLibrary    proto WINAPI,
    pcbe:   PTP_CALLBACK_ENVIRON,
    _mod:   PVOID
;ret VOID

SetThreadpoolCallbackPersistent proto WINAPI,
    pcbe:   PTP_CALLBACK_ENVIRON
;ret VOID

SetThreadpoolCallbackPool   proto WINAPI,
    pcbe:   PTP_CALLBACK_ENVIRON,
    ptpp:   PTP_POOL
;ret VOID

SetThreadpoolCallbackPriority   proto WINAPI,
    pcbe:       PTP_CALLBACK_ENVIRON,
    Priority:   TP_CALLBACK_PRIORITY
;ret VOID

SetThreadpoolCallbackRunsLong   proto WINAPI,
    pcbe:   PTP_CALLBACK_ENVIRON
;ret VOID

SetThreadpoolStackInformation   proto WINAPI,
    ptpp:   PTP_POOL,
    ptpsi:  PTP_POOL_STACK_INFORMATION
;ret BOOL

SetThreadpoolThreadMaximum  proto WINAPI,
    ptpp:       PTP_POOL,
    cthrdMost:  dword
;ret VOID

SetThreadpoolThreadMinimum  proto WINAPI,
    ptpp:       PTP_POOL,
    cthrdMic:   dword
;ret BOOL

SetThreadpoolTimerEx    proto WINAPI,
    pti:            PTP_TIMER,
    pftDueTime:     PFILETIME,
    msPeriod:       dword,
    msWindowLength: dword
;ret BOOL

SetThreadpoolTimer  proto WINAPI,
    pti:            PTP_TIMER,
    pftDueTime:     PFILETIME,
    msPeriod:       dword,
    msWindowLength: dword
;ret VOID

SetThreadpoolWait   proto WINAPI,
    pwa:        PTP_WAIT,
    h:          HANDLE,
    pftTimeout: PFILETIME
;ret VOID

SetThreadpoolWaitEx proto WINAPI,
    pwa:        PTP_WAIT,
    h:          HANDLE,
    pftTimeout: PFILETIME,
    Reserved:   PVOID
;ret BOOL

StartThreadpoolIo   proto WINAPI,
    pio:PTP_IO
;ret VOID

SubmitThreadpoolWork    proto WINAPI,
    pwk:PTP_WORK
;ret VOID

TpInitializeCallbackEnviron macro   CallbackEnviron:req
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.Version, 3
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.Pool, 0
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.CleanupGroup, 0
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.CleanupGroupCancelCallback, 0
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.RaceDll, 0
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.ActivationContext, 0
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.FinalizationCallback, 0
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.u.Flags, 0
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.CallbackPriority, TP_CALLBACK_PRIORITY_NORMAL
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.Size, sizeof TP_CALLBACK_ENVIRON
endm

TpDestroyCallbackEnviron    macro   CallbackEnviron:req
    ;no-op
endm

TpSetCallbackActivationContext  macro   CallbackEnviron:req, ActivationContext:req
    mov     eax, ActivationContext
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.ActivationContext, eax
endm

TpSetCallbackCleanupGroup   macro   CallbackEnviron:req, CleanupGroup:req, CleanupGroupCancelCallback:req
    mov     eax, CleanupGroup
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.CleanupGroup, eax
    mov     eax, CleanupGroupCancelCallback
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.CleanupGroupCancelCallback, eax
endm

TpSetCallbackFinalizationCallback   macro   CallbackEnviron:req, FinalizationCallback:req
    mov     eax, FinalizationCallback
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.FinalizationCallback, eax
endm

TpSetCallbackLongFunction   macro   CallbackEnviron:req
    or      [CallbackEnviron].TP_CALLBACK_ENVIRON.u.s, mask TP_CALLBACK_ENVIRON_LongFunction
endm

TpSetCallbackNoActivationContext    macro   CallbackEnviron:req
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.ActivationContext, -1
endm

TpSetCallbackPersistent macro   CallbackEnviron:req
    or      [CallbackEnviron].TP_CALLBACK_ENVIRON.u.s, mask TP_CALLBACK_ENVIRON_Persistent
endm

TpSetCallbackPriority   macro   CallbackEnviron:req, Priority:req
    mov     eax, Priority
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.CallbackPriority, eax
endm

TpSetCallbackRaceWithDll    macro   CallbackEnviron:req, DllHandle:req
    mov     eax, DllHandle
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.RaceDll, eax
endm

TpSetCallbackThreadpool macro   CallbackEnviron:req, Pool:req
    mov     eax, Pool
    mov     [CallbackEnviron].TP_CALLBACK_ENVIRON.Pool, eax
endm

TrySubmitThreadpoolCallback proto WINAPI,
    pfns:   PTP_SIMPLE_CALLBACK,
    pv:     PVOID,
    pcbe:   PTP_CALLBACK_ENVIRON
;ret BOOL

WaitForThreadpoolIoCallbacks    proto WINAPI,
    pio:                    PTP_IO,
    fCancelPendingCallbacks:BOOL
;ret VOID

WaitForThreadpoolTimerCallbacks proto WINAPI,
    pti:                    PTP_TIMER,
    fCancelPendingCallbacks:BOOL
;ret VOID

WaitForThreadpoolWaitCallbacks  proto WINAPI,
    pwa:                    PTP_WAIT,
    fCancelPendingCallbacks:BOOL
;ret VOID

WaitForThreadpoolWorkCallbacks  proto WINAPI,
    pwk:                    PTP_WORK,
    fCancelPendingCallbacks:BOOL
;ret VOID

BindIoCompletionCallback    proto WINAPI,
    FileHandle: HANDLE,
    Function:   LPOVERLAPPED_COMPLETION_ROUTINE,
    Flags:      ULONG
;ret BOOL

QueueUserWorkItem   proto WINAPI,
    Function:   LPTHREAD_START_ROUTINE,
    Context:    PVOID,
    Flags:      ULONG
;ret BOOL

WT_EXECUTEDEFAULT               equ 00000000h
WT_EXECUTEINIOTHREAD            equ 00000001h
WT_EXECUTEINPERSISTENTTHREAD    equ 00000080h
WT_EXECUTELONGFUNCITON          equ 00000010h
WT_TRANSFER_IMPERSONATION       equ 00000100h

RegisterWaitForSingleObject proto WINAPI,
    phNewWaitObject:PHANDLE,
    hObject:        HANDLE,
    Callback:       WAITORTIMERCALLBACK,
    Context:        PVOID,
    dwMilliseconds: ULONG,
    dwFlags:        ULONG
;ret BOOL

WT_EXECUTEINWAITTHREAD  equ 00000004h
WT_EXECUTEONLYONCE      equ 00000008h

UnregisterWaitEx    proto WINAPI,
    WaitHandle:     HANDLE,
    CompletionEvent:HANDLE
;ret BOOL

;Fiber Functions
ConvertFiberToThread    proto WINAPI    ;ret BOOL

ConvertThreadToFiber    proto WINAPI,
    lpParameter:LPVOID
;ret LPVOID

ConvertThreadToFiberEx  proto WINAPI,
    lpParameter:LPVOID,
    dwFlags:    dword
;ret LPVOID
FIBER_FLAG_FLOAT_SWITCH equ 1h

FiberProc_t typedef proto CALLBACK,
    lpParameter:PVOID
;ret VOID
LPFIBER_START_ROUTINE   typedef ptr FiberProc_t

CreateFiber proto WINAPI,
    dwStackSize:    SIZE_T,
    lpStartAddress: LPFIBER_START_ROUTINE,
    lpParameter:    LPVOID
;ret LPVOID

CreateFiberEx   proto WINAPI,
    dwStackCommitSize:  SIZE_T,
    dwStackReserveSize: SIZE_T,
    dwFlags:            dword,
    lpStartAddress:     LPFIBER_START_ROUTINE,
    lpParameter:        LPVOID
;ret LPVOID

DeleteFiber proto WINAPI,
    lpFiber:LPVOID
;ret VOID

FlsCallback_t   typedef proto WINAPI,
    lpFlsData:  PVOID
;ret VOID
PFLS_CALLBACK_FUNCTION  typedef ptr FlsCallback_t

FlsAlloc    proto WINAPI,
    lpCallback: PFLS_CALLBACK_FUNCTION
;ret dword

FlsFree proto WINAPI,
    dwFlsIndex: dword
;ret BOOL

FlsGetValue proto WINAPI,
    dwFlsIndex: dword
;ret PVOID

FlsSetValue proto WINAPI,
    dwFlsIndex: dword,
    lpFlsData:  PVOID
;ret BOOL

IsThreadAFiber  proto WINAPI    ;ret BOOL

SwitchToFiber   proto WINAPI,
    lpFiber:LPVOID
;ret VOID

;NUMA Support Functions
AllocateUserPhysicalPagesNuma   proto WINAPI,
    hProcess:       HANDLE,
    NumberOfPages:  PULONG_PTR,
    PageArray:      PULONG_PTR,
    nndPreferred:   dword
;ret BOOL

GetNumaAvailableMemoryNode  proto WINAPI,
    Node:           UCHAR,
    AvailableBytes: PULONGLONG
;ret BOOL

GetNumaAvailableMemoryNodeEx    proto WINAPI,
    Node:           USHORT,
    AvailableBytes: PULONGLONG
;ret BOOL

GetNumaHighestNodeNumber    proto WINAPI,
    HighestNodeNumber:  PULONG
;ret BOOL

GetNumaNodeNumberFromHandle proto WINAPI,
    hFile:      HANDLE,
    NodeNumber: PUSHORT
;ret BOOL

GetNumaNodeProcessorMask    proto WINAPI,
    Node:           UCHAR,
    ProcessorMask:  PULONGLONG
;ret BOOL

GetNumaNodeProcessorMaskEx  proto WINAPI,
    Node:           USHORT,
    ProcessorMask:  PGROUP_AFFINITY
;ret BOOL

GetNumaProcessorNode    proto WINAPI,
    Processor:  UCHAR,
    NodeNumber: PUCHAR
;ret BOOL

GetNumaProcessorNodeEx  proto WINAPI,
    Processor:  PPROCESSOR_NUMBER,
    NodeNumber: PUSHORT
;ret BOOL

GetNumaProximityNode    proto WINAPI,
    ProximityId:ULONG,
    NodeNumber: PUCHAR
;ret BOOL

GetNumaProximityNodeEx  proto WINAPI,
    ProximityId:ULONG,
    NodeNumber: PUSHORT
;ret BOOL

;Processor Functions
GetActiveProcessorCount proto WINAPI,
    GroupNumber:word
;ret dword

GetActiveProcessorGroupCount    proto WINAPI    ;ret word

GetCurrentProcessorNumberEx proto WINAPI,
    ProcNumber: PPROCESSOR_NUMBER
;ret VOID

GetLogicalProcessorInformationEx    proto WINAPI,
    RelationshipType:   LOGICAL_PROCESSOR_RELATIONSHIP,
    Buffer:             PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX,
    ReturnedLength:     PDWORD
;ret BOOL

GetMaximumProcessorCount    proto WINAPI,
    GroupNumber:word
;ret dword

GetMaximumProcessorGroupCount   proto WINAPI    ;ret word

QueryIdleProcessorCycleTimeEx   proto WINAPI,
    _Group:                 USHORT,
    BufferLength:           PULONG,
    ProcessorIdleCycleTime: PULONG64
;ret BOOL

;User-Mode Scheduling Functions
CreateUmsCompletionList proto WINAPI,
    UmsCompletionList:  ptr PUMS_COMPLETION_LIST
;ret BOOL

CreateUmsThreadContext  proto WINAPI,
    lpUmsThread:ptr PUMS_CONTEXT
;ret BOOL

DeleteUmsCompletionList proto WINAPI,
    UmsCompletionList:  ptr PUMS_COMPLETION_LIST
;ret BOOL

DeleteUmsThreadContext  proto WINAPI,
    UmsThread:  PUMS_CONTEXT
;ret BOOL

DequeueUmsCompletionList    proto WINAPI,
    UmsCompletionList:  PUMS_COMPLETION_LIST,
    WaitTimeOut:        dword,
    UmsThreadList:      ptr PUMS_CONTEXT
;ret BOOL

EnterUmsSchedulingMode  proto WINAPI,
    SchedulerStartupInfo:   PUMS_SCHEDULER_STARTUP_INFO
;ret BOOL

ExecuteUmsThread    proto WINAPI,
    UmsThread:  PUMS_CONTEXT
;ret BOOL

GetCurrentUmsThread proto WINAPI    ;ret PUMS_CONTEXT

GetNextUmsListItem  proto WINAPI,
    UmsContext: PUMS_CONTEXT
;ret PUMS_CONTEXT

GetUmsCompletionListEvent   proto WINAPI,
    UmsCompletionList:  PUMS_COMPLETION_LIST,
    UmsCompletionEvent: PHANDLE
;ret BOOL

GetUmsSystemThreadInformation   proto WINAPI,
    ThreadHandle:       HANDLE,
    SystemThreadInfo:   PUMS_SYSTEM_THREAD_INFORMATION
;ret BOOL

QueryUmsThreadInformation   proto WINAPI,
    UmsThread:                  PUMS_CONTEXT,
    UmsThreadInfoClass:         UMS_THREAD_INFO_CLASS,
    UmsThreadInformation:       PVOID,
    UmsThreadInformationLength: ULONG,
    ReturnLength:               PULONG
;ret BOOL

SetUmsThreadInformation proto WINAPI,
    UmsThread:                  PUMS_CONTEXT,
    UmsThreadInfoClass:         UMS_THREAD_INFO_CLASS,
    UmsThreadInformation:       PVOID,
    UmsThreadInformationLength: ULONG
;ret BOOL

UmsThreadYield  proto WINAPI,
    SchedulerParam: PVOID
;ret BOOL

;Application Recovery and Restart
;<https://msdn.microsoft.com/en-us/library/windows/desktop/cc948909.aspx>
;An application can use Application Recovery and Restart (ARR) to save data and state information before the application exits due to an unhandled exception or when the
;application stops responding. The application is also restarted, if requested.
;An application can also be restarted if an installer updates a component of the application, or if the computer needs to restart as the result of an update. Note that to
;support automatic application restart after an installer updates an application, both the application and installer need to be authored appropriately. For details, see
;Registering for Application Restart. 
ApplicationRecoveryFinished proto WINAPI,
    bSuccess:   BOOL
;ret VOID

ApplicationRecoveryInProgress   proto WINAPI,
    pbCanceled: PBOOL
;ret HRESULT

ApplicationRecoveryCallback_t typedef proto WINAPI,
    pvParameter:PVOID
;ret dword
APPLICATION_RECOVERY_CALLBACK   typedef ptr ApplicationRecoveryCallback_t

GetApplicationRecoveryCallback  proto WINAPI,
    hProcess:           HANDLE,
    pRecoveryCallback:  ptr APPLICATION_RECOVERY_CALLBACK,
    ppvParameter:       ptr PVOID,
    pdwPingInterval:    PDWORD,
    pdwFlags:           PDWORD
;ret HRESULT

GetApplicationRestartSettings   proto WINAPI,
    hProcess:       HANDLE,
    pwzCommandLine: PWSTR,
    pcchSize:       PDWORD,
    pdwFlags:       PDWORD
;ret HRESULT

RegisterApplicationRecoveryCallback proto WINAPI,
    pRecoveryCallback:  APPLICATION_RECOVERY_CALLBACK,
    pvParameter:        PVOID,
    dwPingInterval:     dword,
    dwFlags:            dword
;ret HRESULT

RegisterApplicationRestart  proto WINAPI,
    pwzCommandLine: PCWSTR,
    dwFlags:        dword
;ret HRESULT

RESTART_NO_CRASH    equ 1
RESTART_NO_HANG     equ 2
RESTART_NO_PATCH    equ 4
RESTART_NO_REBOOT   equ 8

UnregisterApplicationRecoveryCallback   proto WINAPI    ;ret HRESULT

UnregisterApplicationRestart    proto WINAPI    ;ret HRESULT

;Error Handling
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms679320.aspx>
;Well-written applications include error-handling code that allows them to recover gracefully from unexpected errors. When an error occurs, the application may need to
;request user intervention, or it may be able to recover on its own. In extreme cases, the application may log the user off or shut down the system.
Beep    proto WINAPI,
    dwFreq:     dword,
    dwDuration: dword
;ret BOOL

CaptureStackBackTrace   proto WINAPI,
    FramesToSkip:   ULONG,
    FramesToCapture:ULONG,
    BackTrace:      ptr PVOID,
    BackTraceHash:  PULONG
;ret USHORT

FatalAppExitA   proto WINAPI,
    uAction:        UINT,
    lpMessageText:  LPCSTR
;ret void
FatalAppExitW   proto WINAPI,
    uAction:        UINT,
    lpMessageText:  LPCWSTR
;ret void
__AW <FatalAppExit>

FormatMessageA  proto WINAPI,
    dwFlags:        dword,
    lpSource:       LPCVOID,
    dwMessageId:    dword,
    dwLanguageId:   dword,
    lpBuffer:       LPSTR,
    nSize:          dword,
    Arguments:      ptr byte
;ret dword
FormatMessageW  proto WINAPI,
    dwFlags:        dword,
    lpSource:       LPCVOID,
    dwMessageId:    dword,
    dwLanguageId:   dword,
    lpBuffer:       LPWSTR,
    nSize:          dword,
    Arguments:      ptr byte
;ret dword
__AW <FormatMessage>

FORMAT_MESSAGE_ALLOCATE_BUFFER  equ 00000100h
FORMAT_MESSAGE_ARGUMENT_ARRAY   equ 00002000h
FORMAT_MESSAGE_FROM_HMODULE     equ 00000800h
FORMAT_MESSAGE_FROM_STRING      equ 00000400h
FORMAT_MESSAGE_FROM_SYSTEM      equ 00001000h
FORMAT_MESSAGE_IGNORE_INSERTS   equ 00000200h
FORMAT_MESSAGE_MAX_WIDTH_MASK   equ 000000ffh

GetErrorMode    proto WINAPI    ;ret UINT

SEM_FAILCRITICALERRORS      equ 0001h
SEM_NOALIGNMENTFAULTEXCEPT  equ 0004h
SEM_NOGPFAULTERRORBOX       equ 0002h
SEM_NOOPENFILEERRORBOX      equ 8000h

GetLastError    proto WINAPI    ;ret dword

GetThreadErrorMode  proto WINAPI    ;ret dword

SetErrorMode    proto WINAPI,
    uMode:  UINT
;ret UINT

SetLastError    proto WINAPI,
    dwErrCode:  dword
;ret void

SetThreadErrorMode  proto WINAPI,
    dwNewMode:  dword,
    lpOldMode:  LPDWORD
;ret BOOL

;Resources
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ff468900.aspx>
BeginUpdateResourceA    proto WINAPI,
    pFileName:                  LPCSTR,
    bDeleteExistingResources:   BOOL
;ret HANDLE
BeginUpdateResourceW    proto WINAPI,
    pFileName:                  LPCWSTR,
    bDeleteExistingResources:   BOOL
;ret HANDLE
__AW <BeginUpdateResource>

EndUpdateResourceA  proto WINAPI,
    hUpdate:    HANDLE,
    fDiscard:   BOOL
;ret BOOL
EndUpdateResourceW  proto WINAPI,
    hUpdate:    HANDLE,
    fDiscard:   BOOL
;ret BOOL
__AW <EndUpdateResource>

EnumResLangProcA_t  typedef proto CALLBACK,
    hModule:    HMODULE,
    lpszType:   LPCSTR,
    lpszName:   LPCSTR,
    wIDLanguage:word,
    lParam:     LONG_PTR
;ret BOOL
ENUMRESLANGPROCA    typedef ptr EnumResLangProcA_t
EnumResLangProcW_t  typedef proto CALLBACK,
    hModule:    HMODULE,
    lpszType:   LPCWSTR,
    lpszName:   LPCWSTR,
    wIDLanguage:word,
    lParam:     LONG_PTR
;ret BOOL
ENUMRESLANGPROCW    typedef ptr EnumResLangProcW_t
__AW <ENUMRESLANGPROC>

EnumResourceLanguagesA  proto WINAPI,
    hModule:    HMODULE,
    lpType:     LPCSTR,
    lpName:     LPCSTR,
    lpEnumFunc: ENUMRESLANGPROCA,
    lParam:     LONG_PTR
;ret BOOL
EnumResourceLanguagesW  proto WINAPI,
    hModule:    HMODULE,
    lpType:     LPCWSTR,
    lpName:     LPCWSTR,
    lpEnumFunc: ENUMRESLANGPROCW,
    lParam:     LONG_PTR
;ret BOOL
__AW <EnumResourceLanguages>

EnumResourceLanguagesExA    proto WINAPI,
    hModule:    HMODULE,
    lpType:     LPCSTR,
    lpName:     LPCSTR,
    lpEnumFunc: ENUMRESLANGPROCA,
    lParam:     LONG_PTR,
    dwFlags:    dword,
    LangId:     LANGID
;ret BOOL
EnumResourceLanguagesExW    proto WINAPI,
    hModule:    HMODULE,
    lpType:     LPCWSTR,
    lpName:     LPCWSTR,
    lpEnumFunc: ENUMRESLANGPROCW,
    lParam:     LONG_PTR,
    dwFlags:    dword,
    LangId:     LANGID
;ret BOOL
__AW <EnumResourceLanguagesEx>

RESOURCE_ENUM_MUI           equ 0002h
RESOURCE_ENUM_LN            equ 0001h
RESOURCE_ENUM_MUI_SYSTEM    equ 0004h
RESOURCE_ENUM_VALIDATE      equ 0008h

EnumResNameProcA_t  typedef proto CALLBACK,
    hModule:    HMODULE,
    lpszType:   LPCSTR,
    lpszName:   LPSTR,
    lParam:     LONG_PTR
;ret BOOL
ENUMRESNAMEPROCA    typedef ptr EnumResNameProcA_t
EnumResNameProcW_t  typedef proto CALLBACK,
    hModule:    HMODULE,
    lpszType:   LPCWSTR,
    lpszName:   LPWSTR,
    lParam:     LONG_PTR
;ret BOOL
ENUMRESNAMEPROCW    typedef ptr EnumResNameProcW_t
__AW <ENUMRESNAMEPROC>

EnumResourceNamesA  proto WINAPI,
    hModule:    HMODULE,
    lpszType:   LPCSTR,
    lpEnumFunc: ENUMRESNAMEPROCA,
    lParam:     LONG_PTR
;ret BOOL
EnumResourceNamesW  proto WINAPI,
    hModule:    HMODULE,
    lpszType:   LPCWSTR,
    lpEnumFunc: ENUMRESNAMEPROCW,
    lParam:     LONG_PTR
;ret BOOL
__AW <EnumResourceNames>

EnumResourceNamesExA    proto WINAPI,
    hModule:    HMODULE,
    lpszType:   LPCSTR,
    lpEnumFunc: ENUMRESNAMEPROCA,
    lParam:     LONG_PTR,
    dwFlags:    dword,
    LangId:     LANGID
;ret BOOL
EnumResourceNamesExW    proto WINAPI,
    hModule:    HMODULE,
    lpszType:   LPCWSTR,
    lpEnumFunc: ENUMRESNAMEPROCW,
    lParam:     LONG_PTR,
    dwFlags:    dword,
    LangId:     LANGID
;ret BOOL
__AW <EnumResourceNamesEx>

EnumResTypeProcA_t  typedef proto CALLBACK,
    hModule:    HMODULE,
    lpszType:   LPSTR,
    lParam:     LONG_PTR
;ret BOOL
ENUMRESTYPEPROCA    typedef ptr EnumResTypeProcA_t
EnumResTypeProcW_t  typedef proto CALLBACK,
    hModule:    HMODULE,
    lpszType:   LPWSTR,
    lParam:     LONG_PTR
;ret BOOL
ENUMRESTYPEPROCW    typedef ptr EnumResTypeProcW_t
__AW <ENUMRESTYPEPROC>

EnumResourceTypesA  proto WINAPI,
    hModule:    HMODULE,
    lpEnumFunc: ENUMRESTYPEPROCA,
    lParam:     LONG_PTR
;ret BOOL
EnumResourceTypesW  proto WINAPI,
    hModule:    HMODULE,
    lpEnumFunc: ENUMRESTYPEPROCW,
    lParam:     LONG_PTR
;ret BOOL
__AW <EnumResourceTypes>

EnumResourceTypesExA    proto WINAPI,
    hModule:    HMODULE,
    lpEnumFunc: ENUMRESTYPEPROCA,
    lParam:     LONG_PTR,
    dwFlags:    dword,
    LangId:     LANGID
;ret BOOL
EnumResourceTypesExW    proto WINAPI,
    hModule:    HMODULE,
    lpEnumFunc: ENUMRESTYPEPROCW,
    lParam:     LONG_PTR,
    dwFlags:    dword,
    LangId:     LANGID
;ret BOOL
__AW <EnumResourceTypesEx>

FindResourceA   proto WINAPI,
    hModule:HMODULE,
    lpName: LPCSTR,
    lpType: LPCSTR
;ret HRSRC
FindResourceW   proto WINAPI,
    hModule:HMODULE,
    lpName: LPCWSTR,
    lpType: LPCWSTR
;ret HRSRC
__AW <FindResource>

FindResourceExA proto WINAPI,
    hModule:    HMODULE,
    lpType:     LPCSTR,
    lpName:     LPCSTR,
    wLanguage:  word
;ret HRSRC
FindResourceExW proto WINAPI,
    hModule:    HMODULE,
    lpType:     LPCWSTR,
    lpName:     LPCWSTR,
    wLanguage:  word
;ret HRSRC
__AW <FindResourceEx>

FreeResource    proto WINAPI,
    hglbResource:   HGLOBAL
;ret BOOL

LoadResource    proto WINAPI,
    hModule:    HMODULE,
    hResInfo:   HRSRC
;ret HGLOBAL

LockResource    proto WINAPI,
    hResData:   HGLOBAL
;ret LPVOID

SizeofResource  proto WINAPI,
    hModule:    HMODULE,
    hResInfo:   HRSRC
;ret dword

UpdateResourceA proto WINAPI,
    hUpdate:    HANDLE,
    lpType:     LPCSTR,
    lpName:     LPCSTR,
    wLanguage:  word,
    lpData:     LPVOID,
    cbData:     dword
;ret BOOL
UpdateResourceW proto WINAPI,
    hUpdate:    HANDLE,
    lpType:     LPCWSTR,
    lpName:     LPCWSTR,
    wLanguage:  word,
    lpData:     LPVOID,
    cbData:     dword
;ret BOOL
__AW <UpdateResource>

;Strings
;<http://msdn.microsoft.com/en-us/library/windows/desktop/ms646979.aspx>

lstrcatA    proto WINAPI,
    lpString1:  LPSTR,
    lpString2:  LPSTR
;ret LPSTR
lstrcatW    proto WINAPI,
    lpString1:  LPWSTR,
    lpString2:  LPWSTR
;ret LPWSTR
__AW <lstrcat>

lstrcmpA    proto WINAPI,
    lpString1:  LPCSTR,
    lpString2:  LPCSTR
;ret sdword
lstrcmpW    proto WINAPI,
    lpString1:  LPCWSTR,
    lpString2:  LPCWSTR
;ret sdword
__AW <lstrcmp>

lstrcmpiA   proto WINAPI,
    lpString1:  LPCSTR,
    lpString2:  LPCSTR
;ret sdword
lstrcmpiW   proto WINAPI,
    lpString1:  LPCWSTR,
    lpString2:  LPCWSTR
;ret sdword
__AW <lstrcmpi>

lstrcpyA    proto WINAPI,
    lpString1:  LPSTR,
    lpString2:  LPSTR
;ret LPSTR
lstrcpyW    proto WINAPI,
    lpString1:  LPWSTR,
    lpString2:  LPWSTR
;ret LPWSTR
__AW <lstrcpy>

lstrcpynA   proto WINAPI,
    lpString1:  LPSTR,
    lpString2:  LPCSTR,
    iMaxLength: sdword
;ret LPSTR
lstrcpynW   proto WINAPI,
    lpString1:  LPWSTR,
    lpString2:  LPCWSTR,
    iMaxLength: sdword
;ret LPWSTR
__AW <lstrcpyn>

lstrlenA    proto WINAPI,
    lpString:   LPCSTR
;ret sdword
lstrlenW    proto WINAPI,
    lpString:   LPCWSTR
;ret sdword
__AW <lstrlen>