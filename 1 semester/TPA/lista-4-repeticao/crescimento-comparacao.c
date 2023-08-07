#include<stdio.h>
#include<stdlib.h>
int main(){
int altura_feliz = 110, altura_ana = 150, ano;

do {
	altura_feliz = altura_feliz + 3;
	altura_ana = altura_ana + 2;
	ano++;
} while(altura_ana > altura_feliz);
printf("foram precisos %d anos para que a altura de felizberto passe de anacleto", ano);
return 0;	
}
