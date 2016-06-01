;Version Information
;<http://msdn.microsoft.com/en-us/library/windows/desktop/ms646981.aspx>
;Version information makes it easier for applications to install files properly and enables setup programs to analyze files currently installed. The version-information
;resource contains the version number of the file, its intended operating system, and the original file name.
VS_FIXEDFILEINFO    struct
    dwSignature         dword   ?
    dwStrucVersion      dword   ?
    dwFileVersionMS     dword   ?
    dwFileVersionLS     dword   ?
    dwProductVersionMS  dword   ?
    dwProductVersionLS  dword   ?
    dwFileFlagsMask     dword   ?
    dwFileFlags         dword   ?
    dwFileOS            dword   ?
    dwFileType          dword   ?
    dwFileSubtype       dword   ?
    dwFileDateMS        dword   ?
    dwFileDateLS        dword   ?
VS_FIXEDFILEINFO    ends
VS_FF_DEBUG         equ 00000001h
VS_FF_INFOINFERRED  equ 00000010h
VS_FF_PATCHED       equ 00000004h
VS_FF_PRERELEASE    equ 00000002h
VS_FF_PRIVATEBUILD  equ 00000008h
VS_FF_SPECIALBUILD  equ 00000020h

VOS_DOS         equ 00010000h
VOS_NT          equ 00040000h
VOS__WINDOWS16  equ 00000001h
VOS__WINDOWS32  equ 00000004h
VOS_OS216       equ 00020000h
VOS_OS232       equ 00030000h
VOS_PM16        equ 00000002h
VOS_PM32        equ 00000003h
VOS_UNKNOWN     equ 00000000h
VOS_DOS_WINDOWS16   equ VOS_DOS or VOS_WINDOWS16
VOS_DOS_WINDOWS32   equ VOS_DOS or VOS_WINDOWS32
VOS_NT_WINDOWS32    equ VOS_NT or VOS_WINDOWS32
VOS_OS216_PM16      equ VOS_OS216 or VOS_PM16
VOS_OS232_PM32      equ VOS_OS232 or VOS_PM32

VFT_APP         equ 00000001h
VFT_DLL         equ 00000002h
VFT_DRV         equ 00000003h
VFT_FONT        equ 00000004h
VFT_STATIC_LIB  equ 00000007h
VFT_UNKNOWN     equ 00000000h
VFT_VXD         equ 00000005h

VFT2_DRV_COMM               equ 0000000ah
VFT2_DRV_DISPLAY            equ 00000004h
VFT2_DRV_INSTALLABLE        equ 00000008h
VFT2_DRV_KEYBOARD           equ 00000002h
VFT2_DRV_LANGUAGE           equ 00000003h
VFT2_DRV_MOUSE              equ 00000005h
VFT2_DRV_NETWORK            equ 00000006h
VFT2_DRV_PRINTER            equ 00000001h
VFT2_DRV_SOUND              equ 00000009h
VFT2_DRV_SYSTEM             equ 00000007h
VFT2_DRV_VERSIONED_PRINTER  equ 0000000ch
VFT2_UNKNOWN                equ 00000000h

VFT2_FONT_RASTER    equ 00000001h
VFT2_FONT_TRUETYPE  equ 00000003h
VFT2_FONT_VECTOR    equ 00000002h
