%include	"libasm.inc"

section		.text
_ft_strcmp:
			push	rcx
			push	rdx
			xor		rcx, rcx
cycle:
			mov		al, byte[rdi + rcx]
			mov		dl, byte[rsi + rcx]
			cmp		al, dl
			jne		end
			cmp		al, 0
			je		end
			inc		rcx
			jmp		cycle
end:
			movzx	rcx, dl
			sub		rax, rcx
			pop		rdx
			pop		rcx
			ret