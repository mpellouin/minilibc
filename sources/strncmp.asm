BITS 64
SECTION .text
GLOBAL strncmp

strncmp:
    xor rcx, rcx

loop:
    cmp rcx, rdx                ;check if n has been passed
    jge equal_string            ;if so strncmp successfull
    mov r10b, byte [rdi]
    mov r11b, byte [rsi]
    cmp r10b, r11b              ;if first byte of string different
    jne different_strings       ;go to different_strings
    cmp r10b, 0x00              ;Check if one of the string is over
    je equal_string             ;if so strncmp successfull
    inc rdi
    inc rsi
    inc rcx                     ;inc strings and looping index
    jmp loop                 ;jmp back to strncmp (similar to strncmp(str1+1, str2+1, n-1))

different_strings:
    sub r10b, r11b
    movsx rax, r10b             ;Res is set to *s1 - *s2, movsx same reason as strcmp
    ret

equal_string:
    mov rax, 0x00               ;if successfull returns 0
    ret