BITS 64
SECTION .text
GLOBAL memcpy

memcpy:
    xor rcx, rcx                ;sets rcx to 0

loop:
    cmp rcx, rdx                ;compare index to n size
    je exit
    mov r10b, byte [rsi + rcx]
    mov byte [rdi + rcx], r10b  ;sets c byte from rsi in rdi + index
    inc rcx                     ;i++
    jmp loop

exit:
    mov rax, rdi                ;returns address of rdi
    ret