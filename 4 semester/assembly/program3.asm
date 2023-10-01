; reads an string and shows it on screen 
section .data
  mensagem1 db "Digite algo: ", 0 ; 0 also works for breakline
  len1 equ $ - mensagem1
  mensagem2 db "Voce digitou: ", 0
  len2 equ $ - mensagem2

section .bss
  entrada resb 255 ; RESERVE 255 bytes.


section .text
global _start]
_start:
  mov eax,4
  mov ebx,1
  mov ecx, mensagem1
  mov edx, len1
  int 0x80

  mov eax, 3
  mov ebx, 0
  mov ecx, entrada
  mov edx, 255
  int 0x80

  mov eax,4
  mov ebx,1 
  mov ecx, mensagem2
  mov edx, len2
  int 0x80

  mov eax,4
  mov ebx, 1
  mov ecx, entrada
  mov edx, 255
  int 0x80


  ;end
  mov eax, 1 
  mov ebx, 0
  int 0x80




