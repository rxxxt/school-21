%include	"libasm.inc"

section		.text
_ft_strlen:
			xor		rax, rax
cycle:
			cmp		byte[rdi + rax], 0
			je		end
			inc		rax
			jmp		cycle
end:
			ret