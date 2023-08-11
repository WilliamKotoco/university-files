#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_STUDENTS 1

bool busca_aluno(unsigned int key, FILE *fp);
int main()
{

    /// w+ indicate it's both reading and writing
    // FILE *fp = fopen("students.dat", "a");

    //  for (int i = 0; i < NUMBER_STUDENTS; i++)
    // {
    //     char name[100];
    //     char major[100];
    //     char year[4];
    //     char email[200];
    //     unsigned int index;

    //     scanf(" %[^\n]s", name);
    //     scanf(" %[^\n]s", major);
    //     scanf(" %[^\n]s", year);
    //     scanf(" %[^\n]s", email);
    //     scanf(" %u", &index);

    //     /// organize in a way the first field is the number and the second is the name, so it's easier to 
    //     /// retrieve the information needed.
    //     fprintf(fp, "%u %s %s %s %s \n", index, name, major, year, email);
    // }
    
    // fflush(fp); /// flush the buffer to update the file
    // fclose(fp);

    FILE *fp = fopen("students.txt", "r");
    unsigned int key;
    printf("\n Digite a chave para buscar o aluno");
    scanf("%u", &key);
    bool flag = busca_aluno(key, fp);
    
    if(!flag)
        printf("aluno não encontrado");
    return 0;
}

bool busca_aluno(unsigned int key, FILE *fp)
{
     int current_key;
    char name[200];
 
    // while the file is reading
    while(fscanf(fp, "%s", name) == 1)
    {
        fscanf(fp, "%d", &current_key);
        if(current_key == key)
        {
            printf("achou %s \n", name);
            return true;
        }

    }
    return false;
}


