section	.text
   global ft_strlen

ft_strlen:
    mov rax, 0
    mov rcx, rdi

.loop:
    mov dl, [rcx+rax]
    cmp dl, 0
    je .done
    inc rax
    jmp .loop

.done:
    ret
