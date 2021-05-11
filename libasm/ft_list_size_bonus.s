%include	"libasm.inc"

section     .text
_ft_list_size:
			push	rcx
			xor		rax, rax
			cmp		rdi, 0
			je		end
			mov		rcx, [rdi + 8]
cycle:
			inc		rax
			cmp		rcx, 0
            je		end
            mov		rcx, [rcx + 8]
			jmp		cycle

end:
			pop		rcx
			ret