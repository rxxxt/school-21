%include	"libasm.inc"

section     .text
_ft_strdup:
            call	_ft_strlen
            inc		rax
            push    rdi
			mov     rbx, rdi
            mov     rdi, rax
            call    _malloc
            cmp     rax, 0
            je      error
            push    rsi
            mov		rdi, rax
            mov		rsi, rbx
            call    _ft_strcpy
            pop     rsi
            pop		rdi
            ret
error:
            xor     rax, rax
            ret