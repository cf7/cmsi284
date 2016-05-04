

        global main
        extern puts
        extern printf
        extern atoi
                                        ; connect, accept, listen
        section .text           
                                ; filename as input, open file syscall
                                ; 50 - listen(), 100- times(), 

                                ; file descriptor = number that represents socket
                                ; descriptors refer to processes on file table
                                ; file table contains modes in which files are opened
                                ; as well as references to inode table
                                ; inode table contains paths to actual files
main:
        push    rdi
        push    rsi
                                ; argument processing for 2 args

        mov     rax, 201        ; sys_time
        mov     rdi, [rsi + 8]  ; giving it an arbitrary file so it works
        syscall                 ; returns time since last epoch
                                ; "date +%s" in build file to make sure it is the right time
        mov     rsi, rax        ; printing result just to see what is happening
        mov     rdi, format
        xor     rax, rax
        call    printf

        mov     rax,  253       ; sys_inotify_init - initializes a new notify file descriptor
        syscall                 ; and returns file descriptor associated with new notify event queue
                                ; (should be a small nonnegative int)
        
        mov     rsi, rax
        mov     rdi, format
        xor     rax, rax
        call    printf

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
