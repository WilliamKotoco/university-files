#include "../include/ui.h"
#include <string.h>

extern int g_total_elements;
extern struct movie_index_id *index_id;
extern struct movie_index_name  *index_name;

void options() {


    int choice;

    while (1) {
        printf("\n \n \n Menu:\n");
        printf("1. Inserir novo filme\n");
        printf("2. Buscar  filme\n");
        printf("3. Remover filme\n");
        printf("4. Editar nota de filme\n");
        printf("5. Listar todos os filmes \n");
        printf("6. Comprimir arquivo \n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ui_insertion();
                break;

            case 2:
                printf("Opção 2 selecionada: Buscar  filme\n");
                ui_search();
                break;

            case 3:
                printf("Opção 3 selecionada: Remover filme\n");
                ui_remove();
                break;

            case 4:
                printf("Opção 4 selecionada: Editar filme\n");
                ui_update();
                break;

            case 5:
                printf("Opção 5 selecionada: Listar todos cadastrados\n");
                for (int i = 0; i < g_total_elements; i++) {
                    search_by_id( index_id[i].id);

                }
                break;

            case 6:
                printf("Opção 6 selecionada: comprimir arquivo (isso ocasionará no fechamento do programa) \n");
                file_compreesion();
                return;
            case 7:
                printf("Opção 7 selecionada: Sair\n");
                write_index_id_file(index_id);
                write_index_name_file(index_name);
                return;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void ui_insertion() {
    struct movie data;
    uint flag = 0;
    while (!flag) {
        // getchar();
        puts("Digite o nome original: ");
        scanf(" %[^\n]s", data.name);
        //  getchar();
        puts("Digite o nome em português: ");
        scanf(" %[^\n]s", data.translated_name);
        // getchar();
        puts("Digite o nome completo do diretor formato(nome + primeiro sobrenome):  ");
        scanf(" %[^\n]s", data.director);
        // getchar();
        puts("Digite o país de origem: ");
        scanf(" %[^\n]s", data.country);
        //getchar();
        puts("Digite o ano de lançamento: ");
        scanf(" %[^\n]s", data.year);
        // getchar();
        puts("Digite uma nota de 0 a 9: ");
        scanf(" %c", &data.mark);
        //    getchar();
        flag = insertion_data_processing(data);
        if (flag == 0)
            puts("Coloque os dados da maneira correta.");
        if (flag == 1)
            break;
    }
}

void ui_search() {
    uint op;
    printf("Digite [1] para buscar por id ou [2] para buscar por nome");
    scanf("%u", &op);
    if (op == 1) {
        char id[6];
        printf("\n Digite o id: ");
        scanf("%s", id);
        search_by_id(id);
    }

    if (op == 2) {
        char name[NAME_SIZE];
        printf("\n Digite o nome: ");
        scanf(" %[^\n]s", name);
        search_by_name( name);
    } else
        puts("Opção inválida.");

}

void ui_remove() {
    char id[6];
    puts("Digite o ID do filme para remover: ");
    scanf("%s", id);
    remove_caller(id);


}

void ui_update() {
    char id[6], new_mark;
    int mark_int;
    puts("Digite o ID do filme: ");
    scanf("%s", id);

    puts("Digite a nova nota do filme(entre 0 e 9): ");
    scanf(" %c", &new_mark);

    mark_int = new_mark - '0';
    if (mark_int > 9) {
        puts("Nota inválida !");
        return;
    }

    update_call( id, new_mark);


}
