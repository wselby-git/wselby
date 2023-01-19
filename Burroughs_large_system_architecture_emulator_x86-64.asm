section .text
global _start

; define registers
%define REG_A rax
%define REG_B rbx
%define REG_C rcx
%define REG_D rdx
%define REG_E rsi

; NOP
_nop:
    xor %REG_A, %REG_A
    ret

; LD
_ld:
    mov %REG_A, [%REG_B]
    ret

; ST
_st:
    mov [%REG_B], %REG_A
    ret

; ADD
_add:
    add %REG_A, %REG_B
    ret

; SUB
_sub:
    sub %REG_A, %REG_B
    ret

; MUL
_mul:
    imul %REG_A, %REG_B
    ret

; DIV
_div:
    mov %REG_C, %REG_A
    mov %REG_D, %REG_B
    idiv %REG_C
    mov %REG_A, %REG_E
    ret

; JMP
_jmp:
    jmp %REG_A
    ret

; JEQ
_jeq:
    cmp %REG_A, %REG_B
    je %REG_C
    ret

; JNE
_jne:
    cmp %REG_A, %REG_B
    jne %REG_C
    ret

; HALT
_halt:
    xor %REG_A, %REG_A
    mov %REG_A, %REG_B
    call _exit

; _start
_start:
    ; NOP
    call _nop

    ; LD
    mov rax, 0x12345678
    mov rbx, rax
    call _ld
    cmp rax, 0x12345678
    jne _exit

    ; ST
    mov rax, 0x87654321
    mov rbx, rax
    call _st
    cmp rax, 0x87654321
    jne _exit

    ; ADD
    mov rax, 0x1000
    mov rbx, 0x2000
    call _add
    cmp rax, 0x3000
    jne _exit

    ; SUB
    mov rax, 0x3000
    mov rbx, 0x2000
    call _sub
    cmp rax, 0x1000
    jne _exit

    ; MUL
    mov rax, 0x1000
    mov rbx, 0x2000
    call _mul
    cmp rax, 0x2000000
    jne _exit

    ; DIV
    mov rax, 0x2000000
    mov rbx, 0x2000
    mov rcx, 0x1000
    mov rdx, 0x1000
    call _div
    cmp rsi, 0x2000
    jne _exit

    ; JMP
    mov rax, _halt
    call _jmp

    ; JEQ
    mov rax, 0x1000
    mov rbx, 0x1000
    mov rcx, _halt
    call _jeq

    ; JNE
    mov rax, 0x1000
    mov rbx, 0x2000
    mov rcx, _halt
    call _jne

_exit:
    mov rax, 60
    xor rdi, rdi
    syscall
