BITS 64
SECTION .text
GLOBAL rindex

rindex:
    mov rax, 0x00
    jmp loop

set_index:
    mov rax, rdi
    cmp byte [rdi], 0x00
    je end
    inc rdi

loop:
    cmp byte [rdi], sil
    je set_index
    cmp byte [rdi], 0x00
    je end
    inc rdi
    jmp loop

end:
    ret