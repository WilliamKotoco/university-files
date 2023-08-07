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

