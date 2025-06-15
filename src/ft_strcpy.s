section	.text
   global ft_strcpy

ft_strcpy:
    ; dest rdi, src rsi
    MOV rax, rdi    ; record the dest addr for return

.loop:
    MOV bl, [rsi]    ; store current byte of src
    CMP bl, 0
    JE .done
    MOV [rdi], bl    ; cpy temp the byte to the current pos of dest
    INC rdi
    INC rsi
    JMP .loop

.done:
    ret
