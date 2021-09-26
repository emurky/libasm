section	.text
global	_ft_strcmp

_ft_strcmp:
	xor		rax, rax
	xor		rcx, rcx
	xor		rdx, rdx

.loop:
	mov		cl, byte[rdi + rax]
	mov		dl, byte[rsi + rax]
	inc		rax
	cmp		cl, dl
	jne		.substract
	cmp		cl, 0
	jne		.loop
	xor		rax, rax
	ret

.substract
	sub		rcx, rdx
	mov		rax, rcx
	ret
