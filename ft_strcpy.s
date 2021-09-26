section	.text
global	_ft_strcpy

_ft_strcpy:
	mov		rax, rdi
	xor		rcx, rcx
loop:
	mov		al, byte[rsi + rcx]
	mov		byte[rdi + rcx], al
	inc		rcx
	cmp		al, 0
	jne		loop
	ret
