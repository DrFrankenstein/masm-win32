;Icons
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms646973.aspx>
;An icon is a picture that consists of a bitmap image combined with a mask to create transparent areas in the picture. The term icon can refer to either of the following: 
;•A single icon image. This is a resource of type RT_ICON.
;•A group of images, from which the system or an application can choose the most appropriate icon based on size and color depth. This is a resource of type RT_GROUP_ICON.

DuplicateIcon   proto WINAPI,
    hInst:  HINSTANCE,
    hIcon:  HICON
;ret HICON

ExtractAssociatedIconA  proto WINAPI,
    hInst:      HINSTANCE,
    lpIconPath: LPSTR,
    lpiIcon:    ptr word
;ret HICON
ExtractAssociatedIconW  proto WINAPI,
    hInst:      HINSTANCE,
    lpIconPath: LPWSTR,
    lpiIcon:    ptr word
;ret HICON
__AW <ExtractAssociatedIcon>

ExtractIconA    proto WINAPI,
    hInst:          HINSTANCE,
    lpszExeFileName:LPCSTR,
    nIconIndex:     UINT
;ret HICON
ExtractIconW    proto WINAPI,
    hInst:          HINSTANCE,
    lpszExeFileName:LPCWSTR,
    nIconIndex:     UINT
;ret HICON
__AW <ExtractIcon>

ExtractIconExA  proto WINAPI,
    lpszFile:       LPCSTR,
    nIconIndex:     sdword,
    phiconLarge:    ptr HICON,
    phiconSmall:    ptr HICON,
    nIcons:         UINT
;ret UINT
ExtractIconExW  proto WINAPI,
    lpszFile:       LPCWSTR,
    nIconIndex:     sdword,
    phiconLarge:    ptr HICON,
    phiconSmall:    ptr HICON,
    nIcons:         UINT
;ret UINT
__AW <ExtractIconEx>

