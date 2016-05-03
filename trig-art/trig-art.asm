            global  main 
            extern  sin 
            extern  cos 
            extern  printf 
            extern  puts

            section .text 
                            ; 'sd' postfix means "scalar double" for double precision floating point

header:     db      "theta        cos(theta)", 10, 
            db      "------------------------------------", 10, 0 
output:     db      "%10f   %10f", 10, 0 
pi:         dq      3.141592653589793 
delta:      dq      18.0            ; One line moves pi/delta radians. 
two:        dq      2.0             ; For two pi. 


main:       push    rbp 
            mov     rdi, header     ; Print a header. 
            xor     rax, rax 
            call    printf

; add by one
; multiply result by 39.5

L0:     
            movsd   xmm0, [radian]  ; movsd - "move scalar double"
            call    cos             ; result stored in xmm0
            movsd   [cosine], xmm0 
            
            movsd      xmm1, [one]  
            addsd      xmm0, xmm1
            movsd      xmm1, [half]
            mulsd      xmm0, xmm1
            cvtsd2si  rax, xmm0     ; convert/round to integer
            mov     [distance], rax ; save that value

            ;mov     rdi, format1     ; debugging
            ;mov     rsi, [distance]    ; if segfaulting, make sure format1 is %d
            ;xor     rax, rax
            ;call    printf

            mov     r12, [distance]

loop:     
            push    r12
            sub     rsp, 8
            mov     rdi, format2
            mov     rsi, space 
            xor     rax, rax
            call    printf
            add     rsp, 8
            pop     r12
            cmp     r12, 0
            je      printChar
            dec     r12
            jnz    loop

        
printChar:
            mov     rdi, format2
            mov     rsi, char
            xor     rax, rax
            call    printf

            ;mov     rdi, output     ; Display the results.
            ;movsd   xmm0, [radian] 
            ;movsd   xmm1, [cosine] 
            ;mov     rax, 3          ; 3 vector registers!-not clearing when using vector registers
            ;call    printf

incAngle: 
            movsd   xmm0, [radian] 
            movsd   xmm1, [pi] 
            divsd   xmm1, [delta]   ; pi/delta
            addsd   xmm0, xmm1      ; radian += pi/delta 
            movsd   [radian], xmm0  ; restore radian after incrementing
            movsd   xmm2, [pi] 
            mulsd   xmm2, [two] 
            addsd   xmm1, xmm2      ; 2*pi + pi/delta 
            comisd  xmm0, xmm1 
            jc      L0              ; carry flag is set if less than
            pop     rbp
            ret 

            section .data 

radian:     dq      0.0 
cosine:     dq      0.0

space:      db      " ", 0
char:       db      "*", 10, 0
distance:   dq      0
translate:  dq      40.0
format2:    db      "%s", 0
newline:    db      10
one:        dq      1.0
half:       dq      39.5
; calculate how many zeros to pad onto char
; multiply cos(radian) by 80 then use cvtsd2si
; padding zeros means don't add '10' after format strings until ready for newline
; 