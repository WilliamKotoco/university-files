section .data
    numero1 dd '3'
  numero2 dd '4'
  mensagem1 db 'O maior numero eh: ',0
  mensagem2 db 'Os dois numeros sao iguais ', 0

  segment .bss
    maior_numero resb 1 

  section .text
  global _start
  _start:
    mov eax,[numero1]
    mov ebx, [numero2]
    cmp eax, ebx ; instruction to compare two registers

    je numeros_iguais; je means Jump if equal
    jg numero1_maior ; jg means jump if greater
    jb numero2_maior ; jb means jump if less


; section to handle number 2 is greater 
    numero2_maior:
      mov [maior_numero], ebx
      jmp print

    numero1_maior:
      mov [maior_numero], eax
      jmp print ; interrupts the function in this point and goes to another the given section 

    numeros_iguais:
      mov eax, 4
      mov ebx, 1 
      mov ecx, mensagem2
      mov edx, 29 ; 29 is the mensagem2 length
      int 0x80
      jmp end

    print:
      mov eax,4
      mov ebx, 1 
      mov ecx, mensagem1
      mov edx, 20 ; 20 is mensagem1 length
  int 0x80
      jmp print2


    print2:
  mov eax,4
      mov ebx,1 
      mov ecx, maior_numero
      mov edx, 2 
      int 0x80
      jmp end
    ; section to end the program
    end:
      mov eax, 1 
      xor ebx, ebx 
  int 0x80
