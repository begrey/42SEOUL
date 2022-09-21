section .text
	global _ft_read
	extern ___error

_ft_read:
	mov rax, 0x2000003
	syscall
	jc _handle_error ;unsigned int 값을 벗어나 carry flag = 1
	ret

_handle_error:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx 
	mov rax, -1
	ret