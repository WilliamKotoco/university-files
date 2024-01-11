import math
x = [-8,-6,-4,-2,0,2,4]
y = [30,10,9,6,4,5,4]

sum = 0
#for i in range(0, len(x)):
#   sum += 1/(x[i])*y[i] 
#print(sum)

def f(x):
    return 6.357142857* pow(-1.678571429,x)

for xi in x:
    print(f(xi))
