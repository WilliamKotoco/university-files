/*
Dupla: Ana Zerati e William
*/
progenitor(pamela, bob).
progenitor(pamela, sam).
progenitor(tom, bob).
progenitor(tom, sam).
progenitor(tom, liz).
progenitor(bob, ana).
progenitor(bob, patricia).
progenitor(patricia, jim).

male(bob).
male(sam).
male(jim).
male(tom).

female(pamela).
female(liz).
female(ana).
female(patricia).


pai(X, Y) :- progenitor(X,Y), male(X).
mae(X, Y) :- progenitor(X,Y), female(X).


avo(X,Y) :- progenitor(X,Z) , progenitor(Z,Y).
netas(X, Y) :- avo(Y,X) , female(X).

irmaos(X,Y) :- progenitor(Z, X) , progenitor(Z, Y), X \= Y.  % x \= y assures that x isnt y


ancestral(X,Z) :- progenitor(X, Z).   % regra(1)
ancestral(X,Z) :- progenitor(X,Y),  ancestral(Y,Z).  % regra(2)


ancestralFeminino(X,Z) :- mae(X,Z).   % regra(1)
ancestralFeminino(X,Z) :- progenitor(X,Y), female(X),  ancestral(Y,Z).  % regra(2)


ancestralMasculino(X,Z) :- pai(X, Z).   % regra(1)
ancestralMasculino(X,Z) :- progenitor(X,Y),  male(X), ancestral(Y,Z).  % regra(2)