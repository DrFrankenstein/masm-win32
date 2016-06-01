;Version Information
;<http://msdn.microsoft.com/en-us/library/windows/desktop/ms646981.aspx>
;Version information makes it easier for applications to install files properly and enables setup programs to analyze files currently installed. The version-information
;resource contains the version number of the file, its intended operating system, and the original file name.
GetFileVersionInfoA proto WINAPI,
    lptstrFilename: LPCSTR,
    dwHandle:       dword,
    dwLen:          dword,
    lpData:         LPVOID
;ret BOOL
GetFileVersionInfoW proto WINAPI,
    lptstrFilename: LPCWSTR,
    dwHandle:       dword,
    dwLen:          dword,
    lpData:         LPVOID
;ret BOOL
__AW <GetFileVersionInfo>

GetFileVersionInfoExA   proto WINAPI,
    dwFlags:        dword,
    lptstrFileName: LPCSTR,
    dwHandle:       dword,
    dwLen:          dword,
    lpData:         LPVOID
;ret BOOL
GetFileVersionInfoExW   proto WINAPI,
    dwFlags:        dword,
    lptstrFileName: LPCWSTR,
    dwHandle:       dword,
    dwLen:          dword,
    lpData:         LPVOID
;ret BOOL
__AW <GetFileVersionInfoEx>
FILE_VER_GET_LOCALISED  equ 01h
FILE_VER_GET_NEUTRAL    equ 02h
FILE_VER_GET_PREFETCHED equ 04h

GetFileVersionInfoSizeA proto WINAPI,
    lptstrFilename: LPCSTR,
    lpdwHandle:     LPDWORD
;ret dword
GetFileVersionInfoSizeW proto WINAPI,
    lptstrFilename: LPCWSTR,
    lpdwHandle:     LPDWORD
;ret dword
__AW <GetFileVersionInfo>

GetFileVersionInfoSizeExA   proto WINAPI,
    dwFlags:        dword,
    lptstrFilename: LPCSTR,
    lpdwHandle:     LPDWORD
;ret dword
GetFileVersionInfoSizeExW   proto WINAPI,
    dwFlags:        dword,
    lptstrFilename: LPCWSTR,
    lpdwHandle:     LPDWORD
;ret dword
__AW <GetFileVersionInfoSizeEx>

VerFindFileA    proto WINAPI,
    dwFlags:        dword,
    szFileName:     LPCSTR,
    szWinDir:       LPCSTR,
    szAppDir:       LPCSTR,
    szCurDir:       LPSTR,
    pluCurDirLen:   PUINT,
    szDestDir:      LPSTR,
    lpuDestDirLen:  PUINT
;ret dword
VerFindFileW    proto WINAPI,
    dwFlags:        dword,
    szFileName:     LPCWSTR,
    szWinDir:       LPCWSTR,
    szAppDir:       LPCWSTR,
    szCurDir:       LPWSTR,
    pluCurDirLen:   PUINT,
    szDestDir:      LPWSTR,
    lpuDestDirLen:  PUINT
;ret dword
__AW <VerFindFile>
VFFF_ISSHAREDFILE   equ 0001h
VFF_CURNEDEST       equ 0001h
VFF_FILEINUSE       equ 0002h
VFF_BOFFTOOSMALL    equ 0004h

VerInstallFileA proto WINAPI,
    uFlags:         dword,
    szSrcFilename:  LPCSTR,
    szDestFilename: LPCSTR,
    szSrcDir:       LPCSTR,
    szDestDir:      LPCSTR,
    szCurDir:       LPCSTR,
    szTmpFile:      LPSTR,
    lpuTmpFileLen:  PUINT
;ret dword
VerInstallFileW proto WINAPI,
    uFlags:         dword,
    szSrcFilename:  LPCWSTR,
    szDestFilename: LPCWSTR,
    szSrcDir:       LPCWSTR,
    szDestDir:      LPCWSTR,
    szCurDir:       LPCWSTR,
    szTmpFile:      LPWSTR,
    lpuTmpFileLen:  PUINT
;ret dword
__AW <VerInstallFile>
VIFF_FORCEINSTALL   equ 0001h
VIFF_DONTDELETEOLD  equ 0002h

VIF_ACCESSVIOLATION     equ 00000200h
VIF_BUFFTOOSMALL        equ 00040000h
VIF_CANNOTCREATE        equ 00000800h
VIF_CANNOTDELETE        equ 00001000h
VIF_CANNOTDELETECUR     equ 00004000h
VIF_CANNOTLOADCABINET   equ 00100000h
VIF_CANNOTLOADLZ32      equ 00080000h
VIF_CANNOTREADDST       equ 00020000h
VIF_CANNOTREADSRC       equ 00010000h
VIF_CANNOTRENAME        equ 00002000h
VIF_DIFFCODEPG          equ 00000010h
VIF_DIFFLANG            equ 00000008h
VIF_DIFFTYPE            equ 00000020h
VIF_FILEINUSE           equ 00000080h
VIF_MISMATCH            equ 00000002h
VIF_OUTOFMEMORY         equ 00008000h
VIF_OUTOFSPACE          equ 00000100h
VIF_SHARINGVIOLATION    equ 00000400h
VIF_SRCOLD              equ 00000004h
VIF_TEMPFILE            equ 00000001h
VIF_WRITEPROT           equ 00000040h

VerLanguageNameA    proto WINAPI,
    wLang:  dword,
    szLang: LPSTR,
    cchLang:dword
;ret dword
VerLanguageNameW    proto WINAPI,
    wLang:  dword,
    szLang: LPWSTR,
    cchLang:dword
;ret dword
__AW <VerLanguageName>

VerQueryValueA  proto WINAPI,
    pBlock:     LPCVOID,
    lpSubBlock: LPCSTR,
    lplpBuffer: ptr LPVOID,
    puLen:      PUINT
;ret BOOL
VerQueryValueW  proto WINAPI,
    pBlock:     LPCVOID,
    lpSubBlock: LPCWSTR,
    lplpBuffer: ptr LPVOID,
    puLen:      PUINT
;ret BOOL