speed(ford, 100).
speed(chevy, 100).
speed(dodge, 95).
time(ford, 20).
time(chevy, 21).
time(dodge, 24).

distance(X,Y) :- speed(X, Speed), time(X, Time), Y is Speed * Time.
