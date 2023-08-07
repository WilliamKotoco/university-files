/*
Dupla: Ana Zerati e William
*/

ultimo(X, [X]). % é o ultimo da lista se a lista só tiver o elemento (condicao saida)

ultimo(X, [H|T]) :- ultimo(X, T). % quebra a lista nas caudas e chama a regra 1 novamente


penultimo(Y, [Y,X]).

penultimo(X, [H|T]) :- penultimo(X, T).