section .data
  
  WRITE_SYSCALL db 4
  READ_SYSCALL db 3
  SAIDA_SYSCALL db 1

  number db 5                         ;define 5 como o comparador da memoria
  input1 db "Insira o numero: ", 0      ; mensagem 1
  len_input_1 equ $ - input1            ; tamanho da mensagem 1
  saida db "O maior numero eh: ", 0     ; mensagem 2
  len_saida equ $ - saida               ; tamanaho da mensagem 2
  iguais db "Os numeros sao iguais", 0  ; mensagem 3
  len_iguais equ $ - iguais             ; tamanho da mensagem 3


; deixa espaco para o numero que vai ser digitado pelo usuario 
section .bss
    num resb 1   ; reservando 1 byte para a variavel num
    menor resb 1 

; começa o código
section .text
global _start
_start: 
  mov eax, WRITE_SYSCALL         
  mov ebx, 1          
  mov ecx, input1     
  mov edx, len_input_1
  int 0x80
  
  jmp read_number

; le o numero 
read_number:
  mov edx, 1
  mov ecx, num 
  mov ebx, 0
  mov eax, READ_SYSCALL
  int 0x80
  jmp compare

; move os numeros para os registradores e compara eles
compare:
  mov eax, [number] 
  mov ebx, [num]
  cmp eax, ebx

  je numeros_iguais   ;JE  jump if equal
  jg numero1_maior
  jb numero1_menor     ; jb jump if less
  

numero1_maior: 
  mov [menor], ebx
  jmp print1

numero1_menor:
  mov [menor], eax
  jmp print1
  
numeros_iguais:
  mov eax, WRITE_SYSCALL
  mov ebx, 1 
  mov ecx, iguais
  mov edx, len_iguais
  int 0x80 
  jmp end

; mostra a mensagem e chama para mostrar o numero menor 
print1:
  mov eax, WRITE_SYSCALL
  mov ebx, 1 
  mov ecx, input1 
  mov edx, len_input_1
  int 0x80
  jmp print_number



print_number:
  mov eax, WRITE_SYSCALL
  mov ebx, 1 
  mov ecx, menor
  mov edx, 1
  int 0x80
  jmp end
  
; termina o programa
end:
  mov eax, SAIDA_SYSCALL
  xor ebx, ebx
  int 0x80
