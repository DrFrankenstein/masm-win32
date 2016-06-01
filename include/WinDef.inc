ATOM                    typedef word            ;An atom. For more information, see About Atom Tables.
BOOL                    typedef sdword          ;A Boolean variable (should be TRUE or FALSE).
BOOLEAN                 typedef byte            ;A Boolean variable (should be TRUE or FALSE).
CALLBACK                equ stdcall             ;The calling convention for callback functions.
CCHAR                   typedef byte            ;An 8-bit Windows (ANSI) character.
CHAR                    typedef byte            ;An 8-bit Windows (ANSI) character. For more information, see Character Sets Used By Fonts.
COLORREF                typedef dword           ;The red, green, blue (RGB) color value (32 bits). See COLORREF for information on this type.
DWORDLONG               typedef qword           ;A 64-bit unsigned integer. The range is 0 through 18446744073709551615 decimal.
DWORD32                 typedef dword           ;A 32-bit unsigned integer.
DWORD64                 typedef qword           ;A 64-bit unsigned integer.
FLOAT                   typedef real4           ;A floating-point variable.
HALF_PTR                typedef word            ;Half the size of a pointer. Use within a structure that contains a pointer and two small fields.
;INT not typedef'd because it is a reserved word in MASM; use sdword
INT_PTR                 typedef sdword          ;A signed integer type for pointer precision. Use when casting a pointer to an integer to perform pointer arithmetic.
INT8                    typedef sbyte           ;An 8-bit signed integer.
INT16                   typedef sword           ;A 16-bit signed integer.
INT32                   typedef sdword          ;A 32-bit signed integer. The range is –2147483648 through 2147483647 decimal.
INT64                   typedef sqword          ;A 64-bit signed integer. The range is –9223372036854775808 through 9223372036854775807 decimal.
LANGID                  typedef word            ;A language identifier. For more information, see Language Identifiers.
LCID                    typedef dword           ;A locale identifier. For more information, see Locale Identifiers.
LCTYPE                  typedef dword           ;A locale information type. For a list, see Locale Information Constants.
LGRPID                  typedef dword           ;A language group identifier. For a list, see EnumLanguageGroupLocales.
LONG                    typedef sdword          ;A 32-bit signed integer. The range is –2147483648 through 2147483647 decimal.
HRESULT                 typedef LONG            ;The return codes used by COM interfaces. For more information, see Structure of the COM Error Codes. To test an HRESULT value, use the FAILED and SUCCEEDED macros.
LONGLONG                typedef sqword          ;A 64-bit signed integer. The range is –9223372036854775808 through 9223372036854775807 decimal.
LONG_PTR                typedef sdword          ;A signed long type for pointer precision. Use when casting a pointer to a long to perform pointer arithmetic.
LONG32                  typedef sdword          ;A 32-bit signed integer. The range is –2147483648 through 2147483647 decimal.
LONG64                  typedef sqword          ;A 64-bit signed integer. The range is –9223372036854775808 through 9223372036854775807 decimal.
LPARAM                  typedef LONG_PTR        ;A message parameter.
LPBOOL                  typedef ptr BOOL        ;A pointer to a BOOL.
LPBYTE                  typedef ptr byte        ;A pointer to a BYTE.
LPCOLORREF              typedef ptr COLORREF    ;A pointer to a COLORREF value.
LPCSTR                  typedef ptr CHAR        ;A pointer to a constant null-terminated string of 8-bit Windows (ANSI) characters. For more information, see Character Sets Used By Fonts.
LPCVOID                 typedef ptr byte        ;A pointer to a constant of any type.
LPDWORD                 typedef ptr dword       ;A pointer to a DWORD.
LPINT                   typedef ptr sdword      ;A pointer to an INT.
LPLONG                  typedef ptr LONG        ;A pointer to a LONG.
LPSTR                   typedef ptr CHAR        ;A pointer to a null-terminated string of 8-bit Windows (ANSI) characters. For more information, see Character Sets Used By Fonts.
LPVOID                  typedef ptr byte        ;A pointer to any type.
LPWORD                  typedef ptr word        ;A pointer to a WORD.
LRESULT                 typedef LONG_PTR        ;Signed result of message processing.
PBOOL                   typedef ptr BOOL        ;A pointer to a BOOL.
PBOOLEAN                typedef ptr BOOLEAN     ;A pointer to a BOOLEAN.
PBYTE                   typedef ptr byte        ;A pointer to a BYTE.
PCHAR                   typedef ptr CHAR        ;A pointer to a CHAR.
PCSTR                   typedef ptr CHAR        ;A pointer to a constant null-terminated string of 8-bit Windows (ANSI) characters. For more information, see Character Sets Used By Fonts.
PDWORD                  typedef ptr dword       ;A pointer to a DWORD.
PDWORDLONG              typedef ptr DWORDLONG   ;A pointer to a DWORDLONG.
PDWORD32                typedef ptr DWORD32     ;A pointer to a DWORD32.
PDWORD64                typedef ptr DWORD64     ;A pointer to a DWORD64.
PFLOAT                  typedef ptr FLOAT       ;A pointer to a FLOAT.
PHALF_PTR               typedef ptr HALF_PTR    ;A pointer to a HALF_PTR.
PINT                    typedef ptr sdword      ;A pointer to an INT.
PINT_PTR                typedef ptr INT_PTR     ;A pointer to an INT_PTR.
PINT8                   typedef ptr INT8        ;A pointer to an INT8.
PINT16                  typedef ptr INT16       ;A pointer to an INT16.
PINT32                  typedef ptr INT32       ;A pointer to an INT32.
PINT64                  typedef ptr INT64       ;A pointer to an INT64.
PLCID                   typedef ptr LCID        ;A pointer to an LCID.
PLONG                   typedef ptr LONG        ;A pointer to a LONG.
PLONGLONG               typedef ptr LONGLONG    ;A pointer to a LONGLONG.
PLONG_PTR               typedef ptr LONG_PTR    ;A pointer to a LONG_PTR.
PLONG32                 typedef ptr LONG32      ;A pointer to a LONG32.
PLONG64                 typedef ptr LONG64      ;A pointer to a LONG64.
POINTER32               typedef dword           ;A 32-bit pointer. On a 32-bit system, this is a native pointer. On a 64-bit system, this is a truncated 64-bit pointer.
POINTER64               typedef qword           ;A 64-bit pointer. On a 64-bit system, this is a native pointer. On a 32-bit system, this is a sign-extended  32-bit pointer. Note that it is not safe to assume the state of the high pointer bit.
POINTER_SIGNED          typedef sdword          ;A signed pointer.
POINTER_UNSIGNED        typedef dword           ;An unsigned pointer.
PSHORT                  typedef ptr word        ;A pointer to a SHORT.
PSTR                    typedef ptr CHAR        ;A pointer to a null-terminated string of 8-bit Windows (ANSI) characters. For more information, see Character Sets Used By Fonts.
PVOID                   typedef ptr byte        ;A pointer to any type.
HANDLE                  typedef PVOID           ;A handle to an object.
HACCEL                  typedef HANDLE          ;A handle to an accelerator table.
PHANDLE                 typedef ptr HANDLE      ;A pointer to a HANDLE.
HBITMAP                 typedef HANDLE          ;A handle to a bitmap.
HBRUSH                  typedef HANDLE          ;A handle to a brush.
HCOLORSPACE             typedef HANDLE          ;A handle to a color space.
HCONV                   typedef HANDLE          ;A handle to a dynamic data exchange (DDE) conversation.
HCONVLIST               typedef HANDLE          ;A handle to a DDE conversation list.
HCURSOR                 typedef HANDLE          ;A handle to a cursor.
HDC                     typedef HANDLE          ;A handle to a device context (DC).
HDDEDATA                typedef HANDLE          ;A handle to DDE data.
HDESK                   typedef HANDLE          ;A handle to a desktop.
HDROP                   typedef HANDLE          ;A handle to an internal drop structure.
HDWP                    typedef HANDLE          ;A handle to a deferred window position structure.
HENHMETAFILE            typedef HANDLE          ;A handle to an enhanced metafile.
HFILE                   typedef sdword          ;A handle to a file opened by OpenFile, not CreateFile.
HFONT                   typedef HANDLE          ;A handle to a font.
HGDIOBJ                 typedef HANDLE          ;A handle to a GDI object.
HGLOBAL                 typedef HANDLE          ;A handle to a global memory block.
HHOOK                   typedef HANDLE          ;A handle to a hook.
HICON                   typedef HANDLE          ;A handle to an icon.
HINSTANCE               typedef HANDLE          ;A handle to an instance. This is the base address of the module in memory. HMODULE and HINSTANCE are the same today, but represented different things in 16-bit Windows.
HKEY                    typedef HANDLE          ;A handle to a registry key.
PHKEY                   typedef ptr HKEY        ;A pointer to an HKEY.
HKL                     typedef HANDLE          ;An input locale identifier.
HLOCAL                  typedef HANDLE          ;A handle to a local memory block.
HMENU                   typedef HANDLE          ;A handle to a menu.
HMETAFILE               typedef HANDLE          ;A handle to a metafile.
HMODULE                 typedef HINSTANCE       ;A handle to a module. The is the base address of the module in memory. HMODULE and HINSTANCE are the same in current versions of Windows, but represented different things in 16-bit Windows.
HMONITOR                typedef HANDLE          ;A handle to a display monitor.
HPALETTE                typedef HANDLE          ;A handle to a palette.
HPEN                    typedef HANDLE          ;A handle to a pen.
HRGN                    typedef HANDLE          ;A handle to a region.
HRSRC                   typedef HANDLE          ;A handle to a resource.
HSZ                     typedef HANDLE          ;A handle to a DDE string.
HWINSTA                 typedef HANDLE          ;A handle to a window station.
HWND                    typedef HANDLE          ;A handle to a window.
LPHANDLE                typedef ptr HANDLE      ;A pointer to a HANDLE.
PWORD                   typedef ptr word        ;A pointer to a WORD.
SC_HANDLE               typedef HANDLE          ;A handle to a service control manager database. For more information, see SCM Handles.
SC_LOCK                 typedef LPVOID          ;A lock to a service control manager database. For more information, see SCM Handles.
SERVICE_STATUS_HANDLE   typedef HANDLE          ;A handle to a service status value. For more information, see SCM Handles.
;SHORT not typedef'd because it is a reserved word in MASM; use sword
SSIZE_T                 typedef LONG_PTR        ;A signed version of SIZE_T.
PSSIZE_T                typedef ptr SSIZE_T     ;A pointer to a SSIZE_T.
;TBYTE not typedef'd because it is a reserved word in MASM; use byte or WCHAR depending on UNICODE
UCHAR                   typedef byte            ;An unsigned CHAR.
PUCHAR                  typedef ptr UCHAR       ;A pointer to a UCHAR.
UHALF_PTR               typedef word            ;An unsigned HALF_PTR. Use within a structure that contains a pointer and two small fields.
PUHALF_PTR              typedef ptr UHALF_PTR   ;A pointer to a UHALF_PTR.
UINT                    typedef dword           ;An unsigned INT. The range is 0 through 4294967295 decimal.
PUINT                   typedef ptr UINT        ;A pointer to a UINT.
UINT_PTR                typedef dword           ;An unsigned INT_PTR.
PUINT_PTR               typedef ptr UINT_PTR    ;A pointer to a UINT_PTR.
UINT8                   typedef byte            ;An unsigned INT8.
PUINT8                  typedef ptr UINT8       ;A pointer to a UINT8.
UINT16                  typedef word            ;An unsigned INT16.
PUINT16                 typedef ptr UINT16      ;A pointer to a UINT16.
UINT32                  typedef dword           ;An unsigned INT32. The range is 0 through 4294967295 decimal.
PUINT32                 typedef ptr UINT32      ;A pointer to a UINT32.
UINT64                  typedef qword           ;An unsigned INT64. The range is 0 through 18446744073709551615 decimal.
PUINT64                 typedef ptr UINT64      ;A pointer to a UINT64.
ULONG                   typedef dword           ;An unsigned LONG. The range is 0 through 4294967295 decimal.
PULONG                  typedef ptr ULONG       ;A pointer to a ULONG.
ULONGLONG               typedef qword           ;A 64-bit unsigned integer. The range is 0 through 18446744073709551615 decimal.
PULONGLONG              typedef ptr ULONGLONG   ;A pointer to a ULONGLONG.
ULONG_PTR               typedef dword           ;An unsigned LONG_PTR.
PULONG_PTR              typedef ptr ULONG_PTR   ;A pointer to a ULONG_PTR.
SIZE_T                  typedef ULONG_PTR       ;The maximum number of bytes to which a pointer can point. Use for a count that must span the full range of a pointer.
PSIZE_T                 typedef ptr SIZE_T      ;A pointer to a SIZE_T.
DWORD_PTR               typedef ptr ULONG_PTR   ;An unsigned long type for pointer precision. Use when casting a pointer to a long type to perform pointer arithmetic. (Also commonly used for general 32-bit parameters that have been extended to 64 bits in 64-bit Windows.)
PDWORD_PTR              typedef ptr DWORD_PTR   ;A pointer to a DWORD_PTR.
ULONG32                 typedef dword           ;An unsigned LONG32. The range is 0 through 4294967295 decimal.
PULONG32                typedef ptr ULONG32     ;A pointer to a ULONG32.
ULONG64                 typedef qword           ;An unsigned LONG64. The range is 0 through 18446744073709551615 decimal.
PULONG64                typedef ptr ULONG64     ;A pointer to a ULONG64.
USHORT                  typedef word            ;An unsigned SHORT. The range is 0 through 65535 decimal.
PUSHORT                 typedef ptr USHORT      ;A pointer to a USHORT.
USN                     typedef LONGLONG        ;An update sequence number (USN).
VOID                    typedef byte            ;Any type.
WCHAR                   typedef word            ;A 16-bit Unicode character. For more information, see Character Sets Used By Fonts.
LPCWSTR                 typedef ptr WCHAR       ;A pointer to a constant null-terminated string of 16-bit Unicode characters. For more information, see Character Sets Used By Fonts.
LPWSTR                  typedef ptr WCHAR       ;A pointer to a null-terminated string of 16-bit Unicode characters. For more information, see Character Sets Used By Fonts.
PWCHAR                  typedef ptr WCHAR       ;A pointer to a WCHAR.
PCWSTR                  typedef ptr WCHAR       ;A pointer to a constant null-terminated string of 16-bit Unicode characters. For more information, see Character Sets Used By Fonts.
PWSTR                   typedef ptr WCHAR       ;A pointer to a null-terminated string of 16-bit Unicode characters. For more information, see Character Sets Used By Fonts.
ifdef   UNICODE
    TCHAR               typedef WCHAR           ;A WCHAR if UNICODE is defined, a CHAR otherwise.
    LPCTSTR             typedef LPCWSTR         ;An LPCWSTR if UNICODE is defined, an LPCSTR otherwise. For more information, see Windows Data Types for Strings.
    LPTSTR              typedef LPWSTR          ;An LPWSTR if UNICODE is defined, an LPSTR otherwise. For more information, see Windows Data Types for Strings.
    PTSTR               typedef PWSTR           ;A PWSTR if UNICODE is defined, a PSTR otherwise. For more information, see Windows Data Types for Strings.
    PCTSTR              typedef PCWSTR          ;A PCWSTR if UNICODE is defined, a PCSTR otherwise. For more information, see Windows Data Types for Strings.
else
    TCHAR               typedef byte
    LPCTSTR             typedef LPCSTR
    LPTSTR              typedef LPSTR
    PTSTR               typedef PSTR
    PCTSTR              typedef PCSTR
endif
UNICODE_STRING          struct                  ;A Unicode string.
    _Length         USHORT  ?
    MaximumLength   USHORT  ?
    Buffer          PWSTR   ?
UNICODE_STRING          ends
PUNICODE_STRING         typedef ptr UNICODE_STRING
PCUNICODE_STRING        typedef ptr UNICODE_STRING
WINAPI                  equ stdcall             ;The calling convention for system functions.
APIENTRY                equ WINAPI              ;The calling convention for system functions.
WPARAM                  typedef UINT_PTR        ;A message parameter.

FALSE                   equ 0
TRUE                    equ 1

;TODO might have to move this, perhaps in its own guiddef.inc
GUID    struct
    Data1   dword   ?
    Data2   word    ?
    Data3   word    ?
    Data4   byte    8 dup(?)
GUID    ends
LPGUID  typedef ptr GUID
LPCGUID typedef ptr GUID

MAX_PATH    equ 260

__AW    macro   symname
    ifdef   UNICODE
        symname catstr  <&symname>, <W>
    else
        symname catstr  <&symname>, <A>
    endif
endm
