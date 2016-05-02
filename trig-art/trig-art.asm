        global  main 
        extern  sin 
        extern  cos 
        extern  printf 
        section .text 
header: db      "theta        sin(theta)   cos(theta)", 10, 
        db      "------------------------------------", 10, 0 
output: db      "%10f   %10f   %10f", 10, 0 
pi:     dq      3.141592653589793 
delta:  dq      45.0            ; One line moves pi/delta radians. 
two:    dq      2.0             ; For two pi. 
main:   push    rbp 
        mov     rdi, header     ; Print a header. 
        xor     rax, rax 
        call    printf 
L0:     movsd   xmm0, [radian] 
        call    sin             ; Result in xmm0.  
        movsd   [sine], xmm0    ; Save to memory. 
        movsd   xmm0, [radian] 
        call    cos             ; Ditto with cosine. 
        movsd   [cosine], xmm0 
        ; Display the results. 
        mov     rdi, output 
        movsd   xmm0, [radian] 
        movsd   xmm1, [sine] 
        movsd   xmm2, [cosine] 
        mov     rax, 3          ; 3 vector registers! 
        call    printf 
        movsd   xmm0, [radian] 
        movsd   xmm1, [pi] 
        divsd   xmm1, [delta] 
        addsd   xmm0, xmm1      ; radian += pi/delta 
        movsd   [radian], xmm0 
        movsd   xmm2, [pi] 
        mulsd   xmm2, [two] 
        addsd   xmm1, xmm2      ; 2*pi + pi/delta 
        comisd  xmm0, xmm1 
        jc      L0              ; CF is set if less than. 
        pop     rbp 
        ret 
        section .data 
radian: dq      0.0 
sine:   dq      0.0 
cosine: dq      0.0 