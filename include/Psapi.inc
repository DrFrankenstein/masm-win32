GetMappedFileNameA  proto WINAPI,
    hProcess:   HANDLE,
    lpv:        LPVOID,
    lpFilename: LPSTR,
    nSize:      dword
;ret dword

GetMappedFileNameW  proto WINAPI,
    hProcess:   HANDLE,
    lpv:        LPVOID,
    lpFilename: LPWSTR,
    nSize:      dword
;ret dword

ifdef   UNICODE
    GetMappedFileName   textequ <GetMappedFileNameW>
else
    GetMappedFileName   textequ <GetMappedFileNameA>
endif