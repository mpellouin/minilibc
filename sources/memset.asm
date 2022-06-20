BITS 64
SECTION .text
GLOBAL memset

memset:
    xor rcx, rcx                ;sets rcx to 0

loop:
    cmp rcx, rdx                ;compare index to n size
    je exit
    mov byte [rdi + rcx], sil   ;sets c byte from rsi in rdi + index
    inc rcx                     ;i++
    jmp loop

exit:
    mov rax, rdi                ;returns address of rdi
    ret