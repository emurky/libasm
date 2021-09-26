section	.text
global	_ft_strcmp

_ft_strcmp:
	mov		rax, 0
	mov		rcx, 0

loop:
	mov		cl, byte[rdi + rax]
	mov		dl, byte[rsi + rax]
	inc		rax
	cmp		cl, dl
	jne		substract
	cmp		cl, 0
	jne		loop
	xor		rax, rax
	ret

substract
	sub		rcx, rdx
	mov		rax, rcx
	ret
