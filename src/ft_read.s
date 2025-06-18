section	.text
    extern __errno_location
    global ft_read

; ft_read(rdi, rsi, rdx)
ft_read:
    ; read(syscall 0) to fd
    MOV rax, 0
    syscall                ; perform syscall

    test rax, rax          ; check if is negtive
    JS .error              ; jump  if sign flag turn on

    ret

.error
    neg rax                ; get absolute value of syscall return, need to flip for the errno
    mov rdi, rax           ; move the errno as the 1st parameter
    call __errno_location  ; __errno_location will return the addr of errno
    mov [rax], edi         ; store errno into *errno
    mov rax, -1
    ret
