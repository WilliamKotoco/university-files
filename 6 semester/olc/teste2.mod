# Declare variables
var v1 >= 0;
var v2 >= 0;

# Objective function
maximize fun: 2 * v1 + 5 * v2;

# Constraints
s.t. c1: v1 + 2 * v2 <= 16;
s.t. c2: 2 * v1 + v2 <= 12;

solve;

# Output the current optimal solution
printf "fun = %f, v1 = %f, v2 = %f\n", fun, v1, v2;
