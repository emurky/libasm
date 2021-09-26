section	.text
global	_ft_strdup
extern	_malloc, _ft_strlen, _ft_strcpy

_ft_strdup:
	push	rdi
	call	_ft_strlen
	inc		rax
	mov		rdi, rax
	call	_malloc
	cmp		rax, 0
	je		.error
	pop		rsi
	mov		rdi, rax
	call	_ft_strcpy
	ret

.error:
	ret
