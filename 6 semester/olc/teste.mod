var var1 ;
var var2;

maximize fun: var1 + 2*var2 ;

subject to c1: -3*var1 + var2 <= 2;
subject to c2: var2 <= 3;
subject to c3: var1 + 2*var2 <= 9;
subject to c4: 3*var1 + var2 <= 18;
subject to c5: var1 >= 0;
subject to c6: var2 >= 0;

option solver cplex;
solve;

display fun, var1,var2;


