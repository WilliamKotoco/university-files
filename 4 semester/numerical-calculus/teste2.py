import numpy as np
x =[ 1872, 1890, 1900, 1920, 1940, 1950, 1960, 1970, 1980, 1990, 2000, 2010]
y = [9.9, 14.3, 17.4, 30.6, 41.2, 51.9, 70.2, 93.1, 119.0, 146.2, 169.7, 190.5]
ln = []
for i in range(0, len(y)):
    ln.append(np.log(y[i]))


def f(x):
    return 6.093 * pow(10,-18) * np.exp(0.022389 * x)


for xi in x:
    print(f(xi))
