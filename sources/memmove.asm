BITS 64
SECTION .text
GLOBAL memmove

memmove:
    xor rcx, rcx                ;sets rcx to 0
    cmp rcx, rdx                ;compares i and n
    je exit                      ;if i and n are equal, jump to end

push_stack:
    cmp rcx, rdx                ;compare i and n
    je loop                     ;if equal, jump to loop
    mov r10b, byte [rsi + rcx]  ;move byte from src to r10b
    push r10                    ;put value of src into stack
    inc rcx                     ;increment i
    jmp push_stack              ;loop to push_stack

loop:
    dec rcx                     ;decrement i
    pop r10                     ;pop src value from stack
    mov byte [rdi + rcx], r10b  ;sets byte in dest + i
    cmp rcx, 0x00               ;compare i to 0
    je exit                     ;if equal, jump to exit
    jmp loop                    ;loop

exit:
    mov rax, rdi                ;returns address of rdi
    ret