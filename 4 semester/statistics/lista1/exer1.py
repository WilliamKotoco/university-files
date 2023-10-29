import pandas as pd
import matplotlib.pyplot as plt
import statistics
import tabulate
import pprint


def get_data(data):
    mean = statistics.mean(data)
    median = statistics.median(data)
    mode = statistics.mode(data)
    variance = statistics.variance(data)
    stdev = statistics.stdev(data)
    quants = statistics.quantiles(data)
    maximum = max(data)
    minimum = min(data)
    amplitude = maximum - minimum
    cv = (stdev / mean) * 100
    values = {
        'Média': mean,
        'Mediana': median,
        'Moda': mode,
        'Variância': variance,
        'Desvio padrão': stdev,
        '1Q': quants[0],
        '3Q': quants[2],
        'Mínimo': minimum,
        'Máximo': maximum,
        'Amplitude': amplitude,
        'CV': cv,
    }
    return values


data = {
    'L1': [17, 16, 21, 14, 18, 24, 16, 14, 21, 23, 13, 18],
    'L2': [18, 14, 19, 11, 23, 21, 10, 13, 19, 24, 15, 20]
}

dataframe = pd.DataFrame(data)

print(dataframe)

valuesL1 = get_data(dataframe['L1'])
valuesL2 = get_data(dataframe['L2'])

pprint.pprint(valuesL1)
pprint.pprint(valuesL2)

colors = ['blue', 'green']

data_lenght = [dataframe['L1'], dataframe['L2']]

bplots = plt.boxplot(data_lenght, vert=1)
c = 0

for i, bplot in enumerate(bplots['boxes']):
    bplot.set(color=colors[c], linewidth=5)
    c += 1

pessoas = ['L1', 'L2']
plt.xticks([1, 2], pessoas)
plt.title('cu')
plt.ylabel('acertos')
plt.show()

plt.hist(dataframe['L1'])
plt.show()
plt.hist(dataframe['L2'])
plt.show()
