NTAPI   equ stdcall

;Large Integers
;<https://msdn.microsoft.com/en-us/library/windows/desktop/aa383710.aspx>
LARGE_INTEGER   union       ;Represents a 64-bit signed integer value.
    struct
        LowPart     dword   ?   ;The low-order 32 bits.
        HighPart    LONG    ?   ;The high-order 32 bits.
    ends
    struct u
        LowPart     dword   ?   ;The low-order 32 bits.
        HighPart    LONG    ?   ;The high-order 32 bits.
    ends
    QuadPart    LONGLONG    ?   ;A signed 64-bit integer.
LARGE_INTEGER   ends
PLARGE_INTEGER  typedef ptr LARGE_INTEGER

ULARGE_INTEGER  union       ;Represents a 64-bit signed integer value.
    struct
        LowPart     dword   ?   ;The low-order 32 bits.
        HighPart    dword   ?   ;The high-order 32 bits.
    ends
    struct u
        LowPart     dword   ?   ;The low-order 32 bits.
        HighPart    dword   ?   ;The high-order 32 bits.
    ends
    QuadPart    ULONGLONG   ?   ;A signed 64-bit integer.
ULARGE_INTEGER  ends
PULARGE_INTEGER typedef ptr ULARGE_INTEGER

Multiply128     proto WINAPI,       ;Multiplies two 64-bit integers to produce a 128-bit integer.
    Multiplier:     LONG64,         ;The first integer.
    Multiplicand:   LONG64,         ;The second integer.
    HighProduct:    ptr LONG64      ;The high 64 bits of the product.
;ret LONG64                         ;The low 64 bits of the product.

MultiplyExtract128  proto WINAPI,   ;Multiplies two 64-bit integers to produce a 128-bit integer, shifts the product to the right by the specified number of bits, and returns the low 64 bits of the result.
    Multiplier:     LONG64,         ;The first integer.
    Multiplicand:   LONG64,         ;The second integer.
    Shift:          byte            ;The number of bits to shift.
;ret LONG64                         ;The low 64 bits of the result.

MultiplyHigh    proto WINAPI,       ;Multiplies two 64-bit integers to produce a 128-bit integer and gets the high 64 bits.
    Multiplier:     LONG64,         ;The first integer.
    Multiplicand:   LONG64          ;The second integer.
;ret LONGLONG                       ;The high 64 bits of the product.

PopulationCount64   proto WINAPI,   ;Counts the number of one bits (population count) in a 64-bit unsigned integer.
    operand:        DWORD64,        ;The operand.
;ret DWORD64                        ;The count of one bits.

ShiftLeft128    proto,              ;Shifts 128-bit left.
    LowPart:        DWORD64,        ;The low 64 bits. 
    HighPart:       DWORD64,        ;The high 64 bits.
    Shift:          byte            ;Bytes to shift.
;ret DWORD64                        ;The shifted bits.

ShiftRight128   proto,              ;Shifts 128-bit right.
    LowPart:        DWORD64,        ;The low 64 bits. 
    HighPart:       DWORD64,        ;The high 64 bits.
    Shift:          byte            ;Bytes to shift.
;ret DWORD64                        ;The shifted bits.

UnsignedMultiply128 proto WINAPI,   ;Multiplies two unsigned 64-bit integers to produce an unsigned 128-bit integer.
    Multiplier:     DWORD64,        ;The first integer.
    Multiplicand:   DWORD64,        ;The second integer.
    HighProduct:    ptr DWORD64     ;The high 64 bits of the product.
;ret DWORD64                        ;The low 64 bits of the product.

UnsignedMultiplyExtract128  proto,  ;Multiplies two unsigned 64-bit integers to produce an unsigned 128-bit integer, shifts the product to the right by the specified number of bits, and returns the low 64 bits of the result.
    Multiplier:     DWORD64,        ;The first integer.
    Multiplicand:   DWORD64,        ;The second integer.
    Shift:          byte            ;The number of bits to shift.
;ret DWORD64                        ;The low 64 bits of the result.

UnsignedMultiplyHigh    proto WINAPI,   ;Multiplies two 64-bit integers to produce a 128-bit integer and gets the high unsigned 64 bits.
    Multiplier:     DWORD64,            ;The first integer.
    Multiplicand:   DWORD64             ;The second integer.
;ret ULONGLONG                          ;The high 64 bits of the product.

ANYSIZE_ARRAY   equ 1

;Authorization
;<https://msdn.microsoft.com/en-us/library/windows/desktop/aa375769.aspx>
;Authorization is the right granted an individual to use the system and the data stored on it. Authorization is typically set up by a system administrator and verified by
;the computer based on some form of user identification, such as a code number or password. 

SID typedef byte    ;opaque struct
PSID    typedef ptr SID

SID_AND_ATTRIBUTES  struct
    Sid         PSID    ?
    Attributes  dword   ?
SID_AND_ATTRIBUTES  ends
PSID_AND_ATTRIBUTES typedef ptr SID_AND_ATTRIBUTES

TOKEN_GROUPS    struct
    GroupCount  dword               ?
    Groups      SID_AND_ATTRIBUTES  ANYSIZE_ARRAY dup({})
TOKEN_GROUPS    ends
PTOKEN_GROUPS   typedef ptr TOKEN_GROUPS

SE_GROUP_ENABLED            equ 00000004h
SE_GROUP_ENABLED_BY_DEFAULT equ 00000002h
SE_GROUP_INTEGRITY          equ 00000020h
SE_GROUP_INTEGRITY_ENABLED  equ 00000040h
SE_GROUP_LOGON_ID           equ 0c0000000h
SE_GROUP_MANDATORY          equ 00000001h
SE_GROUP_OWNER              equ 00000008h
SE_GROUP_RESOURCE           equ 20000000h
SE_GROUP_USE_FOR_DENY_ONLY  equ 00000010h

LUID    struct
    LowPart     dword   ?
    HighPart    LONG    ?
LUID    ends
PLUID   typedef ptr LUID

LUID_AND_ATTRIBUTES struct
    Luid        LUID    {}
    Attributes  dword   ?
LUID_AND_ATTRIBUTES ends
PLUID_AND_ATTRIBUTES    typedef ptr LUID_AND_ATTRIBUTES

TOKEN_PRIVILEGES    struct
    PrivilegeCount  dword               ?
    Privileges      LUID_AND_ATTRIBUTES ANYSIZE_ARRAY dup({})
TOKEN_PRIVILEGES    ends
PTOKEN_PRIVILEGES   typedef ptr TOKEN_PRIVILEGES

SE_PRIVILEGE_ENABLED            equ 00000002h
SE_PRIVILEGE_ENABLED_BY_DEFAULT equ 00000001h
SE_PRIVILEGE_REMOVED            equ 00000004h
SE_PRIVILEGE_USED_FOR_ACCESS    equ 00000008h

;Standard Access Rights
;Each type of securable object has a set of access rights that correspond to operations specific to that type of object. In addition to these object-specific access rights,
;there is a set of standard access rights that correspond to operations common to most types of securable objects.
;The access mask format includes a set of bits for the standard access rights.
DELETE                      equ 00010000h
READ_CONTROL                equ 00020000h
SYNCHRONIZE                 equ 00100000h
WRITE_DAC                   equ 00040000h
WRITE_OWNER                 equ 00080000h
STANDARD_RIGHTS_ALL         equ DELETE or READ_CONTROL or WRITE_DAC or WRITE_OWNER or SYNCHRONIZE
STANDARD_RIGHTS_EXECUTE     equ READ_CONTROL
STANDARD_RIGHTS_READ        equ READ_CONTROL
STANDARD_RIGHTS_REQUIRED    equ DELETE or READ_CONTROL or WRITE_DAC or WRITE_OWNER
STANDARD_RIGHTS_WRITE       equ READ_CONTROL

;Dynamic-Link Libraries
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms682589.aspx>
;A dynamic-link library (DLL) is a module that contains functions and data that can be used by another module (application or DLL).

DLL_DIRECTORY_COOKIE    typedef PVOID
PDLL_DIRECTORY_COOKIE   typedef ptr DLL_DIRECTORY_COOKIE

AddDllDirectory proto WINAPI,
    NewDirectory:   PCWSTR
;ret DLL_DIRECTORY_COOKIE

DLL_PROCESS_ATTACH  equ 1
DLL_PROCESS_DETACH  equ 0
DLL_THREAD_ATTACH   equ 2
DLL_THREAD_DETACH   equ 3

FreeLibrary proto WINAPI,
    hModule:    HMODULE
;ret BOOL

FreeLibraryAndExitThread    proto WINAPI,
    hModule:    HMODULE,
    dwExitCode: dword
;ret VOID

GetDllDirectoryA    proto WINAPI,
    nBufferLength:  dword,
    lpBuffer:       LPSTR
;ret dword

GetDllDirectoryW    proto WINAPI,
    nBufferLength:  dword,
    lpBuffer:       LPWSTR
;ret dword
__AW <GetDllDirectory>

GetModuleFileNameA  proto WINAPI,
    hModule:    HMODULE,
    lpFileName: LPSTR,
    nSize:      dword
;ret dword

GetModuleFileNameW  proto WINAPI,
    hModule:    HMODULE,
    lpFileName: LPWSTR,
    nSize:      dword
;ret dword
__AW <GetModuleFileName>

GetModuleHandleA    proto WINAPI,
    lpModuleName:   LPCSTR
;ret HMODULE

GetModuleHandleW    proto WINAPI,
    lpModuleName:   LPCWSTR
;ret HMODULE
__AW <GetModuleHandle>

GetModuleHandleExA  proto WINAPI,
    dwFlags:        dword,
    lpModuleName:   LPCSTR,
    phModule:       ptr HMODULE
;ret BOOL

GetModuleHandleExW  proto WINAPI,
    dwFlags:        dword,
    lpModuleName:   LPCWSTR,
    phModule:       ptr HMODULE
;ret BOOL
__AW <GetModuleHandleEx>

GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS          equ 00000004h
GET_MODULE_HANDLE_EX_FLAG_PIN                   equ 00000001h
GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT    equ 00000002h

FARPROC_T   typedef proto WINAPI
FARPROC     typedef ptr FARPROC_T

GetProcAddress  proto WINAPI,
    hModule:    HMODULE,
    lpProcName: LPCSTR
;ret FARPROC

LoadLibraryA    proto WINAPI,
    lpFileName: LPCSTR
;ret HMODULE

LoadLibraryW    proto WINAPI,
    lpFileName: LPCWSTR
;ret HMODULE
__AW <LoadLibrary>

LoadLibraryExA  proto WINAPI,
    lpFileName: LPCSTR,
    hFile:      HANDLE,
    dwFlags:    dword
;ret HMODULE

LoadLibraryExW  proto WINAPI,
    lpFileName: LPCWSTR,
    hFile:      HANDLE,
    dwFlags:    dword
;ret HMODULE
__AW <LoadLibraryEx>

DONT_RESOLVE_DLL_REFERENCE          equ 00000001h
LOAD_IGNORE_CODE_AUTHZ_LEVEL        equ 00000010h
LOAD_LIBRARY_AS_DATAFILE            equ 00000002h
LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE  equ 00000040h
LOAD_LIBRARY_AS_IMAGE_RESOURCE      equ 00000020h
LOAD_LIBRARY_SEARCH_APPLICATION_DIR equ 00000200h
LOAD_LIBRARY_SEARCH_DEFAULT_DIRS    equ 00001000h
LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR    equ 00000100h
LOAD_LIBRARY_SEARCH_SYSTEM32        equ 00000800h
LOAD_LIBRARY_SEARCH_USER_DIRS       equ 00000400h
LOAD_WITH_ALTERED_SEARCH_PATH       equ 00000008h

LOADPARMS32 struct
    lpEnvAddress    LPSTR   ?
    lpCmdLine       LPSTR   ?
    lpCmdShow       LPSTR   ?
    dwReserved      dword   ?
LOADPARMS32 ends

LoadModule  proto WINAPI,
    lpModuleName:       LPCSTR,
    lpParameterBlock:   LPVOID
;ret dword

ERROR_BAD_FORMAT        equ 11
ERROR_FILE_NOT_FOUND    equ 2
ERROR_PATH_NOT_FOUND    equ 3

LoadPackagedLibrary proto WINAPI,
    lpwLibFileName: LPCWSTR,
    Reserved:       dword
;ret HMODULE

RemoveDllDirectory  proto WINAPI,
    Cookie: DLL_DIRECTORY_COOKIE
;ret BOOL

SetDefaultDllDirectories    proto WINAPI,
    DirectoryFlags: dword
;ret BOOL

SetDllDirectoryA    proto WINAPI,
    lpPathName: LPCSTR
;ret BOOL

SetDllDirectoryW    proto WINAPI,
    lpPathName: LPCWSTR
;ret BOOL
__AW <SetDllDirectory>

;Memory Management
;<https://msdn.microsoft.com/en-us/library/windows/desktop/aa366779.aspx>
;The memory manager implements virtual memory, provides a core set of services such as memory mapped files, copy-on-write memory, large memory support, and underlying
;support for the cache manager.

PAGE_EXECUTE            equ 10h
PAGE_EXECUTE_READ       equ 20h
PAGE_EXECUTE_READWRITE  equ 40h
PAGE_EXECUTE_WRITECOPY  equ 80h
PAGE_NOACCESS           equ 01h
PAGE_READONLY           equ 02h
PAGE_READWRITE          equ 04h
PAGE_WRITECOPY          equ 08h
PAGE_TARGETS_INVALID    equ 40000000h
PAGE_TARGETS_NO_UPDATE  equ 40000000h
PAGE_GUARD              equ 100h
PAGE_NOCACHE            equ 200h
PAGE_WRITECOMBINE       equ 400h

HeapCompatibilityInformation        equ 0
HeapEnableTerminationOnCorruption   equ 1
HEAP_INFORMATION_CLASS  typedef dword

;TODO: enclave API constants are documented on MSDN but without their values

ENCLAVE_CREATE_INFO_SGX struct
    Secs    UCHAR   4096 dup(?)
ENCLAVE_CREATE_INFO_SGX ends
PENCLAVE_CREATE_INFO_SGX    typedef ptr ENCLAVE_CREATE_INFO_SGX

ENCLAVE_INIT_INFO_SGX   struct
    SigStruct   UCHAR   1808 dup(?)
    Reserved1   UCHAR   240 dup(?)
    EInitToken  UCHAR   304 dup(?)
    Reserved2   UCHAR   744 dup(?)
ENCLAVE_INIT_INFO_SGX   ends
PENCLAVE_INIT_INFO_SGX  typedef ptr ENCLAVE_INIT_INFO_SGX

MEMORY_BASIC_INFORMATION    struct
    BaseAddress         PVOID   ?
    AllocationBase      PVOID   ?
    AllocationProtect   dword   ?
    RegionSize          SIZE_T  ?
    State               dword   ?
    Protect             dword   ?
    _Type               dword   ?
MEMORY_BASIC_INFORMATION    ends
PMEMORY_BASIC_INFORMATION   typedef ptr MEMORY_BASIC_INFORMATION

MEM_COMMIT  equ 00001000h
MEM_FREE    equ 00010000h
MEM_RESERVE equ 00002000h
MEM_IMAGE   equ 10000000h
MEM_MAPPED  equ 00040000h
MEM_PRIVATE equ 00020000h

STANDARD_RIGHTS_REQUIRED        equ 000f0000h
SECTION_QUERY                   equ 0001h
SECTION_MAP_WRITE               equ 0002h
SECTION_MAP_READ                equ 0004h
SECTION_MAP_EXECUTE             equ 0008h
SECTION_EXTEND_SIZE             equ 0010h
SECTION_MAP_EXECUTE_EXPLICIT    equ 0020h
SECTION_ALL_ACCESS              equ STANDARD_RIGHTS_REQUIRED or SECTION_QUERY or SECTION_MAP_WRITE or SECTION_MAP_READ or SECTION_MAP_EXECUTE or SECTION_EXTEND_SIZE

;Synchronization
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms686353.aspx>
RTL_CRITICAL_SECTION    struct
    LockCount       LONG        ?
    RecursionCount  LONG        ?
    OwningThread    HANDLE      ?
    LockSemaphore   HANDLE      ?
    SpinCount       ULONG_PTR   ?
RTL_CRITICAL_SECTION    ends
PRTL_CRITICAL_SECTION   typedef ptr RTL_CRITICAL_SECTION

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

CpuSetInformation   equ 0
CPU_SET_INFORMATION_TYPE    typedef dword

RelationProcessorCore       equ 0
RelationNumaNode            equ 1
RelationCache               equ 2
RelationProcessorPackage    equ 3
RelationGroup               equ 4
RelationAll                 equ 0ffffh
LOGICAL_PROCESSOR_RELATIONSHIP  typedef dword

JOB_OBJECT_NET_RATE_CONTROL_ENABLE          equ 1h
JOB_OBJECT_NET_RATE_CONTROL_MAX_BANDWIDTH   equ 2h
JOB_OBJECT_NET_RATE_CONTROL_DSCP_TAG        equ 4h
JOB_OBJECT_NET_RATE_CONTROL_VALID_FLAGS     equ 7h
JOB_OBJECT_NET_RATE_CONTROL_FLAGS   typedef dword

ProcessDEPPolicy                    equ 0
ProcessASLRPolicy                   equ 1
ProcessReserved1MitigationPolicy    equ 2
ProcessStructHandleCheckPolicy      equ 3
ProcessSystemCallDisablePolicy      equ 4
MaxProcessMitigationPolicy          equ 5
PROCESS_MITIGATION_POLICY   typedef dword
PPROCESS_MITIGATION_POLICY  typedef ptr PROCESS_MITIGATION_POLICY

CacheUnified        equ 0
CacheInstruction    equ 1
CacheData           equ 2
CacheTrace          equ 3
PROCESSOR_CACHE_TYPE    typedef dword

UmsThreadInvalidInfoClass   equ 0
UmsThreadUserContext        equ 1
UmsThreadPriority           equ 2
UmsThreadAffinity           equ 3
UmsThreadTeb                equ 4
UmsThreadIsSuspended        equ 5
UmsThreadIsTerminated       equ 6
UmsThreadMaxInfoClass       equ 7
UMS_THREAD_INFO_CLASS   typedef dword
PUMS_THREAD_INFO_CLASS  typedef ptr UMS_THREAD_INFO_CLASS

;Process and Thread Structures
CACHE_DESCRIPTOR    struct
    Level           byte                    ?
    Associativity   byte                    ?
    LineSize        word                    ?
    _Size           dword                   ?
    _Type           PROCESSOR_CACHE_TYPE    ?
CACHE_DESCRIPTOR    ends
PCACHE_DESCRIPTOR   typedef ptr CACHE_DESCRIPTOR

IO_COUNTERS struct
    ReadOperationCount  ULONGLONG   ?
    WriteOperationCount ULONGLONG   ?
    OtherOperationCount ULONGLONG   ?
    ReadTransferCount   ULONGLONG   ?
    WriteTransferCount  ULONGLONG   ?
    OtherTransferCount  ULONGLONG   ?
IO_COUNTERS ends
PIO_COUNTERS    typedef ptr IO_COUNTERS

_rec_PROCESS_MITIGATION_ASLR_POLICY record \
    PROCESS_MITIGATION_ASLR_POLICY_EnableBottomUpRandomization:1,
    PROCESS_MITIGATION_ASLR_POLICY_EnableForceReolcateImages:  1,
    PROCESS_MITIGATION_ASLR_POLICY_EnableHighEntropy:          1,
    PROCESS_MITIGATION_ASLR_POLICY_DisallowStrippedImages:     1,
    PROCESS_MITIGATION_ASLR_POLICY_ReservedFlags:              28
PROCESS_MITIGATION_ASLR_POLICY  union
    Flags   dword                               ?
    rec     _rec_PROCESS_MITIGATION_ASLR_POLICY {}
PROCESS_MITIGATION_ASLR_POLICY  ends
PPROCESS_MITIGATION_ASLR_POLICY typedef ptr PROCESS_MITIGATION_ASLR_POLICY

_rec_PROC_MITIG_CFGUARD_POL   record \
    PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY_EnableControlFlowGuard: 1,
    PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY_ReservedFlags:          31
PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY    union
    Flags   dword                       ?
    rec     _rec_PROC_MITIG_CFGUARD_POL {}
PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY    ends
PPROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY   typedef ptr PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY

_rec_PROCESS_MITIGATION_DEP_POLICY  record \
    PROCESS_MITIGATION_DEP_POLICY_Enable:                     1,
    PROCESS_MITIGATION_DEP_POLICY_DisableAtlThunkEmulation:   1,
    PROCESS_MITIGATION_DEP_POLICY_ReservedFlags:              30
PROCESS_MITIGATION_DEP_POLICY   struct
    union
        Flags   dword                               ?
        rec     _rec_PROCESS_MITIGATION_DEP_POLICY  {}
    ends
    Permanent   BOOLEAN ?
PROCESS_MITIGATION_DEP_POLICY   ends
PPROCESS_MITIGATION_DEP_POLICY  typedef ptr PROCESS_MITIGATION_DEP_POLICY

_rec_PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY  record \
    PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY_DisableExtensionPoints: 1,
    PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY_ReservedFlags:          31
PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY   union
    Flags   dword                                                   ?
    rec     _rec_PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY  {}
PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY   ends
PPROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY  typedef ptr PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY

_rec_PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY  record \
    PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY_RaiseExceptionOnInvalidHandleReference: 1,
    PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY_HandleExceptionsPermanentlyEnabled:     1,
    PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY_ReservedFlags:                          30
PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY   union
    Flags   dword                                               ?
    rec     _rec_PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY  {}
PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY   ends
PPROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY  typedef ptr PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY

_rec_PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY  record \
    PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY_DisallowWin32kSystemCalls:  1,
    PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY_ReservedFlags:              31
PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY   union
    Flags   dword                                               ?
    rec     _rec_PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY  {}
PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY   ends
PPROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY  typedef ptr PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY

;Processor Structures
KAFFINITY   typedef ULONG_PTR   ;from <Basetsd.h> in NT DDK
GROUP_AFFINITY  struct
    _Mask       KAFFINITY   ?
    _Group      word        ?
    Reserved    word        3 dup(?)
GROUP_AFFINITY  ends
PGROUP_AFFINITY typedef ptr GROUP_AFFINITY

CACHE_RELATIONSHIP  struct
    Level           byte                    ?
    Associativity   byte                    ?
    LineSize        word                    ?
    CacheSize       dword                   ?
    _Type           PROCESSOR_CACHE_TYPE    ?
    Reserved        byte                    20 dup (?)
    GroupMask       GROUP_AFFINITY          {}
CACHE_RELATIONSHIP  ends

PROCESSOR_NUMBER    struct
    _Group      word    ?
    Number      byte    ?
    Reserved    byte    ?
PROCESSOR_NUMBER    ends
PPROCESSOR_NUMBER   typedef ptr PROCESSOR_NUMBER

PROCESSOR_GROUP_INFO    struct
    MaximumProcessorCount   byte        ?
    ActiveProcessorCount    byte        ?
    Reserved                byte        38 dup(?)
    ActiveProcessorMask     KAFFINITY   ?
PROCESSOR_GROUP_INFO    ends
PPROCESSOR_GROUP_INFO   typedef ptr PROCESSOR_GROUP_INFO

PROCESSOR_RELATIONSHIP  struct
    Flags           byte            ?
    EfficiencyClass byte            ?
    Reserved        byte            21 dup(?)
    GroupCount      word            ?
    GroupMask       GROUP_AFFINITY  ANYSIZE_ARRAY dup({})
PROCESSOR_RELATIONSHIP  ends
PPROCESSOR_RELATIONSHIP typedef ptr PROCESSOR_RELATIONSHIP

GROUP_RELATIONSHIP  struct
    MaximumGroupCount   word                    ?
    ActiveGroupCount    word                    ?
    Reserved            byte                    20 dup (?)
    GroupInfo           PROCESSOR_GROUP_INFO    ANYSIZE_ARRAY dup ({})
GROUP_RELATIONSHIP  ends
PGROUP_RELATIONSHIP typedef ptr GROUP_RELATIONSHIP

NUMA_NODE_RELATIONSHIP  struct
    NodeNumber  dword           ?
    Reserved    byte            20 dup(?)
    GroupMask   GROUP_AFFINITY  {}
NUMA_NODE_RELATIONSHIP  ends
PNUMA_NODE_RELATIONSHIP typedef ptr NUMA_NODE_RELATIONSHIP

SYSTEM_LOGICAL_PROCESSOR_INFORMATION    struct
    ProcessorMask   ULONG_PTR                       ?
    Relationship    LOGICAL_PROCESSOR_RELATIONSHIP  ?
    union
        struct ProcessorCore
            Flags       byte    ?
        ends
        struct NumaNode
            NodeNumber  dword   ?
        ends
        Cache       CACHE_DESCRIPTOR    {}
        Reserved    ULONGLONG           2 dup(?)
    ends
SYSTEM_LOGICAL_PROCESSOR_INFORMATION    ends
PSYSTEM_LOGICAL_PROCESSOR_INFORMATION   typedef ptr SYSTEM_LOGICAL_PROCESSOR_INFORMATION

SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX struct
    Relationship    LOGICAL_PROCESSOR_RELATIONSHIP  ?
    _Size           dword                           ?
    union
        Processor   PROCESSOR_RELATIONSHIP  {}
        NumaNode    NUMA_NODE_RELATIONSHIP  {}
        Cache       CACHE_RELATIONSHIP      {}
        _Group      GROUP_RELATIONSHIP      {}
    ends
SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX ends
PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX    typedef ptr SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX

SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION struct
    CycleTime   DWORD64 ?
SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION ends
PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION    typedef ptr SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION

;Job Object Structures
JOBOBJECT_ASSOCIATE_COMPLETION_PORT struct
    CompletionKey   PVOID   ?
    CompletionPort  HANDLE  ?
JOBOBJECT_ASSOCIATE_COMPLETION_PORT ends
PJOBOBJECT_ASSOCIATE_COMPLETION_PORT    typedef ptr JOBOBJECT_ASSOCIATE_COMPLETION_PORT

JOBOBJECT_BASIC_ACCOUNTING_INFORMATION  struct
    TotalUserTime               LARGE_INTEGER   {}
    TotalKernelTime             LARGE_INTEGER   {}
    ThisPeriodTotalUserTime     LARGE_INTEGER   {}
    ThisPeriodTotalKernelTime   LARGE_INTEGER   {}
    TotalPageFaultCount         dword           ?
    TotalProcesses              dword           ?
    ActiveProcesses             dword           ?
    TotalTerminatedProcesses    dword           ?
JOBOBJECT_BASIC_ACCOUNTING_INFORMATION  ends
PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION typedef ptr JOBOBJECT_BASIC_ACCOUNTING_INFORMATION

JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION   struct
    BasicInfo   JOBOBJECT_BASIC_ACCOUNTING_INFORMATION  {}
    IoInfo      IO_COUNTERS                             {}
JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION   ends
PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION  typedef ptr JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION

JOBOBJECT_BASIC_LIMIT_INFORMATION   struct
    PerProcessUserTimeLimit LARGE_INTEGER   {}
    PerJobUserTimeLimit     LARGE_INTEGER   {}
    LimitFlags              dword           ?
    MinimumWorkingSetSize   SIZE_T          ?
    MaximumWorkingSetSize   SIZE_T          ?
    ActiveProcessLimit      dword           ?
    Affinity                ULONG_PTR       ?
    PriorityClass           dword           ?
    SchedulingClass         dword           ?
JOBOBJECT_BASIC_LIMIT_INFORMATION   ends
PJOBOBJECT_BASIC_LIMIT_INFORMATION  typedef ptr JOBOBJECT_BASIC_LIMIT_INFORMATION

JOB_OBJECT_LIMIT_ACTIVE_PROCESS             equ 00000008h
JOB_OBJECT_LIMIT_AFFINITY                   equ 00000010h
JOB_OBJECT_LIMIT_BREAKAWAY_OK               equ 00000800h
JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION equ 00000400h
JOB_OBJECT_LIMIT_JOB_MEMORY                 equ 00000200h
JOB_OBJECT_LIMIT_JOB_TIME                   equ 00000004h
JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE          equ 00002000h
JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME          equ 00000040h
JOB_OBJECT_LIMIT_PRIORITY_CLASS             equ 00000020h
JOB_OBJECT_LIMIT_PROCESS_MEMORY             equ 00000100h
JOB_OBJECT_LIMIT_PROCESS_TIME               equ 00000002h
JOB_OBJECT_LIMIT_SCHEDULING_CLASS           equ 00000080h
JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK        equ 00001000h
JOB_OBJECT_LIMIT_SUBSET_AFFINITY            equ 00004000h
JOB_OBJECT_LIMIT_WORKINGSET                 equ 00000001h

JOBOBJECT_BASIC_PROCESS_ID_LIST struct
    NumberOfAssignedProcesses   dword       ?
    NumberOfProcessIdsInList    dword       ?
    ProcessIdList               ULONG_PTR   1 dup(?)
JOBOBJECT_BASIC_PROCESS_ID_LIST ends
PJOBOBJECT_BASIC_PROCESS_ID_LIST    typedef ptr JOBOBJECT_BASIC_PROCESS_ID_LIST

JOBOBJECT_BASIC_UI_RESTRICTIONS struct
    UIRestrictionsClass dword   ?
JOBOBJECT_BASIC_UI_RESTRICTIONS ends
PJOBOBJECT_BASIC_UI_RESTRICTIONS    typedef ptr JOBOBJECT_BASIC_UI_RESTRICTIONS

JOB_OBJECT_UILIMIT_DESKTOP          equ 00000040h
JOB_OBJECT_UILIMIT_DISPLAYSETTINGS  equ 00000010h
JOB_OBJECT_UILIMIT_EXITWINDOWS      equ 00000080h
JOB_OBJECT_UILIMIT_GLOBALATOMS      equ 00000020h
JOB_OBJECT_UILIMIT_HANDLES          equ 00000001h
JOB_OBJECT_UILIMIT_READCLIPBOARD    equ 00000002h
JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS equ 00000008h
JOB_OBJECT_UILIMIT_WRITECLIPBOARD   equ 00000004h

JOBOBJECT_END_OF_JOB_TIME_INFORMATION   struct
    EndOfJobTimeAction  dword   ?
JOBOBJECT_END_OF_JOB_TIME_INFORMATION   ends
PJOBOBJECT_END_OF_JOB_TIME_INFORMATION  typedef ptr JOBOBJECT_END_OF_JOB_TIME_INFORMATION

JOB_OBJECT_TERMINATE_AT_END_OF_JOB  equ 0
JOB_OBJECT_POST_AT_END_OF_JOB       equ 1

JOBOBJECT_EXTENDED_LIMIT_INFORMATION    struct
    BasicLimitInformation   JOBOBJECT_BASIC_LIMIT_INFORMATION   {}
    IoInfo                  IO_COUNTERS                         {}
    ProcessMemoryLimit      SIZE_T                              ?
    JobMemoryLimit          SIZE_T                              ?
    PeakProcessMemoryUsed   SIZE_T                              ?
    PeakJobMemoryUsed       SIZE_T                              ?
JOBOBJECT_EXTENDED_LIMIT_INFORMATION    ends
PJOBOBJECT_EXTENDED_LIMIT_INFORMATION   typedef ptr JOBOBJECT_EXTENDED_LIMIT_INFORMATION

JOBOBJECT_SECURITY_LIMIT_INFORMATION    struct
    SecurityLimitFlags  dword               ?
    JobToken            HANDLE              ?
    SidstoDisable       PTOKEN_GROUPS       ?
    PrivilegesToDelete  PTOKEN_PRIVILEGES   ?
    RestrictedSids      PTOKEN_GROUPS       ?
JOBOBJECT_SECURITY_LIMIT_INFORMATION    ends
PJOBOBJECT_SECURITY_LIMIT_INFORMATION   typedef ptr JOBOBJECT_SECURITY_LIMIT_INFORMATION

JOB_OBJECT_SECURITY_FILTER_TOKENS       equ 00000008h
JOB_OBJECT_SECURITY_SECURITY_NO_ADMIN   equ 00000001h
JOB_OBJECT_SECURITY_ONLY_TOKEN          equ 00000004h
JOB_OBJECT_SECURITY_RESTRICTED_TOKEN    equ 00000002h

JOBOBJECT_CPU_RATE_CONTROL_INFORMATION  struct
    ControlFlags    dword   ?
    union
        CpuRate dword   ?
        Weight  dword   ?
        struct
            MinRate word    ?
            MaxRate word    ?
        ends
    ends
JOBOBJECT_CPU_RATE_CONTROL_INFORMATION  ends
PJOBOBJECT_CPU_RATE_CONTROL_INFORMATION typedef ptr JOBOBJECT_CPU_RATE_CONTROL_INFORMATION

JOB_OBJECT_CPU_RATE_CONTROL_ENABLE          equ 1h
JOB_OBJECT_CPU_RATE_CONTROL_WEIGHT_BASED    equ 2h
JOB_OBJECT_CPU_RATE_CONTROL_HARD_CAP        equ 4h
JOB_OBJECT_CPU_RATE_CONTROL_NOTIFY          equ 8h
JOB_OBJECT_CPU_RATE_CONTROL_MIN_MAX_RATE    equ 10h

ToleranceLow    equ 1
ToleranceMedium equ 2
ToleranceHigh   equ 3
JOBOBJECT_RATE_CONTROL_TOLERANCE    typedef dword
ToleranceIntervalShort  equ 1
ToleranceIntervalMedium equ 2
ToleranceIntervalLong   equ 3
JOBOBJECT_RATE_CONTROL_TOLERANCE_INTERVAL   typedef dword

JOBOBJECT_LIMIT_VIOLATION_INFORMATION   struct
    LimitFlags                  dword                               ?
    ViolationLimitFlags         dword                               ?
    IoReadBytes                 DWORD64                             ?
    IoReadBytesLimit            DWORD64                             ?
    IoWriteBytes                DWORD64                             ?
    IoWriteBytesLimit           DWORD64                             ?
    PerJobUserTime              LARGE_INTEGER                       {}
    PerJobUserTimeLimit         LARGE_INTEGER                       {}
    JobMemory                   DWORD64                             ?
    JobMemoryLimit              DWORD64                             ?
    RateControlTolerance        JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
    RateControlToleranceLimit   JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
JOBOBJECT_LIMIT_VIOLATION_INFORMATION   ends
PJOBOBJECT_LIMIT_VIOLATION_INFORMATION  typedef ptr JOBOBJECT_LIMIT_VIOLATION_INFORMATION

JOB_OBJECT_LIMIT_JOB_MEMORY         equ 00000200h
JOB_OBJECT_LIMIT_JOB_READ_BYTES     equ 00010000h
JOB_OBJECT_LIMIT_JOB_TIME           equ 00000004h
JOB_OBJECT_LIMIT_JOB_WRITE_BYTES    equ 00020000h
JOB_OBJECT_LIMIT_RATE_CONTROL       equ 00040000h
JOB_OBJECT_LIMIT_JOB_MEMORY_HIGH    equ 00000200h
JOB_OBJECT_LIMIT_JOB_MEMORY_LOW     equ 00008000h
JOB_OBJECT_LIMIT_JOB_READ_BYTES     equ 00010000h
JOB_OBJECT_LIMIT_JOB_WRITE_BYTES    equ 00020000h
JOB_OBJECT_LIMIT_JOB_TIME           equ 00000004h
JOB_OBJECT_LIMIT_RATE_CONTROL       equ 00040000h
JOB_OBJECT_LIMIT_CPU_RATE_CONTROL   equ 00040000h
JOB_OBJECT_LIMIT_IO_RATE_CONTROL    equ 00080000h
JOB_OBJECT_LIMIT_NET_RATE_CONTROL   equ 00100000h

JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2 struct
    LimitFlags                      dword           ?
    ViolationLimitFlags             dword           ?
    IoReadBytes                     DWORD64         ?
    IoReadBytesLimit                DWORD64         ?
    IoWriteBytes                    DWORD64         ?
    IoWriteBytesLimit               DWORD64         ?
    PerJobUserTime                  LARGE_INTEGER   {}
    PerJobUserTimeLimit             LARGE_INTEGER   {}
    JobMemory                       DWORD64         ?
    union
        JobHighMemoryLimit  DWORD64 ?
        JobMemoryLimit      DWORD64 ?
    ends
    union
        RateControlTolerance    JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
        CpuRateControlTolerance JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
    ends
    union
        RateControlToleranceLimit       JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
        CpuRateControlTileranceLimit    JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
    ends
    JobLowMemoryLimit               DWORD64                             ?
    IoRateControlTolerance          JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
    IoRateControlToleranceLimit     JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
    NetRateControlTolerance         JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
    NetRateControlToleranceLimit    JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2 ends

JOBOBJECT_NET_RATE_CONTROL_INFORMATION  struct
    MaxBandwidth    DWORD64                             ?
    ControlFlags    JOB_OBJECT_NET_RATE_CONTROL_FLAGS   ?
    DscpTag         byte                                ?
JOBOBJECT_NET_RATE_CONTROL_INFORMATION  ends

JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION    struct
    IoReadBytesLimit                DWORD64                                     ?
    IoWriteBytesLimit               DWORD64                                     ?
    PerJobUserTimeLimit             LARGE_INTEGER                               {}
    JobMemoryLimit                  DWORD64                                     ?
    RateControlTolerance            JOBOBJECT_RATE_CONTROL_TOLERANCE            ?
    RateControlToleranceInterval    JOBOBJECT_RATE_CONTROL_TOLERANCE_INTERVAL   ?
    LimitFlags                      dword                                       ?
JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION    ends
PJOBOBJECT_NOTIFICATION_LIMIT_INFORMATION   typedef ptr JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION

JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION_2  struct
    IoReadBytesLimit                DWORD64                                     ?
    IoWriteBytesLimit               DWORD64                                     ?
    PerJobUserTimeLimit             LARGE_INTEGER                               {}
    union                                                                       
        JobHighMemoryLimit  DWORD64 ?
        JobMemoryLimit      DWORD64 ?
    ends                                                                        
    union                                                                       
        RateControlTolerance    JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
        CpuRateControlTolerance JOBOBJECT_RATE_CONTROL_TOLERANCE    ?
    ends                                                                        
    union                                                                       
        RateControlToleranceInterval    JOBOBJECT_RATE_CONTROL_TOLERANCE_INTERVAL   ?
        CpuRateControlToleranceInterval JOBOBJECT_RATE_CONTROL_TOLERANCE_INTERVAL   ?
    ends                                                                        
    LimitFlags                      dword                                       ?
    IoRateControlTolerance          JOBOBJECT_RATE_CONTROL_TOLERANCE            ?
    JobLowMemoryLimit               DWORD64                                     ?
    IoRateControlToleranceInterval  JOBOBJECT_RATE_CONTROL_TOLERANCE_INTERVAL   ?
    NetRateControlTolerance         JOBOBJECT_RATE_CONTROL_TOLERANCE            ?
    NetRateControlToleranceInterval JOBOBJECT_RATE_CONTROL_TOLERANCE_INTERVAL   ?
JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION_2  ends

;Thread Pool Structures
TP_POOL typedef byte    ;opaque struct
PTP_POOL    typedef ptr TP_POOL

TP_CALLBACK_INSTANCE    typedef byte    ;opaque struct
PTP_CALLBACK_INSTANCE   typedef ptr TP_CALLBACK_INSTANCE

TP_IO   typedef byte    ;opaque struct
PTP_IO  typedef ptr TP_IO

TP_CLEANUP_GROUP    typedef byte    ;opaque struct
PTP_CLEANUP_GROUP   typedef ptr TP_CLEANUP_GROUP

TP_TIMER    typedef byte    ;opaque struct
PTP_TIMER   typedef ptr TP_TIMER

TP_WAIT typedef byte    ;opaque struct
PTP_WAIT    typedef ptr TP_WAIT

TP_WORK typedef byte    ;opaque struct
PTP_WORK    typedef ptr TP_WORK

TP_POOL_STACK_INFORMATION   struct
    StackReserve    SIZE_T  ?
    StackCommit     SIZE_T  ?
TP_POOL_STACK_INFORMATION    ends
PTP_POOL_STACK_INFORMATION  typedef ptr TP_POOL_STACK_INFORMATION

TP_VERSION  typedef dword
PTP_VERSION typedef ptr TP_VERSION

_ACTIVATION_CONTEXT typedef byte    ;opaque struct
_PACTIVATION_CONTEXT    typedef ptr _ACTIVATION_CONTEXT

CleanupGroupCancelCallback_t    typedef proto NTAPI,
    ObjectContext:  PVOID,
    CleanupContext: PVOID
;ret VOID
PTP_CLEANUP_GROUP_CANCEL_CALLBACK   typedef ptr CleanupGroupCancelCallback_t

SimpleCallback_t    typedef proto NTAPI,
    Instance:   PTP_CALLBACK_INSTANCE,
    Context:    PVOID
;ret VOID
PTP_SIMPLE_CALLBACK typedef ptr SimpleCallback_t

TP_CALLBACK_PRIORITY_HIGH       equ 0
TP_CALLBACK_PRIORITY_NORMAL     equ 1
TP_CALLBACK_PRIORITY_LOW        equ 2
TP_CALLBACK_PRIORITY_INVALID    equ 3
TP_CALLBACK_PRIORITY    typedef dword

_rec_TP_CALLBACK_ENVIRON_u record \
    TP_CALLBACK_ENVIRON_LongFunction:   1,
    TP_CALLBACK_ENVIRON_Persistent:     1,
    TP_CALLBACK_ENVIRON_Private:        30
TP_CALLBACK_ENVIRON struct
    Version                     TP_VERSION                          ?
    Pool                        PTP_POOL                            ?
    CleanupGroup                PTP_CLEANUP_GROUP                   ?
    CleanupGroupCancelCallback  PTP_CLEANUP_GROUP_CANCEL_CALLBACK   ?
    RaceDll                     PVOID                               ?
    ActivationContext           _PACTIVATION_CONTEXT                ?
    FinalizationCallback        PTP_SIMPLE_CALLBACK                 ?
    union u                                                         
        Flags   dword                                               ?
        s       _rec_TP_CALLBACK_ENVIRON_u                          {}
    ends                                                            
    CallbackPriority            TP_CALLBACK_PRIORITY                ?
    _Size                       dword                               ?
TP_CALLBACK_ENVIRON ends
PTP_CALLBACK_ENVIRON    typedef ptr TP_CALLBACK_ENVIRON

;User-Mode Scheduling Structures
UMS_CREATE_THREAD_ATTRIBUTES    struct
    UmsVersion          dword   ?
    UmsContext          PVOID   ?
    UmsCompletionList   PVOID   ?
UMS_CREATE_THREAD_ATTRIBUTES    ends
PUMS_CREATE_THREAD_ATTRIBUTES   typedef ptr UMS_CREATE_THREAD_ATTRIBUTES

;Process Security and Access Rights
PROCESS_CREATE_PROCESS              equ 0080h
PROCESS_CREATE_THREAD               equ 0002h
PROCESS_DUP_HANDLE                  equ 0040h
PROCESS_QUERY_INFORMATION           equ 0400h
PROCESS_QUERY_LIMITED_INFORMATION   equ 1000h
PROCESS_SET_INFORMATION             equ 0200h
PROCESS_SET_QUOTA                   equ 0100h
PROCESS_SUSPEND_RESUME              equ 0800h
PROCESS_TERMINATE                   equ 0001h
PROCESS_VM_OPERATION                equ 0008h
PROCESS_VM_READ                     equ 0010h
PROCESS_VM_WRITE                    equ 0020h
PROCESS_ALL_ACCESS                  equ STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 0fffh

ALL_PROCESSOR_GROUPS    equ 0ffffh

;Obsolete Functions
NtGetCurrentProcessorNumber proto WINAPI    ;ret ULONG

ProcessBasicInformation     equ 0
ProcessDebugPort            equ 7
ProcessWow64Information     equ 26
ProcessImageFileName        equ 27
ProcessBreakOnTermination   equ 29
PROCESSINFOCLASS    typedef dword
NtQueryInformationProcess   proto WINAPI,
    ProcessHandle:              HANDLE,
    ProcessInformationClass:    PROCESSINFOCLASS,
    ProcessInformation:         PVOID,
    ProcessInformationLength:   ULONG,
    ReturnLength:               PULONG
;ret NTSTATUS

ThreadIsIoPending   equ 16
THREADINFOCLASS typedef dword
NtQueryInformationThread    proto WINAPI,
    ThreadHandle:               HANDLE,
    ThreadInformationClasss:    THREADINFOCLASS,
    ThreadInformation:          PVOID,
    ThreadInformationLength:    ULONG,
    ReturnLength:               PULONG
;ret NTSTATUS

WinExec proto WINAPI,
    lpCmdLine:  LPCSTR,
    uCmdShow:   UINT
;ret UINT

ZwQueryInformationProcess   proto WINAPI,
    ProcessHandle:              HANDLE,
    ProcessInformationClass:    PROCESSINFOCLASS,
    ProcessInformation:         PVOID,
    ProcessInformationLength:   ULONG,
    ReturnLength:               PULONG
;ret NTSTATUS

;Structured Exception Handling
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms680657.aspx>
;An exception is an event that occurs during the execution of a program, and requires the execution of code outside the normal flow of control. There are two kinds of
;exceptions: hardware exceptions and software exceptions. Hardware exceptions are initiated by the CPU. They can result from the execution of certain instruction sequences,
;such as division by zero or an attempt to access an invalid memory address. Software exceptions are initiated explicitly by applications or the operating system. For
;example, the system can detect when an invalid parameter value is specified.
;Structured exception handling is a mechanism for handling both hardware and software exceptions. Therefore, your code will handle hardware and software exceptions
;identically. Structured exception handling enables you to have complete control over the handling of exceptions, provides support for debuggers, and is usable across all
;programming languages and machines. Vectored exception handling is an extension to structured exception handling.
;The system also supports termination handling, which enables you to ensure that whenever a guarded body of code is executed, a specified block of termination code is also
;executed. The termination code is executed regardless of how the flow of control leaves the guarded body. For example, a termination handler can guarantee that clean-up
;tasks are performed even if an exception or some other error occurs while the guarded body of code is being executed.
;EXCEPTION_MAXIMUM_PARAMETERS    equ 15
;EXCEPTION_RECORD    struct
;    ExceptionCode           dword               ?
;    ExceptionFlags          dword               ?
;    ExceptionRecord         PEXCEPTION_RECORD   ?
;    ExceptionAddress        PVOID               ?
;    NumberParameters        dword               ?
;    ExceptionInformation    ULONG_PTR           EXCEPTION_MAXIMUM_PARAMETERS dup(?)
;EXCEPTION_RECORD    ends
;PEXCEPTION_RECORD   typedef ptr EXCEPTION_RECORD

;Error Handling
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms679320.aspx>
;Well-written applications include error-handling code that allows them to recover gracefully from unexpected errors. When an error occurs, the application may need to
;request user intervention, or it may be able to recover on its own. In extreme cases, the application may log the user off or shut down the system.
C_ASSERT    textequ <.erre>

;RtlUnwind   proto WINAPI,
;    TargetFrame:    PVOID,
;    TargetIp:       PVOID,
;    ExceptionRecord:PEXCEPTION_RECORD
;    ReturnValue:    PVOID
;;ret void

;Resources
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ff468900.aspx>
MESSAGE_RESOURCE_BLOCK  struct
    LowId           dword   ?
    HighId          dword   ?
    OffsetToEntries dword   ?
MESSAGE_RESOURCE_BLOCK  ends

MESSAGE_RESOURCE_DATA   struct
    NumberOfBlocks  dword                   ?
    Blocks          MESSAGE_RESOURCE_BLOCK  {}
MESSAGE_RESOURCE_DATA   ends
PMESSAGE_RESOURCE_DATA  typedef ptr MESSAGE_RESOURCE_DATA

MESSAGE_RESOURCE_ENTRY  struct
    Length_ word    ?
    Flags   word    ?
    Text    byte    ?
MESSAGE_RESOURCE_ENTRY  ends
PMESSAGE_RESOURCE_ENTRY typedef ptr MESSAGE_RESOURCE_ENTRY