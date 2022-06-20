BITS 64
SECTION .text
GLOBAL strstr

strstr:
    cmp byte [rsi], 0x00
    je matched_substring

loop:
    xor rcx, rcx
    mov r10b, byte [rdi]
    cmp byte [rsi], r10b
    je compare_strings
    cmp r10b, 0x00
    je unmatched_substring
    inc rdi
    jmp loop

compare_strings:
    inc rcx
    cmp byte [rsi + rcx], 0x00
    je matched_substring
    mov r10b, byte [rdi + rcx]
    cmp byte [rsi + rcx], r10b
    je compare_strings
    inc rdi
    jmp loop

unmatched_substring:
    mov rax, 0x00
    ret

matched_substring:
    mov rax, rdi
    ret