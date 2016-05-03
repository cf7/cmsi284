
        global main
        extern printf
        extern puts
        extern atoi
        extern madlib_by_numbers

        section .text

main:
        sub     rsp, 8
        xor     rax, rax

        mov     r11, rdi        ; store number of args
        sub     r11, 2
        mov     rdi, [rsi + 8]  ; template
        add     rsi, 16
        mov     rdx, rsi        ; pointer to array of words
        mov     rsi, r11        ; word count
        call    madlib_by_numbers
        mov     rsi, rax
        mov     rdi, formats
        xor     rax, rax
        call    printf

done:
        add     rsp, 8
        ret

formats:
        db      "%s", 10, 0
