# Declare variables
var ana;
var bibi;

# Objective function
maximize funct: -1 * ana + 2* bibi;

# Constraints
s.t. c1: 3 * ana + 4 * bibi <= 12;
s.t. c2: 2 * ana - bibi <= 12;
option solver cplex;

solve;

# Output the current optimal solution
printf "funct = %f, ana = %f, var2 = %f\n", funct, ana, bibi;
