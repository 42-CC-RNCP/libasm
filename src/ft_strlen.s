section	.text
   global ft_strlen

ft_strlen:
    MOV rax, 0
    MOV rbx, rdi

.loop:
    MOV dl, [rbx+rax]
    CMP dl, 0
    je .done
    INC rax
    jmp .loop

.done:
    ret
