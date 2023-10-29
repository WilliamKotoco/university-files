import statistics 
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
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
    ca = 3*(mean - median)/ stdev
    values = {
        'Média': mean,
        'Mediana': median,
        'Moda': mode,
        'Variância': variance,
        'Desvio padrão': stdev,
        '1Q': quants[0],
        '3Q': quants[2],
        'IQ': quants[2] - quants[0],
        'Mínimo': minimum,
        'Máximo': maximum,
        'Amplitude': amplitude,
        'CV': cv,
        'Coeficiente Assimetria': ca
    }
    return values

machineA = [
    88.24, 87.58, 87.99, 87.89, 88.04,
    88.14, 88.10, 88.07, 87.83, 87.77,
    87.85, 88.19, 88.39, 87.90, 87.69,
    88.18, 87.96, 87.96, 87.93, 88.26,
    87.72, 87.59, 88.09, 88.30, 88.12,
    88.22, 87.82, 88.01, 88.03, 88.09
]

machineB = [
    87.8, 88.18, 88.13, 87.92, 88.22, 88.06, 88.15, 88.28, 88.08, 88.04, 88.3,
    88.14, 88.14, 87.7, 88.25, 88.3, 88.09, 87.91, 88.03, 88.14, 88.18, 87.98,
    87.79, 87.63, 87.82, 87.95, 88.04, 88.14, 88.19, 87.9
]

machineA = np.array(machineA)
machineB = np.array(machineB)
print(len(machineA))

data = {'MachineA': machineA, 'MachineB': machineB}

df = pd.DataFrame(data)

printA = df['MachineA'].value_counts()
print(printA)
printB = df['MachineB'].value_counts()
print(printB)



data_A = get_data(machineA)
data_B = get_data(machineB)

pprint.pprint(data_A)
print("")
pprint.pprint(data_B)


plt.subplot(1,2,1)
plt.hist(machineA, edgecolor='green', alpha=0.9)
plt.title("Peças da máquina A")
plt.xlabel("Diâmetros das peças manufaturadas")
plt.ylabel("Frequência")

plt.subplot(1,2,2)
plt.hist(machineB, edgecolor='green', alpha=0.9)
plt.title("Peças da máquina B")
plt.xlabel("Diâmetros das peças manufaturadas")
plt.ylabel("Frequência")
plt.tight_layout()
plt.show()

data_A = get_data(machineA)
data_B = get_data(machineB)

print(data_A['Coeficiente Assimetria'])
print(data_B['Coeficiente Assimetria'])

# histograma A é mais instável (tem o coeficiente de variação e o IQ maiores), mas o histograma B é mais assimétrico à esquerda(ou seja, os valores estao concentrados
# maiores que a mediana)

colors = ['blue', 'green']
data_length = [machineA, machineB]

bplots = plt.boxplot(data_length, vert=1)
c = 0

for i, bplot in enumerate(bplots['boxes']):
    bplot.set(color=colors[c], linewidth=5)
    c += 1

maquinas = ['Maquina1', 'Maquina2']
plt.xticks([1,2], maquinas)
plt.title("Boxplot do diâmetro das peças manufaturadas")
plt.ylabel("cu")
plt.show()

## O boxplot confirma através da mediana estar um pouco acima do centro, que a máquina B é ligeiramente assimétrica à esquerda. COnfirma também que a máquina 1 tem mais variação dos dados
# pelo fato da caixa ser maior.z