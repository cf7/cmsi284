
                global main
                extern puts
                extern printf
                extern atoi

                section .text

main:
            push    rdi
            push    rsi
            add     rsi, 8
            cmp     rdi, 2
            jne     error1

            

error1:
            mov edi, wrongNumberArgs
            call puts
            jmp  done

done:
            pop     rdi
            pop     rsi
            ret

wrongNumberArgs:
            db "Requires exactly one argument", 10, 0