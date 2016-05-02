        global  main
        extern  puts
        extern  printf
        extern  reverse_range_in_place  ; void functions affect data in place

        section .text
main:

        push    rdi                     ; save registers that puts uses
        push    rsi
        sub     rsp, 8                  ; must align stack before call

        ;xor     rdi, rdi
        ;xor     rsi, rsi
        ;xor     rdx, rdx
        ;mov     rdi, string                ; the argument string to display
        ;mov     esi, start
        ;mov     edx, end
        ;call    reverse_range_in_place

        mov     rdi, [rsi]
        call    puts

        add     rsp, 8                  ; restore %rsp to pre-aligned value
        pop     rsi                     ; restore registers puts used
        pop     rdi

        add     rsi, 8                  ; point to next argument
        dec     rdi                     ; count down
        jnz     main                    ; if not done counting keep going

        ret

format:
        db      "%s", 10, 0
string:
        db      "hello", 10
start:
        db      0
end:
        db      5      