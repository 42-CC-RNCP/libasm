section	.text
   global ft_strcpy

ft_strcpy:
    ; dest rdi, src rsi
    MOV rax, rdi    ; record the dest addr for return

.loop:
    MOV dl, [rsi]    ; store current byte of src
    mov [rdi], dl    ; store to dest
    CMP dl, 0
    JE .done
    INC rdi
    INC rsi
    JMP .loop

.done:
    ret
