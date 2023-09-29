

; This section initializes constants and data for later use.  
section .data
input1 db "Enter the first number: ", 0xa; stores the message in the input register. Oxa is the breakline
len1 equ $ - input1 ; stores the length
input2 db "Enter the second number: ", 0xa ; stores the message in the input2 register. Oxa is the breakline
len2 equ $ - input2 ;stores the lenght

; This section reserve bytes to variables that are not initialized yet. 
section .bss
num1 resb 10 ; resb is an mneumonic for RESERVE bytes
num2 resw 10
res resw 10

; code starts on the text section
section .text
global _start
_start :

; prints the input 1
mov edx, len1   ;edx register is used for I/0 port acess
mov ecx, input1 ;ecx register is used for string operations
mov ebx, 1 ;  set the ebx to 1 (file descriptor fot standart output)
mov eax, 4; move eax to syswrite
int 0x80; syscall to interrupt


; gets the first number
mov edx, 10
mov ecx, num1 ; stores on num1
mov ebx, 0 ;
mov eax, 3  ; 3 is the syscall for reading
int 0x80


; prints the input 2
mov edx, len2
mov ecx, input2
mov ebx, 1
mov eax, 4
int 0x80

; gets the second number
mov edx, 10
mov ecx, num2
mov ebx, 0 
mov eax, 3
int 0x80

; conversion chracter to string
  mov eax,[num1]
  sub eax,'0' 
  mov ebx,[num2]
  sub ebx,'0'


  add eax,ebx
  add eax,'0' 
  
  mov [res],eax 

; prints the result
mov edx, 1
mov ecx, res
mov ebx, 1
mov eax, 4
int 0x80

mov ebx,0
mov eax, 1
int 0x80

