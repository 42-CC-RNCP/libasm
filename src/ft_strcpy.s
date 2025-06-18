section	.text
   global ft_strcpy

ft_strcpy:
    ; dest rdi, src rsi
    mov rax, rdi    ; record the dest addr for return

.loop:
    mov dl, [rsi]    ; store current byte of src
    mov [rdi], dl    ; store to dest
    cmp dl, 0
    je .done
    inc rdi
    inc rsi
    jmp .loop

.done:
    ret
