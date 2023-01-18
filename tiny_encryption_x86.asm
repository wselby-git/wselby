; TEA algorithm implementation in x86 assembly
section .data
    key dd 0x12345678, 0x9abcdef0 ; encryption key

section .text
global encrypt

encrypt:
    ; function prologue
    push ebp
    mov ebp, esp
    push ebx
    push esi
    push edi

    ; TEA encryption algorithm
    mov eax, [ebp + 8] ; get plaintext block
    mov ebx, [ebp + 12]
    mov ecx, [key] ; get key
    mov edx, [key + 4]
    mov esi, 0x9e3779b9 ; set round constant
    mov edi, 32 ; set number of rounds

enc_loop:
    add eax, (ebx shl 4) + ecx
    mov ebx, ebx + (eax shl 4) + edx
    add eax, ebx
    dec edi
    jnz enc_loop

    ; function epilogue
    mov [ebp + 8], eax ; store ciphertext block
    mov [ebp + 12], ebx
    pop edi
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret
