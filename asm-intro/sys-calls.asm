

        global main
        extern puts
        extern printf
        extern atoi

        section .text           
                                ; filename as input, open file syscall
                                ; 50 - listen(), 100- times(), 
main:
        push    rdi
        push    rsi
        
        mov     rax, 50         ; sys_listen, returns 0 if successful
        mov     rdi, 1          ; int fd
        mov     rsi, 1          ; int backlog
        syscall

        mov     rdi, format
        mov     rsi, rax
        xor     rax, rax
        call    printf
        ; write(1, message, 13)
        ;mov     rax, 1                  ; system call 1 is write
        ;mov     rdi, 1                  ; stdout is file handle 1, write needs file handle as first input
        ;mov     rsi, message            ; address of string to output
        ;mov     rdx, 13                 ; number of bytes to output
        ;syscall                         ; invoke operating system to do the write

        ; exit(0)
        mov     eax, 60                 ; system call 60 is exit
        xor     rdi, rdi                ; exit code 0
        syscall                         ; invoke operating system to exit

        jmp     done
done:
        pop     rsi
        pop     rdi
        ret

format:
        db      "%d", 10, 0
message:
        db      "Hello, World", 10, 0     ; note the newline at the end