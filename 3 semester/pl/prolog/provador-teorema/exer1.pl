/**
Enunciado:3

1 - p
2 - (p ^ q) -> r
3 - (s v t ) --> q
4- t
**/


/**
Respostas
1-  certo
2 - ~(p^q) v r == (~p v ~q) v r

3- ~(s v t) v q == (~s ^~t) v q == (~s v q) ^ (~t v q)

4- certo
**/

/**
Cortando:
1 - p ^ (~p v ~q) v r == ~q v r (corta os p)

2 - ~q v r ^ (~s ^ ~t) v q == r ^ ~s ^~t (corta os q)

3 - r ^ ~s ^ ~t ^ t == r ^ ~s 

no fim fica r ^ ~s
*/

ama(bibi, amor).
not( ama(bibi,amor) , odeia(bibi,amor)).
coquinha(amor, bibi)

/*
Exercício: provar que R é verdadeiro
Abordagem: prova por contradição. Adicionar ~r na base de fatos.
Agora a base é:
1-  p
2- (~p v ~q) v r
3- (~s v q) ^ (~t v q) (3.1 e 3.2)
4- t
5- ~r

Combinando 5 com 2: ~p v ~q
Combinando com 3.2: ~p v ~t
Combinando com 4: ~p
Combinando com 1: p


*/
