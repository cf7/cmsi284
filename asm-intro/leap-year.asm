

            global main
            extern puts
            extern printf
            extern atoi

            section .text

main:
            push    rdi
            push    rsi
            ;add     rsp, 8
            cmp     rdi, 2
            jne     error1

            mov     rdi, [rsi + 8]
            xor     rax, rax
            call    atoi        ; result of atoi call stored in rax
            mov     r11, rax    ; store just in case it isn't a leap year
            ;mov     rsi, rax
            ;mov     rdi, yes
            ;xor     rax, rax
            ;call    printf

            xor     r12, r12
            xor     rdx, rdx    ; clear rdx every time when using div
            mov     r12, [four]
            div     r12
            cmp     rdx, 0    
            jz      isLY
            mov     rax, r11
            mov     r12, [hundred]
            div     r12
            cmp     rdx, 0
            jz      notLY
            mov     rax, r11
            mov     r12, [fourHundred]
            div     r12
            cmp     rdx, 0
            jne     notLY

error1:
            mov     edi, wrongNumberArgs
            call    puts
            jmp     done

isLY:
            mov     rsi, r11
            mov     rdi, yes
            xor     rax, rax
            call    printf
            jmp     done
notLY:
            mov     rsi, r11
            mov     rdi, no
            xor     rax, rax
            call    printf
            jmp     done
done:
            pop     rsi
            pop     rdi
            ret

wrongNumberArgs:
            db      "Requires exactly one argument", 10, 0
yes:
            db      "%d is a leap year", 10, 0
no:
            db      "%d is not a leap year", 10, 0

four:
            dq      4
hundred:
            dq      100
fourHundred:
            dq      400