;Thread Ordering Service Functions
AvQuerySystemResponsiveness proto WINAPI,
    AvrtHandle:                 HANDLE,
    SystemResponsivenessValue:  PULONG
;ret BOOL

AvRtCreateThreadOrderingGroup   proto WINAPI,
    Context:            PHANDLE,
    Period:             PLARGE_INTEGER,
    ThreadOrderingGuid: LPGUID,
    Timeout:            PLARGE_INTEGER
;ret BOOL

AvRtCreateThreadOrderingGroupExA    proto WINAPI,
    Context:            PHANDLE,
    Period:             PLARGE_INTEGER,
    ThreadOrderingGuid: LPGUID,
    Timeout:            PLARGE_INTEGER,
    TaskName:           LPCSTR
;ret BOOL
AvRtCreateThreadOrderingGroupExW    proto WINAPI,
    Context:            PHANDLE,
    Period:             PLARGE_INTEGER,
    ThreadOrderingGuid: LPGUID,
    Timeout:            PLARGE_INTEGER,
    TaskName:           LPCWSTR
;ret BOOL
__AW <AvRtCreateThreadOrderingGroupEx>

AcRtDeleteThreadOrderingGroup   proto WINAPI,
    Context:HANDLE
;ret BOOL

AvRtJoinThreadOrderingGroup proto WINAPI,
    Context:            PHANDLE,
    ThreadOrderingGuid: LPGUID,
    Before:             BOOL
;ret BOOL

AvRtLeaveThreadOrderingGroup    proto WINAPI,
    Context:HANDLE
;ret BOOL

AvRtWaitOnThreadOrderingGroup   proto WINAPI,
    Context:HANDLE
;ret BOOL

;Multimedia Class Scheduler Service Functions
AvRevertMmThreadCharacteristics proto WINAPI,
    AvrtHandle: HANDLE
;ret BOOL

AvSetMmMaxThreadCharacteristicsA    proto WINAPI,
    FirstTask:  LPCSTR,
    SecondTask: LPCSTR,
    TaskIndex:  LPDWORD
;ret HANDLE
AvSetMmMaxThreadCharacteristicsW    proto WINAPI,
    FirstTask:  LPCWSTR,
    SecondTask: LPCWSTR,
    TaskIndex:  LPDWORD
;ret HANDLE
__AW <AvSetMmMaxThreadCharacteristics>

AvSetMmThreadCharacteristicsA   proto WINAPI,
    TaskName:   LPCSTR,
    TaskIndex:  LPDWORD
;ret HANDLE
AvSetMmThreadCharacteristicsW   proto WINAPI,
    TaskName:   LPCWSTR,
    TaskIndex:  LPDWORD
;ret HANDLE
__AW <AvSetMmThreadCharacteristics>

AVRT_PRIORITY_CRITICAL  equ 2
AVRT_PRIORITY_HIGH      equ 1
AVRT_PRIORITY_LOW       equ -1
AVRT_PRIORITY_NORMAL    equ 0
AVRT_PRIORITY   typedef dword
AvSetMmThreadPriority   proto WINAPI,
    AvrtHandle: HANDLE,
    Priority:   AVRT_PRIORITY
;ret BOOL