BITS 64
SECTION .text
GLOBAL strchr

strchr:
    cmp byte [rdi], sil     ;check if *str is matching c (sil = 8-bit from rsi)
    je exit                 ;if so return str
    cmp byte [rdi], 0x00    ;check if end of string
    je exit_null            ;if so return null
    inc rdi
    jmp strchr

exit:
    mov rax, rdi
    ret

exit_null:
    mov rax, 0x00
    ret
