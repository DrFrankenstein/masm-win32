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

;Process and Thread Structures
LIST_ENTRY  struct
    Flink   ptr LIST_ENTRY  ?
    Blink   ptr LIST_ENTRY  ?
LIST_ENTRY  ends
PLIST_ENTRY     typedef ptr LIST_ENTRY
PRLIST_ENTRY    typedef ptr LIST_ENTRY

PEB_LDR_DATA    struct
    Reserved1               byte        8 dup(?)
    Reserved2               PVOID       3 dup(?)
    InMemoryOrderModuleList LIST_ENTRY  {}
PEB_LDR_DATA    ends
PPEB_LDR_DATA   typedef ptr PEB_LDR_DATA

PEB struct
    Reserved1               byte                            2 dup(?)
    BeingDebugged           byte                            ?
    Reserved2               byte                            ?
    Reserved3               PVOID                           2 dup(?)
    Ldr                     PPEB_LDR_DATA                   ?
    ProcessParameters       PRTL_USER_PROCESS_PARAMETERS    ?
    Reserved4               byte                            104 dup(?)
    Reserved5               PVOID                           52 dup(?)
    PostProcessInitRoutine  PPS_POST_PROCESS_INIT_ROUTINE   ?
    Reserved6               byte                            128 dup(?)
    Reserved7               PVOID                           ?
    SessionId               ULONG                           ?
PEB ends
PPEB    typedef ptr PEB

LDR_DATA_TABLE_ENTRY struct
    Reserved1           PVOID           2 dup(?)
    InMemoryOrderLinks  LIST_ENTRY      {}
    Reserved2           PVOID           2 dup(?)
    DllBase             PVOID           ?
    EntryPoint          PVOID           ?
    Reserved3           PVOID           ?
    FullDllName         UNICODE_STRING  ?
    Reserved4           byte            8 dup(?)
    Reserved5           PVOID           3 dup(?)
    union
        CheckSum    ULONG   ?
        Reserved6   PVOID   ?
    ends
    TimeDateStamp       ULONG           ?
LDR_DATA_TABLE_ENTRY ends
PLDR_DATA_TABLE_ENTRY  typedef ptr LDR_DATA_TABLE_ENTRY

RTL_USER_PROCESS_PARAMETERS struct
    Reserved1       byte            16 dup(?)
    Reserved2       PVOID           10 dup(?)
    ImagePathName   UNICODE_STRING  ?
    CommandLine     UNICODE_STRING  ?
RTL_USER_PROCESS_PARAMETERS ends

PROCESS_BASIC_INFORMATION   struct
    Reserved1       PVOID       ?
    PebBaseAddress  PPEB        ?
    Reserved2       PVOID       2 dup(?)
    UniqueProcessId ULONG_PTR   ?
    Reserved3       PVOID       ?
PROCESS_BASIC_INFORMATION   ends

;Error Handling
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms679320.aspx>
;Well-written applications include error-handling code that allows them to recover gracefully from unexpected errors. When an error occurs, the application may need to
;request user intervention, or it may be able to recover on its own. In extreme cases, the application may log the user off or shut down the system.
RtlNtStatusToDosError   proto WINAPI,
    Status: NTSTATUS
;ret ULONG