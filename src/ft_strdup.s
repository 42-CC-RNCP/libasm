extern malloc
extern ft_strlen
extern ft_strcpy

section	.text
   global ft_strdup

; ft_strdup(const char *s1(rdi)),
ft_strdup:
    mov rcx, rdi    ; save the pointer of s1

    mov rsi, rdi
    push rcx
    call ft_strlen  ; rax = len(s1)
    add rax, 1
    mov rdi, rax
    call malloc     ; rax = addr of the array
    test rax, rax
    jz .error

    pop rcx
    mov rdi, rax
    mov rsi, rcx
    call ft_strcpy
    test rax, rax
    jz .error
    ret

.error:
    xor rax, rax
    ret
