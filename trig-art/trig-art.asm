
        global main
        extern printf
        extern puts
        extern atoi

main:
        push    rdi
        push    rsi

        jmp     done
done:
        pop     rsi
        pop     rdi
        ret