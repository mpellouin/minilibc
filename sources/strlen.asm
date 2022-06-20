BITS 64
SECTION .text
GLOBAL strlen

strlen:
    xor rcx, rcx
    ;resets rcx, used for looping
    ;enters automatically the loop

loop:
    cmp byte [rdi], 0x00
    je string_over
    inc rcx ;size++
    inc rdi ;str++
    jmp loop

string_over:
    mov rax, rcx ;put size in return value
    ret
