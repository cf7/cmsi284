

        global main
        extern puts
        extern printf
        extern atoi
                        
        section .text           

main:
        push    rdi
        push    rsi
        
        cmp     rdi, 2
        jne     error1          ; argument processing for 2 args

        mov     rax, 201        ; sys_time
        mov     rdi, [rsi + 8]  ; giving it an arbitrary file so it works
        syscall                 ; returns time since last epoch
        mov     r12, rax
        push    r12
                                ; "date +%s" in build file to make sure it is the right time
        mov     rsi, rax        ; printing result just to see what is happening
        mov     rdi, format
        xor     rax, rax
        call    printf

        mov     rax,  253       ; sys_inotify_init - initializes a new notify file descriptor
        syscall                 ; and returns file descriptor associated with new notify event queue
                                ; (should be a small nonnegative int)
        mov     r11, rax
        push    r11

        mov     rsi, rax
        mov     rdi, format
        xor     rax, rax
        call    printf

        pop     r12
        cmp     r12, 0
        jge     success1
        jl      error2

success1:
        pop     r11
        cmp     r11, 0
        jge     success2
        jl      error2

success2:

        ; write(1, message, 13)
        mov     rax, 1                  ; system call 1 is write
        mov     rdi, 1                  ; file handle 1 is stdout
        mov     rsi, message            ; address of string to output
        mov     rdx, 24                 ; number of bytes - length of message below
        syscall                         ; invoke operating system to do the write

        jmp     done

error1:
        mov     rdi, wrongNumberArgs
        call    puts
error2:
        mov     rdi, callError
        call    puts
done:
        pop     rsi
        pop     rdi
        
        ; exit(0)
        mov     eax, 60                 ; system call 60 is exit
        xor     rdi, rdi                ; exit code 0
        syscall                         ; invoke operating system to exit
        ret

wrongNumberArgs:
        db      "Requires exactly one argument", 10, 0
callError:
        db      "System calls unsuccessful", 10, 0
format:
        db      "%d", 10, 0
message:
        db      "System calls successful", 10, 0
