lista1 = [a,b,c].
lista2 = [a,c,b].

ListaAninhada = [cozinha , [mesa, cadeira], sala, [sofa, estante]]. %lista dentro de lista

/*
head e tail da lista podem ser separadas da seguinte maneira
?- [H | T] = [a,b,c ].
H = a
T = [b,c]
*/

/*
Buscas, functor
Se ele for a cabeça da lista, já acaba a recursão. Se não for, entra na segunda
regra que diz que ele pertence somente se for a cabeça da cauda.

A partir daí surge uma recursão, em que ele vai quebrando em cabeças e caudas até que
a lista fique vazia ou ele encontre (passe na condição inicial)
*/
pertence(X, [X  |T]).   % x pertence a lista quando ele é head da lista
pertence(X, [H|T]) :- pertence(X,T). % usa recursao, dividindo e analisando a cabeça da cauda toda hora


/*
Função recursiva para determinar o prefixo e de uma lista
ex: [a,b] é prefixo de [a,b,c]
*/
prefixo([], Ys).
/* Essa regra é sempre cumprida se for um prefixo, visto
que o header são iguais.

Vai chamando e comparando os headers até chegar num ponto em que os headers
são iguais e a tail é uma lista vazia, de forma que chega-se na 
condião de parada*/

prefixo([X|Xs], [X|Ys]) :- prefixo(Xs,Ys). 




sufixo(Xs, Xs).  % duas listas iguais
sufixo(Xs, [Y|Ys]) :- sufixo(Xs, Ys).

/*
Para verificar se um elemento faz parte de uma sublista:

Ou seja, só é verdadeiro se houver uma lista que tenha prefixos de Ys e sufixos e Xs
*/
sublist(Xs,Ys) :- prefixo(Ps, Ys) , sufixo(Xs, Ps). 
/*
Função recursiva para verificar se um elemento é o último da lista
*/

ultimo(X, [X]). % é o ultimo da lista se a lista só tiver o elemento (condicao saida)

ultimo(X, [H|T]) :- ultimo(X, T). % quebra a lista nas caudas e chama a regra 1 novamente