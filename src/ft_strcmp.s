section	.text
   global ft_strcmp

ft_strcmp:
    xor rax, rax

.loop:
    movzx rax, byte [rdi] ; move s1[i] into rax
    movzx rdx, byte [rsi] ; move s2[i] into rdx
    cmp al, 0
    je .ret
    cmp dl, 0
    je .ret
    cmp al, dl
    jne .ret
    inc rdi               ; s1++
    inc rsi               ; s2++
    jmp .loop

.ret:
    sub rax, rdx
    ret
