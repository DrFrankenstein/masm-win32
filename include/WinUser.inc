;Input Feedback Configuration
;<https://msdn.microsoft.com/en-us/library/windows/desktop/hh707352.aspx>
FEEDBACK_TYPE                       typedef dword
FEEDBACK_TOUCH_CONTACTVISUALIZATION equ 1
FEEDBACK_PEN_BARRELVISUALIZATION    equ 2
FEEDBACK_PEN_TAP                    equ 3
FEEDBACK_PEN_DOUBLETAP              equ 4
FEEDBACK_PEN_PRESSANDHOLD           equ 5
FEEDBACK_PEN_RIGHTTAP               equ 6
FEEDBACK_TOUCH_TAP                  equ 7
FEEDBACK_TOUCH_DOUBLETAP            equ 8
FEEDBACK_TOUCH_PRESSANDHOLD         equ 9
FEEDBACK_TOUCH_RIGHTTAP             equ 10
FEEDBACK_GESTURE_PRESSANDTAP        equ 11
FEEDBACK_MAX                        equ 0ffffffffh

;Windows
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms632595.aspx>
;In a graphical Windows-based application, a window is a rectangular area of the screen where the application displays output and receives input from the user. Therefore, one of the first tasks of a graphical Windows-based application is to create a window. 
;A window shares the screen with other windows, including those from other applications. Only one window at a time can receive input from the user. The user can use the mouse, keyboard, or other input device to interact with this window and the application that owns it.

;Window Styles
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms632600.aspx>
;The following are the window styles. After the window has been created, these styles cannot be modified, except as noted.
WS_BORDER           equ 00800000h   ;The window has a thin-line border.
WS_CAPTION          equ 00C00000h   ;The window has a title bar (includes the WS_BORDER style).
WS_CHILD            equ 40000000h   ;The window is a child window. A window with this style cannot have a menu bar. This style cannot be used with the WS_POPUP style.
WS_CHILDWINDOW      equ 40000000h   ;Same as the WS_CHILD style.
WS_CLIPCHILDREN     equ 02000000h   ;Excludes the area occupied by child windows when drawing occurs within the parent window. This style is used when creating the parent window.
WS_CLIPSIBLINGS     equ 04000000h   ;Clips child windows relative to each other; that is, when a particular child window receives a WM_PAINT message, the WS_CLIPSIBLINGS style clips all other overlapping child windows out of the region of the child window to be updated.
WS_DISABLED         equ 08000000h   ;The window is initially disabled. A disabled window cannot receive input from the user. To change this after a window has been created, use the EnableWindow function.
WS_DLGFRAME         equ 00400000h   ;The window has a border of a style typically used with dialog boxes. A window with this style cannot have a title bar.
WS_GROUP            equ 00020000h   ;The window is the first control of a group of controls. The group consists of this first control and all controls defined after it, up to the next control with the WS_GROUP style.
WS_HSCROLL          equ 00100000h   ;The window has a horizontal scroll bar.
WS_ICONIC           equ 20000000h   ;The window is initially minimized. Same as the WS_MINIMIZE style.
WS_MAXIMIZE         equ 01000000h   ;The window is initially maximized.
WS_MAXIMIZEBOX      equ 00010000h   ;The window has a maximize button. Cannot be combined with the WS_EX_CONTEXTHELP style. The WS_SYSMENU style must also be specified. 
WS_MINIMIZE         equ 20000000h   ;The window is initially minimized. Same as the WS_ICONIC style.
WS_MINIMIZEBOX      equ 00020000h   ;The window has a minimize button. Cannot be combined with the WS_EX_CONTEXTHELP style. The WS_SYSMENU style must also be specified. 
WS_OVERLAPPED       equ 00000000h   ;The window is an overlapped window. An overlapped window has a title bar and a border. Same as the WS_TILED style.
WS_POPUP            equ 80000000h   ;The windows is a pop-up window. This style cannot be used with the WS_CHILD style.
WS_SIZEBOX          equ 00040000h   ;The window has a sizing border. Same as the WS_THICKFRAME style.
WS_SYSMENU          equ 00080000h   ;The window has a window menu on its title bar. The WS_CAPTION style must also be specified.
WS_TABSTOP          equ 00010000h   ;The window is a control that can receive the keyboard focus when the user presses the TAB key. Pressing the TAB key changes the keyboard focus to the next control with the WS_TABSTOP style.
WS_THICKFRAME       equ 00040000h   ;The window has a sizing border. Same as the WS_SIZEBOX style.
WS_TILED            equ 00000000h   ;The window is an overlapped window. An overlapped window has a title bar and a border. Same as the WS_OVERLAPPED style. 
WS_VISIBLE          equ 10000000h   ;The window is initially visible.
WS_VSCROLL          equ 00200000h   ;The window has a vertical scroll bar.
WS_OVERLAPPEDWINDOW equ WS_OVERLAPPED or WS_CAPTION or WS_SYSMENU or WS_THICKFRAME or WS_MINIMIZEBOX or WS_MAXIMIZEBOX  ;The window is an overlapped window. Same as the WS_TILEDWINDOW style.
WS_TILEDWINDOW      equ WS_OVERLAPPED or WS_CAPTION or WS_SYSMENU or WS_THICKFRAME or WS_MINIMIZEBOX or WS_MAXIMIZEBOX  ;The window is an overlapped window. Same as the WS_OVERLAPPEDWINDOW style. 
WS_POPUPWINDOW      equ WS_POPUP or WS_BORDER or WS_SYSMENU ;The window is a pop-up window. The WS_CAPTION and WS_POPUPWINDOW styles must be combined to make the window menu visible.

;Extended Window Styles
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ff700543.aspx>
;The following are the extended window styles.
WS_EX_ACCEPTFILES       equ 00000010h   ;The window accepts drag-drop files.
WS_EX_APPWINDOW         equ 00040000h   ;Forces a top-level window onto the taskbar when the window is visible. 
WS_EX_CLIENTEDGE        equ 00000200h   ;The window has a border with a sunken edge.
WS_EX_COMPOSITED        equ 02000000h   ;Paints all descendants of a window in bottom-to-top painting order using double-buffering.
WS_EX_CONTEXTHELP       equ 00000400h   ;The title bar of the window includes a question mark. When the user clicks the question mark, the cursor changes to a question mark with a pointer. If the user then clicks a child window, the child receives a WM_HELP message.
WS_EX_CONTROLPARENT     equ 00010000h   ;The window itself contains child windows that should take part in dialog box navigation.
WS_EX_DLGMODALFRAME     equ 00000001h   ;The window has a double border; the window can, optionally, be created with a title bar by specifying the WS_CAPTION style in the dwStyle parameter.
WS_EX_LAYERES           equ 00080000h   ;The window is a layered window.
WS_EX_LAYOUTRTL         equ 00400000h   ;If the shell language is Hebrew, Arabic, or another language that supports reading order alignment, the horizontal origin of the window is on the right edge. Increasing horizontal values advance to the left.
WS_EX_LEFT              equ 00000000h   ;The window has generic left-aligned properties. This is the default.
WS_EX_LEFTSCROLLBAR     equ 00004000h   ;If the shell language is Hebrew, Arabic, or another language that supports reading order alignment, the vertical scroll bar (if present) is to the left of the client area. For other languages, the style is ignored.
WS_EX_LTRREADING        equ 00000000h   ;The window text is displayed using left-to-right reading-order properties. This is the default.
WS_EX_MDICHILD          equ 00000040h   ;The window is a MDI child window.
WS_EX_NOACTIVATE        equ 08000000h   ;A top-level window created with this style does not become the foreground window when the user clicks it. The system does not bring this window to the foreground when the user minimizes or closes the foreground window.
WS_EX_NOINHERITLAYOUT   equ 00100000h   ;The window does not pass its window layout to its child windows.
WS_EX_NOPARENTNOTIFY    equ 00000004h   ;The child window created with this style does not send the WM_PARENTNOTIFY message to its parent window when it is created or destroyed.
WS_EX_NOREDIRECTIONBITMAP equ 00200000h ;The window does not render to a redirection surface. This is for windows that do not have visible content or that use mechanisms other than surfaces to provide their visual.
WS_EX_RIGHT             equ 00001000h   ;The window has generic "right-aligned" properties. This depends on the window class. This style has an effect only if the shell language is Hebrew, Arabic, or another language that supports reading-order alignment.
WS_EX_RIGHTSCROLLBAR    equ 00000000h   ;The vertical scroll bar (if present) is to the right of the client area. This is the default.
WS_EX_RTLREADING        equ 00002000h   ;If the shell language is Hebrew, Arabic, or another language that supports reading-order alignment, the window text is displayed using right-to-left reading-order properties. For other languages, the style is ignored.
WS_EX_STATICEDGE        equ 00020000h   ;The window has a three-dimensional border style intended to be used for items that do not accept user input.
WS_EX_TOOLWINDOW        equ 00000080h   ;The window is intended to be used as a floating toolbar. A tool window has a title bar that is shorter than a normal title bar, and the window title is drawn using a smaller font.
WS_EX_TOPMOST           equ 00000008h   ;The window should be placed above all non-topmost windows and should stay above them, even when the window is deactivated.
WS_EX_TRANSPARENT       equ 00000020h   ;The window should not be painted until siblings beneath the window (that were created by the same thread) have been painted. The window appears transparent because the bits of underlying sibling windows have already been painted.
WS_EX_WINDOWEDGE        equ 00000100h   ;The window has a border with a raised edge.
WS_EX_OVERLAPPEDWINDOW  equ WS_EX_WINDOWEDGE or WS_EX_CLIENTEDGE    ;The window is an overlapped window.
WS_EX_PALETTEWINDOW     equ WS_EX_WINDOWEDGE or WS_EX_TOOLWINDOW or WS_EX_TOPMOST   ;The window is palette window, which is a modeless dialog box that presents an array of commands. 

GET_X_LPARAM    macro   lParam:req  ;Retrieves the signed x-coordinate from the specified LPARAM value.
    and     lParam, ffffh
endm

GET_Y_LPARAM    macro   lParam:req  ;Retrieves the signed y-coordinate from the given LPARAM value.
    HIWORD  lParam
endm

HIBYTE  macro   wValue:req  ;Retrieves the high-order byte from the given 16-bit value. 
    shr     wValue, 8
endm

HIWORD  macro   dwValue:req ;Retrieves the high-order word from the specified 32-bit value. 
    shr     dwValue, 16
endm

LOBYTE  macro   wValue:req  ;Retrieves the low-order byte from the specified value. 
    and     wValue, 0ffh
endm

LOWORD  macro   dwValue:req ;Retrieves the low-order word from the specified value. 
    and     wValue, 0ffffh
endm

MAKELONG    macro   dest:req, wLow:req, wHigh:req   ;Creates a LONG value by concatenating the specified values. 
    mov     dest, wHigh
    shl     dest, 16
    or     dest, wLow
endm

MAKELPARAM  macro   dest:req, wLow:req, wHigh:req   ;Creates a value for use as an lParam parameter in a message. The macro concatenates the specified values. 
    MAKELONG    dest, wLow, wHigh
endm

MAKELRESULT macro   dest:req, wLow:req, wHigh:req   ;Creates a value for use as a return value from a window procedure. The macro concatenates the specified values. 
    MAKELONG    dest, wLow, wHigh
endm

MAKEWORD    macro   dest:req, wLow:req, wHigh:req   ;Creates a WORD value by concatenating the specified values. 
    mov     dest, wHigh
    shl     dest, 8
    or      dest, wLow
endm

MAKEWPARAM  macro   dest:req, wLow:req, wHigh:req   ;Creates a value for use as a wParam parameter in a message. The macro concatenates the specified values.
    MAKELONG    dest, wLow, wHigh
endm

;Window Messages
MN_GETHMENU         equ 01e1h   ;Retrieves the menu handle for the current window.
WM_ERASEBKGND       equ 0014h   ;Sent when the window background must be erased (for example, when a window is resized). The message is sent to prepare an invalidated portion of a window for painting.
WM_GETFONT          equ 0031h   ;Retrieves the font with which the control is currently drawing its text.
WM_GETTEXT          equ 000dh   ;Copies the text that corresponds to a window into a buffer provided by the caller.
WM_GETTEXTLENGTH    equ 000eh   ;Determines the length, in characters, of the text associated with a window.
WM_SETFONT          equ 0030h   ;Sets the font that a control is to use when drawing text.
WM_SETICON          equ 0080h   ;Associates a new large or small icon with a window. The system displays the large icon in the ALT+TAB dialog box, and the small icon in the window caption.
ICON_BIG            equ 1       ;Set the large icon for the window.
ICON_SMALL          equ 0       ;Set the small icon for the window.
WM_SETTEXT          equ 000ch   ;Sets the text of a window.

;Window Notifications
WM_ACTIVATEAPP      equ 001ch   ;Sent when a window belonging to a different application than the active window is about to be activated.
WM_CANCELMODE       equ 001fh   ;Sent to cancel certain modes, such as mouse capture.
WM_CHILDACTIVATE    equ 0022h   ;Sent to a child window when the user clicks the window's title bar or when the window is activated, moved, or sized.
WM_CLOSE            equ 0010h   ;Sent as a signal that a window or an application should terminate.
WM_COMPACTING       equ 0041h   ;Sent to all top-level windows when the system detects more than 12.5 percent of system time over a 30- to 60-second interval is being spent compacting memory. This indicates that system memory is low.
WM_CREATE           equ 0001h   ;Sent when an application requests that a window be created by calling the CreateWindowEx or CreateWindow function. (The message is sent before the function returns.)
WM_DESTROY          equ 0002h   ;Sent when a window is being destroyed. It is sent to the window procedure of the window being destroyed after the window is removed from the screen.
WM_DPICHANGED       equ 02e0h   ;Sent when the effective dots per inch (dpi) for a window has changed.
WM_ENABLE           equ 000ah   ;Sent when an application changes the enabled state of a window.
WM_ENTERSIZEMOVE    equ 0231h   ;Sent one time to a window after it enters the moving or sizing modal loop.
WM_EXITSIZEMOVE     equ 0232h   ;Sent one time to a window, after it has exited the moving or sizing modal loop.
WM_GETICON          equ 007fh   ;Sent to a window to retrieve a handle to the large or small icon associated with a window.
ICON_SMALL2         equ 2       ;Retrieves the small icon provided by the application. If the application does not provide one, the system uses the system-generated icon for that window.
WM_GETMINMAXINFO    equ 0024h   ;Sent to a window when the size or position of the window is about to change.
WM_INPUTLANGCHANGE  equ 0051h   ;Sent to the topmost affected window after an application's input language has been changed.
WM_INPUTLANGCHANGEREQUEST equ 0050h ;Posted to the window with the focus when the user chooses a new input language, either with the hotkey (specified in the Keyboard control panel application) or from the indicator on the system taskbar.
INPUTLANGCHANGE_BACKWARD equ 0004h  ;A hot key was used to choose the previous input locale in the installed list of input locales. This flag cannot be used with the INPUTLANGCHANGE_FORWARD flag.
INPUTLANGCHANGE_FORWARD equ 0002h   ;A hot key was used to choose the next input locale in the installed list of input locales. This flag cannot be used with the INPUTLANGCHANGE_BACKWARD flag.
INPUTLANGCHANGE_SYSCHARSET equ 0001h;The new input locale's keyboard layout can be used with the system character set.
WM_MOVE             equ 0003h   ;Sent after a window has been moved.
WM_MOVING           equ 0216h   ;Sent to a window that the user is moving. By processing this message, an application can monitor the position of the drag rectangle and, if needed, change its position.
WM_NCACTIVATE       equ 0086h   ;Sent to a window when its nonclient area needs to be changed to indicate an active or inactive state.
WM_NCCALCSIZE       equ 0083h   ;Sent when the size and position of a window's client area must be calculated. By processing this message, an application can control the content of the window's client area when the size or position of the window changes.
WM_NCCREATE         equ 0081h   ;Sent prior to the WM_CREATE message when a window is first created.
WM_NCDESTROY        equ 0082h   ;Notifies a window that its nonclient area is being destroyed. The DestroyWindow function sends the WM_NCDESTROY message to the window following the WM_DESTROY message.
WM_NULL             equ 0000h   ;Performs no operation. An application sends the WM_NULL message if it wants to post a message that the recipient window will ignore.
WM_QUERYDRAGICON    equ 0037h   ;Sent to a minimized (iconic) window. The window is about to be dragged by the user but does not have an icon defined for its class. An application can return a handle to an icon or cursor.
WM_QUERYOPEN        equ 0013h   ;Sent to an icon when the user requests that the window be restored to its previous size and position.
WM_QUIT             equ 0012h   ;Indicates a request to terminate an application, and is generated when the application calls the PostQuitMessage function. This message causes the GetMessage function to return zero.
WM_SHOWWINDOW       equ 0018h   ;Sent to a window when the window is about to be hidden or shown.
WM_SIZE             equ 0005h   ;Sent to a window after its size has changed.
SIZE_MAXHIDE        equ 4       ;Message is sent to all pop-up windows when some other window is maximized.
SIZE_MAXIMIZED      equ 2       ;The window has been maximized.
SIZE_MAXSHOW        equ 3       ;Message is sent to all pop-up windows when some other window has been restored to its former size.
SIZE_MINIMIZED      equ 1       ;The window has been minimized.
SIZE_RESTORED       equ 0       ;The window has been resized, but neither the SIZE_MINIMIZED nor SIZE_MAXIMIZED value applies.
WM_SIZING           equ 0214h   ;Sent to a window that the user is resizing. By processing this message, an application can monitor the size and position of the drag rectangle and, if needed, change its size or position.
WMSZ_BOTTOM         equ 6       ;Bottom edge
WMSZ_BOTTOMLEFT     equ 7       ;Bottom-left corner
WMSZ_BOTTOMRIGHT    equ 8       ;Bottom-right corner
WMSZ_LEFT           equ 1       ;Left edge
WMSZ_RIGHT          equ 2       ;Right edge
WMSZ_TOP            equ 3       ;Top edge
WMSZ_TOPLEFT        equ 4       ;Top-left corner
WMSZ_TOPRIGHT       equ 5       ;Top-right corner
WM_STYLECHANGED     equ 007dh   ;Sent to a window after the SetWindowLong function has changed one or more of the window's styles.
GWL_EXSTYLE         equ -20     ;The extended window styles have changed.
GWL_STYLE           equ -16     ;The window styles have changed.
WM_STYLECHANGING    equ 007ch   ;Sent to a window when the SetWindowLong function is about to change one or more of the window's styles.
WM_THEMECHANGED     equ 031ah   ;Broadcast to every window following a theme change event. Examples of theme change events are the activation of a theme, the deactivation of a theme, or a transition from one theme to another.
WM_USERCHANGED      equ 0054h   ;Sent to all windows after the user has logged on or off. When the user logs on or off, the system updates the user-specific settings. The system sends this message immediately after updating the settings.
WM_WINDOWPOSCHANGED equ 0047h   ;Sent to a window whose size, position, or place in the Z order has changed as a result of a call to the SetWindowPos function or another window-management function.
WM_WINDOWPOSCHANGING equ 0046h  ;Sent to a window whose size, position, or place in the Z order is about to change as a result of a call to the SetWindowPos function or another window-management function.

;Window Structures
ALTTABINFO  struct              ;Contains status information for the application-switching (ALT+TAB) window.
    cbSize      dword   ?       ;The size, in bytes, of the structure.
    cItems      sdword  ?       ;The number of items in the window. 
    cColumns    sdword  ?       ;The number of columns in the window. 
    cRows       sdword  ?       ;The number of rows in the window. 
    iColFocus   sdword  ?       ;The column of the item that has the focus. 
    iRowFocus   sdword  ?       ;The row of the item that has the focus
    cxItem      sdword  ?       ;The width of each icon in the application-switching window. 
    cyItem      sdword  ?       ;The height of each icon in the application-switching window. 
    ptStart     POINT   {}      ;The top-left corner of the first icon. 
ALTTABINFO  ends
PALTTABINFO     typedef ptr ALTTABINFO
LPALTTABINFO    typedef ptr ALTTABINFO

CHANGEFILTERSTRUCT  struct      ;Contains extended result information obtained by calling the ChangeWindowMessageFilterEx function. 
    cbSize      dword   ?       ;The size of the structure, in bytes. Must be set to sizeof(CHANGEFILTERSTRUCT), otherwise the function fails with ERROR_INVALID_PARAMETER.
    ExtStatus   dword   ?       ;If the function succeeds, this field contains one of the following values.
CHANGEFILTERSTRUCT  ends
PCHANGEFILTERSTRUCT typedef ptr CHANGEFILTERSTRUCT
MSGFLTINFO_NONE                     equ 0
MSGFLTINFO_ALLOWED_HIGHER           equ 3   ;The message is allowed at a scope higher than the window. Applies to MSGFLT_DISALLOW. 
MSGFLTINFO_ALREADYALLOWED_FORWND    equ 1   ;The message has already been allowed by this window's message filter, and the function thus succeeded with no change to the window's message filter. Applies to MSGFLT_ALLOW. 
MSGFLTINFO_ALREADYDISALLOWED_FORWND equ 2   ;The message has already been blocked by this window's message filter, and the function thus succeeded with no change to the window's message filter. Applies to MSGFLT_DISALLOW. 

CLIENTCREATESTRUCT  struct      ;Contains information about the menu and first multiple-document interface (MDI) child window of an MDI client window. An application passes a pointer to this structure as the lpParam parameter of the CreateWindow function when creating an MDI client window. 
    hWindowMenu     HANDLE  ?   ;A handle to the MDI application's window menu. An MDI application can retrieve this handle from the menu of the MDI frame window by using the GetSubMenu function. 
    idFirstChild    UINT    ?   ;The child window identifier of the first MDI child window created.
CLIENTCREATESTRUCT  ends
LPCLIENTCREATESTRUCT    typedef ptr CLIENTCREATESTRUCT

CREATESTRUCTA   struct              ;Defines the initialization parameters passed to the window procedure of an application. These members are identical to the parameters of the CreateWindowEx function.
    lpCreateParams  LPVOID      ?   ;Contains additional data which may be used to create the window.
    hInstance       HINSTANCE   ?   ;A handle to the module that owns the new window. 
    hMenu           HMENU       ?   ;A handle to the menu to be used by the new window.
    hwndParent      HWND        ?   ;A handle to the parent window, if the window is a child window.
    cy              sdword      ?   ;The height of the new window, in pixels.
    _cx             sdword      ?   ;The width of the new window, in pixels.
    y               sdword      ?   ;The y-coordinate of the upper left corner of the new window. If the new window is a child window, coordinates are relative to the parent window. Otherwise, the coordinates are relative to the screen origin. 
    x               sdword      ?   ;The x-coordinate of the upper left corner of the new window. If the new window is a child window, coordinates are relative to the parent window. Otherwise, the coordinates are relative to the screen origin. 
    style           LONG        ?   ;The style for the new window. For a list of possible values, see Window Styles.
    lpszName        LPCSTR      ?   ;The name of the new window. 
    lpszClass       LPCSTR      ?   ;A pointer to a null-terminated string or an atom that specifies the class name of the new window. 
    dwExStyle       dword       ?   ;The extended window style for the new window. For a list of possible values, see Extended Window Styles.
CREATESTRUCTA   ends
CREATESTRUCTW   struct              ;Defines the initialization parameters passed to the window procedure of an application. These members are identical to the parameters of the CreateWindowEx function.
    lpCreateParams  LPVOID      ?   ;Contains additional data which may be used to create the window.
    hInstance       HINSTANCE   ?   ;A handle to the module that owns the new window. 
    hMenu           HMENU       ?   ;A handle to the menu to be used by the new window.
    hwndParent      HWND        ?   ;A handle to the parent window, if the window is a child window.
    cy              sdword      ?   ;The height of the new window, in pixels.
    _cx             sdword      ?   ;The width of the new window, in pixels.
    y               sdword      ?   ;The y-coordinate of the upper left corner of the new window. If the new window is a child window, coordinates are relative to the parent window. Otherwise, the coordinates are relative to the screen origin. 
    x               sdword      ?   ;The x-coordinate of the upper left corner of the new window. If the new window is a child window, coordinates are relative to the parent window. Otherwise, the coordinates are relative to the screen origin. 
    style           LONG        ?   ;The style for the new window. For a list of possible values, see Window Styles.
    lpszName        LPCWSTR     ?   ;The name of the new window. 
    lpszClass       LPCWSTR     ?   ;A pointer to a null-terminated string or an atom that specifies the class name of the new window. 
    dwExStyle       dword       ?   ;The extended window style for the new window. For a list of possible values, see Extended Window Styles.
CREATESTRUCTW   ends
__AW <CREATESTRUCT>

LPCREATESTRUCT  typedef ptr CREATESTRUCT

GUITHREADINFO   struct          ;Contains information about a GUI thread.
    cbSize          dword   ?   ;The size of this structure, in bytes.
    flags           dword   ?   ;The thread state.
    hwndActive      HWND    ?   ;A handle to the active window within the thread.
    hwndFocus       HWND    ?   ;A handle to the window that has the keyboard focus.
    hwndCapture     HWND    ?   ;A handle to the window that has captured the mouse.
    hwndMenuOwner   HWND    ?   ;A handle to the window that owns any active menus.
    hwndMoveSize    HWND    ?   ;A handle to the window in a move or size loop.
    hwndCaret       HWND    ?   ;A handle to the window that is displaying the caret.
    rcCaret         RECT    {}  ;The caret's bounding rectangle, in client coordinates, relative to the window specified by the hwndCaret member.
GUITHREADINFO   ends
PGUITHREADINFO  typedef ptr GUITHREADINFO
LPGUITHREADINFO typedef ptr GUITHREADINFO
GUI_CARETBLINKING   equ 00000001h   ;The caret's blink state. This bit is set if the caret is visible.
GUI_INMENUMODE      equ 00000004h   ;The thread's menu state. This bit is set if the thread is in menu mode.
GUI_INMOVESIZE      equ 00000002h   ;The thread's move state. This bit is set if the thread is in a move or size loop.
GUI_POPUPMENUMODE   equ 00000010h   ;The thread's pop-up menu state. This bit is set if the thread has an active pop-up menu.
GUI_SYSTEMMENUMODE  equ 00000008h   ;The thread's system menu state. This bit is set if the thread is in a system menu mode.

MINMAXINFO  struct              ;Contains information about a window's maximized size and position and its minimum and maximum tracking size. 
    ptReserved      POINT   {}  ;Reserved; do not use.
    ptMaxSize       POINT   {}  ;The maximized width (x member) and the maximized height (y member) of the window. For top-level windows, this value is based on the width of the primary monitor.
    ptMaxPosition   POINT   {}  ;The position of the left side of the maximized window (x member) and the position of the top of the maximized window (y member). For top-level windows, this value is based on the position of the primary monitor.
    ptMinTrackSize  POINT   {}  ;The minimum tracking width (x member) and the minimum tracking height (y member) of the window.
    ptMaxTrackSize  POINT   {}  ;The maximum tracking width (x member) and the maximum tracking height (y member) of the window.
MINMAXINFO  ends
PMINMAXINFO     typedef ptr MINMAXINFO
LPMINMAXINFO    typedef ptr MINMAXINFO

WINDOWPOS   struct              ;Contains information about the size and position of a window. 
    hwnd            HWND    ?   ;A handle to the window. 
    hwndInsertAfter HWND    ?   ;The position of the window in Z order (front-to-back position). This member can be a handle to the window behind which this window is placed, or can be one of the special values listed with the SetWindowPos function. 
    x               sdword  ?   ;The position of the left edge of the window. 
    y               sdword  ?   ;The position of the top edge of the window. 
    _cx             sdword  ?   ;The window width, in pixels. 
    cy              sdword  ?   ;The window height, in pixels. 
    flags           UINT    ?   ;The window position.
WINDOWPOS   ends
LPWINDOWPOS typedef ptr WINDOWPOS
PWINDOWPOS  typedef ptr WINDOWPOS
SWP_ASYNCWINDOWPOS  equ 4000h
SWP_DEFERERASE      equ 2000h
SWP_DRAWFRAME       equ 0020h   ;Draws a frame (defined in the window's class description) around the window. Same as the SWP_FRAMECHANGED flag.
SWP_FRAMECHANGED    equ 0020h   ;Sends a WM_NCCALCSIZE message to the window, even if the window's size is not being changed. If this flag is not specified, WM_NCCALCSIZE is sent only when the window's size is being changed.
SWP_HIDEWINDOW      equ 0080h   ;Hides the window.
SWP_NOACTIVATE      equ 0010h   ;Does not activate the window. If this flag is not set, the window is activated and moved to the top of either the topmost or non-topmost group (depending on the setting of the hwndInsertAfter member).
SWP_NOCOPYBITS      equ 0010h   ;Discards the entire contents of the client area. If this flag is not specified, the valid contents of the client area are saved and copied back into the client area after the window is sized or repositioned.
SWP_NOMOVE          equ 0002h   ;Retains the current position (ignores the x and y members).
SWP_NOOWNERZORDER   equ 0200h   ;Does not change the owner window's position in the Z order.
SWP_NOREDRAW        equ 0008h   ;Does not redraw changes. If this flag is set, no repainting of any kind occurs.
SWP_NOREPOSITION    equ 0200h   ;Does not change the owner window's position in the Z order. Same as the SWP_NOOWNERZORDER flag.
SWP_NOSENDCHANGING  equ 0400h   ;Prevents the window from receiving the WM_WINDOWPOSCHANGING message.
SWP_NOSIZE          equ 0001h   ;Retains the current size (ignores the _cx and cy members).
SWP_NOZORDER        equ 0004h   ;Retains the current Z order (ignores the hwndInsertAfter member).
SWP_SHOWWINDOW      equ 0040h   ;Displays the window.

NCCALCSIZE_PARAMS   struct          ;Contains information that an application can use while processing the WM_NCCALCSIZE message to calculate the size, position, and valid contents of the client area of a window. 
    rgrc    RECT        3 dup({})   ;An array of rectangles. The meaning of the array of rectangles changes during the processing of the WM_NCCALCSIZE message.
    lppos   PWINDOWPOS  ?           ;A pointer to a WINDOWPOS structure that contains the size and position values specified in the operation that moved or resized the window.
NCCALCSIZE_PARAMS   ends
LPNCCALCSIZE_PARAMS typedef ptr NCCALCSIZE_PARAMS

STYLESTRUCT struct          ;Contains the styles for a window. 
    styleOld    dword   ?   ;The previous styles for a window.
    styleNew    dword   ?   ;The new styles for a window.
STYLESTRUCT ends
LPSTYLESTRUCT   typedef ptr STYLESTRUCT

TITLEBARINFO    struct              ;Contains title bar information.
    cbSize      dword   ?           ;The size, in bytes, of the structure.
    rcTitleBar  RECT    {}          ;The coordinates of the title bar. These coordinates include all title-bar elements except the window menu. 
    rgstate     dword   6 dup(?)    ;An array that receives a value for each element of the title bar.
TITLEBARINFO    ends
PTITLEBARINFO   typedef ptr TITLEBARINFO
LPTITLEBARINFO  typedef ptr TITLEBARINFO
STATE_SYSTEM_FOCUSABLE      equ 00100000h   ;The element can accept the focus.
STATE_SYSTEM_INVISIBLE      equ 00008000h   ;The element is invisible.
STATE_SYSTEM_OFFSCREEN      equ 00010000h   ;The element has no visible representation.
STATE_SYSTEM_UNAVAILABLE    equ 00000001h   ;The element is unavailable.
STATE_SYSTEM_PRESSED        equ 00000008h   ;The element is in the pressed state.

TITLEBARINFOEX  struct              ;Expands on the information described in the TITLEBARINFO structure by including the coordinates of each element of the title bar.
    cbSize      dword   ?           ;The size of the structure, in bytes.
    rcTitleBar  RECT    {}          ;The bounding rectangle of the title bar. The rectangle is expressed in screen coordinates and includes all titlebar elements except the window menu.
    rgstate     dword   6 dup(?)    ;An array that receives a DWORD value for each element of the title bar.
    rgrect      RECT    6 dup({})   ;An array that receives a structure for each element of the title bar. The structures are expressed in screen coordinates.
TITLEBARINFOEX  ends
PTITLEBARINFOEX     typedef ptr TITLEBARINFOEX
LPTITLEBARINFOEX    typedef ptr TITLEBARINFOEX

UPDATELAYEREDWINDOWINFO struct          ;Used by UpdateLayeredWindowIndirect to provide position, size, shape, content, and translucency information for a layered window.
    cbSize      dword               ?   ;The size, in bytes, of this structure.
    hdcDst      HDC                 ?   ;A handle to a DC for the screen. This handle is obtained by specifying NULL in this member when calling UpdateLayeredWindowIndirect. The handle is used for palette color matching when the window contents are updated.
    pptDst      PPOINT              ?   ;The new screen position of the layered window. If the new position is unchanged from the current position, pptDst can be NULL.
    psize       PSIZE               ?   ;The new size of the layered window. If the size of the window will not change, this parameter can be NULL. If hdcSrc is NULL, psize must be NULL.
    hdcSrc      HDC                 ?   ;A handle to the DC for the surface that defines the layered window. This handle can be obtained by calling the CreateCompatibleDC function. If the shape and visual context of the window will not change, hdcSrc can be NULL.
    pptSrc      PPOINT              ?   ;The location of the layer in the device context. If hdcSrc is NULL, pptSrc should be NULL. 
    crKey       COLORREF            ?   ;The color key to be used when composing the layered window. To generate a COLORREF, use the RGB macro.
    pblend      PBLENDFUNCTION      ?   ;The transparency value to be used when composing the layered window.
    dwFlags     dword               ?
    prcDirty    PRECT               ?   ;The area to be updated. This parameter can be NULL. If it is non-NULL, only the area in this rectangle is updated from the source DC.
UPDATELAYEREDWINDOWINFO ends
PUPDATELAYEREDWINDOWINFO    typedef ptr UPDATELAYEREDWINDOWINFO
ULW_ALPHA       equ 00000002h   ;Use pblend as the blend function. If the display mode is 256 colors or less, the effect of this value is the same as the effect of ULW_OPAQUE.
ULW_COLORKEY    equ 00000001h   ;Use crKey as the transparency color. 
ULW_OPAQUE      equ 00000004h   ;Draw an opaque layered window. 
ULW_EX_NORESIZE equ 00000008h   ;Force the UpdateLayeredWindowIndirect function to fail if the current window size does not match the size specified in the psize. 

WINDOWINFO  struct              ;Contains window information.
    cbSize          dword   ?   ;The size of the structure, in bytes.
    rcWindow        RECT    {}  ;The coordinates of the window.
    rcClient        RECT    {}  ;The coordinates of the client area.
    dwStyle         dword   ?   ;The window styles. For a table of window styles, see Window Styles.
    dwExStyle       dword   ?   ;The extended window styles. For a table of extended window styles, see Extended Window Styles.
    dwWindowStatus  dword   ?   ;The window status. If this member is WS_ACTIVECAPTION (0x0001), the window is active. Otherwise, this member is zero.
    cxWindowBorders UINT    ?   ;The width of the window border, in pixels.
    cyWindowBorders UINT    ?   ;The height of the window border, in pixels. 
    atomWindowType  ATOM    ?   ;The window class atom (see RegisterClass).
    wCreatorVersion word    ?   ;The Windows version of the application that created the window.
WINDOWINFO  ends
PWINDOWINFO     typedef ptr WINDOWINFO
LPWINDOWINFO    typedef ptr WINDOWINFO
WS_ACTIVECAPTION    equ 0001h

WINDOWPLACEMENT struct              ;Contains information about the placement of a window on the screen.
    _length             UINT    ?   ;The length of the structure, in bytes.
    flags               UINT    ?   ;The flags that control the position of the minimized window and the method by which the window is restored.
    showCmd             UINT    ?   ;The current show state of the window.
    ptMinPosition       POINT   {}  ;The coordinates of the window's upper-left corner when the window is minimized.
    ptMaxPosition       POINT   {}  ;The coordinates of the window's upper-left corner when the window is maximized.
    rcNormalPosition    RECT    {}  ;The window's coordinates when the window is in the restored position. 
WINDOWPLACEMENT ends
PWINDOWPLACEMENT    typedef ptr WINDOWPLACEMENT
LPWINDOWPLACEMENT   typedef ptr WINDOWPLACEMENT
WPF_ASYNCWINDOWPLACEMENT    equ 0004h   ;If the calling thread and the thread that owns the window are attached to different input queues, the system posts the request to the thread that owns the window.
WPF_RESTORETOMAXIMIZED      equ 0002h   ;The restored window will be maximized, regardless of whether it was maximized before it was minimized.
WPF_SETMINPOSITION          equ 0001h   ;The coordinates of the minimized window may be specified. 
SW_HIDE             equ 0   ;Hides the window and activates another window.
SW_MAXIMIZE         equ 3   ;Maximizes the specified window.
SW_MINIMIZE         equ 6   ;Minimizes the specified window and activates the next top-level window in the z-order.
SW_RESTORE          equ 9   ;Activates and displays the window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when restoring a minimized window.
SW_SHOW             equ 5   ;Activates the window and displays it in its current size and position. 
SW_SHOWMAXIMIZED    equ 3   ;Activates the window and displays it as a maximized window.
SW_SHOWMINIMIZED    equ 2   ;Activates the window and displays it as a minimized window.
SW_SHOWMINNOACTIVE  equ 7   ;Displays the window as a minimized window. This value is similar to SW_SHOWMINIMIZED, except the window is not activated.
SW_SHOWNA           equ 8   ;Displays the window in its current size and position. This value is similar to SW_SHOW, except the window is not activated.
SW_SHOWNOACTIVATE   equ 4   ;Displays a window in its most recent size and position. This value is similar to SW_SHOWNORMAL, except the window is not activated.
SW_SHOWNORMAL       equ 1   ;Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.

;Window Functions
AdjustWindowRect    proto WINAPI,   ;Calculates the required size of the window rectangle, based on the desired client-rectangle size.
    lpRect:     LPRECT,             ;A pointer to a RECT structure that contains the coordinates of the top-left and bottom-right corners of the desired client area.
    dwStyle:    dword,              ;The window style of the window whose required size is to be calculated.
    bMenu:      BOOL                ;Indicates whether the window has a menu.
;ret BOOL

AdjustWindowRectEx  proto WINAPI,   ;Calculates the required size of the window rectangle, based on the desired size of the client rectangle.
    lpRect:     LPRECT,             ;A pointer to a RECT structure.
    dwStyle:    dword,              ;The window style of the window whose required size is to be calculated.
    bMenu:      BOOL,               ;Indicates whether the window has a menu.
    dwExStyle:  dword               ;The extended window style of the window.
;ret BOOL

AllowSetForegroundWindow    proto WINAPI,
    dwProcessId:dword
;ret BOOL

AnimateWindow   proto WINAPI,
    hwnd:   HWND,
    dwTime: dword,
    dwFlags:dword
;ret BOOL
AW_ACTIVATE     equ 00020000h
AW_BLEND        equ 00080000h
AW_CENTER       equ 00000010h
AW_HIDE         equ 00010000h
AW_HOR_POSITIVE equ 00000001h
AW_HOR_NEGATIVE equ 00000002h
AW_SLIDE        equ 00040000h
AW_VER_POSITIVE equ 00000004h
AW_VER_NEGATIVE equ 00000008h

AnyPopup    proto WINAPI    ;ret BOOL

ArrangeIconicWindows    proto WINAPI,
    hWnd:HWND
;ret UINT

BeginDeferWindowPos proto WINAPI,
    nNumWindows:sdword
;ret HDWP

BringWindowToTop    proto WINAPI,
    hWnd:HWND
;ret BOOL

CalculatePopupWindowPosition    proto WINAPI,
    anchorPoint:            PPOINT,
    windowSize:             PSIZE,
    flags:                  UINT,
    excludeRect:            PRECT,
    popupWindowPosition:    PRECT
;ret BOOL
TPM_CENTERALIGN     equ 0004h
TPM_LEFTALIGN       equ 0000h
TPM_RIGHTALIGN      equ 0008h
TPM_BOTTOMALIGN     equ 0020h
TPM_TOPALIGN        equ 0000h
TPM_VCENTERALIGN    equ 0010h
TPM_HORIZONTAL      equ 0000h
TPM_VERTICAL        equ 0040h
TPM_WORKAREA        equ 10000h

CascadeWindows  proto WINAPI,
    hwndParent: HWND,
    wHow:       UINT,
    lpRect:     LPRECT,
    cKids:      UINT,
    lpKids:     ptr HWND
;ret word
MDITILE_SKIPDISABLED    equ 0002h
MDITILE_ZORDER          equ 0004h

ChangeWindowMessageFilter   proto WINAPI,
    message:    UINT,
    dwFlag:     dword
;ret BOOL
MSGFLT_ADD      equ 1
MSGFLT_REMOVE   equ 2

ChangeWindowMessageFilterEx proto WINAPI,
    hWnd:               HWND,
    message:            UINT,
    action:             dword,
    pChangeFilterStruct:PCHANGEFILTERSTRUCT
;ret BOOL
MSGFLT_RESET    equ 0

ChildWindowFromPoint    proto WINAPI,
    hWndParent: HWND,
    Point:      POINT
;ret HWND

ChildWindowFromPointEx  proto WINAPI,
    hwndParent: HWND,
    pt:         POINT,
    uFlags:     UINT
;ret HWND
CWP_ALL             equ 0000h
CWP_SKIPDISABLED    equ 0002h
CWP_SKIPINVISIBLE   equ 0001h
CWP_SKIPTRANSPARENT equ 0004h

CloseWindow proto WINAPI,
    hWnd:   HWND
;ret BOOL

CreateWindowExA proto WINAPI,
    dwExStyle:      dword,
    lpClassName:    LPCSTR,
    lpWindowName:   LPCSTR,
    dwStyle:        dword,
    x:              sdword,
    y:              sdword,
    nWidth:         sdword,
    nHeight:        sdword,
    hWndParent:     HWND,
    hMenu:          HMENU,
    hInstance:      HINSTANCE,
    lpParam:        LPVOID
;ret HWND

CreateWindowExW proto WINAPI,
    dwExStyle:      dword,
    lpClassName:    LPCWSTR,
    lpWindowName:   LPCWSTR,
    dwStyle:        dword,
    x:              sdword,
    y:              sdword,
    nWidth:         sdword,
    nHeight:        sdword,
    hWndParent:     HWND,
    hMenu:          HMENU,
    hInstance:      HINSTANCE,
    lpParam:        LPVOID
;ret HWND
__AW <CreateWindowEx>

CW_USEDEFAULT   equ 80000000h

CreateWindowA   macro   lpClassName:req, lpWindowName:req, dwStyle:req, x:req, y:req, nWidth:req, nHeight:req, hWndParent:req, hMenu:req, hInstance:req, lpParam:req
    invoke CreateWindowExA, 0, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam
endm

CreateWindowW   macro   lpClassName:req, lpWindowName:req, dwStyle:req, x:req, y:req, nWidth:req, nHeight:req, hWndParent:req, hMenu:req, hInstance:req, lpParam:req
    invoke CreateWindowExW, 0, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam
endm

;CreateWindowA   proto WINAPI,
;    lpClassName:    LPCSTR,
;    lpWindowName:   LPCSTR,
;    dwStyle:        dword,
;    x:              sdword,
;    y:              sdword,
;    nWidth:         sdword,
;    nHeight:        sdword,
;    hWndParent:     HWND,
;    hMenu:          HMENU,
;    hInstance:      HINSTANCE,
;    lpParam:        LPVOID
;;ret HWND
;
;CreateWindowW   proto WINAPI,
;    lpClassName:    LPCWSTR,
;    lpWindowName:   LPCWSTR,
;    dwStyle:        dword,
;    x:              sdword,
;    y:              sdword,
;    nWidth:         sdword,
;    nHeight:        sdword,
;    hWndParent:     HWND,
;    hMenu:          HMENU,
;    hInstance:      HINSTANCE,
;    lpParam:        LPVOID
;;ret HWND
;
__AW <CreateWindow>

DeferWindowPos  proto WINAPI,
    hWinPosInfo:    HDWP,
    hWnd:           HWND,
    hWndInsertAfter:HWND,
    x:              sdword,
    y:              sdword,
    _cx:            sdword,
    cy:             sdword,
    uFlags:         UINT
;ret HDWP
HWND_BOTTOM     equ 1
HWND_NOTOPMOST  equ -2
HWND_TOP        equ 0
HWND_TOPMOST    equ -1

DeregisterShellHookWindow   proto WINAPI,
    hWnd:   HWND
;ret BOOL

DestroyWindow   proto WINAPI,
    hWnd:   HWND
;ret BOOL

EndDeferWindowPos   proto WINAPI,
    hWinPosInfo:    HDWP
;ret BOOL

EndTask proto WINAPI,
    hWnd:       HWND,
    fShutDown:  BOOL,
    fForce:     BOOL
;ret BOOL

EnumChildProc_t typedef proto CALLBACK,
    hwnd:   HWND,
    lParam: LPARAM
;ret BOOL
WNDENUMPROC     typedef ptr EnumChildProc_t

EnumChildWindows    proto WINAPI,
    hWndParent: HWND,
    lpEnumFunc: WNDENUMPROC,
    lParam:     LPARAM
;ret BOOL

EnumThreadWindows   proto WINAPI,
    dwThreadId: dword,
    lpfn:       WNDENUMPROC,
    lParam:     LPARAM
;ret BOOL

EnumWindows proto WINAPI,
    lpEnumFunc: WNDENUMPROC,
    lParam:     LPARAM
;ret BOOL

FindWindowA proto WINAPI,
    lpClassName:    LPCSTR,
    lpWindowName:   LPCSTR
;ret HWND

FindWindowW proto WINAPI,
    lpClassName:    LPCWSTR,
    lpWindowName:   LPCWSTR
;ret HWND
__AW <FindWindow>

FindWindowExA   proto WINAPI,
    hwndParent:     HWND,
    hwndChildAfter: HWND,
    lpszClass:      LPCSTR,
    lpszWindow:     LPCSTR
;ret HWND

FindWindowExW   proto WINAPI,
    hwndParent:     HWND,
    hwndChildAfter: HWND,
    lpszClass:      LPCWSTR,
    lpszWindow:     LPCWSTR
;ret HWND
__AW <FindWindowEx>

GetAltTabInfoA  proto WINAPI,
    hwnd:       HWND,
    iItem:      sdword,
    pati:       PALTTABINFO,
    pszItemText:LPCSTR,
    cchItemText:UINT
;ret BOOL

GetAltTabInfoW  proto WINAPI,
    hwnd:       HWND,
    iItem:      sdword,
    pati:       PALTTABINFO,
    pszItemText:LPCWSTR,
    cchItemText:UINT
;ret BOOL
__AW <GetAltTabInfo>

GetAncestor proto WINAPI,
    hwnd:   HWND,
    gaFlags:UINT
;ret HWND
GA_PARENT       equ 1
GA_ROOT         equ 2
GA_ROOTOWNER    equ 3

GetClientRect   proto WINAPI,
    hWnd:   HWND,
    lpRect: LPRECT
;ret BOOL

GetDesktopWindow    proto WINAPI    ;ret HWND
GetForegroundWindow proto WINAPI    ;ret HWND

GetGUITreadInfo proto WINAPI,
    idThread:   dword,
    lpgui:      LPGUITHREADINFO
;ret BOOL

GetLastActivePopup  proto WINAPI,
    hWnd:   HWND
;ret HWND

GetLayeredWindowAttributes  proto WINAPI,
    hwnd:       HWND,
    pcrKey:     ptr COLORREF,
    pbAlpha:    ptr byte,
    pdwFlags:   ptr dword
;ret BOOL
LWA_ALPHA       equ 00000002h
LWA_COLORKEY    equ 00000001h

GetNextWindow   proto WINAPI,
    hWnd:   HWND,
    wCmd:   UINT
;ret HWND   ;TODO: reimplement as a macro to GetWindow?

GetParent   proto WINAPI,
    hWnd:   HWND
;ret HWND

GetProcessDefaultLayout proto WINAPI,
    pdwDefaultLayout:   ptr dword
;ret BOOL

GetShellWindow  proto WINAPI    ;ret HWND

GetSysColor proto WINAPI,
    nIndex: sdword
;ret dword
COLOR_3DDKSHADOW                equ 21
COLOR_3DFACE                    equ 15
COLOR_3DHIGHLIGHT               equ 20
COLOR_3DHILIGHT                 equ 20
COLOR_3DLIGHT                   equ 22
COLOR_3DSHADOW                  equ 16
COLOR_ACTIVEBORDER              equ 10
COLOR_ACTIVECAPTION             equ 2
COLOR_APPWORKSPACE              equ 12
COLOR_BACKGROUND                equ 1
COLOR_BTNFACE                   equ 15
COLOR_BTNHIGHLIGHT              equ 20
COLOR_BTNHILIGHT                equ 20
COLOR_BTNSHADOW                 equ 16
COLOR_BTNTEXT                   equ 18
COLOR_CAPTIONTEXT               equ 9
COLOR_DESKTOP                   equ 1
COLOR_GRADIENTACTIVECAPTION     equ 27
COLOR_GRADIENTINACTIVECAPTION   equ 28
COLOR_GRAYTEST                  equ 17
COLOR_HIGHLIGHT                 equ 13
COLOR_HIGHLIGHTTEXT             equ 14
COLOR_HOTLIGHT                  equ 26
COLOR_INACTIVEBORDER            equ 11
COLOR_INACTIVECAPTION           equ 3
COLOR_INACTIVECAPTIONTEXT       equ 19
COLOR_INFOBK                    equ 24
COLOR_INFOTEXT                  equ 23
COLOR_MENU                      equ 4
COLOR_MENUHILIGHT               equ 29
COLOR_MENUBAR                   equ 30
COLOR_MENUTEXT                  equ 7
COLOR_SCROLLBAR                 equ 0
COLOR_WINDOW                    equ 5
COLOR_WINDOWFRAME               equ 6
COLOR_WINDOWTEST                equ 8

GetTitleBarInfo proto WINAPI,
    hwnd:   HWND,
    pti:    PTITLEBARINFO
;ret BOOL

GetTopWindow    proto WINAPI,
    hWnd:   HWND
;ret HWND

GetWindow       proto WINAPI,
    hWnd:   HWND,
    uCmd:   UINT
;ret HWND
GW_CHILD        equ 5
GW_ENABLEDPOPUP equ 6
GW_HWNDFIRST    equ 0
GW_HWNDLAST     equ 1
GW_HWNDNEXT     equ 2
GW_HWNDPREV     equ 3
GW_OWNER        equ 4

GetWindowDisplayAffinity    proto WINAPI,
    hWnd:       HWND,
    dwAffinity: ptr dword
;ret BOOL

GetWindowInfo   proto WINAPI,
    hwnd:   HWND,
    pwi:    PWINDOWINFO
;ret BOOL

GetWindowModuleFileNameA    proto WINAPI,
    hwnd:           HWND,
    lpszFileName:   LPSTR,
    cchFileNameMax: UINT
;ret UINT

GetWindowModuleFileNameW    proto WINAPI,
    hwnd:           HWND,
    lpszFileName:   LPWSTR,
    cchFileNameMax: UINT
;ret UINT
__AW <GetWindowModuleFileName>

GetWindowPlacement  proto WINAPI,
    hWnd:       HWND,
    lpwndpl:    LPWINDOWPLACEMENT
;ret BOOL

GetWindowRect   proto WINAPI,
    hWnd:   HWND,
    lpRect: LPRECT
;ret BOOL

GetWindowTextA  proto WINAPI,
    hWnd:       HWND,
    lpString:   LPSTR,
    nMaxCount:  sdword
;ret sdword

GetWindowTextW  proto WINAPI,
    hWnd:       HWND,
    lpString:   LPWSTR,
    nMaxCount:  sdword
;ret sdword
__AW <GetWindowText>

GetWindowTextLength proto WINAPI,
    hWnd:   HWND
;ret sdword

GetWindowThreadProcessId    proto WINAPI,
    hWnd:           HWND,
    lpdwProcessId:  LPDWORD
;ret dword

InternalGetWindowText   proto WINAPI,
    hWnd:       HWND,
    lpString:   LPWSTR,
    nMaxCount:  sdword
;ret sdword

IsChild proto WINAPI,
    hWndParent: HWND,
    hWnd:       HWND
;ret BOOL

IsGUIThread proto WINAPI,
    bConvert:   BOOL
;ret BOOL

IsHungAppWindow proto WINAPI,
    hWnd:   HWND
;ret BOOL

IsIconic    proto WINAPI,
    hWnd:   HWND
;ret BOOL

IsProcessDPIAware   proto WINAPI    ;ret BOOL

IsWindow    proto WINAPI,
    hWnd:   HWND
;ret BOOL

IsWindowUnicode proto WINAPI,
    hWnd:   HWND
;ret BOOL

IsWindowVisible proto WINAPI,
    hWnd:   HWND
;ret BOOL

IsZoomed    proto WINAPI,
    hWnd:   HWND
;ret BOOL

LockSetForegroundWindow proto WINAPI,
    uLockCode:  UINT
;ret BOOL
LSFW_LOCK   equ 1
LSFW_UNLOCK equ 2

LogicalToPhysicalPoint  proto WINAPI,
    hWnd:   HWND,
    lpPoint:LPPOINT
;ret BOOL

MoveWindow  proto WINAPI,
    hWnd:       HWND,
    X:          sdword,
    Y:          sdword,
    nWidth:     sdword,
    nHeight:    sdword,
    bRepaint:   BOOL
;ret BOOL

OpenIcon    proto WINAPI,
    hWnd:   HWND
;ret BOOL

PhysicalToLogicalPoint  proto WINAPI,
    hWnd:       HWND,
    lpPoint:    LPPOINT
;ret BOOL

RealChildWindowFromPoint    proto WINAPI,
    hwndParent:             HWND,
    prParentClientCoords:   POINT
;ret BOOL

RealGetWindowClassW proto WINAPI,
    hwnd:   HWND,
    pszType:LPWSTR,
    cchType:UINT
;ret UINT
ifdef   UNICODE
    RealGetWindowClass  textequ <RealGetWindowClassW>
endif

RegisterShellHookWindow proto WINAPI,
    hWnd:   HWND
;ret BOOL

SetForegroundWindow proto WINAPI,
    hWnd:   HWND
;ret BOOL

SetLayeredWindowAttributes  proto WINAPI,
    hwnd:   HWND,
    crKey:  COLORREF,
    bAlpha: byte,
    dwFlags:dword
;ret BOOL

SetParent   proto WINAPI,
    hWndChild:      HWND,
    hWndNewParent:  HWND
;ret HWND

SetProcessDefaultLayout proto WINAPI,
    dwDefaultLayout:    dword
;ret BOOL
LAYOUT_RTL  equ 00000001h

SetProcessDPIAware  proto WINAPI    ;ret BOOL

SetSysColors    proto WINAPI,
    cElements:      sdword,
    lpaElements:    ptr sdword,
    lpaRgbValues:   ptr COLORREF
;ret BOOL
    
SetWindowDisplayAffinity    proto WINAPI,
    hWnd:       HWND,
    dwAffinity: dword
;ret BOOL

SetWindowFeedbackSettings   proto WINAPI,
    hwnd:           HWND,
    feedback:       FEEDBACK_TYPE,
    flags:          dword,
    _size:          UINT32,
    configuration:  ptr VOID
;ret BOOL
GWFS_INCLUDE_ANCESTORS  equ 00000001h

SetWindowPlacement  proto WINAPI,
    hWnd:   HWND,
    lpwndpl:LPWINDOWPLACEMENT
;ret BOOL

SetWindowPos    proto WINAPI,
    hWnd:           HWND,
    hWndInsertAfter:HWND,
    X:              sdword,
    Y:              sdword,
    _cx:            sdword,
    cy:             sdword,
    uFlags:         UINT
;ret BOOL

SetWindowTextA  proto WINAPI,
    hWnd:       HWND,
    lpString:   LPCSTR
;ret BOOL

SetWindowTextW  proto WINAPI,
    hWnd:       HWND,
    lpString:   LPCWSTR
;ret BOOL
__AW <SetWindowText>

ShowOwnedPopups proto WINAPI,
    hWnd:   HWND,
    fShow:  BOOL
;ret BOOL

ShowWindow  proto WINAPI,
    hWnd:       HWND,
    nCmdShow:   sdword
;ret BOOL
SW_FORCEMINIMIZE    equ 11
SW_HIDE             equ 0
SW_MAXIMIZE         equ 3
SW_MINIMIZE         equ 6
SW_RESTORE          equ 9
SW_SHOW             equ 5
SW_SHOWDEFAULT      equ 10
SW_SHOWMAXIMIZED    equ 3
SW_SHOWMINIMIZED    equ 2
SW_SHOWMINNOACTIVE  equ 7
SW_SHOWNA           equ 8
SW_SHOWNOACTIVATE   equ 4
SW_SHOWNORMAL       equ 1

ShowWindowAsync proto WINAPI,
    hWnd:       HWND,
    nCmdShow:   sdword
;ret BOOL

SoundSentry proto WINAPI    ;ret BOOL

SwitchToThisWindow  proto WINAPI,
    hWnd:   HWND,
    fAltTab:BOOL
;ret VOID

TileWindows proto WINAPI,
    hwndParent: HWND,
    wHow:       UINT,
    lpRect:     LPRECT,
    cKids:      UINT,
    lpKids:     ptr HWND
;ret WORD
MDITILE_HORIZONTAL  equ 0001h
MDITILE_VERTICAL    equ 0000h

UpdateLayeredWindow proto WINAPI,
    hwnd:       HWND,
    hdcDst:     HDC,
    pptDst:     PPOINT,
    psize:      PSIZE,
    hdcSrc:     HDC,
    pptSrc:     PPOINT,
    crKey:      COLORREF,
    pblend:     ptr BLENDFUNCTION,
    dwFlags:    dword
;ret BOOL

UpdateLayeredWindowIndirect proto WINAPI,
    hwnd:       HWND,
    pULWInfo:   PUPDATELAYEREDWINDOWINFO
;ret BOOL

WindowFromPhysicalPoint proto WINAPI,
    Point:  POINT
;ret HWND

WindowFromPoint proto WINAPI,
    Point:  POINT
;ret HWND

WinMain_t   typedef proto CALLBACK,
    hInstance:      HINSTANCE,
    hPrevInstance:  HINSTANCE,
    lpCmdLine:      LPSTR,
    nCmdShow:       sdword
;ret sdword

;Window Classes
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms632596.aspx>
;A window class is a set of attributes that the system uses as a template to create a window. Every window is a member of a window class. All window classes are process specific.

WindowProc_t    typedef proto CALLBACK,
    hwnd:   HWND,
    uMsg:   UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret LRESULT
WNDPROC     typedef ptr WindowProc_t

;Window Class Structures
WNDCLASS    struct
    style           UINT        ?
    lpfnWndProc     WNDPROC     ?
    cbClsextra      sdword      ?
    cbWndExtra      sdword      ?
    hInstance       HINSTANCE   ?
    hIcon           HICON       ?
    hCursor         HCURSOR     ?
    hbrBackground   HBRUSH      ?
    lpszMenuName    LPCTSTR     ?
    lpszClassName   LPCTSTR     ?
WNDCLASS    ends
PWNDCLASS   typedef ptr WNDCLASS
LPWNDCLASS  typedef ptr WNDCLASS

WNDCLASSEX  struct
    cbSize          UINT        ?
    style           UINT        ?
    lpfnWndProc     WNDPROC     ?
    cbClsExtra      sdword      ?
    cbWndExtra      sdword      ?
    hInstance       HINSTANCE   ?
    hIcon           HICON       ?
    hCursor         HCURSOR     ?
    hbrBackground   HBRUSH      ?
    lpszMenuName    LPCTSTR     ?
    lpszClassName   LPCTSTR     ?
    hIconSm         HICON       ?
WNDCLASSEX  ends
PWNDCLASSEX     typedef ptr WNDCLASSEX
LPWNDCLASSEX    typedef ptr WNDCLASSEX

;Window Class Functions
GetClassInfoA   proto WINAPI,
    hInstance:      HINSTANCE,
    lpClassName:    LPCSTR,
    lpWndClass:     LPWNDCLASS
;ret BOOL

GetClassInfoW   proto WINAPI,
    hInstance:      HINSTANCE,
    lpClassName:    LPCWSTR,
    lpWndClass:     LPWNDCLASS
;ret BOOL
__AW <GetClassInfo>

GetClassInfoExA proto WINAPI,
    hinst:      HINSTANCE,
    lpszClass:  LPCSTR,
    lpwcx:      LPWNDCLASSEX
;ret BOOL

GetClassInfoExW proto WINAPI,
    hinst:      HINSTANCE,
    lpszClass:  LPCWSTR,
    lpwcx:      LPWNDCLASSEX
;ret BOOL
__AW <GetClassInfoEx>

GetClassLongA   proto WINAPI,
    hWnd:   HWND,
    nIndex: sdword
;ret dword

GetClassLongW   proto WINAPI,
    hWnd:   HWND,
    nIndex: sdword
;ret dword
__AW <GetClassLong>

GCW_ATOM            equ -32
GCL_CBCLSEXTRA      equ -20
GCL_CBWNDEXTRA      equ -18
GCL_HBRBACKGROUND   equ -10
GCL_HCURSOR         equ -12
GCL_HICON           equ -14
GCL_HICONSM         equ -34
GCL_HMODULE         equ -16
GCL_MENUNAME        equ -8
GCL_STYLE           equ -26
GCL_WNDPROC         equ -24

;Possibly only available on Win64:
GetClassLongPtr     equ GetClassLong
;GetClassLongPtrA    proto WINAPI,
;    hWnd:   HWND,
;    nIndex: sdword
;;ret ULONG_PTR
;
;GetClassLongPtrW    proto WINAPI,
;    hWnd:   HWND,
;    nIndex: sdword
;;ret ULONG_PTR
;
;__AW <GetClassLongPtr>

GCLP_HBRBACKGROUND  equ -10
GCLP_HCURSOR        equ -12
GCLP_HICON          equ -14
GCLP_HICONSM        equ -34
GCLP_MENUNAME       equ -8
GCLP_WNDPROC        equ -24

GetClassNameA   proto WINAPI,
    hWnd:       HWND,
    lpClassName:LPSTR,
    nMaxCount:  sdword
;ret sdword

GetClassNameW   proto WINAPI,
    hWnd:       HWND,
    lpClassName:LPWSTR,
    nMaxCount:  sdword
;ret sdword
__AW <GetClassName>

GetClassWord    proto WINAPI,
    hWnd:   HWND,
    nIndex: sdword
;ret WORD

DialogProc_t    typedef proto CALLBACK,
    hwndDlg:    HWND,
    uMsg:       UINT,
    wParam:     WPARAM,
    lParam:     LPARAM
;ret INT_PTR
DLGPROC     typedef ptr DialogProc_t

GetWindowLongA  proto WINAPI,
    hWnd:   HWND,
    nIndex: sdword
;ret LONG

GetWindowLongW  proto WINAPI,
    hWnd:   HWND,
    nIndex: sdword
;ret LONG
__AW <GetWindowLong>

GWL_EXSTYLE     equ -20
GWL_HINSTANCE   equ -6
GWL_HWNDPARENT  equ -8
GWL_ID          equ -12
GWL_STYLE       equ -16
GWL_USERDATA    equ -21
GWL_WNDPROC     equ -4
DWL_MSGRESULT   equ 0
DWL_DLGPROC     equ DWL_MSGRESULT + sizeof LRESULT
DWL_USER        equ DWL_DLGPROC + sizeof DLGPROC

GetWindowLongPtr    equ GetWindowLong
GWLP_HINSTANCE  equ -6
GWLP_HWNDPARENT equ -8
GWLP_ID         equ -12
GWLP_USERDATA   equ -21
GWLP_WNDPROC    equ -4
DWLP_MSGRESULT  equ 0
DWLP_DLGPROC    equ DWLP_MSGRESULT + sizeof LRESULT
DWLP_USER       equ DWLP_DLGPROC + sizeof DLGPROC

RegisterClassA  proto WINAPI,
    lpWndClass: LPWNDCLASS
;ret ATOM

RegisterClassW  proto WINAPI,
    lpWndClass: LPWNDCLASS
;ret ATOM
__AW <RegisterClass>

RegisterClassExA    proto WINAPI,
    lpwcx:  LPWNDCLASSEX
;ret ATOM

RegisterClassExW    proto WINAPI,
    lpwcx:  LPWNDCLASSEX
;ret ATOM
__AW <RegisterClassEx>

SetClassLongA   proto WINAPI,
    hWnd:       HWND,
    nIndex:     sdword,
    dwNewLong:  LONG
;ret dword

SetClassLongW   proto WINAPI,
    hWnd:       HWND,
    nIndex:     sdword,
    dwNewLong:  LONG
;ret dword
__AW <SetClassLong>

SetClassLongPtr equ SetClassLong

SetClassWord    proto WINAPI,
    hWnd:       HWND,
    nIndex:     sdword,
    nNewWord:   word
;ret word

SetWindowLongA  proto WINAPI,
    hWnd:       HWND,
    nIndex:     sdword,
    dwNewLong:  LONG
;ret LONG

SetWindowLongW  proto WINAPI,
    hWnd:       HWND,
    nIndex:     sdword,
    dwNewLong:  LONG
;ret LONG
__AW <SetWindowLong>

SetWindowLongPtr    equ SetWindowLong

UnregisterClassA    proto WINAPI,
    lpClassName:    LPCSTR,
    hInstance:      HINSTANCE
;ret BOOL

UnregisterClassW    proto WINAPI,
    lpClassName:    LPCWSTR,
    hInstance:      HINSTANCE
;ret BOOL
__AW <UnregisterClass>

;Window Procedures
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms632593.aspx>
;Every window has an associated window procedure — a function that processes all messages sent or posted to all windows of the class. All aspects of a window's appearance and behavior depend on the window procedure's response to these messages. 

CallWindowProcA proto WINAPI,
    lpPrevWndFund:  WNDPROC,
    hWnd:           HWND,
    Msg:            UINT,
    wParam:         WPARAM,
    lParam:         LPARAM
;ret LRESULT

CallWindowProcW proto WINAPI,
    lpPrevWndFund:  WNDPROC,
    hWnd:           HWND,
    Msg:            UINT,
    wParam:         WPARAM,
    lParam:         LPARAM
;ret LRESULT
__AW <CallWindowProc>

DefWindowProcA  proto WINAPI,
    hWnd:   HWND,
    Msg:    UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret LRESULT

DefWindowProcW  proto WINAPI,
    hWnd:   HWND,
    Msg:    UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret LRESULT
__AW <DefWindowProc>

;Messages and Message Queues
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms632590.aspx>

;Message Constants
WM_USER     equ 0400h
WM_APP      equ 8000h
OCM__BASE   equ WM_USER + 1c00h

;Message Structures
BSMINFO struct
    cbSize  UINT    ?
    hdesk   HDESK   ?
    hwnd    HWND    ?
    luid    LUID    {}
BSMINFO ends
PBSMINFO    typedef ptr BSMINFO

MSG struct
    hwnd    HWND    ?
    message UINT    ?
    wParam  WPARAM  ?
    lParam  LPARAM  ?
    time    dword   ?
    pt      POINT   {}
MSG ends
PMSG    typedef ptr MSG
LPMSG   typedef ptr MSG

;Message Functions
BroadcastSystemMessageW proto WINAPI,
    dwFlags:        dword,
    lpdwRecipients: LPDWORD,
    uiMessage:      UINT,
    wParam:         WPARAM,
    lParam:         LPARAM
;ret sdword

ifdef   UNICODE
    BroadcastSystemMessage  textequ <BroadcastSystemMessageW>
endif

BSF_ALLOWSFW            equ 00000080h
BSF_FLUSHDISK           equ 00000004h
BSF_FORCEIFHUNG         equ 00000020h
BSF_IGNORECURRENTTASK   equ 00000002h
BSF_NOHANG              equ 00000008h
BSF_NOTIMEOUTIFNOTHUNG  equ 00000040h
BSF_POSTMESSAGE         equ 00000010h
BSF_QUERY               equ 00000001h
BSF_SENDNOTIFYMESSAGE   equ 00000100h
BSM_ALLCOMPONENTS       equ 00000000h
BSM_ALLDESKTOPS         equ 00000010h
BSM_APPLICATIONS        equ 00000008h

BroadcastSystemMessageExA   proto WINAPI,
    dwFlags:        dword,
    lpdwRecipients: LPDWORD,
    uiMessage:      UINT,
    wParam:         WPARAM,
    lParam:         LPARAM,
    pBSMInfo:       PBSMINFO
;ret sdword

BroadcastSystemMessageExW   proto WINAPI,
    dwFlags:        dword,
    lpdwRecipients: LPDWORD,
    uiMessage:      UINT,
    wParam:         WPARAM,
    lParam:         LPARAM,
    pBSMInfo:       PBSMINFO
;ret sdword
__AW <BroadcastSystemMessageEx>

BSF_LUID        equ 00000400h
BSF_RETURNHDESK equ 00000200h

DispatchMessageA    proto WINAPI,
    lpmsg:  LPMSG
;ret LRESULT

DispatchMessageW    proto WINAPI,
    lpmsg:  LPMSG
;ret LRESULT
__AW <DispatchMessage>

GetInputState   proto WINAPI    ;ret BOOL

GetMessageA proto WINAPI,
    lpMsg:          LPMSG,
    hWnd:           HWND,
    wMsgFilterMin:  UINT,
    wMsgFilterMax:  UINT
;ret BOOL

GetMessageW proto WINAPI,
    lpMsg:          LPMSG,
    hWnd:           HWND,
    wMsgFilterMin:  UINT,
    wMsgFilterMax:  UINT
;ret BOOL
__AW <GetMessage>

GetMessageExtraInfo proto WINAPI    ;ret LPARAM
GetMessagePos       proto WINAPI    ;ret dword
GetMessageTime      proto WINAPI    ;ret LONG

GetQueueStatus  proto WINAPI,
    flags:  UINT
;ret dword
QS_ALLPOSTMESSAGE   equ 0100h
QS_HOTKEY           equ 0080h
QS_KEY              equ 0001h
QS_MOUSEBUTTON      equ 0004h
QS_MOUSEMOVE        equ 0002h
QS_PAINT            equ 0020h
QS_POSTMESSAGE      equ 0008h
QS_RAWINPUT         equ 0400h
QS_SENDMESSAGE      equ 0040h
QS_TIMER            equ 0010h
QS_MOUSE            equ QS_MOUSEMOVE or QS_MOUSEBUTTON
QS_INPUT            equ QS_MOUSE or QS_KEY or QS_RAWINPUT
QS_ALLEVENTS        equ QS_INPUT or QS_POSTMESSAGE or QS_TIMER or QS_PAINT or QS_HOTKEY
QS_ALLINPUT         equ QS_INPUT or QS_POSTMESSAGE or QS_TIMER or QS_PAINT or QS_HOTKEY or QS_SENDMESSAGE

InSendMessage   proto WINAPI    ;ret BOOL
InSendMessageEx proto WINAPI,
    lpReserved: LPVOID
;ret dword
ISMEX_CALLBACK  equ 00000004h
ISMEX_NOTIFY    equ 00000002h
ISMEX_REPLIED   equ 00000008h
ISMEX_SEND      equ 00000001h

PeekMessageA    proto WINAPI,
    lpMsg:          LPMSG,
    hWnd:           HWND,
    wMsgFilterMin:  UINT,
    wMsgFilterMax:  UINT,
    wRemoveMessage: UINT
;ret BOOL

PeekMessageW    proto WINAPI,
    lpMsg:          LPMSG,
    hWnd:           HWND,
    wMsgFilterMin:  UINT,
    wMsgFilterMax:  UINT,
    wRemoveMessage: UINT
;ret BOOL
__AW <PeekMessage>

PM_NOREMOVE         equ 0000h
PM_REMOVE           equ 0001h
PM_NOYIELD          equ 0002h
PM_QS_INPUT         equ QS_INPUT shl 16
PM_QS_PAINT         equ QS_PAINT shl 16
PM_QS_POSTMESSAGE   equ (QS_POSTMESSAGE or QS_HOTKEY or QS_TIMER) shl 16
PM_QS_SENDMESSAGE   equ QS_SENDMESSAGE shl 16

PostMessageA    proto WINAPI,
    hWnd:   HWND,
    Msg:    UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret BOOL

PostMessageW    proto WINAPI,
    hWnd:   HWND,
    Msg:    UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret BOOL
__AW <PostMessage>

HWND_BROADCAST  equ 0ffffh

PostQuitMessage proto WINAPI,
    nExitCode:  sdword
;ret VOID

PostThreadMessageA  proto WINAPI,
    idThread:   dword,
    Msg:        UINT,
    wParam:     WPARAM,
    lParam:     LPARAM
;ret BOOL

PostThreadMessageW  proto WINAPI,
    idThread:   dword,
    Msg:        UINT,
    wParam:     WPARAM,
    lParam:     LPARAM
;ret BOOL
__AW <PostThreadMessage>

RegisterWindowMessageA  proto WINAPI,
    lpString:   LPCSTR
;ret UINT

RegisterWindowMessageW  proto WINAPI,
    lpString:   LPCWSTR
;ret UINT
__AW <RegisterWindowMessage>

ReplyMessage    proto WINAPI,
    lResult:    LRESULT
;ret BOOL

SendAsyncProc_t typedef proto CALLBACK,
    hwnd:   HWND,
    uMsg:   UINT,
    dwData: ULONG_PTR,
    lResult:LRESULT
;ret VOID
SENDASYNCPROC   typedef ptr SendAsyncProc_t

SendMessageA    proto WINAPI,
    hWnd:   HWND,
    Msg:    UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret LRESULT

SendMessageW    proto WINAPI,
    hWnd:   HWND,
    Msg:    UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret LRESULT
__AW <SendMessage>

SendMessageCallbackA    proto WINAPI,
    hWnd:       HWND,
    Msg:        UINT,
    wParam:     WPARAM,
    lParam:     LPARAM,
    lpCallBack: SENDASYNCPROC,
    dwData:     ULONG_PTR
;ret BOOL

SendMessageCallbackW    proto WINAPI,
    hWnd:       HWND,
    Msg:        UINT,
    wParam:     WPARAM,
    lParam:     LPARAM,
    lpCallBack: SENDASYNCPROC,
    dwData:     ULONG_PTR
;ret BOOL
__AW <SendMessageCallback>

SendMessageTimeoutA proto WINAPI,
    hWnd:       HWND,
    Msg:        UINT,
    wParam:     WPARAM,
    lParam:     LPARAM,
    fuFlags:    UINT,
    uTimeout:   UINT,
    lpdwResult: PDWORD_PTR
;ret LRESULT

SendMessageTimeoutW proto WINAPI,
    hWnd:       HWND,
    Msg:        UINT,
    wParam:     WPARAM,
    lParam:     LPARAM,
    fuFlags:    UINT,
    uTimeout:   UINT,
    lpdwResult: PDWORD_PTR
;ret LRESULT
__AW <SendMessageTimeout>

SMTO_ABORTIFHUNG        equ 0002h
SMTO_BLOCK              equ 0001h
SMTO_NORMAL             equ 0000h
SMTO_NOTIMEOUTIFHUNG    equ 0008h
SMTO_ERRORONEXIT        equ 0020h

SendNotifyMessageA  proto WINAPI,
    hWnd:   HWND,
    Msg:    UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret BOOL

SendNotifyMessageW  proto WINAPI,
    hWnd:   HWND,
    Msg:    UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret BOOL
__AW <SendNotifyMessage>

SetMessageExtraInfo proto WINAPI,
    lParam: LPARAM
;ret LPARAM

TranslateMessage    proto WINAPI,
    lpMsg:  LPMSG
;ret BOOL

WaitMessage proto WINAPI    ;ret BOOL

;Timers
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms632592.aspx>
;A timer is an internal routine that repeatedly measures a specified interval, in milliseconds. 

WM_TIMER            equ 0113h
USER_TIMER_MINIMUM  equ 0000000ah
USER_TIMER_MAXIMUM  equ 7fffffffh

TimerProc_t typedef proto CALLBACK,
    hwnd:   HWND,
    uMsg:   UINT,
    idEvent:UINT_PTR,
    dwTime: dword
;ret VOID
TIMERPROC   typedef ptr TimerProc_t

KillTimer   proto WINAPI,
    hWnd:       HWND,
    uIDEvent:   UINT_PTR
;ret BOOL

SetCoalescableTimer proto WINAPI,
    hwnd:           HWND,
    nIDEvent:       UINT_PTR,
    uElapse:        UINT,
    lpTimerFunc:    TIMERPROC,
    uToleranceDelay:ULONG
;ret UINT_PTR
TIMERV_DEFAULT_COALESCING   equ 00000000h
TIMERV_NO_COALESCING        equ 0ffffffffh

SetTimer    proto WINAPI,
    hWnd:       HWND,
    nIDEvent:   UINT_PTR,
    uElapse:    UINT,
    lpTimerFunc:TIMERPROC
;ret UINT_PTR

;Window Properties
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms632594.aspx>
;A window property is any data assigned to a window. A window property is usually a handle of the window-specific data, but it may be any value. Each window property is identified by a string name. 

PropEnumProc_t  typedef proto CALLBACK,
    hwnd:       HWND,
    lpszString: LPCTSTR,
    hData:      HANDLE
;ret BOOL
PROPENUMPROC    typedef ptr PropEnumProc_t

EnumPropsA  proto WINAPI,
    hWnd:       HWND,
    lpEnumFunc: PROPENUMPROC
;ret sdword

EnumPropsW  proto WINAPI,
    hWnd:       HWND,
    lpEnumFunc: PROPENUMPROC
;ret sdword
__AW <EnumProps>

PropEnumProcEx_t    typedef proto CALLBACK,
    hwnd:       HWND,
    lpszString: LPTSTR,
    hData:      HANDLE,
    dwData:     ULONG_PTR
;ret BOOL
PROPENUMPROCEX  typedef ptr PropEnumProcEx_t

EnumPropsExA    proto WINAPI,
    hWnd:       HWND,
    lpEnumFunc: PROPENUMPROCEX,
    lParam:     LPARAM
;ret sdword
__AW <EnumPropsEx>

GetPropA    proto WINAPI,
    hWnd:       HWND,
    lpString:   LPCSTR
;ret HANDLE

GetPropW    proto WINAPI,
    hWnd:       HWND,
    lpString:   LPCWSTR
;ret HANDLE
__AW <GetProp>

RemovePropA proto WINAPI,
    hWnd:       HWND,
    lpString:   LPCSTR
;ret HANDLE

RemovePropW proto WINAPI,
    hWnd:       HWND,
    lpString:   LPCWSTR
;ret HANDLE
__AW <RemoveProp>

SetPropA    proto WINAPI,
    hWnd:       HWND,
    lpString:   LPCSTR,
    hData:      HANDLE
;ret BOOL

SetPropW    proto WINAPI,
    hWnd:       HWND,
    lpString:   LPCSTR,
    hData:      HANDLE
;ret BOOL
__AW <SetProp>

;Configuration
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ff625300.aspx>
;Display elements are the parts of a window and the display that appear on the system display screen. System metrics are the dimensions of various display elements. Typical system metrics include the window border width, icon height, and so on. System metrics also describe other aspects of the system, such as whether a mouse is installed, double-byte characters are supported, or a debugging version of the operating system is installed. The GetSystemMetrics function retrieves the specified system metric.
;Applications can also retrieve and set the color of window elements such as menus, scroll bars, and buttons by using the GetSysColor and SetSysColors functions, respectively.
;The SystemParametersInfo function retrieves or sets various system attributes, such as double-click time, screen saver time-out, window border width, and desktop pattern. When an application uses SystemParametersInfo to set a parameter, the change takes place immediately. This function also enables applications to update the user profile, so changes to the system will be preserved when the system is restarted.

CONTACTVISUALIZATION_OFF                equ 0000h
CONTACTVISUALIZATION_ON                 equ 0001h
CONTACTVISUALIZATION_PRESENTATIONMODE   equ 0002h
GESTUREVISUALIZATION_OFF                equ 0000h
GESTUREVISUALIZATION_ON                 equ 001fh
GESTUREVISUALIZATION_TAP                equ 0001h
GESTUREVISUALIZATION_DOUBLETAP          equ 0002h
GESTUREVISUALIZATION_PRESSANDTAP        equ 0004h
GESTUREVISUALIZATION_PRESSANDHOLD       equ 0008h
GESTUREVISUALIZATION_RIGHTTAP           equ 0010h
PENVISUALIZATION_OFF                    equ 0000h
PENVISUALIZATION_ON                     equ 0023h
PENVISUALIZATION_TAP                    equ 0001h
PENVISUALIZATION_DOUBLETAP              equ 0002h
PENVISUALIZATION_CURSOR                 equ 0020h

GetSystemMetrics    proto WINAPI,
    nIndex: sdword
;ret sdword

SM_ARRANGE              equ 56
SM_CLEANBOOT            equ 67
SM_CMONITORS            equ 80
SM_CMOUSEBUTTONS        equ 43
SM_CONVERTIBLESLATEMODE equ 2003h
SM_CXBORDER             equ 5
SM_CXCURSOR             equ 13
SM_CXDLGFRAME           equ 7
SM_CXDOUBLECLK          equ 36
SM_CXDRAG               equ 68
SM_CXEDGE               equ 45
SM_CXFIXEDFRAME         equ 7
SM_CXFOCUSBORDER        equ 83
SM_CXFRAME              equ 32
SM_CXFULLSCREEN         equ 16
SM_CXHSCROLL            equ 21
SM_CXHTHUMB             equ 10
SM_CXICON               equ 11
SM_CXICONSPACING        equ 38
SM_CXMAXIMIZED          equ 61
SM_CXMAXTRACK           equ 59
SM_CXMENUCHECK          equ 71
SM_CXMENUSIZE           equ 54
SM_CXMIN                equ 28
SM_CXMINIMIZED          equ 57
SM_CXMINSPACING         equ 47
SM_CXMINTRACK           equ 34
SM_CXPADDEDBORDER       equ 92
SM_CXSCREEN             equ 0
SM_CXSIZE               equ 30
SM_CXSIZEFRAME          equ 32
SM_CXSMICON             equ 49
SM_CXSMSIZE             equ 52
SM_CXVIRTUALSCREEN      equ 78
SM_CXVSCROLL            equ 2
SM_CYBORDER             equ 6
SM_CYCAPTION            equ 4
SM_CYCURSOR             equ 14
SM_CYDLGFRAME           equ 8
SM_CYDOUBLECLK          equ 37
SM_CYDRAG               equ 69
SM_CYEDGE               equ 46
SM_CYFIXEDFRAME         equ 8
SM_CYFOCUSBORDER        equ 84
SM_CYFRAME              equ 33
SM_CYFULLSCREEN         equ 17
SM_CYHSCROLL            equ 3
SM_CYICON               equ 12
SM_CYICONSPACING        equ 39
SM_CYKANJIWINDOW        equ 18
SM_CYMAXIMIZED          equ 62
SM_CYMAXTRACK           equ 60
SM_CYMENU               equ 15
SM_CYMENUCHECK          equ 72
SM_CYMENUSIZE           equ 55
SM_CYMIN                equ 29
SM_CYMINIMIZED          equ 58
SM_CYMINSPACING         equ 48
SM_CYMINTRACK           equ 35
SM_CYSCREEN             equ 1
SM_CYSIZE               equ 31
SM_CYSIZEFRAME          equ 33
SM_CYSMCAPTION          equ 51
SM_CYSMICON             equ 50
SM_CYSMSIZE             equ 53
SM_CYVIRTUALSCREEN      equ 79
SM_CYVSCROLL            equ 20
SM_CYVTHUMB             equ 9
SM_DBCSENABLED          equ 42
SM_DEBUG                equ 22
SM_DIGITIZER            equ 94
SM_IMMENABLED           equ 82
SM_MAXIMUMTOUCHES       equ 95
SM_MEDIACENTER          equ 87
SM_MENUDROPALIGNMENT    equ 40
SM_MIDEASTENABLED       equ 74
SM_MOUSEPRESENT         equ 19
SM_MOUSEHORIZONTALWHEELPRESENT  equ 91
SM_MOUSEWHEELPRESENT    equ 75
SM_NETWORK              equ 63
SM_PENWINDOWS           equ 41
SM_REMOTECONTROL        equ 2001h
SM_REMOTESESSION        equ 1000h
SM_SAMEDISPLAYFORMAT    equ 81
SM_SECURE               equ 44
SM_SERVERR2             equ 89
SM_SHOWSOUNDS           equ 70
SM_SHUTTINGDOWN         equ 2000h
SM_SLOWMACHINE          equ 73
SM_STARTER              equ 88
SM_SWAPBUTTON           equ 23
SM_SYSTEMDOCKED         equ 2004h
SM_TABLETPC             equ 86
SM_XVIRTUALSCREEN       equ 76
SM_YVIRTUALSCREEN       equ 77
ARW_BOTTOMLEFT          equ 0000h
ARW_BOTTOMRIGHT         equ 0001h
ARW_TOPLEFT             equ 0002h
ARW_TOPRIGHT            equ 0003h
ARW_LEFT                equ 0000h
ARW_RIGHT               equ 0000h
ARW_UP                  equ 0004h
ARW_DOWN                equ 0004h
ARW_HIDE                equ 0008h
NID_INTEGRATED_TOUCH    equ 01h
NID_EXTERNAL_TOUCH      equ 02h
NID_INTEGRATED_PEN      equ 04h
NID_EXTERNAL_PEN        equ 08h
NID_MULTI_INPUT         equ 40h
NID_READY               equ 80h

SystemParametersInfo    proto WINAPI,
    uiAction:   UINT,
    uiParam:    UINT,
    pvParam:    PVOID,
    fWinIni:    UINT
;ret BOOL

;Accessibility parameters
SPI_GETACCESSTIMEOUT            equ 003ch
SPI_GETAUDIODESCRIPTION         equ 0074h
SPI_GETCLIENTAREAANIMATION      equ 1042h
SPI_GETDISABLEOVERLAPPEDCONTENT equ 1040h
SPI_GETFILTERKEYS               equ 0032h
SPI_GETFOCUSBORDERHEIGHT        equ 2010h
SPI_GETFOCUSBORDERWIDTH         equ 200eh
SPI_GETHIGHCONTRAST             equ 0042h
SPI_GETLOGICALDPIOVERRIDE       equ 009eh
SPI_GETMESSAGEDURATION          equ 2016h
SPI_GETMOUSECLICKLOCK           equ 101eh
SPI_GETMOUSECLICKLOCKTIME       equ 2008h
SPI_GETMOUSEKEYS                equ 0036h
SPI_GETMOUSESONAR               equ 101ch
SPI_GETMOUSEVANISH              equ 1020h
SPI_GETSCREENREADER             equ 0046h
SPI_GETSERIALKEYS               equ 003eh
SPI_GETSHOWSOUNDS               equ 0038h
SPI_GETSOUNDSENTRY              equ 0040h
SPI_GETSTICKYKEYS               equ 003ah
SPI_GETTOGGLEKEYS               equ 0034h
SPI_SETACCESSTIMEOUT            equ 003dh
SPI_SETAUDIODESCRIPTION         equ 0075h
SPI_SETCLIENTAREAANIMATION      equ 1043h
SPI_SETDISABLEOVERLAPPEDCONTENT equ 1041h
SPI_SETFILTERKEYS               equ 0033h
SPI_SETFOCUSBORDERHEIGHT        equ 2011h
SPI_SETFOCUSBORDERWIDTH         equ 200fh
SPI_SETHIGHCONTRAST             equ 0043h
SPI_SETLOGICALDPIOVERRIDE       equ 009fh
SPI_SETMESSAGEDURATION          equ 2017h
SPI_SETMOUSECLICKLOCK           equ 101fh
SPI_SETMOUSECLICKLOCKTIME       equ 2009h
SPI_SETMOUSEKEYS                equ 0037h
SPI_SETMOUSESONAR               equ 101dh
SPI_SETMOUSEVANISH              equ 1021h
SPI_SETSCREENREADER             equ 0047h
SPI_SETSERIALKEYS               equ 003fh
SPI_SETSHOWSOUNDS               equ 0039h
SPI_SETSOUNDSENTRY              equ 0041h
SPI_SETSTICKYKEYS               equ 003bh
SPI_SETTOGGLEKEYS               equ 0035h

;Desktop parameters
SPI_GETCLEARTYPE                equ 1048h
SPI_GETDESKWALLPAPER            equ 0073h
SPI_GETDROPSHADOW               equ 1024h
SPI_GETFLATMENU                 equ 1022h
SPI_GETFONTSMOOTHING            equ 004ah
SPI_GETFONTSMOOTHINGCONTRAST    equ 200ch
SPI_GETFONTSMOOTHINGORIENTATION equ 2012h
SPI_GETFONTSMOOTHINGTYPE        equ 200ah
SPI_GETWORKAREA                 equ 0030h
SPI_SETCLEARTYPE                equ 1049h
SPI_SETCURSORS                  equ 0057h
SPI_SETDESKPATTERN              equ 0015h
SPI_SETDESKWALLPAPER            equ 0014h
SPI_SETDROPSHADOW               equ 1025h
SPI_SETFLATMENU                 equ 1023h
SPI_SETFONTSMOOTHING            equ 004bh
SPI_SETFONTSMOOTHINGCONTRAST    equ 200dh
SPI_SETFONTSMOOTHINGORIENTATION equ 2013h
SPI_SETFONTSMOOTHINGTYPE        equ 200Bh
SPI_SETWORKAREA                 equ 002fh
FE_FONTSMOOTHINGORIENTATIONBGR  equ 0000h
FE_FONTSMOOTHINGORIENTATIONRGB  equ 0001h
FE_FONTSMOOTHINGSTANDARD        equ 0001h
FE_FONTSMOOTHINGCLEARTYPE       equ 0002h

;Icon parameters
SPI_GETICONMETRICS          equ 002dh
SPI_GETICONTITLELOGFONT     equ 001fh
SPI_GETITONTITLEWRAP        equ 0019h
SPI_ICONHORIZONTALSPACING   equ 000dh
SPI_ICONVERTICALSPACING     equ 0018h
SPI_SETICONMETRICS          equ 003eh
SPI_SETICONS                equ 0058h
SPI_SETICONTITLELOGFONT     equ 0022h
SPI_SETICONTITLEWRAP        equ 001ah

;Input parameters
SPI_GETBEEP                     equ 0001h
SPI_GETBLOCKSENDINPUTRESETS     equ 1026h
SPI_GETCONTACTVISUALIZATION     equ 2018h
SPI_GETDEFAULTINPUTLANG         equ 0059h
SPI_GETRESTUREVISUALIZATION     equ 201ah
SPI_GETKEYBOARDCUES             equ 100ah
SPI_GETKEYBOARDDELAY            equ 0016h
SPI_GETKEYBOARDPREF             equ 0044h
SPI_GETKEYBOARDSPEED            equ 000ah
SPI_GETMOUSE                    equ 0003h
SPI_GETMOUSEHOVERHEIGHT         equ 0064h
SPI_GETMOUSEHOVERTIME           equ 0066h
SPI_GETMOUSEHOVERWIDTH          equ 0062h
SPI_GETMOUSESPEED               equ 0070h
SPI_GETMOUSETRAILS              equ 005eh
SPI_GETMOUSEWHEELROUTING        equ 201ch
SPI_GETPENVISUALIZATION         equ 201eh
SPI_GETSNAPTODEFBUTTON          equ 005fh
SPI_GETSYSTEMLANGUAGEBAR        equ 1050h
SPI_GETTHREADLOCALINPUTSETTINGS equ 103eh
SPI_GETWHEELSCROLLCHARS         equ 006ch
SPI_GEHWHEELSCROLLLINES         equ 0068h
SPI_SETBEEP                     equ 0002h
SPI_SETBLOCKSENDINPUTRESETS     equ 1027h
SPI_SETCONTACTVISUALIZATION     equ 2019h
SPI_SETDEFAULTINPUTLANG         equ 005ah
SPI_SETDOUBLECLICKTIME          equ 0020h
SPI_SETDOUBLECLKHEIGHT          equ 001eh
SPI_SETDOUBLECLKWIDTH           equ 001dh
SPI_SETGESTUREVISUALIZATION     equ 201bh
SPI_SETKEYBOARDCUES             equ 100bh
SPI_SETKEYBOARDDELAY            equ 0017h
SPI_SETKEYBOARDPREF             equ 0045h
SPI_SETKEYBOARDSPEED            equ 000bh
SPI_SETLANGTOGGLE               equ 005bh
SPI_SETMOUSE                    equ 0004h
SPI_SETMOUSEBUTTONSWAP          equ 0021h
SPI_SETMOUSEHOVERHEIGHT         equ 0065h
SPI_SETMOUSEHOVERTIME           equ 0067h
SPI_SETMOUSEHOVERWIDTH          equ 0063h
SPI_SETMOUSESPEED               equ 0071h
SPI_SETMOUSETRAILS              equ 005dh
SPI_SETMOUSEWHEELROUTING        equ 201dh
SPI_SETPENVISUALIZATION         equ 201fh
SPI_SETSNAPTODEFBUTTON          equ 0060h
SPI_SETSYSTEMLANGUAGEBAR        equ 1051h
SPI_SETTHREADLOCALINPUTSETTINGS equ 104fh
SPI_SETWHEELSCROLLCHARS         equ 006dh
SPI_SETWHEELSCROLLLINES         equ 0069h

;Menu parameters
SPI_GETMENUDROPALIGNMENT    equ 001bh
SPI_GETMENUFADE             equ 1012h
SPI_GETMENUSHOWDELAY        equ 006ah
SPI_SETMENUDROPALIGNMENT    equ 001ch
SPI_SETMENUFADE             equ 1013h
SPI_SETMENUSHOWDELAY        equ 006bh

;Power parameters
SPI_GETLOWPOWERACTIVE   equ 0053h
SPI_GETLOWPOWERTIMEOUT  equ 004fh
SPI_GETPOWEROFFACTIVE   equ 0054h
SPI_GETPOWEROFFTIMEOUT  equ 0050h
SPI_SETLOWPOWERACTIVE   equ 0055h
SPI_SETLOWPOWERTIMEOUT  equ 0051h
SPI_SETPOWEROFFACTIVE   equ 0056h
SPI_SETPOWEROFFTIMEOUT  equ 0052h

;Screen saver parameters
SPI_GETSCREENSAVEACTIVE     equ 0010h
SPI_GETSCREENSAVERRUNNING   equ 0072h
SPI_GETSCREENSAVESECURE     equ 0076h
SPI_GETSCREENSAVETIMEOUT    equ 000eh
SPI_SETSCREENSAVEACTIVE     equ 0011h
SPI_SETSCREENSAVESECURE     equ 0077h
SPI_SETSCREENSAVETIMEOUT    equ 000fh

;Time-out parameters
SPI_GETHUNGAPPTIMEOUT           equ 0078h
SPI_GETWAITTOKILLTIMEOUT        equ 007ah
SPI_GETWAITTOKILLSERVICETIMEOUT equ 007ch
SPI_SETHUNGAPPTIMEOUT           equ 0079h
SPI_SETWAITTOKILLTIMEOUT        equ 007bh
SPI_SETWAITTOKILLSERVICETIMEOUT equ 007dh

;UI effects parameters
SPI_GETCOMBOBOXANIMATION        equ 1004h
SPI_GETCURSORSHADOW             equ 101ah
SPI_GETGRADIENTCAPTIONS         equ 1008h
SPI_GETHOTTRACKING              equ 100eh
SPI_GETLISTBOXSMOOTHSCROLLING   equ 1006h
SPI_GETMENUANIMATION            equ 1002h
SPI_GETMENUUNDERLINES           equ 100ah
SPI_GETSELECTIONFADE            equ 1014h
SPI_GETTOOLTIPANIMATION         equ 1016h
SPI_GETTOOLTIPFADE              equ 1018h
SPI_GETUIEFFECTS                equ 103eh
SPI_SETCOMBOBOXANIMATION        equ 1005h
SPI_SETCURSORSHADOW             equ 101bh
SPI_SETGRADIENTCAPTIONS         equ 1009h
SPI_SETHOTTRACKING              equ 100fh
SPI_SETLISTBOXSMOOTHSCROLLING   equ 1007h
SPI_SETMENUANIMATION            equ 1003h
SPI_SETMENUUNDERLINES           equ 100bh
SPI_SETSELECTIONFADE            equ 1015h
SPI_SETTOOLTIPANIMATION         equ 1017h
SPI_SETTOOLTIPFADE              equ 1019h
SPI_SETUIEFFECTS                equ 103fh

;Window parameters
SPI_GETACTIVEWINDOWTRACKING     equ 1000h
SPI_GETACTIVEWNDTRKZORDER       equ 100ch
SPI_GETACTIVEWNDTRKTIMEOUT      equ 2002h
SPI_GETANIMATION                equ 0048h
SPI_GETBORDER                   equ 0005h
SPI_GETCARETWIDTH               equ 2006h
SPI_GETDOCKMOVING               equ 0090h
SPI_GETDRAGFROMMAXIMIZE         equ 008ch
SPI_GETDRAGFULLWINDOWS          equ 0026h
SPI_GETFOREGROUNDFLASHCOUNT     equ 0026h
SPI_GETFOREGROUNDLOCKTIMEOUT    equ 2000h
SPI_GETMINIMIZEDMETRICS         equ 002bh
SPI_GETMOUSEDOCKTHRESHOLD       equ 007eh
SPI_GETMOUSEDRAGOUTTHRESHOLD    equ 0084h
SPI_GETMOUSESIDEMOVETHRESHOLD   equ 0088h
SPI_GETNONCLIENTMETRICS         equ 0029h
SPI_GETPENDOCKTHRESHOLD         equ 0080h
SPI_GETPENDRAGOUTTHRESHOLD      equ 0086h
SPI_GETPENSIDEMOVETHRESHOLD     equ 008ah
SPI_GETSHOWIMEUI                equ 006eh
SPI_GETSNAPSIZING               equ 008eh
SPI_GETWINARRANGING             equ 0082h
SPI_SETACTIVEWINDOWTRACKING     equ 1001h
SPI_SETACTIVEWNDTRKZORDER       equ 100dh
SPI_SETACTIVEWNDTRKTIMEOUT      equ 2003h
SPI_SETANIMATION                equ 0049h
SPI_SETBORDER                   equ 0006h
SPI_SETCARETWIDTH               equ 2007h
SPI_SETDOCKMOVING               equ 0091h
SPI_SETDRAGFROMMAXIMIZE         equ 008dh
SPI_SETDRAGFULLWINDOWS          equ 0025h
SPI_SETDRAGHEIGHT               equ 004dh
SPI_SETDRAGWIDTH                equ 004ch
SPI_SETFOREGROUNDFLASHCOUNT     equ 2005h
SPI_SETFOREGROUNDLOCKTIMEOUT    equ 2001h
SPI_SETMINIMIZEDMETRICS         equ 002ch
SPI_SETMOUSEDOCKTHRESHOLD       equ 007fh
SPI_SETMOUSEDRAGOUTTHRESHOLD    equ 0085h
SPI_SETMOUSESIDEMOVETHRESHOLD   equ 0089h
SPI_SETNONCLIENTMETRICS         equ 002ah
SPI_SETPENDOCKTHRESHOLD         equ 0081h
SPI_SETPENDRAGOUTTHRESHOLD      equ 0087h
SPI_SETPENSIDEMOVETHRESHOLD     equ 008bh
SPI_SETSHOWIMEUI                equ 006fh
SPI_SETSNAPSIZING               equ 008fh
SPI_SETWINARRANGING             equ 0083h

SPIF_UPDATEINIFILE      equ 0001h
SPIF_SENDCHANGE         equ 0002h
SPIF_SENDWININICHANGE   equ SPIF_SENDCHANGE

ANIMATIONINFO   struct
    cbSize      UINT    ?
    iMinAnimate sdword  ?
ANIMATIONINFO   ends
LPANIMATIONINFO typedef ptr ANIMATIONINFO

AUDIODESCRIPTION    struct
    cbSize  UINT    ?
    Enabled BOOL    ?
    Locale  LCID    ?
AUDIODESCRIPTION    ends
LPAUDIODESCRIPTION  typedef ptr AUDIODESCRIPTION

MINIMIZEDMETRICS    struct
    cbSize      UINT    ?
    iWidth      sdword  ?
    iHorzGap    sdword  ?
    iVertGap    sdword  ?
    iArrange    sdword  ?
MINIMIZEDMETRICS    ends
PMINIMIZEDMETRICS   typedef ptr MINIMIZEDMETRICS
LPMINIMIZEDMETRICS  typedef ptr MINIMIZEDMETRICS

LF_FACESIZE equ 32
LOGFONTA    struct
    lfHeight            LONG    ?
    lfWidth             LONG    ?
    lfEscapement        LONG    ?
    lfOrientation       LONG    ?
    lfWeight            LONG    ?
    lfItalic            byte    ?
    lfUnderline         byte    ?
    lfStrikeOut         byte    ?
    lfCharSet           byte    ?
    lfOutPrecision      byte    ?
    lfClipPrecision     byte    ?
    lfQuality           byte    ?
    lfPitchAndFamily    byte    ?
    lfFaceName          CHAR    LF_FACESIZE dup(?)
LOGFONTA    ends
LOGFONTW    struct
    lfHeight            LONG    ?
    lfWidth             LONG    ?
    lfEscapement        LONG    ?
    lfOrientation       LONG    ?
    lfWeight            LONG    ?
    lfItalic            byte    ?
    lfUnderline         byte    ?
    lfStrikeOut         byte    ?
    lfCharSet           byte    ?
    lfOutPrecision      byte    ?
    lfClipPrecision     byte    ?
    lfQuality           byte    ?
    lfPitchAndFamily    byte    ?
    lfFaceName          WCHAR   LF_FACESIZE dup(?)
LOGFONTW    ends
__AW <LOGFONT>
PLOGFONT    typedef ptr LOGFONT

NONCLIENTMETRICSA   struct
    cbSize              UINT        ?
    iBorderWidth        sdword      ?
    iScrollWidth        sdword      ?
    iScrollHeight       sdword      ?
    iCaptionWidth       sdword      ?
    iCaptionHeight      sdword      ?
    lfCaptionFont       LOGFONTA    {}
    iSmCaptionWidth     sdword      ?
    iSmCaptionHeight    sdword      ?
    lfSmCaptionFont     LOGFONTA    {}
    iMenuWidth          sdword      ?
    iMenuHeight         sdword      ?
    lfMenuFont          LOGFONTA    {}
    lfStatusFont        LOGFONTA    {}
    ifMessageFont       LOGFONTA    {}
    iPaddedBorderWidth  sdword      ?
NONCLIENTMETRICSA   ends
NONCLIENTMETRICSW   struct
    cbSize              UINT        ?
    iBorderWidth        sdword      ?
    iScrollWidth        sdword      ?
    iScrollHeight       sdword      ?
    iCaptionWidth       sdword      ?
    iCaptionHeight      sdword      ?
    lfCaptionFont       LOGFONTW    {}
    iSmCaptionWidth     sdword      ?
    iSmCaptionHeight    sdword      ?
    lfSmCaptionFont     LOGFONTW    {}
    iMenuWidth          sdword      ?
    iMenuHeight         sdword      ?
    lfMenuFont          LOGFONTW    {}
    lfStatusFont        LOGFONTW    {}
    ifMessageFont       LOGFONTW    {}
    iPaddedBorderWidth  sdword      ?
NONCLIENTMETRICSW   ends
__AW <NONCLIENTMETRICS>
PNONCLIENTMETRICS   typedef ptr NONCLIENTMETRICS
LPNONCLIENTMETRICS  typedef ptr NONCLIENTMETRICS

WM_WININICHANGE     equ 001ah
WM_SETTINGCHANGE    equ WM_WININICHANGE

;Hooks
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms632589.aspx>
;A hook is a point in the system message-handling mechanism where an application can install a subroutine to monitor the message traffic in the system and process certain types of messages before they reach the target window procedure. 

WM_CANCELJOURNAL    equ 004bh
WM_QUEUESYNC        equ 0023h

CBT_CREATEWNDA  struct
    lpcs            LPCREATESTRUCT  ?
    hwndInsertAfter HWND            ?
CBT_CREATEWNDA  ends
CBT_CREATEWNDW  struct
    lpcs            LPCREATESTRUCT  ?
    hwndInsertAfter HWND            ?
CBT_CREATEWNDW  ends
__AW <CBT_CREATEWND>
LPCBT_CREATEWND typedef ptr CBT_CREATEWND

CBTACTIVATESTRUCT   struct
    fMouse      BOOL    ?
    hWndActive  HWND    ?
CBTACTIVATESTRUCT   ends
LPCBTACTIVATESTRUCT typedef ptr CBTACTIVATESTRUCT

CWPRETSTRUCT    struct
    lResult LRESULT ?
    lParam  LPARAM  ?
    wParam  WPARAM  ?
    message UINT    ?
    hwnd    HWND    ?
CWPRETSTRUCT    ends
PCWPRETSTRUCT   typedef ptr CWPRETSTRUCT
LPCWPRETSTRUCT  typedef ptr CWPRETSTRUCT

CWPSTRUCT   struct
    lParam  LPARAM  ?
    wParam  WPARAM  ?
    message UINT    ?
    hwnd    HWND    ?
CWPSTRUCT   ends
PCWPSTRUCT  typedef ptr CWPSTRUCT
LPCWPSTRUCT typedef ptr CWPSTRUCT

DEBUGHOOKINFO   struct
    idThread            dword   ?
    idThreadInstaller   dword   ?
    lParam              LPARAM  ?
    wParam              WPARAM  ?
    code                sdword  ?
DEBUGHOOKINFO   ends
PDEBUGHOOKINFO  typedef ptr DEBUGHOOKINFO
LPDEBUGHOOKINFO typedef ptr DEBUGHOOKINFO

EVENTMSG    struct
    message UINT    ?
    paramL  UINT    ?
    paramH  UINT    ?
    time    dword   ?
    hwnd    HWND    ?
EVENTMSG    ends
PEVENTMSG   typedef ptr EVENTMSG
LPEVENTMSG  typedef ptr EVENTMSG

KBDLLHOOKSTRUCT struct
    vkCode      dword       ?
    scanCode    dword       ?
    flags       dword       ?
    time        dword       ?
    dwExtraInfo ULONG_PTR   ?
KBDLLHOOKSTRUCT ends
PKBDLLHOOKSTRUCT    typedef ptr KBDLLHOOKSTRUCT
LPKBDLLHOOKSTRUCT   typedef ptr KBDLLHOOKSTRUCT
KF_EXTENDED             equ 0100h
LLKHF_EXTENDED          equ KF_EXTENDED shr 8
LLKHF_LOWER_IL_INJECTED equ 00000002h
LLKHF_INJECTED          equ 00000010h
KF_ALTDOWN              equ 2000h
LLKHF_ALTDOWN           equ KF_ALTDOWN shr 8
KF_UP                   equ 8000h
LLKHF_UP                equ KF_UP shr 8

MOUSEHOOKSTRUCT struct
    pt              POINT       {}
    hwnd            HWND        ?
    wHitTestCode    UINT        ?
    dwExtraInfo     ULONG_PTR   ?
MOUSEHOOKSTRUCT ends
PMOUSEHOOKSTRUCT    typedef ptr MOUSEHOOKSTRUCT
LPMOUSEHOOKSTRUCT   typedef ptr MOUSEHOOKSTRUCT

MOUSEHOOKSTRUCTEX   struct
    _MOUSEHOOKSTRUCT    MOUSEHOOKSTRUCT {}
    mouseData           dword           ?
MOUSEHOOKSTRUCTEX   ends
PMOUSEHOOKSTRUCTEX  typedef ptr MOUSEHOOKSTRUCTEX
LPMOUSEHOOKSTRUCTEX typedef ptr MOUSEHOOKSTRUCTEX
XBUTTON1    equ 0001h
XBUTTON2    equ 0002h

MSLLHOOKSTRUCT  struct
    pt          POINT       {}
    mouseData   dword       ?
    flags       dword       ?
    time        dword       ?
    dwExtraInfo ULONG_PTR   ?
MSLLHOOKSTRUCT  ends
PMSLLHOOKSTRUCT     typedef ptr MSLLHOOKSTRUCT
LPMSLLHOOKSTRUCT    typedef ptr MSLLHOOKSTRUCT
LLMHF_INJECTED          equ 00000001h
LLPHF_LOWER_IL_INJECTED equ 00000002h

HookProc_t  typedef proto CALLBACK,
    nCode:  sdword,
    wParam: WPARAM,
    lParam: LPARAM
;ret LRESULT
HOOKPROC    typedef ptr HookProc_t

CallMsgFilter   proto WINAPI,
    lpMsg:  LPMSG,
    nCode:  sdword
;ret BOOL

CallNextHookEx  proto WINAPI,
    hhk:    HHOOK,
    nCode:  sdword,
    wParam: WPARAM,
    lParam: LPARAM
;ret LRESULT

SetWindowsHookExW   proto WINAPI,
    idHook:     sdword,
    lpfn:       HOOKPROC,
    hMod:       HINSTANCE,
    dwThreadId: dword
;ret HHOOK

SetWindowsHookExA   proto WINAPI,
    idHook:     sdword,
    lpfn:       HOOKPROC,
    hMod:       HINSTANCE,
    dwThreadId: dword
;ret HHOOK
__AW <SetWindowsHookEx>

WH_CALLWNDPROC      equ 4
WH_CALLWNDPROCRET   equ 12
WH_CBT              equ 5
WH_DEBUG            equ 9
WH_FOREGROUNDIDLE   equ 11
WH_GETMESSAGE       equ 3
WH_JOURNALPLAYBACK  equ 1
WH_JOURNALRECORD    equ 0
WH_KEYBOARD         equ 2
WH_KEYBOARD_LL      equ 13
WH_MOUSE            equ 7
WH_MOUSE_LL         equ 14
WH_MSGFILTER        equ -1
WH_SHELL            equ 10
WH_SYSMSGFILTER     equ 6

UnhookWindowsHookEx proto WINAPI,
    hhk:    HHOOK
;ret BOOL

;Multiple Document Interface
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms632591.aspx>
;The multiple-document interface (MDI) is a specification that defines a user interface for applications that enable the user to work with more than one document at the same time. 

WM_MDIACTIVATE      equ 0222h
WM_MDICASCADE       equ 0227h
WM_MDICREATE        equ 0220h
WM_MDIDESTROY       equ 0221h
WM_MDIGETACTIVE     equ 0229h
WM_MDIICONARRANGE   equ 0228h
WM_MDIMAXIMIZE      equ 0225h
WM_MDINEXT          equ 0224h
WM_MDIREFRESHMENU   equ 0234h
WM_MDIRESTORE       equ 0223h
WM_MDISETMENU       equ 0230h
WM_MDITILE          equ 0226h

MDICREATESTRUCTA    struct
    szClass LPCSTR  ?
    szTitle LPCSTR  ?
    hOwner  HANDLE  ?
    x       sdword  ?
    y       sdword  ?
    _cx     sdword  ?
    cy      sdword  ?
    style   dword   ?
    lParam  LPARAM  ?
MDICREATESTRUCTA    ends

MDICREATESTRUCTW    struct
    szClass LPCWSTR ?
    szTitle LPCWSTR ?
    hOwner  HANDLE  ?
    x       sdword  ?
    y       sdword  ?
    _cx     sdword  ?
    cy      sdword  ?
    style   dword   ?
    lParam  LPARAM  ?
MDICREATESTRUCTW    ends
__AW <MDICREATESTRUCT>
LPMDICREATESTRUCT   typedef ptr MDICREATESTRUCT

CreateMDIWindowA    proto WINAPI,
    lpClassName:    LPCSTR,
    lpWindowName:   LPCSTR,
    dwStyle:        dword,
    X:              sdword,
    Y:              sdword,
    nWidth:         sdword,
    nHeight:        sdword,
    hWndParent:     HWND,
    hInstance:      HINSTANCE,
    lParam:         LPARAM
;ret HWND

CreateMDIWindowW    proto WINAPI,
    lpClassName:    LPCWSTR,
    lpWindowName:   LPCWSTR,
    dwStyle:        dword,
    X:              sdword,
    Y:              sdword,
    nWidth:         sdword,
    nHeight:        sdword,
    hWndParent:     HWND,
    hInstance:      HINSTANCE,
    lParam:         LPARAM
;ret HWND
__AW <CreateMDIWindow>

DefFrameProcA   proto WINAPI,
    hWnd:           HWND,
    hWndMDIClient:  HWND,
    uMsg:           UINT,
    wParam:         WPARAM,
    lParam:         LPARAM
;ret LRESULT

DefFrameProcW   proto WINAPI,
    hWnd:           HWND,
    hWndMDIClient:  HWND,
    uMsg:           UINT,
    wParam:         WPARAM,
    lParam:         LPARAM
;ret LRESULT
__AW <DefFrameProc>

DefMDIChildProcA    proto WINAPI,
    hWnd:   HWND,
    uMsg:   UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret LRESULT

DefMDIChildProcW    proto WINAPI,
    hWnd:   HWND,
    uMsg:   UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret LRESULT
__AW <DefMDIChildProc>

TranslateMDISysAccel    proto WINAPI,
    hWndClient: HWND,
    lpMsg:      LPMSG
;ret BOOL

;Painting and Drawing
;<https://msdn.microsoft.com/en-us/library/dd162759.aspx>

WM_DISPLAYCHANGE    equ 007eh
WM_NCPAINT          equ 0085h
WM_PAINT            equ 000fh
WM_PRINT            equ 0317h
WM_PRINTCLIENT      equ 0138h
WM_SETREDRAW        equ 000bh
WM_SYNCPAINT        equ 0088h
PRF_CHECKVISIBLE    equ 00000001h
PRF_CHILDREN        equ 00000010h
PRF_CLIENT          equ 00000004h
PRF_ERASEBKGND      equ 00000008h
PRF_NONCLIENT       equ 00000002h
PRF_OWNED           equ 00000020h

PAINTSTRUCT struct
    hdc         HDC     ?
    fErase      BOOL    ?
    rcPaint     RECT    {}
    fRestore    BOOL    ?
    fIncUpdate  BOOL    ?
    rgbReserved byte    32 dup(?)
PAINTSTRUCT ends
PPAINTSTRUCT    typedef ptr PAINTSTRUCT
LPPAINTSTRUCT   typedef ptr PAINTSTRUCT

BeginPaint  proto WINAPI,
    hwnd:   HWND,
    lpPaint:LPPAINTSTRUCT
;ret HDC

DrawAnimatedRects   proto WINAPI,
    hwnd:       HWND,
    idAni:      sdword,
    lprcFrom:   PRECT,
    lprcTo:     PRECT
;ret BOOL

IDANI_OPEN      equ 1
IDANI_CAPTION   equ 3

DrawCaption proto WINAPI,
    hwnd:   HWND,
    hdc:    HDC,
    lprc:   LPCRECT,
    uFlags: UINT
;ret BOOL

DC_ACTIVE   equ 0001h
DC_BUTTONS  equ 1000h
DC_GRADIENT equ 0020h
DC_ICON     equ 0004h
DC_INBUTTON equ 0010h
DC_SMALLCAP equ 0002h
DC_TEXT     equ 0008h

DrawEdge    proto WINAPI,
    hdc:        HDC,
    qrc:        LPRECT,
    edge:       UINT,
    grfFlags:   UINT
;ret BOOL

BDR_RAISEDINNER             equ 0004h
BDR_SUNKENINNER             equ 0008h
BDR_RAISEDOUTER             equ 0001h
BDR_SUNKENOUTER             equ 0002h
EDGE_BUMP                   equ BDR_RAISEDOUTER or BDR_SUNKENINNER
EDGE_ETCHED                 equ BDR_SUNKENOUTER or BDR_RAISEDINNER
EDGE_RAISED                 equ BDR_RAISEDOUTER or BDR_RAISEDINNER
EDGE_SUNKEN                 equ BDR_SUNKENOUTER or BDR_SUNKENINNER
BF_ADJUST                   equ 2000h
BF_BOTTOM                   equ 0008h
BF_DIAGONAL                 equ 0010h
BF_FLAT                     equ 4000h
BF_LEFT                     equ 0001h
BF_MIDDLE                   equ 0800h
BF_MONO                     equ 8000h
BF_RIGHT                    equ 0004h
BF_SOFT                     equ 1000h
BF_TOP                      equ 0002h
BF_BOTTOMLEFT               equ BF_BOTTOM or BF_LEFT
BF_BOTTOMRIGHT              equ BF_BOTTOM or BF_RIGHT
BF_DIAGONAL_ENDBOTTOMLEFT   equ BF_DIAGONAL or BF_BOTTOM or BF_LEFT
BF_DIAGONAL_ENDBOTTOMRIGHT  equ BF_DIAGONAL or BF_BOTTOM or BF_RIGHT
BF_DIAGONAL_ENDTOPLEFT      equ BF_DIAGONAL or BF_TOP or BF_LEFT
BF_DIAGONAL_ENDTOPRIGHT     equ BF_DIAGONAL or BF_TOP or BF_RIGHT
BF_RECT                     equ BF_LEFT or BF_TOP or BF_RIGHT or BF_BOTTOM
BF_TOPLEFT                  equ BF_TOP or BF_LEFT
BF_TOPRIGHT                 equ BF_TOP or BF_RIGHT

DrawFocusRect   proto WINAPI,
    hDC:    HDC,
    lprc:   PRECT
;ret BOOL

DrawFrameControl    proto WINAPI,
    hdc:    HDC,
    lprc:   LPRECT,
    uType:  UINT,
    uState: UINT
;ret BOOL

DFC_BUTTON     equ 4
DFC_CAPTION    equ 1
DFC_MENU       equ 2
DFC_POPUPMENU  equ 5
DFC_SCROLL     equ 3

DFCS_BUTTON3STATE           equ 0008h
DFCS_BUTTONCHECK            equ 0000h
DFCS_BUTTONPUSH             equ 0010h
DFCS_BUTTONRADIO            equ 0004h
DFCS_BUTTONRADIOIMAGE       equ 0001h
DFCS_BUTTONRADIOMASK        equ 0002h
DFCS_CAPTIONCLOSE           equ 0000h
DFCS_CAPTIONHELP            equ 0004h
DFCS_CAPTIONMAX             equ 0002h
DFCS_CAPTIONMIN             equ 0001h
DFCS_CAPTIONRESTORE         equ 0003h
DFCS_MENUARROW              equ 0000h
DFCS_MENUARROWRIGHT         equ 0004h
DFCS_MENUBULLET             equ 0002h
DFCS_MENUCHECK              equ 0001h
DFCS_SCROLLCOMBOBOX         equ 0005h
DFCS_SCROLLDOWN             equ 0001h
DFCS_SCROLLLEFT             equ 0002h
DFCS_SCROLLRIGHT            equ 0003h
DFCS_SCROLLSIZEGRIP         equ 0008h
DFCS_SCROLLSIZEGRIPRIGHT    equ 0010h
DFCS_SCROLLUP               equ 0000h
DFCS_ADJUSTRECT             equ 2000h
DFCS_CHECKED                equ 0400h
DFCS_FLAT                   equ 4000h
DFCS_HOT                    equ 1000h
DFCS_INACTIVE               equ 0100h
DFCS_MONO                   equ 8000h
DFCS_PUSHED                 equ 0200h
DFCS_TRANSPARENT            equ 0800h

DrawStateProc_t typedef proto WINAPI,
    hdc:    HDC,
    lData:  LPARAM,
    wData:  WPARAM,
    _cx:    sdword,
    cy:     sdword
;ret BOOL
DRAWSTATEPROC   typedef ptr DrawStateProc_t

DrawStateA  proto WINAPI,
    hdc:            HDC,
    hbr:            HBRUSH,
    lpOutputFunc:   DRAWSTATEPROC,
    lData:          LPARAM,
    wData:          WPARAM,
    x:              sdword,
    y:              sdword,
    _cx:            sdword,
    cy:             sdword,
    fuFlags:        UINT
;ret BOOL

DrawStateW  proto WINAPI,
    hdc:            HDC,
    hbr:            HBRUSH,
    lpOutputFunc:   DRAWSTATEPROC,
    lData:          LPARAM,
    wData:          WPARAM,
    x:              sdword,
    y:              sdword,
    _cx:            sdword,
    cy:             sdword,
    fuFlags:        UINT
;ret BOOL
__AW <DrawState>    

DST_BITMAP      equ 0004h
DST_COMPLEX     equ 0000h
DST_ICON        equ 0003h
DST_PREFIXTEXT  equ 0002h
DST_TEXT        equ 0001h
DSS_DISABLED    equ 0020h
DSS_HIDEPREFIX  equ 0200h
DSS_MONO        equ 0080h
DSS_NORMAL      equ 0000h
DSS_PREFIXONLY  equ 0400h
DSS_RIGHT       equ 8000h
DSS_UNION       equ 0010h

EndPaint    proto WINAPI,
    hWnd:   HWND,
    lpPaint:LPPAINTSTRUCT
;ret BOOL

ExcludeUpdateRgn    proto WINAPI,
    hDC:    HDC,
    hWnd:   HWND
;ret sdword

COMPLEXREGION   equ 3
_ERROR          equ 0
NULLREGION      equ 1
SIMPLEREGION    equ 2

GetUpdateRect   proto WINAPI,
    hWnd:   HWND,
    lpRect: LPRECT,
    bErase: BOOL
;ret BOOL

GetUpdateRgn    proto WINAPI,
    hWnd:   HWND,
    hRgn:   HRGN,
    bErase: BOOL
;ret sdword

GetWindowDC proto WINAPI,
    hWnd:   HWND
;ret HDC

GetWindowRgn    proto WINAPI,
    hWnd:   HWND,
    hRgn:   HRGN
;ret sdword

GetWindowRgnBox proto WINAPI,
    hWnd:   HWND,
    lprc:   LPRECT
;ret sdword

OutputProc_t    typedef proto WINAPI,
    hdc:    HDC,
    lpData: LPARAM,
    cchData:sdword
;ret BOOL
GRAYSTRINGPROC  typedef ptr OutputProc_t

GrayStringA proto WINAPI,
    hDC:            HDC,
    hBrush:         HBRUSH,
    lpOutputFunc:   GRAYSTRINGPROC,
    lpData:         LPARAM,
    nCount:         sdword,
    X:              sdword,
    Y:              sdword,
    nWidth:         sdword,
    nHeight:        sdword
;ret BOOL

GrayStringW proto WINAPI,
    hDC:            HDC,
    hBrush:         HBRUSH,
    lpOutputFunc:   GRAYSTRINGPROC,
    lpData:         LPARAM,
    nCount:         sdword,
    X:              sdword,
    Y:              sdword,
    nWidth:         sdword,
    nHeight:        sdword
;ret BOOL
__AW <GrayString>

InvalidateRect  proto WINAPI,
    hWnd:   HWND,
    lpRect: LPRECT,
    bErase: BOOL
;ret BOOL

InvalidateRgn   proto WINAPI,
    hWnd:   HWND,
    hRgn:   HRGN,
    bErase: BOOL
;ret BOOL

LockWindowUpdate    proto WINAPI,
    hWndLock:   HWND
;ret BOOL

PaintDesktop    proto WINAPI,
    hdc:    HDC
;ret BOOL

RedrawWindow    proto WINAPI,
    hWnd:       HWND,
    lprcUpdate: LPRECT,
    hrgnUpdate: HRGN,
    flags:      UINT
;ret BOOL

RDW_ERASE           equ 0004h
RDW_FRAME           equ 0400h
RDW_INTERNALPAINT   equ 0002h
RDW_INVALIDATE      equ 0001h
RDW_NOERASE         equ 0020h
RDW_NOFRAME         equ 0800h
RDW_NOINTERNALPAINT equ 0010h
RDW_VALIDATE        equ 0008h
RDW_ERASENOW        equ 0200h
RDW_UPDATENOW       equ 0100h
RDW_ALLCHILDREN     equ 0080h
RDW_NOCHILDREN      equ 0040h

SetWindowRgn    proto WINAPI,
    hWnd:   HWND,
    hRgn:   HRGN,
    bRedraw:BOOL
;ret sdword

UpdateWindow    proto WINAPI,
    hWnd:   HWND
;ret BOOL

ValidateRect    proto WINAPI,
    hWnd:   HWND,
    lpRect: LPRECT
;ret BOOL

ValidateRgn proto WINAPI,
    hWnd:   HWND,
    hRgn:   HRGN
;ret BOOL

FrameRect   proto WINAPI,
    hDC:    HDC,
    lprc:   LPRECT,
    hbr:    HBRUSH
;ret sdword

InvertRect  proto WINAPI,
    hDC:    HDC,
    lprc:   LPRECT
;ret BOOL

;Resources
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ff468900.aspx>
RT_ACCELERATOR  equ 9
RT_ANICURSOR    equ 21
RT_ANIICON      equ 22
RT_BITMAP       equ 2
RT_CURSOR       equ 1
RT_DIALOG       equ 5
RT_DLGINCLUDE   equ 17
RT_FONT         equ 8
RT_FONTDIR      equ 7
RT_HTML         equ 23
RT_ICON         equ 3
RT_MANIFEST     equ 24
RT_MENU         equ 4
RT_MESSAGETABLE equ 11
RT_PLUGPLAY     equ 19
RT_RCDATA       equ 10
RT_STRING       equ 6
RT_VERSION      equ 16
RT_VXD          equ 20
RT_GROUP_CURSOR equ RT_CURSOR + 11
RT_GROUP_ICON   equ RT_ICON + 11

FVIRTKEY    equ TRUE
FNOINVERT   equ 02h
FSHIFT      equ 04h
FCONTROL    equ 08h
FALT        equ 10h

MFR_END     equ 80h
MFR_POPUP   equ 01h

CURSORSHAPE struct
    xHotSpot    sdword  ?
    yHotSpot    sdword  ?
    cx_         sdword  ?
    cy          sdword  ?
    cbWidth     sdword  ?
    Planes      byte    ?
    BitsPixel   byte    ?
CURSORSHAPE ends

CopyImage   proto WINAPI,
    hImage:     HANDLE,
    uType:      UINT,
    cxDesired:  sdword,
    cyDesired:  sdword,
    fuFlags:    UINT
;ret HANDLE

IMAGE_BITMAP    equ 0
IMAGE_CURSOR    equ 2
IMAGE_ICON      equ 1

LR_COPYDELETEORG    equ 00000008h
LR_COPYFROMRESOURCE equ 00004000h
LR_COPYRETURNORG    equ 00000004h
LR_CREATEDIBSECTION equ 00002000h
LR_DEFAULTSIZE      equ 00000040h
LR_MONOCHROME       equ 00000001h

LoadImageA  proto WINAPI,
    hinst:      HINSTANCE,
    lpszName:   LPCSTR,
    uType:      UINT,
    cxDesired:  sdword,
    cyDesired:  sdword,
    fuLoad:     UINT
;ret HANDLE
LoadImageW  proto WINAPI,
    hinst:      HINSTANCE,
    lpszName:   LPCWSTR,
    uType:      UINT,
    cxDesired:  sdword,
    cyDesired:  sdword,
    fuLoad:     UINT
;ret HANDLE
__AW <LoadImage>

OBM_BTNCORNERS equ 32758
OBM_BTSIZE equ 32761
OBM_CHECK equ 32760
OBM_CHECKBOXES equ 32759
OBM_CLOSE equ 32754
OBM_COMBO equ 32738
OBM_DNARROW equ 32752
OBM_DNARROWD equ 32742
OBM_DNARROWI equ 32736
OBM_LFARROW equ 32750
OBM_LFARROWI equ 32734
OBM_LFARROWD equ 32740
OBM_MNARROW equ 32739
OBM_OLD_CLOSE equ 32767
OBM_OLD_DNARROW equ 32764
OBM_OLD_LFARROW equ 32762
OBM_OLD_REDUCE equ 32757
OBM_OLD_RESTORE equ 32755
OBM_OLD_RGARROW equ 32763
OBM_OLD_UPARROW equ 32765
OBM_OLD_ZOOM equ 32756
OBM_REDUCE equ 32749
OBM_REDUCED equ 32746
OBM_RESTORE equ 32747
OBM_RESTORED equ 32744
OBM_RGARROW equ 32751
OBM_RGARROWD equ 32741
OBM_RGARROWI equ 32735
OBM_SIZE equ 32766
OBM_UPARROW equ 32753
OBM_UPARROWD equ 32743
OBM_UPARROWI equ 32737
OBM_ZOOM equ 32748
OBM_ZOOMD equ 32745
OCR_NORMAL equ 32512
OCR_IBEAM equ 32513
OCR_WAIT equ 32514
OCR_CROSS equ 32515
OCR_UP equ 32516
OCR_SIZE equ 32640
OCR_ICON equ 32641
OCR_SIZENWSE equ 32642
OCR_SIZENESW equ 32643
OCR_SIZEWE equ 32644
OCR_SIZENS equ 32645
OCR_SIZEALL equ 32646
OCR_NO equ 32648
OCR_APPSTARTING equ 32650
OIC_SAMPLE equ 32512
OIC_HAND equ 32513
OIC_QUES equ 32514
OIC_BANG equ 32515
OIC_NOTE equ 32516
OIC_WINLOGO equ 32517
OIC_WARNING equ OIC_BANG
OIC_ERROR equ OIC_HAND
OIC_INFORMATION equ OIC_NOTE

LR_DEFAULTCOLOR     equ 00000000h
LR_LOADFROMFILE     equ 00000010h
LR_LOADMAP3DCOLORS  equ 00001000h
LR_LOADTRANSPARENT  equ 00000020h
LR_SHARED           equ 00008000h
LR_VGACOLOR         equ 00000080h

;Carets
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms646968.aspx>
;A caret is a blinking line, block, or bitmap in the client area of a window. The caret typically indicates the place at which text or graphics will be inserted.
;Applications can create a caret, change its blink time, and display, hide, or relocate the caret.
CreateCaret proto WINAPI,
    hWnd:   HWND,
    hBitmap:HBITMAP,
    nWidth: sdword,
    nHeight:sdword
;ret BOOL

DestroyCaret    proto WINAPI    ;ret BOOL

GetCaretBlinkTime   proto WINAPI    ;ret UINT

GetCaretPos proto WINAPI,
    lpPoint:LPPOINT
;ret BOOL

HideCaret   proto WINAPI,
    hWnd:   HWND
;ret BOOL

SetCaretBlinkTime   proto WINAPI,
    uMSeconds:  UINT
;ret BOOL

SetCaretPos proto WINAPI,
    X:  sdword,
    Y:  sdword
;ret BOOL

ShowCaret   proto WINAPI,
    hWnd:   HWND
;ret BOOL

;Cursors
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms646970.aspx>
;A cursor is a small picture whose location on the screen is controlled by a pointing device, such as a mouse, pen, or trackball. In the remainder of this overview, the
;term mouse refers to any pointing device. 
;When the user moves the mouse, the system moves the cursor accordingly. The cursor functions enable applications to create, load, display, animate, move, confine, and
;destroy cursors.
WM_SETCURSOR    equ 0020h

CURSORINFO  struct
    cbSize      dword   ?
    flags       dword   ?
    hCursor     HCURSOR ?
    ptScreenPos POINT   {}
CURSORINFO ends
PCURSORINFO typedef ptr CURSORINFO
LPCURSORINFO    typedef ptr CURSORINFO

CURSOR_SHOWING      equ 00000001h
CURSOR_SUPPRESSED   equ 00000002h

ClipCursor  proto WINAPI,
    lpRect: LPRECT
;ret BOOL

CopyCursor  textequ <CopyIcon>

CreateCursor    proto WINAPI,
    hInst:          HINSTANCE,
    xHotSpot:       sdword,
    yHotSpot:       sdword,
    nWidth:         sdword,
    nHeight:        sdword,
    pvANDPlane:     PVOID,
    pvXORPlane:     PVOID
;ret HCURSOR

DestroyCursor   proto WINAPI,
    hCursor:HCURSOR
;ret BOOL

GetClipCursor   proto WINAPI,
    lpRect: LPRECT
;ret BOOL

GetCursor   proto WINAPI    ;ret HCURSOR

GetCursorInfo   proto WINAPI,
    pci:PCURSORINFO
;ret BOOL

GetCursorPos    proto WINAPI,
    lpPoint:LPPOINT
;ret BOOL

GetPhysicalCursorPos    proto WINAPI,
    lpPoint:LPPOINT
;ret BOOL

LoadCursorA proto WINAPI,
    hInstance:      HINSTANCE,
    lpCursorName:   LPCSTR
;ret HCURSOR
LoadCursorW proto WINAPI,
    hInstance:      HINSTANCE,
    lpCursorName:   LPCWSTR
;ret HCURSOR
__AW <LoadCursor>

IDC_APPSTARTING equ 32650
IDC_ARROW       equ 32512
IDC_CROSS       equ 32515
IDC_HAND        equ 32649
IDC_HELP        equ 32651
IDC_IBEAM       equ 32513
IDC_ICON        equ 32641
IDC_NO          equ 32648
IDC_SIZE        equ 32640
IDC_SIZEALL     equ 32646
IDC_SIZENESW    equ 32643
IDC_SIZENS      equ 32645
IDC_SIZENWSE    equ 32642
IDC_SIZEWE      equ 32644
IDC_UPARROW     equ 32516
IDC_WAIT        equ 32514

LoadCursorFromFileA proto WINAPI,
    lpFileName: LPCSTR
;ret HCURSOR
LoadCursorFromFileW proto WINAPI,
    lpFileName: LPCWSTR
;ret HCURSOR
__AW <LoadCursorFromFile>

SetCursor   proto WINAPI,
    hCursor:HCURSOR
;ret HCURSOR

SetCursorPos    proto WINAPI,
    X:  sdword,
    Y:  sdword
;ret BOOL

SetPhysicalCursorPos    proto WINAPI,
    X:  sdword,
    Y:  sdword
;ret BOOL

SetSystemCursor proto WINAPI,
    hcur:   HCURSOR,
    id:     dword
;ret BOOL

ShowCursor  proto WINAPI,
    bShow:  BOOL
;ret sdword

;Icons
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms646973.aspx>
;An icon is a picture that consists of a bitmap image combined with a mask to create transparent areas in the picture. The term icon can refer to either of the following: 
;•A single icon image. This is a resource of type RT_ICON.
;•A group of images, from which the system or an application can choose the most appropriate icon based on size and color depth. This is a resource of type RT_GROUP_ICON.
ICONINFO    struct
    fIcon       BOOL    ?
    xHotspot    dword   ?
    yHotspot    dword   ?
    hbmMask     HBITMAP ?
    hbmColor    HBITMAP ?
ICONINFO    ends
PICONINFO   typedef ptr ICONINFO

ICONINFOEXA struct
    cbSize      dword   ?
    fIcon       BOOL    ?
    xHotspot    dword   ?
    yHotspot    dword   ?
    hbmMask     HBITMAP ?
    hbmColor    HBITMAP ?
    wResID      word    ?
    szModName   CHAR    MAX_PATH dup(?)
    szResName   CHAR    MAX_PATH dup(?)
ICONINFOEXA ends
PICONINFOEXA    typedef ptr ICONINFOEXA
ICONINFOEXW struct
    cbSize      dword   ?
    fIcon       BOOL    ?
    xHotspot    dword   ?
    yHotspot    dword   ?
    hbmMask     HBITMAP ?
    hbmColor    HBITMAP ?
    wResID      word    ?
    szModName   WCHAR   MAX_PATH dup(?)
    szResName   WCHAR   MAX_PATH dup(?)
ICONINFOEXW ends
PICONINFOEXW    typedef ptr ICONINFOEXW
__AW <ICONINFOEX>

ICONMETRICSA    struct
    cbSize          UINT        ?
    iHorzSpacing    sdword      ?
    iVertSpacing    sdword      ?
    iTitleWrap      sdword      ?
    lfFont          LOGFONTA    {}
ICONMETRICSA    ends
ICONMETRICSW    struct
    cbSize          UINT        ?
    iHorzSpacing    sdword      ?
    iVertSpacing    sdword      ?
    iTitleWrap      sdword      ?
    lfFont          LOGFONTW    {}
ICONMETRICSW    ends
__AW <ICONMETRICS>
PICONMETRICS    typedef ptr ICONMETRICS
LPICONMETRICS   typedef ptr ICONMETRICS

CopyIcon    proto WINAPI,
    hIcon:  HICON
;ret HICON

CreateIcon  proto WINAPI,
    hInstance:  HINSTANCE,
    nWidth:     sdword,
    nHeight:    sdword,
    cPlanes:    byte,
    cBitsPixel: byte,
    lpbANDbits: ptr byte,
    lpbXORbits: ptr byte
;ret HICON

CreateIconFromResource  proto WINAPI,
    presbits:   PBYTE,
    dwResSize:  dword,
    fIcon:      BOOL,
    dwVer:      dword
;ret HICON

CreateIconFormResourceEx    proto WINAPI,
    pbIconBits: PBYTE,
    cbIconBits: dword,
    fIcon:      BOOL,
    dwVersion:  dword,
    cxDesired:  sdword,
    cyDesired:  sdword,
    uFlags:     UINT
;ret HICON

CreateIconIndirect  proto WINAPI,
    piconinfo:  PICONINFO
;ret HICON

DestroyIcon proto WINAPI,
    hIcon:  HICON
;ret BOOL

DrawIcon    proto WINAPI,
    hDC:    HDC,
    X:      sdword,
    Y:      sdword,
    hIcon:  HICON
;ret BOOL

DrawIconEx  proto WINAPI,
    hdc:                HDC,
    xLeft:              sdword,
    yTop:               sdword,
    hIcon:              HICON,
    cxWidth:            sdword,
    cyWidth:            sdword,
    istepIfAniCur:      UINT,
    hbrFlickerFreeDraw: HBRUSH,
    diFlags:            UINT
;ret BOOL

DI_COMPAT       equ 0004h
DI_DEFAULTSIZE  equ 0008h
DI_IMAGE        equ 0002h
DI_MASK         equ 0001h
DI_NOMIRROR     equ 0010h
DI_NORMAL       equ 0003h

GetIconInfo proto WINAPI,
    hIcon:      HICON,
    piconinfo:  PICONINFO
;ret BOOL

IDI_APPLICATION equ 32512
IDI_ASTERISK    equ 32516
IDI_EXCLAMATION equ 32515
IDI_HAND        equ 32513
IDI_QUESTION    equ 32514
IDI_WINLOGO     equ 32517

GetIconInfoExA  proto WINAPI,
    hIcon:      HICON,
    piconinfoex:PICONINFOEXA
;ret BOOL
GetIconInfoExW  proto WINAPI,
    hIcon:      HICON,
    piconinfoex:PICONINFOEXW
;ret BOOL
__AW <GetIconInfoEx>

LoadIconA   proto WINAPI,
    hInstance:  HINSTANCE,
    lpIconName: LPCSTR
;ret HICON
LoadIconW   proto WINAPI,
    hInstance:  HINSTANCE,
    lpIconName: LPCWSTR
;ret HICON
__AW <LoadIcon>

LookupIconIdFromDirectory   proto WINAPI,
    presbits:   PBYTE,
    fIcon:      BOOL
;ret sdword

LookupIconIdFromDirectoryEx proto WINAPI,
    presbits:   PBYTE,
    fIcon:      BOOL,
    cxDesired:  sdword,
    cyDesired:  sdword,
    Flags:      UINT
;ret sdword

PrivateExtractIconsA    proto WINAPI,
    lpszFile:   LPCSTR,
    nIconIndex: sdword,
    cxIcon:     sdword,
    cyIcon:     sdword,
    phicon:     ptr HICON,
    piconid:    ptr UINT,
    nIcons:     UINT,
    flags:      UINT
;ret UINT
PrivateExtractIconsW    proto WINAPI,
    lpszFile:   LPCWSTR,
    nIconIndex: sdword,
    cxIcon:     sdword,
    cyIcon:     sdword,
    phicon:     ptr HICON,
    piconid:    ptr UINT,
    nIcons:     UINT,
    flags:      UINT
;ret UINT
__AW <PrivateExtractIcons>

;Keyboard Accelerators
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms645526.aspx>
;A keyboard accelerator (or, simply, accelerator) is a keystroke or combination of keystrokes that generates a WM_COMMAND or WM_SYSCOMMAND message for an application. 
WM_CHANGEUISTATE    equ 0127h
UIS_CLEAR       equ 2
UIS_INITIALIZE  equ 3
UIS_SET         equ 1
UISF_ACTIVE     equ 4h
UISF_HIDEACCEL  equ 2h
UISF_HIDEFOCUS  equ 1h
WM_INITMENU         equ 0116h
WM_QUERYUISTATE     equ 0129h
WM_UPDATEUISTATE    equ 0128h
WM_INITMENUPOPUP    equ 0117h
WM_MENUCHAR         equ 0120h
MF_POPUP    equ 00000010h
MF_SYSMENU  equ 00002000h
MNC_CLOSE   equ 1
MNC_EXECUTE equ 2
MNC_IGNORE  equ 0
MNC_SELECT  equ 3
WM_MENUSELECT   equ 011fh
MF_BITMAP       equ 00000004h
MF_CHECKED      equ 00000008h
MF_DISABLED     equ 00000002h
MF_GRAYED       equ 00000001h
MF_HILITE       equ 00000080h
MF_MOUSESELECT  equ 00008000h
MF_OWNERDRAW    equ 00000100h
WM_SYSCHAR      equ 0106h
WM_SYSCOMMMAND  equ 0112h
SC_CLOSE        equ 0f060h
SC_CONTEXTHELP  equ 0f180h
SC_DEFAULT      equ 0f160h
SC_HOTKEY       equ 0f150h
SC_HSCROLL      equ 0f080h
SC_ISSECURE     equ 00000001h
SC_KEYMENU      equ 0f100h
SC_MAXIMIZE     equ 0f030h
SC_MINIMIZE     equ 0f020h
SC_MONITORPOWER equ 0f170h
SC_MOUSEMENU    equ 0f090h
SC_MOVE         equ 0f010h
SC_NEXTWINDOW   equ 0f040h
SC_PREVWINDOW   equ 0f050h
SC_RESTORE      equ 0f120h
SC_SCREENSAVE   equ 0f140h
SC_SIZE         equ 0f000h
SC_TASKLIST     equ 0f130h
SC_VSCROLL      equ 0f070h

ACCEL   struct
    fVirt   byte    ?
    key     word    ?
    cmd     word    ?
ACCEL   ends
LPACCEL typedef ptr ACCEL

CopyAcceleratorTableA   proto WINAPI,
    hAccelSrc:      HACCEL,
    lpAccelDst:     LPACCEL,
    cAccelEntries:  sdword
;ret sdword
CopyAcceleratorTableW   proto WINAPI,
    hAccelSrc:      HACCEL,
    lpAccelDst:     LPACCEL,
    cAccelEntries:  sdword
;ret sdword
__AW <CopyAcceleratorTable>

CreateAcceleratorTableA proto WINAPI,
    lpaccl:     LPACCEL,
    cEntries:   sdword
;ret HACCEL
CreateAcceleratorTableW proto WINAPI,
    lpaccl:     LPACCEL,
    cEntries:   sdword
;ret HACCEL
__AW <CreateAcceleratorTable>

DestroyAcceleratorTable proto WINAPI,
    hAccel: HACCEL
;ret BOOL

LoadAcceleratorsA   proto WINAPI,
    hInstance:  HINSTANCE,
    lpTableName:LPCSTR
;ret HACCEL
LoadAcceleratorsW   proto WINAPI,
    hInstance:  HINSTANCE,
    lpTableName:LPCWSTR
;ret HACCEL
__AW <LoadAccelerators>

TranslateAcceleratorA   proto WINAPI,
    hWnd:       HWND,
    hAccTable:  HACCEL,
    lpMsg:      LPMSG
;ret sdword

;Menus
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms646977.aspx>
WM_COMMAND              equ 0111h
WM_CONTEXTMENU          equ 007bh
WM_ENTERMENULOOP        equ 0211h
WM_EXITMENULOOP         equ 0212h
WM_GETTITLEBARINFOEX    equ 033fh
WM_MENUCOMMAND          equ 0126h
WM_MENUDRAG             equ 0123h
MND_CONTINUE    equ 0
MND_ENDMENU     equ 1
WM_MENUGETOBJECT        equ 0124h
MNGO_NOERROR        equ 00000001h
MNGO_NOINTERFACE    equ 00000000h
WM_MENURBUTTONUP    equ 0122h
WM_NEXTMENU         equ 0213h
WM_UNINITMENUPOPUP  equ 0125h

MDINEXTMENU struct
    hmenuIn     HMENU   ?
    hmenuNext   HMENU   ?
    hwndNext    HWND    ?
MDINEXTMENU ends
PMDINEXTMENU    typedef ptr MDINEXTMENU

MENUBARINFO struct
    cbSize      dword   ?
    rcBar       RECT    {}
    hMenu       HMENU   ?
    hwndMenu    HWND    ?
    fBarFocused BOOL    ?
    fFocused    BOOL    ?
MENUBARINFO ends
PMENUBARINFO    typedef ptr MENUBARINFO

MENUGETOBJECTINFO   struct
    dwFlags dword   ?
    uPos    UINT    ?
    hmenu   HMENU   ?
    riid    PVOID   ?
    pvObj   PVOID   ?
MENUGETOBJECTINFO   ends
PMENUGETOBJECTINFO  typedef ptr MENUGETOBJECTINFO
MNGOF_BOTTOMGAP equ 00000002h
MNGOF_TOPGAP    equ 00000001h

MENUINFO    struct
    cbSize          dword       ?
    fMask           dword       ?
    dwStyle         dword       ?
    cyMax           UINT        ?
    hbrBack         HBRUSH      ?
    dwContextHelpID dword       ?
    dwMenuData      ULONG_PTR   ?
MENUINFO    ends
LPMENUINFO  typedef ptr MENUINFO
LPCMENUINFO typedef ptr MENUINFO
MIM_APPLYTOSUBMENUS equ 80000000h
MIM_BACKGROUND      equ 00000002h
MIM_HELPID          equ 00000004h
MIM_MAXHEIGHT       equ 00000001h
MIM_MENUDATA        equ 00000008h
MIM_STYLE           equ 00000010h
MNS_AUTODISMISS equ 10000000h
MNS_CHECKORBMP  equ 04000000h
MNS_DRAGDROP    equ 20000000h
MNS_MODELESS    equ 40000000h
MNS_NOCHECK     equ 80000000h
MNS_NOTIFYBYPOS equ 08000000h

MENUITEMINFOA   struct
    cbSize          UINT        ?
    fMask           UINT        ?
    fType           UINT        ?
    fState          UINT        ?
    wID             UINT        ?
    hSubMenu        HMENU       ?
    hbmpChecked     HBITMAP     ?
    hbmpUnchecked   HBITMAP     ?
    dwItemData      ULONG_PTR   ?
    dwTypeData      LPSTR       ?
    cch             UINT        ?
    hbmpItem        HBITMAP     ?
MENUITEMINFOA   ends
LPMENUITEMINFOA typedef ptr MENUITEMINFOA
LPCMENUITEMINFOA    typedef ptr MENUITEMINFOA
MENUITEMINFOW   struct
    cbSize          UINT        ?
    fMask           UINT        ?
    fType           UINT        ?
    fState          UINT        ?
    wID             UINT        ?
    hSubMenu        HMENU       ?
    hbmpChecked     HBITMAP     ?
    hbmpUnchecked   HBITMAP     ?
    dwItemData      ULONG_PTR   ?
    dwTypeData      LPWSTR      ?
    cch             UINT        ?
    hbmpItem        HBITMAP     ?
MENUITEMINFOW   ends
LPMENUITEMINFOW typedef ptr MENUITEMINFOW
LPCMENUITEMINFOW    typedef ptr MENUITEMINFOW
__AW <MENUITEMINFO>
LPMENUITEMINFO  typedef ptr MENUITEMINFO
LPCMENUITEMINFO typedef ptr MENUITEMINFO
MIIM_BITMAP     equ 00000080h
MIIM_CHECKMARKS equ 00000008h
MIIM_DATA       equ 00000020h
MIIM_FTYPE      equ 00000100h
MIIM_ID         equ 00000002h
MIIM_STATE      equ 00000001h
MIIM_STRING     equ 00000040h
MIIM_SUBMENU    equ 00000004h
MIIM_TYPE       equ 00000010h
MFT_BITMAP          equ 00000004h
MFT_MENUBARBREAK    equ 00000020h
MFT_MENUBREAK       equ 00000040h
MFT_OWNERDRAW       equ 00000100h
MFT_RADIOCHECK      equ 00000200h
MFT_RIGHTJUSTIFY    equ 00004000h
MFT_RIGHTORDER      equ 00002000h
MFT_SEPARATOR       equ 00000800h
MFT_STRING          equ 00000000h
MFS_CHECKED     equ 00000008h
MFS_DEFAULT     equ 00001000h
MFS_DISABLED    equ 00000003h
MFS_ENABLED     equ 00000000h
MFS_GRAYED      equ 00000003h
MFS_HILITE      equ 00000080h
MFS_UNCHECKED   equ 00000000h
MFS_UNHILITE    equ 00000000h
HBMMENU_CALLBACK        equ -1
HBMMENU_MBAR_CLOSE      equ 5
HBMMENU_MBAR_CLOSE_D    equ 6
HBMMENU_MBAR_MINIMIZE   equ 3
HBMMENU_MBAR_MINIMIZE_D equ 7
HBMMENU_MBAR_RESTORE    equ 2
HBMMENU_POPUP_CLOSE     equ 8
HBMMENU_POPUP_MAXIMIZE  equ 10
HBMMENU_POPUP_MINIMIZE  equ 11
HBMMENU_POPUP_RESTORE   equ 9
HBMMENU_SYSTEM          equ 1

MENUITEMTEMPLATE    struct
    mtOption    word    ?
    mtID        word    ?
    mtString    WCHAR   ?
MENUITEMTEMPLATE    ends
PMENUITEMTEMPLATE   typedef ptr MENUITEMTEMPLATE

MF_HELP         equ 00004000h
MF_MENUBARBREAK equ 00000020h
MF_MENUBREAK    equ 00000040h

MENUITEMTEMPLATEHEADER  struct
    versionNumber   word    ?
    offset_         word    ?
MENUITEMTEMPLATEHEADER  ends
PMENUITEMTEMPLATEHEADER typedef ptr MENUITEMTEMPLATEHEADER

TPMPARAMS   struct
    cbSize      UINT    ?
    rcExclude   RECT    {}
TPMPARAMS   ends
LPTPMPARAMS typedef ptr TPMPARAMS

AppendMenuA proto WINAPI,
    hMenu:      HMENU,
    uFlags:     UINT,
    uIDNewItem: UINT_PTR,
    lpNewItem:  LPCSTR
;ret BOOL
AppendMenuW proto WINAPI,
    hMenu:      HMENU,
    uFlags:     UINT,
    uIDNewItem: UINT_PTR,
    lpNewItem:  LPCWSTR
;ret BOOL
__AW <AppendMenu>

MF_ENABLED      equ 00000000h
MF_SEPARATOR    equ 00000800h
MF_STRING       equ 00000000h
MF_UNCHECKED    equ 00000000h

CheckMenuItem   proto WINAPI,
    hmenu:          HMENU,
    uIDCheckItem:   UINT,
    uCheck:         UINT
;ret dword

MF_BYCOMMAND    equ 00000000h
MF_BYPOSITION   equ 00000400h

CheckMenuRadioItem  proto WINAPI,
    hmenu:  HMENU,
    idFirst:UINT,
    idLast: UINT,
    idCheck:UINT,
    uFlags: UINT
;ret BOOL

CreateMenu  proto WINAPI    ;ret HMENU
CreatePopupMenu proto WINAPI    ;ret HMENU

DeleteMenu  proto WINAPI,
    hMenu:      HMENU,
    uPosition:  UINT,
    uFlags:     UINT
;ret BOOL

DestroyMenu proto WINAPI,
    hMenu:  HMENU
;ret BOOL

DrawMenuBar proto WINAPI,
    hWnd:   HWND
;ret BOOL

EnableMenuItem  proto WINAPI,
    hMenu:          HMENU,
    uIDEnableItem:  UINT,
    uEnable:        UINT
;ret BOOL

EndMenu proto WINAPI    ;ret BOOL

GetMenu proto WINAPI,
    hWnd:   HWND
;ret HMENU

GetMenuBarInfo  proto WINAPI,
    hwnd:       HWND,
    idObject:   LONG,
    idItem:     LONG,
    pmbi:       PMENUBARINFO
;ret BOOL

OBJID_CLIENT    equ 0fffffffch
OBJID_MENU      equ 0fffffffdh
OBJID_SYSMENU   equ 0ffffffffh

GetMenuCheckMarkDimensions  proto WINAPI    ;ret LONG

GetMenuDefaultItem  proto WINAPI,
    hMenu:      HMENU,
    fByPos:     UINT,
    gmdiFlags:  UINT
;ret UINT
GMDI_GOINTOPOPUPS   equ 0002h
GMDI_USEDISABLED    equ 0001h

GetMenuInfo proto WINAPI,
    hmenu:  HMENU,
    lpcmi:  LPMENUINFO
;ret BOOL

GetMenuItemCount    proto WINAPI,
    hMenu:  HMENU
;ret sdword

GetMenuItemID   proto WINAPI,
    hMenu:  HMENU,
    nPos:   sdword
;ret UINT

GetMenuItemInfoA    proto WINAPI,
    hMenu:      HMENU,
    uItem:      UINT,
    fByPosition:BOOL,
    lpmii:      LPMENUITEMINFOA
;ret BOOL
GetMenuItemInfoW    proto WINAPI,
    hMenu:      HMENU,
    uItem:      UINT,
    fByPosition:BOOL,
    lpmii:      LPMENUITEMINFOW
;ret BOOL
__AW <GetMenuItemInfo>

GetMenuItemRect proto WINAPI,
    hWnd:       HWND,
    hMenu:      HMENU,
    uItem:      UINT,
    lprcItem:   LPRECT
;ret BOOL

GetMenuState    proto WINAPI,
    hMenu:  HMENU,
    uId:    UINT,
    uFlags: UINT
;ret UINT

GetMenuStringA  proto WINAPI,
    hMenu:      HMENU,
    uIDItem:    UINT,
    lpString:   LPSTR,
    nMaxCount:  sdword,
    uFlag:      UINT
;ret sdword
GetMenuStringW  proto WINAPI,
    hMenu:      HMENU,
    uIDItem:    UINT,
    lpString:   LPWSTR,
    nMaxCount:  sdword,
    uFlag:      UINT
;ret sdword
__AW <GetMenuString>

GetSubMenu  proto WINAPI,
    hMenu:  HMENU,
    nPos:   sdword
;ret HMENU

GetSystemMenu   proto WINAPI,
    hWnd:   HWND,
    bRevert:BOOL
;ret HMENU

HiliteMenuItem  proto WINAPI,
    hwnd:       HWND,
    hmenu:      HMENU,
    uItemHilite:UINT,
    uHilite:    UINT
;ret BOOL

InsertMenuA proto WINAPI,
    hMenu:      HMENU,
    uPosition:  UINT,
    uFlags:     UINT,
    uIDNewItem: UINT_PTR,
    lpNewItem:  LPCSTR
;ret BOOL
InsertMenuW proto WINAPI,
    hMenu:      HMENU,
    uPosition:  UINT,
    uFlags:     UINT,
    uIDNewItem: UINT_PTR,
    lpNewItem:  LPCWSTR
;ret BOOL
__AW <InsertMenu>

InsertMenuItemA proto WINAPI,
    hMenu:      HMENU,
    uItem:      UINT,
    fByPosition:BOOL,
    lpmii:      LPCMENUITEMINFOA
;ret BOOL
InsertMenuItemW proto WINAPI,
    hMenu:      HMENU,
    uItem:      UINT,
    fByPosition:BOOL,
    lpmii:      LPCMENUITEMINFOW
;ret BOOL    
__AW <InsertMenuItem>

IsMenu  proto WINAPI,
    hMenu:  HMENU
;ret BOOL

LoadMenuA   proto WINAPI,
    hInstance:  HINSTANCE,
    lpMenuName: LPCSTR
;ret HMENU
LoadMenuW   proto WINAPI,
    hInstance:  HINSTANCE,
    lpMenuName: LPCWSTR
;ret HMENU
__AW <LoadMenu>

LoadMenuIndirectA   proto WINAPI,
    lpMenuTemplate: ptr MENUTEMPLATE
;ret HMENU
LoadMenuIndirectW   proto WINAPI,
    lpMenuTemplate: ptr MENUTEMPLATE
;ret HMENU
__AW <LoadMenuIndirect>

MenuItemFromPoint   proto WINAPI,
    hWnd:       HWND,
    hMenu:      HMENU,
    ptScreen:   POINT
;ret sdword

ModifyMenuA proto WINAPI,
    hMnu:       HMENU,
    uPosition:  UINT,
    uFlags:     UINT,
    uIDNewItem: UINT_PTR,
    lpNewItem:  LPCSTR
;ret BOOL
ModifyMenuW proto WINAPI,
    hMnu:       HMENU,
    uPosition:  UINT,
    uFlags:     UINT,
    uIDNewItem: UINT_PTR,
    lpNewItem:  LPCWSTR
;ret BOOL
__AW <ModifyMenu>

RemoveMenu  proto WINAPI,
    hMenu:      HMENU,
    uPosition:  UINT,
    uFlags:     UINT
;ret BOOL

SetMenu proto WINAPI,
    hWnd:   HWND,
    hMenu:  HMENU
;ret BOOL

SetMenuDefaultItem  proto WINAPI,
    hMenu:  HMENU,
    uItem:  UINT,
    fByPos: UINT
;ret BOOL

SetMenuInfo proto WINAPI,
    hmenu:  HMENU,
    lpcmi:  LPCMENUINFO
;ret BOOL

SetMenuItemBitmaps  proto WINAPI,
    hMenu:              HMENU,
    uPosition:          UINT,
    uFlags:             UINT,
    hBitmapUnchecked:   HBITMAP,
    hBitmapChecked:     HBITMAP
;ret BOOL

SetMenuItemInfo proto WINAPI,
    hMenu:      HMENU,
    uItem:      UINT,
    fByPosition:BOOL,
    lpmii:      LPMENUITEMINFO
;ret BOOL

TrackPopupMenu  proto WINAPI,
    hMenu:      HMENU,
    uFlags:     UINT,
    x:          sdword,
    y:          sdword,
    nReserved:  sdword,
    hWnd:       HWND,
    prcRect:    LPCRECT
;ret BOOL
TPM_NONOTIFY    equ 0080h
TPM_RETURNCMD   equ 0100h

TPM_LEFTBUTTON  equ 0000h
TPM_RIGHTBUTTON equ 0002h

TPM_HORNEGANIMATION equ 0800h
TPM_HORPOSANIMATION equ 0400h
TPM_NOANIMATION     equ 4000h
TPM_VERNEGANIMATION equ 2000h
TPM_VERPOSANIMATION equ 1000h

TrackPopupMenuEx    proto WINAPI,
    hmenu:  HMENU,
    fuFlags:UINT,
    x:      sdword,
    y:      sdword,
    hwnd:   HWND,
    lptpm:  LPTPMPARAMS
;ret BOOL

;Strings
;<http://msdn.microsoft.com/en-us/library/windows/desktop/ms646979.aspx>

CharLowerA  proto WINAPI,
    lpsz:   LPSTR
;ret LPSTR
CharLowerW  proto WINAPI,
    lpsz:   LPWSTR
;ret LPWSTR
__AW <CharLower>

CharLowerBuffA  proto WINAPI,
    lpsz:       LPSTR,
    cchLength:  dword
;ret dword
CharLowerBuffW  proto WINAPI,
    lpsz:       LPWSTR,
    cchLength:  dword
;ret dword
__AW <CharLowerBuff>

CharNextA   proto WINAPI,
    lpsz:   LPCSTR
;ret LPSTR
CharNextW   proto WINAPI,
    lpsz:   LPCWSTR
;ret LPWSTR
__AW <CharNext>

CharNextExA proto WINAPI,
    CodePage:       word,
    lpCurrentChar:  LPCSTR,
    dwFlags:        dword
;ret LPSTR
CP_ACP      equ 0
CP_MACCP    equ 2
CP_OEMCP    equ 1

CharPrevA   proto WINAPI,
    lpszStart:  LPCSTR,
    lpszCurrent:LPCSTR
;ret LPSTR
CharPrevW   proto WINAPI,
    lpszStart:  LPCWSTR,
    lpszCurrent:LPCWSTR
;ret LPWSTR
__AW <CharPrev>

CharPrevExA proto WINAPI,
    CodePage:       word,
    lpStart:        LPCSTR,
    lpCurrentChar:  LPCSTR,
    dwFlags:        dword
;ret LPSTR

CharToOemA  proto WINAPI,
    lpszSrc:LPCSTR,
    lpszDst:LPSTR
;ret BOOL
CharToOemW  proto WINAPI,
    lpszSrc:LPCWSTR,
    lpszDst:LPSTR
;ret BOOL
__AW <CharToOem>

CharToOemBuffA  proto WINAPI,
    lpszSrc:        LPCSTR,
    lpszDst:        LPSTR,
    cchDstLength:   dword
;ret BOOL
CharToOemBuffW  proto WINAPI,
    lpszSrc:        LPCWSTR,
    lpszDst:        LPSTR,
    cchDstLength:   dword
;ret BOOL
__AW <CharToOemBuff>

CharUpperA  proto WINAPI,
    lpsz:   LPSTR
;ret LPSTR
CharUpperW proto WINAPI,
    lpsz:   LPWSTR
;ret LPSTR
__AW <CharUpper>

CharUpperBuffA  proto WINAPI,
    lpsz:       LPSTR,
    cchLength:  dword
;ret dword
CharUpperBuffW  proto WINAPI,
    lpsz:       LPWSTR,
    cchLength:  dword
;ret dword

IsCharAlphaA    proto WINAPI,
    ch_:CHAR
;ret BOOL
IsCharAlphaW    proto WINAPI,
    ch_:WCHAR
;ret BOOL
__AW <IsCharAlpha>

IsCharAlphaNumericA proto WINAPI,
    ch_:CHAR
;ret BOOL
IsCharAlphaNumericW proto WINAPI,
    ch_:WCHAR
;ret BOOL
__AW <IsCharAlphaNumeric>

IsCharLowerA    proto WINAPI,
    ch_:TCHAR
;ret BOOL
IsCharLower textequ <IsCharLowerA>

IsCharUpperA    proto WINAPI,
    ch_:CHAR
;ret BOOL
IsCharUpperW    proto WINAPI,
    ch_:WCHAR
;ret BOOL
__AW <IsCharUpper>

LoadStringA proto WINAPI,
    hInstance:  HINSTANCE,
    uID:        UINT,
    lpBuffer:   LPSTR,
    nBufferMax: sdword
;ret sdword
LoadStringW proto WINAPI,
    hInstance:  HINSTANCE,
    uID:        UINT,
    lpBuffer:   LPSTR,
    nBufferMax: sdword
;ret sdword
__AW <LoadString>

OemToCharA  proto WINAPI,
    lpszSrc:LPCSTR,
    lpszDst:LPSTR
;ret BOOL
OemToCharW  proto WINAPI,
    lpszSrc:LPCSTR,
    lpszDst:LPWSTR
;ret BOOL
__AW <OemToChar>

OemToCharBuffA  proto WINAPI,
    lpszSrc:        LPCSTR,
    lpszDst:        LPSTR,
    cchDstLength:   dword
;ret BOOL
OemToCharBuffW  proto WINAPI,
    lpszSrc:        LPCSTR,
    lpszDst:        LPWSTR,
    cchDstLength:   dword
;ret BOOL
__AW <OemToCharBuff>

wsprintfA   proto c,
    lpOut:  LPSTR,
    lpFmt:  LPCSTR,
    args:   vararg
;ret sdword
wsprintfW   proto c,
    lpOut:  LPWSTR,
    lpFmt:  LPCWSTR,
    args:   vararg
;ret sdword
__AW <wsprintf>

va_list typedef ptr byte
wvsprintfA  proto c,
    lpOutput:   LPSTR,
    lpFmt:      LPCSTR,
    arglist:    va_list
;ret sdword
wvsprintfW  proto c,
    lpOutput:   LPWSTR,
    lpFmt:      LPCWSTR,
    arglist:    va_list
;ret sdword
__AW <wvsprintf>

;The Windows Shell
;<https://msdn.microsoft.com/en-us/library/windows/desktop/bb773177.aspx>
;The Windows UI provides users with access to a wide variety of objects necessary for running applications and managing the operating system. The most numerous and
;familiar of these objects are the folders and files that reside on computer disk drives. There are also a number of virtual objects that allow the user to perform tasks
;such as sending files to remote printers or accessing the Recycle Bin. The Shell organizes these objects into a hierarchical namespace and provides users and applications
;with a consistent and efficient way to access and manage objects.
HELPINFO    struct
    cbSize          UINT    ?
    iContextType    sdword  ?
    iCtrlId         sdword  ?
    hItemHandle     HANDLE  ?
    dwContextId     dword   ?
    MousePos        POINT   {}
HELPINFO    ends
LPHELPINFO  typedef ptr HELPINFO

;Dialog Boxes
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms632588.aspx>
;A dialog box is a temporary window an application creates to retrieve user input. An application typically uses dialog boxes to prompt the user for additional information
;for menu items. A dialog box usually contains one or more controls (child windows) with which the user enters text, chooses options, or directs the action.
;Windows also provides predefined dialog boxes that support common menu items such as Open and Print. Applications that use these menu items should use the common dialog
;boxes to prompt for this user input, regardless of the type of application.
DM_GETDEFID     equ WM_USER + 0
DM_SETDEFID     equ WM_USER + 1
DM_REPOSITION   equ WM_USER + 2

WM_CTLCOLORDLG  equ 0136h
WM_ENTERIDLE    equ 0121h
MSGF_DIALOGBOX  equ 0
MSGF_MENU       equ 2
WM_GETDLGCODE   equ 0087h
DLGC_BUTTON             equ 2000h
DLGC_DEFPUSHBUTTON      equ 0010h
DLGC_HASSETSEL          equ 0008h
DLGC_RADIOBUTTON        equ 0040h
DLGC_STATIC             equ 0100h
DLGC_UNDEFPUSHBUTTON    equ 0020h
DLGC_WANTALLKEYS        equ 0004h
DLGC_WANTARROWS         equ 0001h
DLGC_WANTCHARS          equ 0080h
DLGC_WANTMESSAGE        equ 0004h
DLGC_WANTTAB            equ 0002h
WM_INITDIALOG   equ 0110h
WM_NEXTDLGCTL   equ 0028h

DS_3DLOOK           equ 0004h
DS_ABSALIGN         equ 01h
DS_CENTER           equ 0400h
DS_CENTERMOUSE      equ 1000h
DS_CONTEXTHELP      equ 2000h
DS_CONTROL          equ 0400h
DS_FIXEDSYS         equ 0008h
DS_LOCALEDIT        equ 20h
DS_MODALFRAME       equ 80h
DS_NOFAILCREATE     equ 0010h
DS_NOIDLEMSG        equ 100h
DS_SETFONT          equ 40h
DS_SETFOREGROUND    equ 200h
DS_SHELLFONT        equ DS_SETFONT or DS_FIXEDSYS
DS_SYSMODAL         equ 02h

DLGITEMTEMPLATE struct
    style           dword   ?
    dwExtendedStyle dword   ?
    x               sword   ?
    y               sword   ?
    cx_             sword   ?
    cy              sword   ?
    id              word    ?
DLGITEMTEMPLATE ends

;DLGITEMTEMPLATEEX   struct
;    helpID      dword   ?
;    exStyle     dword   ?
;    style       dword   ?
;    x           sword   ?
;    y           sword   ?
;    cx_         sword   ?
;    cy          sword   ?
;    id          dword   ?
;    windowClass word    ?   ;variable-length
;    title_      word    ?   ;variable-length
;    extraCount  word    ?
;DLGITEMTEMPLATEEX   ends

DLGTEMPLATE struct
    style           dword   ?
    dwExtendedStyle dword   ?
    cdit            word    ?
    x               sword   ?
    y               sword   ?
    cx_             sword   ?
    cy              sword   ?
DLGTEMPLATE ends
LPDLGTEMPLATE   typedef ptr DLGTEMPLATE
LPCDLGTEMPLATE  typedef ptr DLGTEMPLATE

;DLGTEMPLATEEX   struct
;    dlgVer      word    ?
;    signature   word    ?
;    helpID      dword   ?
;    exStyle     dword   ?
;    style       dword   ?
;    cDlgItems   dword   ?
;    x           sword   ?
;    y           sword   ?
;    cx_         sword   ?
;    cy          sword   ?
;    menu        word    ?   ;variable-length
;    windowClass word    ?   ;variable-length
;    title_      WCHAR   ?   ;variable-lenfth
;    pointsize   word    ?
;    weight      word    ?
;    italic      byte    ?
;    charset     byte    ?
;    typeface    WCHAR   ?   ;variable-length
;DLGTEMPLATEEX   ends

MsgBoxCallback_t    typedef proto CALLBACK,
    lpHelpInfo: LPHELPINFO
;ret VOID
MSGBOXCALLBACK  typedef ptr MsgBoxCallback_t
MSGBOXPARAMSA   struct
    cbSize              UINT            ?
    hwndOwner           HWND            ?
    hInstance           HINSTANCE       ?
    lpszText            LPCSTR          ?
    lpszCaption         LPCSTR          ?
    dwStyle             dword           ?
    lpszIcon            LPCSTR          ?
    dwContextHelpId     DWORD_PTR       ?
    lpfnMsgBoxCallback  MSGBOXCALLBACK  ?
    dwLanguageId        dword           ?
MSGBOXPARAMSA   ends
LPMSGBOXPARAMSA typedef ptr MSGBOXPARAMSA
MSGBOXPARAMSW   struct
    cbSize              UINT            ?
    hwndOwner           HWND            ?
    hInstance           HINSTANCE       ?
    lpszText            LPCWSTR         ?
    lpszCaption         LPCWSTR         ?
    dwStyle             dword           ?
    lpszIcon            LPCWSTR         ?
    dwContextHelpId     DWORD_PTR       ?
    lpfnMsgBoxCallback  MSGBOXCALLBACK  ?
    dwLanguageId        dword           ?
MSGBOXPARAMSW   ends
LPMSGBOXPARAMSW typedef ptr MSGBOXPARAMSW
__AW <MSGBOXPARAMS>
LPMSGBOXPARAMS typedef ptr MSGBOXPARAMS

DialogProc_t    typedef proto CALLBACK,
    hwndDlg:HWND,
    uMsg:   UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret INT_PTR
DLGPROC typedef ptr DialogProc_t

CreateDialogA   proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCSTR,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC
;ret HWND
CreateDialogW   proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCWSTR,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC
;ret HWND
__AW <CreateDialog>

CreateDialogIndirectA   proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCDLGTEMPLATE,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC
;ret HWND
CreateDialogIndirectW   proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCDLGTEMPLATE,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC
;ret HWND
__AW <CreateDialogIndirect>

CreateDialogIndirectParamA  proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCDLGTEMPLATE,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC,
    lParamInit:     LPARAM
;ret HWND
CreateDialogIndirectParamW  proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCDLGTEMPLATE,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC,
    lParamInit:     LPARAM
;ret HWND
__AW <CreateDialogIndirectParam>

CreateDialogParamA  proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplateName: LPCSTR,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC,
    dwInitParam:    LPARAM
;ret HWND
CreateDialogParamW  proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplateName: LPCWSTR,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC,
    dwInitParam:    LPARAM
;ret HWND
__AW <CreateDialogParam>

DefDlgProcW  proto WINAPI,
    hDlg:   HWND,
    Msg:    UINT,
    wParam: WPARAM,
    lParam: LPARAM
;ret LRESULT
DefDlgProc  textequ <DefDlgProcW>

DialogBoxA  proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCSTR,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC
;ret INT_PTR
DialogBoxW  proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCWSTR,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC
;ret INT_PTR
__AW <DialogBox>

DialogBoxIndirectA  proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCDLGTEMPLATE,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC
;ret INT_PTR
DialogBoxIndirectW  proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCDLGTEMPLATE,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC
;ret INT_PTR
__AW <DialogBoxIndirect>

DialogBoxIndirectParamA proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCDLGTEMPLATE,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC,
    lParamInit:     LPARAM
;ret INT_PTR
DialogBoxIndirectParamW proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplate:     LPCDLGTEMPLATE,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC,
    lParamInit:     LPARAM
;ret INT_PTR
__AW <DialogBoxIndirectParam>

DialogBoxParamA proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplateName: LPCSTR,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC,
    dwInitParam:    LPARAM
;ret INT_PTR
DialogBoxParamW proto WINAPI,
    hInstance:      HINSTANCE,
    lpTemplateName: LPCWSTR,
    hWndParent:     HWND,
    lpDialogFunc:   DLGPROC,
    dwInitParam:    LPARAM
;ret INT_PTR
__AW <DialogBoxParam>

EndDialog   proto WINAPI,
    hDlg:   HWND,
    nResult:INT_PTR
;ret BOOL

GetDialogBaseUnits  proto WINAPI    ;ret LONG

GetDlgCtrlID    proto WINAPI,
    hwndCtl:HWND
;ret sdword

GetDlgItem  proto WINAPI,
    hDlg:       HWND,
    nIDDlgItem: sdword
;ret HWND

GetDlgItemInt   proto WINAPI,
    hDlg:           HWND,
    nIDDlgItem:     sdword,
    lpTranslated:   PBOOL,
    bSigned:        BOOL
;ret UINT

GetDlgItemTextA proto WINAPI,
    hDlg:       HWND,
    nIDDlgItem: sdword,
    lpString:   LPSTR,
    nMaxCount:  sdword
;ret UINT
GetDlgItemTextW proto WINAPI,
    hDlg:       HWND,
    nIDDlgItem: sdword,
    lpString:   LPWSTR,
    nMaxCount:  sdword
;ret UINT
__AW <GetDlgItemText>

GetNextDlgGroupItem proto WINAPI,
    hDlg:       HWND,
    hCtl:       HWND,
    bPrevious:  BOOL
;ret HWND

GetNextDlgTabItem   proto WINAPI,
    hDlg:       HWND,
    hCtl:       HWND,
    bPrevious:  BOOL
;ret HWND

IsDialogMessageA    proto WINAPI,
    hDlg:   HWND,
    lpMsg:  LPMSG
;ret BOOL
IsDialogMessageW    proto WINAPI,
    hDlg:   HWND,
    lpMsg:  LPMSG
;ret BOOL
__AW <IsDialogMessage>

MapDialogRect   proto WINAPI,
    hDlg:   HWND,
    lpRect: LPRECT
;ret BOOL

MessageBoxA proto WINAPI,
    hWnd:       HWND,
    lpText:     LPCSTR,
    lpCaption:  LPCSTR,
    uType:      UINT
;ret sdword
MessageBoxW proto WINAPI,
    hWnd:       HWND,
    lpText:     LPCWSTR,
    lpCaption:  LPCWSTR,
    uType:      UINT
;ret sdword
__AW <MessageBox>

MB_ABORTRETRYIGNORE     equ 00000002h
MB_CANCELTRYCONTINUE    equ 00000006h
MB_HELP                 equ 00004000h
MB_OK                   equ 00000000h
MB_OKCANCEL             equ 00000001h
MB_RETRYCANCEL          equ 00000005h
MB_YESNO                equ 00000004h
MB_YESNOCANCEL          equ 00000003h
MB_ICONEXCLAMATION      equ 00000030h
MB_ICONWARNING          equ 00000030h
MB_ICONINFORMATION      equ 00000040h
MB_ICONASTERISK         equ 00000040h
MB_ICONQUESTION         equ 00000020h
MB_ICONSTOP             equ 00000010h
MB_ICONERROR            equ 00000010h
MB_ICONHAND             equ 00000010h
MB_DEFBUTTON1           equ 00000000h
MB_DEFBUTTON2           equ 00000100h
MB_DEFBUTTON3           equ 00000200h
MB_DEFBUTTON4           equ 00000300h
MB_APPLMODAL            equ 00000000h
MB_SYSTEMMODAL          equ 00001000h
MB_TASKMODAL            equ 00002000h
MB_DEFAULT_DESKTOP_ONLY equ 00020000h
MB_RIGHT                equ 00080000h
MB_RTLREADING           equ 00100000h
MB_SETFOREGROUND        equ 00010000h
MB_TOPMOST              equ 00040000h
MB_SERVICE_NOTIFICATION equ 00200000h

IDABORT                 equ 3
IDCANCEL                equ 2
IDCONTINUE              equ 11
IDIGNORE                equ 5
IDNO                    equ 7
IDOK                    equ 1
IDRETRY                 equ 4
IDTRYAGAIN              equ 10
IDYES                   equ 6

MessageBoxExA   proto WINAPI,
    hWnd:       HWND,
    lpText:     LPCSTR,
    lpCaption:  LPCSTR,
    uType:      UINT,
    wLanguageId:word
;ret sdword
MessageBoxExW   proto WINAPI,
    hWnd:       HWND,
    lpText:     LPCWSTR,
    lpCaption:  LPCWSTR,
    uType:      UINT,
    wLanguageId:word
;ret sdword
__AW <MessageBoxEx>

MessageBoxIndirectA proto WINAPI,
    lpMsgBoxParams: LPMSGBOXPARAMSA
;ret sdword
MessageBoxIndirectW proto WINAPI,
    lpMsgBoxParams: LPMSGBOXPARAMSW
;ret sdword
__AW <MessageBoxIndirect>

SendDlgItemMessageA proto WINAPI,
    hDlg:       HWND,
    nIDDlgItem: sdword,
    Msg:        UINT,
    wParam:     WPARAM,
    lParam:     LPARAM
;ret LRESULT
SendDlgItemMessageW proto WINAPI,
    hDlg:       HWND,
    nIDDlgItem: sdword,
    Msg:        UINT,
    wParam:     WPARAM,
    lParam:     LPARAM
;ret LRESULT
__AW <SendDlgItemMessage>

SetDlgItemInt   proto WINAPI,
    hDlg:       HWND,
    nIDDlgItem: sdword,
    uValue:     UINT,
    bSigned:    BOOL
;ret BOOL

SetDlgItemTextA proto WINAPI,
    hDlg:       HWND,
    nIDDlgItem: sdword,
    lpString:   LPCSTR
;ret BOOL
SetDlgItemTextW proto WINAPI,
    hDlg:       HWND,
    nIDDlgItem: sdword,
    lpString:   LPCWSTR
;ret BOOL
__AW <SetDlgItemText>

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

;Process Functions
GetGuiResources proto WINAPI,
    hProcess:   HANDLE,
    uiFlags:    dword
;ret dword
GR_GDIOBJECTS       equ 0
GR_GDIOBJECTS_PEAK  equ 2
GR_USEROBJECTS      equ 1
GR_USEROBJECTS_PEAK equ 4

IsImmersiveProcess  proto WINAPI,
    hProcess:   HANDLE
;ret BOOL

SetProcessRestrictionExemption  proto WINAPI,
    fEnableExemption:   BOOL
;ret BOOL

;Thread Functions
AttachThreadInput   proto WINAPI,
    idAttach:   dword,
    idAttachTo: dword,
    fAttach:    BOOL
;ret BOOL

WaitForInputIdle    proto WINAPI,
    hProcess:       HANDLE,
    dwMilliseconds: dword
;ret dword

;WOW64 Functions
IsWow64Message  proto WINAPI    ;ret BOOL

;Error Handling
;<https://msdn.microsoft.com/en-us/library/windows/desktop/ms679320.aspx>
;Well-written applications include error-handling code that allows them to recover gracefully from unexpected errors. When an error occurs, the application may need to
;request user intervention, or it may be able to recover on its own. In extreme cases, the application may log the user off or shut down the system.
FLASHWINFO  struct
    cbSize      UINT    ?
    hwnd        HWND    ?
    dwFlags     dword   ?
    uCount      UINT    ?
    dwtimeout   dword   ?
FLASHWINFO  ends
PFLASHWINFO typedef ptr FLASHWINFO

FLASHW_ALL          equ 00000003h
FLASHW_CAPTION      equ 00000001h
FLASHW_STOP         equ 0
FLASHW_TIMER        equ 00000004h
FLASHW_TIMERNOFG    equ 0000000ch
FLASHW_TRAY         equ 00000002h

FlashWindow proto WINAPI,
    hWnd:   HWND,
    bInvert:BOOL
;ret BOOL

FlashWindowEx   proto WINAPI,
    pfwi:   PFLASHWINFO
;ret BOOL

MessageBeep proto WINAPI,
    uType:  UINT
;ret 

SetLastErrorEx  proto WINAPI,
    dwErrCode:  dword,
    dwType:     dword
;ret void

;Keyboard Input
;<http://msdn.microsoft.com/en-us/library/windows/desktop/ms645530.aspx>

;Virtual-key codes
VK_LBUTTON              equ 01h
VK_RBUTTON              equ 02h
VK_CANCEL               equ 03h
VK_MBUTTON              equ 04h
VK_XBUTTON1             equ 05h
VK_XBUTTON2             equ 06h
VK_BACK                 equ 08h
VK_TAB                  equ 09h
VK_CLEAR                equ 0ch
VK_RETURN               equ 0dh
VK_SHIFT                equ 10h
VK_CONTROL              equ 11h
VK_MENU                 equ 12h
VK_PAUSE                equ 13h
VK_CAPITAL              equ 14h
VK_KANA                 equ 15h
VK_HANGUEL              equ 15h
VK_HANGUL               equ 15h
VK_JUNJA                equ 17h
VK_FINAL                equ 18h
VK_HANJA                equ 19h
VK_KANJI                equ 19h
VK_ESCAPE               equ 1bh
VK_CONVERT              equ 1ch
VK_NONCONVERT           equ 1dh
VK_ACCEPT               equ 1eh
VK_MODECHANGE           equ 1fh
VK_SPACE                equ 20h
VK_PRIOR                equ 21h
VK_NEXT                 equ 22h
VK_END                  equ 23h
VK_HOME                 equ 24h
VK_LEFT                 equ 25h
VK_UP                   equ 26h
VK_RIGHT                equ 27h
VK_DOWN                 equ 28h
VK_SELECT               equ 29h
VK_PRINT                equ 2ah
VK_EXECUTE              equ 2bh
VK_SNAPSHOT             equ 2ch
VK_INSERT               equ 2dh
VK_DELETE               equ 2eh
VK_HELP                 equ 2fh
VK_LWIN                 equ 5bh
VK_RWIN                 equ 5ch
VK_APPS                 equ 5dh
VK_SLEEP                equ 5fh
VK_NUMPAD0              equ 60h
VK_NUMPAD1              equ 61h
VK_NUMPAD2              equ 62h
VK_NUMPAD3              equ 63h
VK_NUMPAD4              equ 64h
VK_NUMPAD5              equ 65h
VK_NUMPAD6              equ 66h
VK_NUMPAD7              equ 67h
VK_NUMPAD8              equ 68h
VK_NUMPAD9              equ 69h
VK_MULTIPLY             equ 6ah
VK_ADD                  equ 6bh
VK_SEPARATOR            equ 6ch
VK_SUBTRACT             equ 6dh
VK_DECIMAL              equ 6eh
VK_DIVIDE               equ 6fh
VK_F1                   equ 70h
VK_F2                   equ 71h
VK_F3                   equ 72h
VK_F4                   equ 73h
VK_F5                   equ 74h
VK_F6                   equ 75h
VK_F7                   equ 76h
VK_F8                   equ 77h
VK_F9                   equ 78h
VK_F10                  equ 79h
VK_F11                  equ 7ah
VK_F12                  equ 7bh
VK_F13                  equ 7ch
VK_F14                  equ 7dh
VK_F15                  equ 7eh
VK_F16                  equ 7fh
VK_F17                  equ 80h
VK_F18                  equ 81h
VK_F19                  equ 82h
VK_F20                  equ 83h
VK_F21                  equ 84h
VK_F22                  equ 85h
VK_F23                  equ 86h
VK_F24                  equ 87h
VK_NUMLOCK              equ 90h
VK_SCROLL               equ 91h
VK_LSHIFT               equ 0a0h
VK_RSHIFT               equ 0a1h
VK_LCONTROL             equ 0a2h
VK_RCONTROL             equ 0a3h
VK_LMENU                equ 0a4h
VK_RMENU                equ 0a5h
VK_BROWSER_BACK         equ 0a6h
VK_BROWSER_FORWARD      equ 0a7h
VK_BROWSER_REFRESH      equ 0a8h
VK_BROWSER_STOP         equ 0a9h
VK_BROWSER_SEARCH       equ 0aah
VK_BROWSER_FAVORITES    equ 0abh
VK_BROWSER_HOME         equ 0ach
VK_VOLUME_MUTE          equ 0adh
VK_VOLUME_DOWN          equ 0aeh
VK_VOLUME_UP            equ 0afh
VK_MEDIA_NEXT_TRACK     equ 0b0h
VK_MEDIA_PREV_TRACK     equ 0b1h
VK_MEDIA_STOP           equ 0b2h
VK_MEDIA_PLAY_PAUSE     equ 0b3h
VK_LAUNCH_MAIL          equ 0b4h
VK_LAUNCH_MEDIA_SELECT  equ 0b5h
VK_LAUNCH_APP1          equ 0b6h
VK_LAUNCH_APP2          equ 0b7h
VK_OEM_1                equ 0bah
VK_OEM_PLUS             equ 0bbh
VK_OEM_COMMA            equ 0bch
VK_OEM_MINUS            equ 0bdh
VK_OEM_PERIOD           equ 0beh
VK_OEM_2                equ 0bfh
VK_OEM_3                equ 0c0h
VK_OEM_4                equ 0dbh
VK_OEM_5                equ 0dch
VK_OEM_6                equ 0ddh
VK_OEM_7                equ 0deh
VK_OEM_8                equ 0dfh
VK_OEM_102              equ 0e2h
VK_PROCESSKEY           equ 0e5h
VK_PACKET               equ 0e7h
VK_ATTN                 equ 0f6h
VK_CRSEL                equ 0f7h
VK_EXSEL                equ 0f8h
VK_EREOF                equ 0f9h
VK_PLAY                 equ 0fah
VK_ZOOM                 equ 0fbh
VK_NONAME               equ 0fch
VK_PA1                  equ 0fdh
VK_OEM_CLEAR            equ 0feh

;Keyboard Input Messages
WM_SETHOTKEY    equ 0032h
WM_GETHOTKEY    equ 0033h   
HOTKEYF_ALT     equ 04h
HOTKEYF_CONTROL equ 02h
HOTKEYF_EXT     equ 08h
HOTKEYF_SHIFT   equ 01h

;Keyboard Input Notifications
WM_ACTIVATE     equ 0006h
WA_ACTIVE       equ 1
WA_CLICKACTIVE  equ 2
WA_INACTIVE     equ 0
WM_APPCOMMAND   equ 0319h
APPCOMMAND_BASS_BOOST                           equ 20
APPCOMMAND_BASS_DOWN                            equ 19
APPCOMMAND_BASS_UP                              equ 21
APPCOMMAND_BROWSER_BACKWARD                     equ 1
APPCOMMAND_BROWSER_FAVORITES                    equ 6
APPCOMMAND_BROWSER_FORWARD                      equ 2
APPCOMMAND_BROWSER_HOME                         equ 7
APPCOMMAND_BROWSER_REFRESH                      equ 3
APPCOMMAND_BROWSER_SEARCH                       equ 5
APPCOMMAND_BROWSER_STOP                         equ 4
APPCOMMAND_CLOSE                                equ 31
APPCOMMAND_COPY                                 equ 36
APPCOMMAND_CORRECTION_LIST                      equ 45
APPCOMMAND_CUT                                  equ 37
APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE    equ 43
APPCOMMAND_FIND                                 equ 28
APPCOMMAND_FORWARD_MAIL                         equ 40
APPCOMMAND_HELP                                 equ 27
APPCOMMAND_LAUNCH_APP1                          equ 17
APPCOMMAND_LAUNCH_APP2                          equ 18
APPCOMMAND_LAUNCH_MAIL                          equ 15
APPCOMMAND_LAUNCH_MEDIA_SELECT                  equ 16
APPCOMMAND_MEDIA_CHANNEL_DOWN                   equ 52
APPCOMMAND_MEDIA_CHANNEL_UP                     equ 51
APPCOMMAND_MEDIA_FAST_FORWARD                   equ 49
APPCOMMAND_MEDIA_NEXTTRACK                      equ 11
APPCOMMAND_MEDIA_PAUSE                          equ 47
APPCOMMAND_MEDIA_PLAY                           equ 46
APPCOMMAND_MEDIA_PLAY_PAUSE                     equ 14
APPCOMMAND_MEDIA_PREVIOUSTRACK                  equ 12
APPCOMMAND_MEDIA_RECORD                         equ 48
APPCOMMAND_MEDIA_REWIND                         equ 50
APPCOMMAND_MEDIA_STOP                           equ 13
APPCOMMAND_MIC_ON_OFF_TOGGLE                    equ 44
APPCOMMAND_MICROPHONE_VOLUME_DOWN               equ 25
APPCOMMAND_MICROPHONE_VOLUME_MUTE               equ 24
APPCOMMAND_MICROPHONE_VOLUME_UP                 equ 26
APPCOMMAND_NEW                                  equ 29
APPCOMMAND_OPEN                                 equ 30
APPCOMMAND_PASTE                                equ 38
APPCOMMAND_PRINT                                equ 33
APPCOMMAND_REDO                                 equ 35
APPCOMMAND_REPLY_TO_MAIL                        equ 39
APPCOMMAND_SAVE                                 equ 32
APPCOMMAND_SEND_MAIL                            equ 41
APPCOMMAND_SPELL_CHECK                          equ 42
APPCOMMAND_TREBLE_DOWN                          equ 22
APPCOMMAND_TREBLE_UP                            equ 23
APPCOMMAND_UNDO                                 equ 34
APPCOMMAND_VOLUME_DOWN                          equ 9
APPCOMMAND_VOLUME_MUTE                          equ 8
APPCOMMAND_VOLUME_UP                            equ 10
FAPPCOMMAND_KEY     equ 0
FAPPCOMMAND_MOUSE   equ 8000h
FAPPCOMMAND_OEM     equ 1000h
WM_CHAR         equ 0102h
WM_DEADCHAR     equ 0103h
WM_HOTKEY       equ 0312h
IDHOT_SNAPDESKTOP   equ -2
IDHOT_SNAPWINDOW    equ -1
MOD_ALT     equ 0001h
MOD_CONTROL equ 0002h
MOD_SHIFT   equ 0004h
MOD_WIN     equ 0008h
WM_KEYDOWN      equ 0100h
WM_KEYUP        equ 0101h
WM_KILLFOCUS    equ 0008h
WM_SETFOCUS     equ 0007h
WM_SYSDEADCHAR  equ 0107h
WM_SYSKEYDOWN   equ 0104h
WM_SYSKEYUP     equ 0105h
WM_UNICHAR      equ 0109h

HARDWAREINPUT   struct
    uMsg    dword   ?
    wParamL word    ?
    wParamH word    ?
HARDWAREINPUT   ends
PHARDWAREINPUT  typedef ptr HARDWAREINPUT

KEYBDINPUT  struct
    wVk         word        ?
    wScan       word        ?
    dwFlags     dword       ?
    time        dword       ?
    dwExtraInfo ULONG_PTR   ?
KEYBDINPUT  ends
PKEYBDINPUT typedef ptr KEYBDINPUT
KEYEVENTF_EXTENDEDKEY   equ 0001h
KEYEVENTF_KEYUP         equ 0002h
KEYEVENTF_SCANCODE      equ 0008h
KEYEVENTF_UNICODE       equ 0004h

MOUSEINPUT  struct
    dx_         LONG        ?
    dy          LONG        ?
    mouseData   dword       ?
    dwFlags     dword       ?
    time        dword       ?
    dwExtraInfo ULONG_PTR   ?
MOUSEINPUT  ends
PMOUSEINPUT typedef ptr MOUSEINPUT

INPUT   struct
    type_   dword   ?
    union
        mi  MOUSEINPUT      {}
        ki  KEYBDINPUT      {}
        hi  HARDWAREINPUT   {}
    ends
INPUT   ends
PINPUT  typedef ptr INPUT
LPINPUT typedef ptr INPUT
INPUT_MOUSE     equ 0
INPUT_KEYBOARD  equ 1
INPUT_HARDWARE  equ 2

LASTINPUTINFO   struct
    cbSize  UINT    ?
    dwTime  dword   ?
LASTINPUTINFO   ends
PLASTINPUTINFO  typedef ptr LASTINPUTINFO

;Keyboard Input Functions
ActivateKeyboardLayout  proto WINAPI,
    hkl:    HKL,
    Flags:  UINT
;ret HKL
HKL_NEXT    equ 1
HML_PREV    equ 0

KLF_ACTIVATE        equ 00000001h
KLF_NOTELLSHELL     equ 00000080h
KLF_REORDER         equ 00000008h
KLF_REPLACELANG     equ 00000010h
KLF_SUBSTITUTE_OK   equ 00000002h
KLF_RESET           equ 40000000h
KLF_SETFORPROCESS   equ 00000100h
KLF_SHIFTLOCK       equ 00010000h

BlockInput  proto WINAPI,
    fBlockIt:   BOOL
;ret BOOL

EnableWindow    proto WINAPI,
    hWnd:   HWND,
    bEnable:BOOL
;ret BOOL

GetActiveWidow  proto WINAPI    ;ret HWND

GetAsyncKeyState    proto WINAPI,
    vKey:   sdword
;ret SHORT

GetFocus    proto WINAPI    ;ret HWND

GetKBCodePage   proto WINAPI    ;ret UINT

GetKeyboardLayout   proto WINAPI,
    idThread:   dword
;ret HKL

GetKeyboardLayoutList   proto WINAPI,
    nBuff:  sdword,
    lpList: ptr HKL
;ret sdword

GetKeyboardLayoutNameA  proto WINAPI,
    lpszKLID:   LPSTR
;ret BOOL
GetKeyboardLayoutNameW  proto WINAPI,
    lpszKLID:   LPWSTR
;ret BOOL
__AW <GetKeyboardLayoutName>

GetKeyboardState    proto WINAPI,
    lpKeyState: PBYTE
;ret BOOL

GetKeyboardType proto WINAPI,
    nTypeFlag:  sdword
;ret sdword

GetKeyNameTextA proto WINAPI,
    lParam:     LONG,
    lpString:   LPSTR,
    cchSize:    sdword
;ret sdword
GetKeyNameTextW proto WINAPI,
    lParam:     LONG,
    lpString:   LPWSTR,
    cchSize:    sdword
;ret sdword
__AW <GetKeyNameText>

GetKeyState proto WINAPI,
    nVirtKey:   sdword
;ret SHORT

GetLastInputInfo    proto WINAPI,
    plii:   PLASTINPUTINFO
;ret BOOL

IsWindowEnabled proto WINAPI,
    hWnd:   HWND
;ret BOOL

keybd_event proto WINAPI,
    bVk:        byte,
    bScan:      byte,
    dwFlags:    dword,
    dwExtraInfo:ULONG_PTR
;ret VOID

LoadKeyboardLayoutA proto WINAPI,
    pwszKLID:   LPCSTR,
    Flags:      UINT
;ret HKL
LoadKeyboardLayoutW proto WINAPI,
    pwszKLID:   LPCWSTR,
    Flags:      UINT
;ret HKL
__AW <LoadKeyboardLayout>

MapVirtualKeyA  proto WINAPI,
    uCode:      UINT,
    uMapType:   UINT
;ret UINT
MapVirtualKeyW  proto WINAPI,
    uCode:      UINT,
    uMapType:   UINT
;ret UINT
__AW <MapVirtualKey>
MAPVK_VK_TO_CHAR    equ 2
MAPVK_VK_TO_VSC     equ 0
MAPVK_VSC_TO_VK     equ 1
MAPVK_VSC_TO_VK_EX  equ 3

MapVirtualKeyExA    proto WINAPI,
    uCode:      UINT,
    uMapType:   UINT,
    dwhkl:      HKL
;ret UINT
MapVirtualKeyExW    proto WINAPI,
    uCode:      UINT,
    uMapType:   UINT,
    dwhkl:      HKL
;ret UINT
__AW <MapVirtualKeyEx>
MAPVK_VK_TO_VSC_EX  equ 4

OemKeyScan  proto WINAPI,
    wOemChar:   word
;ret dword

RegisterHotKey  proto WINAPI,
    hWnd:       HWND,
    id:         sdword,
    fsModifiers:UINT,
    vk:         UINT
;ret BOOL
MOD_NOREPEAT    equ 4000h

SendInput   proto WINAPI,
    nInputs:UINT,
    pInputs:LPINPUT,
    cbSize: sdword
;ret UINT

SetActiveWindow proto WINAPI,
    hWnd:   HWND
;ret HWND

SetFocus    proto WINAPI,
    hWnd:   HWND
;ret HWND

SetKeyboardState    proto WINAPI,
    lpKeyState: LPBYTE
;ret BOOL

ToAscii proto WINAPI,
    uVirtKey:   UINT,
    uScanCode:  UINT,
    lpKeyState: ptr byte,
    lpChar:     LPWORD,
    uFlags:     UINT
;ret sdword

ToAsciiEx   proto WINAPI,
    uVirtKey:   UINT,
    uScanCode:  UINT,
    lpKeyState: ptr byte,
    lpChar:     LPWORD,
    uFlags:     UINT,
    dwhkl:      HKL
;ret sdword

ToUnicode   proto WINAPI,
    wVirtKey:   UINT,
    wScanCode:  UINT,
    lpKeyState: ptr byte,
    pwszBuff:   LPWSTR,
    cchBuff:    sdword,
    wFlags:     UINT
;ret sdword

ToUnicodeEx proto WINAPI,
    wVirtKey:   UINT,
    wScanCode:  UINT,
    lpKeyState: ptr byte,
    pwszBuff:   LPWSTR,
    cchBuff:    sdword,
    wFlags:     UINT,
    dwhkl:      HKL
;ret sdword

UnloadKeyboardLayout    proto WINAPI,
    hkl:HKL
;ret BOOL

UnregisterHotKey    proto WINAPI,
    hWnd:   HWND,
    id:     sdword
;ret BOOL

VkKeyScanA  proto WINAPI,
    ch_:CHAR
;ret SHORT
VkKeyScanW  proto WINAPI,
    ch_:WCHAR
;ret SHORT
__AW <VkKeyScan>

VkKeyScanExA    proto WINAPI,
    ch_:    CHAR,
    dwhkl:  HKL
;ret SHORT
VkKeyScanExW    proto WINAPI,
    ch_:    WCHAR,
    dwhkl:  HKL
;ret SHORT
__AW <VkKeyScanEx>

;Mouse Input
;<http://msdn.microsoft.com/en-us/library/windows/desktop/ms645533.aspx>
WM_CAPTURECHANGED   equ 0215h
WM_LBUTTONDBLCLK    equ 0203h
MK_CONTROL  equ 0008h
MK_LBUTTON  equ 0001h
MK_MBUTTON  equ 0010h
MK_RBUTTON  equ 0002h
MK_SHIFT    equ 0004h
MK_XBUTTON1 equ 0020h
MK_XBUTTON2 equ 0040h
WM_LBUTTONDOWN      equ 0201h
WM_LBUTTONUP        equ 0202h
WM_MBUTTONDBLCLK    equ 0209h
WM_MBUTTONDOWN      equ 0207h
WM_MBUTTONUP        equ 0208h
WM_MOUSEACTIVATE    equ 0021h
WM_MOUSEHOVER       equ 02a1h
WM_MOUSEHWHEEL      equ 020eh
WM_MOUSELEAVE       equ 02a3h
WM_MOUSEMOVE        equ 0200h
WM_MOUSEWHEEL       equ 020ah
WM_NCHITTEST        equ 0084h
HTBORDER        equ 18
HTBOTTOM        equ 15
HTBOTTOMLEFT    equ 16
HTBOTTOMRIGHT   equ 17
HTCAPTION       equ 2
HTCLIENT        equ 1
HTCLOSE         equ 20
HTERROR         equ -2
HTGROWBOX       equ 4
HTHELP          equ 21
HTHSCROLL       equ 6
HTLEFT          equ 10
HTMENU          equ 5
HTMAXBUTTON     equ 9
HTMINBUTTON     equ 8
HTNOWHERE       equ 0
HTREDUCE        equ 8
HTRIGHT         equ 11
HTSIZE          equ 4
HTSYSMENU       equ 3
HTTOP           equ 12
HTTOPLEFT       equ 13
HTTOPRIGHT      equ 14
HTTRANSPARENT   equ -1
HTVSCROLL       equ 7
HTZOOM          equ 9
WM_NCLBUTTONDBLCLK  equ 00a3h
WM_NCLBUTTONDOWN    equ 00a1h
WM_NCLBUTTONUP      equ 00a2h
WM_NCMBUTTONDBLCLK  equ 00a9h
WM_NCMBUTTONDOWN    equ 00a7h
WM_NCMBUTTONUP      equ 00a8h
WM_NCMOUSEHOVER     equ 02a0h
WM_NCMOUSELEAVE     equ 02a2h
WM_NCMOUSEMOVE      equ 00a0h
WM_NCRBUTTONDBLCLK  equ 00a6h
WM_NCRBUTTONDOWN    equ 00a4h
WM_NCRBUTTONUP      equ 00a5h
WM_NCXBUTTONDBLCLK  equ 00adh
WM_NCXBUTTONDOWN    equ 00abh
WM_NCXBUTTONUP      equ 00ach
WM_RBUTTONDBLCLK    equ 0206h
WM_RBUTTONDOWN      equ 0204h
WM_RBUTTONUP        equ 0205h
WM_XBUTTONDBLCLK    equ 020dh
WM_XBUTTONDOWN      equ 020bh
WM_XBUTTONUP        equ 020ch

MOUSEMOVEPOINT  struct
    x           sdword      ?
    y           sdword      ?
    time        dword       ?
    dwExtraInfo ULONG_PTR   ?
MOUSEMOVEPOINT  ends
PMOUSEMOVEPOINT typedef ptr MOUSEMOVEPOINT
LPMOUSEMOVEPOINT    typedef ptr MOUSEMOVEPOINT

TRACKMOUSEEVENT struct
    cbSize      dword   ?
    dwFlags     dword   ?
    hwndTrack   HWND    ?
    dwHoverTime dword   ?
TRACKMOUSEEVENT ends
LPTRACKMOUSEEVENT   typedef ptr TRACKMOUSEEVENT
TME_CANCEL      equ 80000000h
TME_HOVER       equ 00000001h
TME_LEAVE       equ 00000002h
TME_NONCLIENT   equ 00000010h
TME_QUERY       equ 40000000h

DragDetect  proto WINAPI,
    hwnd:   HWND,
    pt:     POINT
;ret BOOL

GetCapture  proto WINAPI    ;ret HWND

GetDoubleClickTime  proto WINAPI    ;ret UINT

GetMouseMovePointsEx    proto WINAPI,
    cbSize:     UINT,
    lppt:       LPMOUSEMOVEPOINT,
    lpptBuf:    LPMOUSEMOVEPOINT,
    nBufPoints: sdword,
    resolution: dword
;ret sdword
GMMP_USE_DISPLAY_POINTS         equ 1
GMMP_USE_HIGH_RESOLUTION_POINTS equ 2

mouse_event proto WINAPI,
    dwFlags:    dword,
    dx_:        dword,
    dy:         dword,
    dwData:     dword,
    dwExtraInfo:ULONG_PTR
;ret VOID
MOUSEEVENTF_ABSOLUTE    equ 8000h
MOUSEEVENTF_LEFTDOWN    equ 0002h
MOUSEEVENTF_LEFTUP      equ 0004h
MOUSEEVENTF_MIDDLEDOWN  equ 0020h
MOUSEEVENTF_MIDDLEUP    equ 0040h
MOUSEEVENTF_MOVE        equ 0001h
MOUSEEVENTF_RIGHTDOWN   equ 0008h
MOUSEEVENTF_RIGHTUP     equ 0010h
MOUSEEVENTF_WHEEL       equ 0800h
MOUSEEVENTF_XDOWN       equ 0080h
MOUSEEVENTF_XUP         equ 0100h
MOUSEEVENTF_HWHEEL      equ 01000h

ReleaseCapture  proto WINAPI    ;ret BOOL

SetCapture  proto WINAPI,
    hWnd:   HWND
;ret HWND

SetDoubleClickTime  proto WINAPI,
    uInterval:  UINT
;ret BOOL

SwapMouseButton proto WINAPI,
    fSwap:  BOOL
;ret BOOL

TrackMouseEvent proto WINAPI,
    lpEventTrack:   LPTRACKMOUSEEVENT
;ret BOOL