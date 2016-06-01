;Windows GDI
;<https://msdn.microsoft.com/en-us/library/dd145203.aspx>
;The Microsoft Windows graphics device interface (GDI) enables applications to use graphics and formatted text on both the video display and the printer. Windows-based applications do not access the graphics hardware directly. Instead, GDI interacts with device drivers on behalf of applications.
POINT   struct          ;The POINT structure defines the x- and y- coordinates of a point.
    x       LONG    ?   ;The x-coordinate of the point.
    y       LONG    ?   ;The y-coordinate of the point.
POINT   ends
PPOINT  typedef ptr POINT
LPPOINT typedef ptr POINT

POINTS  struct          ;The POINTS structure defines the coordinates of a point.
    x       sword   ?   ;The x-coordinate of the point.
    y       sword   ?   ;The y-coordinate of the point.
POINTS  ends
PPOINTS typedef ptr POINTS

RECT    struct          ;The RECT structure defines the coordinates of the upper-left and lower-right corners of a rectangle.
    left    LONG    ?   ;The x-coordinate of the upper-left corner of the rectangle.
    top     LONG    ?   ;The y-coordinate of the upper-left corner of the rectangle.
    right   LONG    ?   ;The x-coordinate of the lower-right corner of the rectangle.
    bottom  LONG    ?   ;The y-coordinate of the lower-right corner of the rectangle.
RECT    ends
PRECT   typedef ptr RECT
LPRECT  typedef ptr RECT
LPCRECT typedef ptr RECT

_SIZE   struct          ;The SIZE structure specifies the width and height of a rectangle.
    _cx     LONG    ?   ;Specifies the rectangle's width. The units depend on which function uses this.
    cy      LONG    ?   ;Specifies the rectangle's height. The units depend on which function uses this.
_SIZE   ends
PSIZE   typedef ptr _SIZE

BLENDFUNCTION   struct              ;The BLENDFUNCTION structure controls blending by specifying the blending functions for source and destination bitmaps.
    BlendOp             byte    ?   ;The source blend operation. Currently, the only source and destination blend operation that has been defined is AC_SRC_OVER. For details, see the following Remarks section.
    BlendFlags          byte    ?   ;Must be zero.
    SourceConstantAlpha byte    ?   ;Specifies an alpha transparency value to be used on the entire source bitmap. The SourceConstantAlpha value is combined with any per-pixel alpha values in the source bitmap.
    AlphaFormat         byte    ?   ;This member controls the way the source and destination bitmaps are interpreted. AlphaFormat has the following value.
BLENDFUNCTION   ends
PBLENDFUNCTION  typedef ptr BLENDFUNCTION
LPBLENDFUNCTION typedef ptr BLENDFUNCTION

GdiFlush    proto WINAPI    ;ret BOOL
GdiGetBatchLimit    proto WINAPI    ;ret dword
GdiSetBatchLimit    proto WINAPI,
    dwLimit:    dword
;ret dword

GetBkColor  proto WINAPI,
    hdc:    HDC
;ret COLORREF

CLR_INVALID equ 0ffffffffh

GetBkMode   proto WINAPI,
    hdc:    HDC
;ret sdword

OPAQUE      equ 2
TRANSPARENT equ 1

GetBoundsRect   proto WINAPI,
    hdc:        HDC,
    lprcBounds: LPRECT,
    flags:      UINT
;ret UINT

DCB_ACCUMULATE  equ 0002h
DCB_DISABLE     equ 0008h
DCB_ENABLE      equ 0004h
DCB_RESET       equ 0001h
DCB_DIRTY       equ DCB_ACCUMULATE
DCB_SET         equ DCB_RESET or DCB_ACCUMULATE

GetROP2 proto WINAPI,
    hdc:    HDC
;ret sdword

R2_BLACK        equ 1
R2_COPYPEN      equ 13
R2_MASKNOTPEN   equ 3
R2_MASKPEN      equ 9
R2_MASKPENNOT   equ 5
R2_MERGENOTPEN  equ 12
R2_MERGEPEN     equ 15
R2_MERGEPENNOT  equ 14
R2_NOP          equ 11
R2_NOT          equ 6
R2_NOTCOPYPEN   equ 4
R2_NOTMASKPEN   equ 8
R2_NOTMERGEPEN  equ 2
R2_NOTXORPEN    equ 10
R2_WHITE        equ 16
R2_XORPEN       equ 7

SetBkColor  proto WINAPI,
    hdc:    HDC,
    crColor:COLORREF
;ret COLORREF

SetBkMode   proto WINAPI,
    hdc:    HDC,
    iBkMode:sdword
;ret sdword

SetBoundsRect   proto WINAPI,
    hdc:        HDC,
    lprcBounds: LPRECT,
    flags:      UINT
;ret UINT

SetROP2 proto WINAPI,
    hdc:        HDC,
    fnDrawMode: sdword
;ret sdword

BLACKNESS       equ 00000042h
NOTSRCERASE     equ 001100a6h
NOTSRCCOPY      equ 00330008h
SRCERASE        equ 00440328h
DSTINVERT       equ 00550009h
PATINVERT       equ 005a0049h
SRCINVERT       equ 00660046h
SRCAND          equ 008800c6h
MERGEPAINT      equ 00bb0226h
MERGECOPY       equ 00bf08c9h
SRCCOPY         equ 00cc0020h
SRCPAINT        equ 00ee0086h
PATCOPY         equ 00f00021h
PATPAINT        equ 00fb0a09h
WHITENESS       equ 00ff0062h
NOMIRRORBITMAP  equ 80000000h

;Filled Shapes
;<https://msdn.microsoft.com/en-us/library/dd162714.aspx>
;Filled shapes are geometric forms that are outlined by using the current pen and filled by using the current brush.

Chord   proto WINAPI,
    hdc:        HDC,
    nLeftRect:  sdword,
    nTopRect:   sdword,
    nRightRect: sdword,
    nBottomRect:sdword,
    nXRadial1:  sdword,
    nYRadial1:  sdword,
    nXRadial2:  sdword,
    nYRadial2:  sdword
;ret BOOL

Ellipse proto WINAPI,
    hdc:        HDC,
    nLeftRect:  sdword,
    nTopRect:   sdword,
    nRightRect: sdword,
    nBottomRect:sdword
;ret BOOL

FillRect    proto WINAPI,
    hDC:    HDC,
    lprc:   LPRECT,
    hbr:    HBRUSH
;ret sdword

Pie proto WINAPI,
    hdc:        HDC,
    nLeftRect:  sdword,
    nTopRect:   sdword,
    nRightRect: sdword,
    nBottomRect:sdword,
    nXRadial1:  sdword,
    nYRadial1:  sdword,
    nXRadial2:  sdword,
    nYRadial2:  sdword
;ret BOOL

Polygon proto WINAPI,
    hDC:        HDC,
    lpPoints:   LPPOINT,
    nCount:     sdword
;ret BOOL

PolyPolygon proto WINAPI,
    hdc:            HDC,
    lpPoints:       LPPOINT,
    lpPolyCounts:   ptr sdword,
    nCount:         sdword
;ret BOOL

Rectangle   proto WINAPI,
    hdc:        HDC,
    nLeftRect:  sdword,
    nTopRect:   sdword,
    nRightRect: sdword,
    nBottomRect:sdword
;ret BOOL

RoundRect   proto WINAPI,
    hdc:        HDC,
    nLeftRect:  sdword,
    nTopRect:   sdword,
    nRightRect: sdword,
    nBottomRect:sdword,
    nWidth:     sdword,
    nHeight:    sdword
;ret BOOL