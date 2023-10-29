import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import statistics as stat
from scipy.stats import norm
iq1 = 39 - 27
whislo1 =  27 - 1.5*(iq1)
whishi1 =  39 + 1.5*(iq1)

iq2 = 42 - 23
whislo2 = 23 - 1.5 * iq2 
whishi2 = 42 + 1.5  * iq2
stats = [
    {'med': 33, 'q1': 27,  'q3': 39, 'whislo': whislo1, 'whishi': whishi1 },
    {'med': 32, 'q1': 23, 'q3': 42, 'whislo':whislo2, 'whishi': whishi2},
]

_ , ax = plt.subplots()
ax.bxp(stats, showfliers=False)
plt.show()


x1 = np.linspace(18, 48, 1000)
y1 = norm.pdf(x1, 33, 5)
plt.subplot(1, 2, 1)
plt.plot(x1, y1)

plt.subplot(1,2,2)
y2 = norm.pdf(x1, 32, 10)
plt.plot(x1,y2)

plt.show()
