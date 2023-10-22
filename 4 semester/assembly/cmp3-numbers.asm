section .data
  num1 dd '5'
  num2 dd '7'
  num3 dd '2'
  input1 dw "O maior numero eh ", 0
  len_input1 equ $ - input1


section .bss
  maior resd 1
section .text
global _start

_start:
  mov eax, [num1]
  mov ebx, [num2]

  cmp eax, ebx 
   jg num1_maior
   jb num2_maior


num1_maior:
  mov [maior], eax
  jmp segunda_comparacao

num2_maior:
  mov [maior], ebx
  jmp segunda_comparacao

segunda_comparacao:
  mov eax, [maior]
  mov ebx, [num3]

  cmp eax, ebx
  jg num1_maior_todos
  jb num2_maior_todos

num1_maior_todos:
  jmp print
num2_maior_todos:
  mov [maior], ebx
  jmp print

print:
mov eax,4
mov ebx, 1 
mov ecx, input1
mov edx, len_input1
int 0x80
jmp print_number


print_number:
mov eax,4
mov ebx, 1 
mov ecx, maior
mov edx, 1 
int 0x80
jmp end


end:
mov eax, 1 
xor ebx, ebx 
int 0x80
