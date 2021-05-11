%include	"libasm.inc"

section     .text
_ft_write:
			mov		rax, 0x2000004
            syscall
            jc		error
            ret
error:
			push	rdx
			mov		rdx, rax
            call	___error
            mov		[rax], rdx
            pop		rdx
            mov		rax, -1
            ret