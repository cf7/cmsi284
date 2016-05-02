
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

quarters:
            xor     rdx, rdx    ; rdx might be used by other processes, clear it first
            xor     rcx, rcx
            mov     r9, [quarter]
            div     r9          ; div stores remainder in rdx, result in rax (SDM pg 326)
            mov     rcx, rdx     ; store remainder
            mov     rsi, rax
            mov     rdi, quartersFormat
            xor     rax, rax
            call    printf

dimes:
            xor     rdx, rdx
            mov     rax, rcx    ; the remainder from quarters
            mov     r9, [dime]
            div     r9
            xor     rcx, rcx   
            mov     rcx, rdx    ; need to use rcx, for some reason r9 was being wiped
            mov     rsi, rax
            mov     rdi, dimesFormat
            xor     rax, rax    
            call    printf

nickels:
            xor     rdx, rdx
            mov     rax, rcx    ; the remainder from quarters
            mov     r9, [nickel]
            div     r9
            mov     rcx, rdx    
            mov     rsi, rax
            mov     rdi, nickelsFormat
            xor     rax, rax    
            call    printf
            jmp     done
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


quartersFormat:
            db      "Quarters: %d", 10, 0
dimesFormat:
            db      "Dimes: %d", 10, 0
nickelsFormat:
            db      "Nickels: %d", 10, 0
penniesFormat:
            db      "Pennies: %d", 10, 0
quarter:
            dq      25
dime:  
            dq      10
nickel:
            db      5
penny:
            db      1