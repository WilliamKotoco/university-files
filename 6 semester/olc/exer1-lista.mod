var v1;
var v2;

maximize fun: 2* v1 + 5* v2;
subject to c1: v1 + 2 *v2 <= 16;
subject to c2: 2* v1 + v2 <= 12;
subject to c3: v1 >= 0;
subject to c4: v2 >= 0;

option solver cplex;

solve;

display fun, v1, v2;
