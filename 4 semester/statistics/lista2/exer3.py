
import matplotlib.pyplot as plt
import numpy as np
import pprint
import statistics 
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


turma_a = [
    13.58, 16.18, 16.39, 16.78, 17.32,
    15.59, 16.19, 16.39, 16.79,27.51,
    15.65, 16.21, 16.41, 16.84,
    15.66, 16.28, 16.43, 16.85,
    16.02, 16.29, 16.43, 16.86,
    16.02, 16.30, 16.45, 16.89,
    16.03, 16.31, 16.46, 16.94,
    16.05, 16.36, 16.53, 16.97,
    16.06, 16.37, 16.59, 17.04,
    16.09, 16.37, 16.63, 17.06,
    16.11, 16.37, 16.70, 17.18,
    16.14, 16.38, 16.77, 17.26
]


data = get_data(turma_a)
pprint.pprint(data)

bins = np.arange(12, 30, 0.5)
plt.hist(turma_a, bins = bins, edgecolor='green', alpha=0.9)
plt.title("Desemepnho da turma A em relação ao tempo de execução")
plt.xlabel("Tempo de execução do algoritmo ")
plt.ylabel("Frequência")
plt.show()

## Ambos os gráficos são simétricos quando se remove o outilier de 27 segundos do dado B
