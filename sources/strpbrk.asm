BITS 64
SECTION .text
GLOBAL strpbrk

strpbrk:
    cmp byte [rsi], 0x00
    je unmatched_chars

init_loop:
    xor rcx, rcx
    mov r10b, byte [rdi]        ;set first char of rdi in r10
    cmp r10b, 0x00              ;verify is string not empty
    je unmatched_chars
    mov r11b, byte [rsi]        ;(re)set first char of rsi in r11


lookup_char:
    cmp r10b, r11b              ;if first byte of string different
    je match_chars
    inc rcx
    mov r11b, byte [rsi + rcx]  ;put next char from rsi in r11
    cmp r11b, 0x00              ;verify char not null to continue verif
    jne lookup_char

loop:
    inc rdi                     ;next char in rdi
    jmp init_loop

match_chars:
    mov rax, rdi                ;return addr of byte matched
    ret

unmatched_chars:
    mov rax, 0x00               ;if successfull returns 0
    ret