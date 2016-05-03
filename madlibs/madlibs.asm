
        global main
        extern printf
        extern puts
        extern atoi
        extern madlib_by_numbers

        section .text

main:
       
        ;sub     rsp, 8

        ;mov     rsi, rdi
        ;mov     rdi, formatd
        ;xor     rax, rax
        ;call    printf
        mov     rdi, [rsi + 8]
        add     rsi, 16
        mov     rdx, rsi
        mov     rsi, [filler]
        call    madlib_by_numbers
        mov     rsi, rax
        mov     rdi, formats
        xor     rax, rax
        call    printf

done:
        
        ret


filler:
        dq      0
formatd:
        db      "%d", 10, 0
formats:
        db      "%s", 10, 0
one:
        dq      1