import statistics 

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

def filtrate(volume):
    mean = statistics.mean(volume)
    stdev = statistics.stdev(volume)
    filtrate_data = []
    for item in volume:
        new_item = (item - mean)/stdev
        filtrate_data.append(new_item)
    return filtrate_data
    
volume = [753, 751, 752, 753, 753, 752, 753, 754, 754, 752,
753, 751, 752, 750, 753, 755, 753, 756, 751, 750]


data = get_data(volume)

plt.hist(volume, edgecolor='green', alpha=0.9)
plt.title("Volume de vinho ")
plt.xlabel("Volume preenchido")
plt.ylabel("Frequência")
plt.show()
pprint.pprint(data)

filtrate_data = filtrate(volume)
data = get_data(filtrate_data)
print("Dados sobre os dados normalizados: ")
print()
pprint.pprint(data)

# Podemos dizer que é uma distribução normal. O histograma parece-se ligeriamente simétrico, a média é bem próxima da mediana e os dados normalizados estão entre -3 e 3 
    
