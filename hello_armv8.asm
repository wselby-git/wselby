.global _start

_start:
    // Print the "Hello, World!" string
    mov x0, #0x0
    ldr x1, =msg
    bl printf

    // Exit the program
    mov x0, #0x0
    bl exit

msg:
    .asciz "Hello, World!"
