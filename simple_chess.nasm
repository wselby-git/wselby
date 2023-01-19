; --------------------------
;       Chess Board
; --------------------------

section .data

    Board:   db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

    WhitePawn:    db 0xE4  ; White Pawn
    BlackPawn:    db 0xE4  ; Black Pawn

    WhiteBishop:  db 0xA7  ; White Bishop
    BlackBishop:  db 0xA7  ; Black Bishop

    WhiteKnight:  db 0xB3  ; White Knight
    BlackKnight:  db 0xB3  ; Black Knight

    WhiteRook:    db 0xC2  ; White Rook
    BlackRook:    db 0xC2  ; Black Rook

    WhiteQueen:   db 0xAA  ; White Queen
    BlackQueen:   db 0xAA  ; Black Queen

    WhiteKing:    db 0xA2  ; White King
    BlackKing:    db 0xA2  ; Black King

section .text

    global _start

_start:
    ; Draw the board
    mov si, 0
    drawBoard:
        mov al, [Board+si]
        cmp al, 0
        je drawWhitePieces
        call drawPiece
    inc si
    cmp si, 64
    jne drawBoard

drawWhitePieces:
    ; Draw white pieces
    mov si, 0
    drawWhitePiece:
        mov al, [Board+si]
        cmp al, 0
        je drawBlackPieces
        cmp al, 0x01
        je drawWhitePawn
        cmp al, 0x02
        je drawWhiteBishop
        cmp al, 0x03
        je drawWhiteKnight
        cmp al, 0x04
        je drawWhiteRook
        cmp al, 0x05
        je drawWhiteQueen
        cmp al, 0x06
        je drawWhiteKing
    inc si
    cmp si, 64
    jne drawWhitePiece

drawBlackPieces:
    ; Draw black pieces
    mov si, 0
    drawBlackPiece:
        mov al, [Board+si]
        cmp al, 0
        je drawFinished
        cmp al, 0x07
        je drawBlackPawn
        cmp al, 0x08
        je drawBlackBishop
        cmp al, 0x09
        je drawBlackKnight
        cmp al, 0x0A
        je drawBlackRook
        cmp al, 0x0B
        je drawBlackQueen
        cmp al, 0x0C
        je drawBlackKing
    inc si
    cmp si, 64
    jne drawBlackPiece

drawFinished:
    ; Finished drawing board
    mov ax, 0x4C00
    int 0x21

; Draw a piece
drawPiece:
    push ax
    push bx
    push cx
    push dx

    mov bx, 0x03D4
    mov dx, 0x03D5
    mov al, 0x0F
    out dx, al

    mov cx, si
    mov al, 0x0E
    out dx, al
    xor ax, ax
    div cx, 8
    add al, 0x18
    out bx, al
    mov al, 0x0F
    out dx, al
    mov ax, 0
    div cx, 8
    mov al, ah
    out bx, al

    pop dx
    pop cx
    pop bx
    pop ax
    ret

; Draw white pawn
drawWhitePawn:
    mov al, WhitePawn
    call drawPiece
    ret

; Draw black pawn
drawBlackPawn:
    mov al, BlackPawn
    call drawPiece
    ret

; Draw white bishop
drawWhiteBishop:
    mov al, WhiteBishop
    call drawPiece
    ret

; Draw black bishop
drawBlackBishop:
    mov al, BlackBishop
    call drawPiece
    ret

; Draw white knight
drawWhiteKnight:
    mov al, WhiteKnight
    call drawPiece
    ret

; Draw black knight
drawBlackKnight:
    mov al, BlackKnight
    call drawPiece
    ret

; Draw white rook
drawWhiteRook:
    mov al, WhiteRook
    call drawPiece
    ret

; Draw black rook
drawBlackRook:
    mov al, BlackRook
    call drawPiece
    ret

; Draw white queen
drawWhiteQueen:
    mov al, WhiteQueen
    call drawPiece
    ret

; Draw black queen
drawBlackQueen:
    mov al, BlackQueen
    call drawPiece
    ret

; Draw white king
drawWhiteKing:
    mov al, WhiteKing
    call drawPiece
    ret

; Draw black king
drawBlackKing:
    mov al, BlackKing
    call drawPiece
    ret
