BITS 64
SECTION .text
GLOBAL strcasecmp

strcasecmp:
    mov r10b, byte [rdi]
    mov r11b, byte [rsi]
    jmp check_maj_rdi

comparison:
    cmp r10b, r11b              ;if first byte of string different
    jne exit                    ;go to different_strings
    cmp r10b, 0x00              ;Check if one of the string is over
    je exit                     ;if so strcmp successfull
    inc rdi
    inc rsi
    jmp strcasecmp              ;jmp back to strncmp (similar to strcmp(str1+1, str2+1))

check_maj_rdi:
    cmp r10b, 'A'
    jl check_maj_rsi
    cmp r10b, 'Z'
    jg check_maj_rsi
    add r10b, 0x20

check_maj_rsi:
    cmp r11b, 'A'
    jl comparison
    cmp r11b, 'Z'
    jg comparison
    add r11b, 0x20
    jmp comparison

exit:
    sub r10b, r11b              ; *s1 - *s2
    movsx rax, r10b             ;movsx for byte conversion 8 to 64
    ret