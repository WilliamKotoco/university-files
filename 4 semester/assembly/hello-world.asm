section .data
	hello db "Hello World!", 0x0A
	hello_len equ $ - hello ; string lentgh 

section .text
	global _start

start:
	mov eax, 4			; syscall for system write
	mov ebx, 1			; description for stdout

	mov ecx, hello		; string's address 
	mov edx, hello_len ; register edx receives the string length
	
	int 0x80			; call syscal 4 (responsible for writting)
	
	mov eax, 1			; eax register receives 1, syscall code responsible for finishing the program
	xor ebx, ebx 		; exit status (0)
	int 0x80			; call syscall 1, present on the eax register
