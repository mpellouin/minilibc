BITS 64
SECTION .text
GLOBAL index

index:
    mov rax, 0x00

loop:
    cmp byte [rdi], sil
    je end
    cmp byte [rdi], 0x00
    je exit
    inc rdi
    jmp loop

exit:
    ret

end:
    mov rax, rdi
    ret