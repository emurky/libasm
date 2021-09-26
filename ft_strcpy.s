section	.text
global	_ft_strcpy

_ft_strcpy:
	mov		rax, rdi
	xor		rcx, rcx
loop:
	mov		dl, byte[rsi + rcx]
	mov		byte[rax + rcx], dl
	inc		rcx
	cmp		dl, 0
	jne		loop
	ret
