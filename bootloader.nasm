global _start

_start:

; Load GDT
lgdt [gdtr]

; Set the Data Segment Register
mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax
mov ss, ax

; Set the Code Segment Register
mov ax, 0x08
mov cs, ax

; Jump to the kernel
jmp 0x08:start_kernel

; GDT Descriptor
gdt:

; Null descriptor
dd 0
dd 0

; Code descriptor
dw 0xFFFF
dw 0x0000
db 0x00
db 0x9A
db 0xCF
db 0x00

; Data descriptor
dw 0xFFFF
dw 0x0000
db 0x00
db 0x92
db 0xCF
db 0x00

gdtr:
dw gdt_end - gdt - 1
dd gdt

gdt_end:

; Kernel entry point
start_kernel:
; Your kernel code here...
