BITS 64
SECTION .text
GLOBAL strcmp

strcmp:
    mov r10b, byte [rdi]
    mov r11b, byte [rsi]
    cmp r10b, r11b              ;if first byte of string different
    jne different_strings       ;go to different_strings
    cmp r10b, 0x00              ;Check if one of the string is over
    je equal_string             ;if so strcmp successfull
    inc rdi
    inc rsi
    jmp strcmp                  ;jmp back to strncmp (similar to strcmp(str1+1, str2+1))

different_strings:
    sub r10b, r11b              ; *s1 - *s2
    movsx rax, r10b             ;movsx for byte conversion 8 to 64
    ret

equal_string:
    mov rax, 0x00               ;if succesfull return value set to 0
    ret