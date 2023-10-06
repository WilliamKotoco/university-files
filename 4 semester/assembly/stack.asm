section .bss
  num resb 1


section .text
global _start

_start:
  mov rcx, 9
  mov rax, '1'

  loop1:
    mov [num], rax ; stores eax in num. Eax holds the inc of the number printed in the last iteration 
    mov rax, 4
    mov rbx, 1 
    
    push rcx ; add ecx on the top and increments it
    
    mov rcx, num ; move the num into ecx. 
    mov rdx, 1 
    int 0x80

    mov rax, [num]
    sub rax, '0' ;converts to decimal 

    inc rax ; increments eax register by 1
    add rax, '0'

    pop rcx ; remove the ecx and dcerem

    loop loop1 ; the loop is equivalent to do{}while(--ecx != 0) 

    mov rax, 1  
    int 0x80 
