%include	"libasm.inc"

section     .text
_ft_list_push_front:
			cmp		rsi, 0
			je		end
			push	rdi
			push	rsi
			mov		rdi, 16
			call	_malloc
			pop		rsi
			pop		rdi
			cmp		rax, 0
			je		end
			mov		[rax], rsi
			push	rcx
			mov		rcx, [rdi]
			mov		[rax + 8], rcx
			mov		[rdi], rax
			pop		rcx
end:
			ret