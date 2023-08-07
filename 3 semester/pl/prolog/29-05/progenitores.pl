progenitor(sara, isaque).
progenitor(abraao, isaque).
progenitor(abraao, ismael).
progenitor(isaque, esau).
progenitor(isaque, jaco).
progenitor(jaco, jose).



% usamos o _ para sabermos se existe solucao. Exemplo: progenitor(isaque, _).

% para descobrir os avos de abraao progenitor(abraao, X) , progenitor(X,Y)    vai retornar os X e Y que fazem isso ser true


% criando uma regra:
filho(Y,X) :- progenitor(X,Y). 
avo(X,Y) :- progenitor(X,Z) , progenitor(Z,Y).

% definindo uma regra para trabalhar recursivamente, ver os ancestrais de uma determinada pessoa.
ancestral(X,Z) :- progenitor(X, Z).   % regra(1)
ancestral(X,Z) :- progenitor(X,Y),  ancestral(Y,Z).  % regra(2)

% resumindo: x é um ancestral de z se x for progenitor de z e x for pai de Y
/*
a regra 1 recupera o pai e a regra 2 é responsável pela recursão
*/

% essa regra verifica se tem filho, sem se importar com quem é o filho.. Utiliza o conceito de variável anonima.
tem_filho(X) :- progenitor(X, _).
