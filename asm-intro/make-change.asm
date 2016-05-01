
            global main
            extern puts
            extern printf
            extern atoi

            section .text

main:
            push    rdi
            push    rsi
            ;add     rsi, 8
            cmp     rdi, 2
            jne     error1

            mov     rdi, [rsi + 8]
            call    atoi        ; result of atoi call stored in rax

quarters:
            xor     r8, r8
            mov     rdx, rax
            mov     r9, [quarter]
            div     r9
            mov     rsi, rdx    ; div stores remainder in rdx, result in rax (SDM pg 326)
            jmp    print

error1:
            mov     edi, wrongNumberArgs
            call    puts
            jmp     done

done:
            pop     rsi
            pop     rdi
            ret

wrongNumberArgs:
            db      "Requires exactly one argument", 10, 0

print:
            mov     rdi, format     ; printf needs (rdi-format, rsi-input)
            xor     rax, rax        ; always remember to clear rax for printf
            call    printf
            jmp     done

format:
            db      "%d", 10, 0

quarter:
            dq      25
dime:  
            dq      10
nickel:
            dq      5