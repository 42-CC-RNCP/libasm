section	.text
   global ft_strcmp

ft_strcmp:
    XOR rax, rax

.loop:
    movzx rax, byte [rdi] ; move s1[i] into rax
    movzx rdx, byte [rsi] ; move s2[i] into rdx
    CMP rax, 0
    JE .ret
    CMP rdx, 0
    JE .ret
    CMP al, dl
    JNE .ret
    INC rdi               ; s1++
    INC rsi               ; s2++
    JMP .loop

.ret:
    movsx rax, byte [rdi]    ; sign-extend s1[i] into rax
    movsx rdx, byte [rsi]    ; sign-extend s2[i] into rdx
    SUB rax, rdx
    ret
