section .text
    global _ft_strcmp

_ft_strcmp:
    mov rax, 0
	mov rbx, 0
	mov rcx, 0
	jmp compare

compare:
	mov ah, BYTE [rdi + rcx]
	mov bh, BYTE [rsi + rcx]
	cmp ah, bh
	jne diff
	je	same

diff:
	sub rax, rbx
	ret

same:
	cmp al, 0
	je 	end
	inc rcx
	jmp compare

end:
	mov rax, 0
	ret