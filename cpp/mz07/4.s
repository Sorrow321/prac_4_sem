forward.args(long long, int, int):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     QWORD PTR [rbp-24], rdi
        mov     DWORD PTR [rbp-28], esi
        mov     DWORD PTR [rbp-32], edx
        mov     edx, DWORD PTR [rbp-32]
        mov     eax, DWORD PTR [rbp-28]
        cdqe
        mov     rcx, QWORD PTR [rbp-24]
        mov     rsi, rax
        mov     edi, ecx
        call    process(int, long long, unsigned int)
        mov     DWORD PTR [rbp-4], eax
        mov     eax, DWORD PTR [rbp-4]
        neg     eax
        leave
        ret
