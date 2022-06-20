BITS 64
SECTION .text
GLOBAL strcspn

strcspn:
    xor r10b, r10b              ;sets r10b value to 0

iteration_starter:
    xor rcx, rcx                ;rcx value to zero
    cmp byte [rdi] , 0x00       ;verify is string not empty
    je exit
    mov r11b, byte [rsi]        ;(re)set first char of rsi in r11

lookup_char:
    cmp byte [rdi], r11b        ;if first byte of string different
    je exit                     ;exit program

empty_rsi:
    cmp byte [rsi], 0x00        ;if rsi is empty
    jne filled_rsi              ;if not empty, go to filled_rsi
    inc r10b
    jmp loop

filled_rsi:
    inc rcx
    mov r11b, byte [rsi + rcx]  ;str++
    cmp r11b, 0x00              ;verify char not null to continue lookup
    jne lookup_char
    inc r10b                    ;increment strcspn counter

loop:
    inc rdi                     ;next char in rdi
    jmp iteration_starter

exit:
    movsx rax, r10b             ;return nb of char not in rsi counted from rdi in r10b
    ret