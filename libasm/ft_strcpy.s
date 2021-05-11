%include	"libasm.inc"

section     .text
_ft_strcpy:
			push	rcx
			xor		rcx, rcx
copy:
			mov		al, byte[rsi + rcx]
			mov		byte[rdi + rcx], al
			cmp		al, 0
			je		end
			inc		rcx
			jmp		copy
end:
			pop		rcx
			mov		rax, rdi
			ret