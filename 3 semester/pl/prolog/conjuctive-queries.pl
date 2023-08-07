/*
Usa-se para fazer uma busca com mais de duas propriedades na consulta.
*/
parent(joao, lucio).
parent(maria, lucio).
male(joao). %poderia fazer uma regra para verificar se é homem.

% exemplo de querry: parent(x, lucio) , male(X).
