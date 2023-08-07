

maior_igual_5(X) :-
X >= 5, write('maior igual a 5').

maior_igual_5(X) :- 
X < 5, write('menor que 5').

/*
Fazendo um loop, deve-se usar recursão. Conta de trás para frente conta da recursão.
*/
loop(N) :- N>0,
write('value of N is: '), write(N), nl, S is N-1, loop(S).

/*
Outra maneira de fazer um for)
*/
count(N,N) :- write(N), nl. % para quando N == N

count(Counter, N) :-
Counter < N,
write(Counter), nl,
NextCounter is Counter + 1,
count(NextCounter, N).
