
        global main
        extern puts
        extern printf
        extern atoi

        section .text

main:
        push    rdi    ; holds argc
        push    rsi    ; holds argsv
        cmp     rdi, 2 ; check number of arguments
        jne     error1



error1:
        mov     edi, wrongNumberArgs

wrongNumberArgs:
        db      "Requires exactly one argument", 10, 0 