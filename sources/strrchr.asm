BITS 64
SECTION .text
GLOBAL strrchr

strrchr:
    mov r10, 0x00           ;init return value to null

loop:
    cmp byte [rdi], sil     ;check if *str is matching c (sil = 8-bit from rsi)
    jne not_matched         ;if not so skip next line
    mov r10, rdi            ;set match address in r10

not_matched:
    cmp byte [rdi], 0x00    ;check if end of string
    je exit                 ;if so return null
    inc rdi                 ;str++
    jmp loop

exit:
    mov rax, r10            ;return last match address or null if no match
    ret
