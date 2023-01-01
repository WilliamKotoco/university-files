#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct queue
{
	int id, time, weight;
	struct queue *next;
};

struct aux
{
	int id, time;
};
void add(struct queue **header, int id, int time, int weight);
void removelist(struct queue **header);

int main()
{

	int num_elems, num_OS, *attending;
	// attending guarda o tempo de "ocupação" dos atendentes
	int id, time, weight, i;
	struct queue *header = NULL;
	struct aux auxiliar;
	/*
	Essa struct auxiliar guarda informações sobre o próximo atendente, ou seja, o que estiver menos 
	ocupado(menos ocupado = o que vai ficar ocioso mais rapido)
	*/
	scanf("%d %d", &num_elems, &num_OS);
	attending = calloc(num_OS, sizeof(int));
	/*
	Calloc aloca ja zerando os elementos. Assim, o vetor do tempo de "ocupação" dos atendentes
	vão estar com tudo zero inicialmente
	*/
	for (i = 0; i < num_elems; i++)
	{
		scanf("%d %d %d", &id, &time, &weight);
		add(&header, id, time, weight);
	}
	while (header != NULL) // em outras palavras: enquanto todos não forem atendidos
	{
		auxiliar.time = INT_MAX; //valor maximo do inteiro, para aleardo nao sacanear nos casos teste
		for (i = 0; i < num_OS; i++)
		{
			if (attending[i] < auxiliar.time)
			{
				/*
				Se há algum atendente com o tempo de ocupacao menor que o atendente auxiilar, que é o
				atendente que tem o menor tempo de ocupacao...
				*/
				auxiliar.time = attending[i];
				auxiliar.id = i;
			}
			// com isso, o auxiliar vai guardar sempre o antendente que vai terminar o trabalho mais rapido
		}
		if (auxiliar.time < header->time)
		{
			attending[auxiliar.id] = header->time;
			// o tempo ocupado muda no instante que o cliente chega, somamos com o tempo de atender e depois removemos o cliente
		}
		attending[auxiliar.id] = attending[auxiliar.id] + header->weight;

		removelist(&header);
	
}
for (i = 0; i < num_OS; i++)
{

	/*
	 Como não vai ter mais processo na lista, o o vetor attending guarda o tempo q cada atendente vai ficar ocupado, no final
	 ele vai ficar com o ultimo instnate que atendeu
	*/
	printf("%d ", attending[i]);
}

return 0;
}

void add(struct queue **header, int id, int time, int weight)
{
	struct queue *aux, *prev, *element;
	element = malloc(sizeof(struct queue));
	element->id = id;
	element->time = time;
	element->weight = weight;

	if ((*header) == NULL)
	{
		element->next = NULL;
		(*header) = element;
		return;
	}
	if (time < (*header)->time || (time == (*header)->time && id < (*header)->id))
	{
		element->next = (*header);
		(*header) = element;
		return;
	}
	aux = prev = (*header);
	while (aux != NULL)
	{
		/*
		Anda pela lista toda e sai da funcao quando achar o lugar pra inserir. Se não achar o lugar para 
		inserir, vai sair do while e colocar no final
		*/

		if (time < aux->time || (time == aux->time && id < aux->id))
		{
			prev->next = element;
			element->next = aux;
			return;
		}
		prev = aux;
		aux = aux->next;
	}
	// ja percorreu todo e nao achou, entao vai pro final
	prev->next = element;
	element->next = NULL;
	return;
}
void removelist(struct queue **header)
{
	struct queue *aux = (*header);
	(*header) = (*header)->next;
	free(aux);
}