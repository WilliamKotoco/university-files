import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import statistics as stat

data = {
    'Turno1': [
        9, 12, 6, 9, 7, 14, 12, 4, 6, 7, 8, 5, 9, 7, 8, 11, 3, 6, 7, 7, 11, 4,
        4, 8, 7, 5, 6, 4, 5, 8, 19, 9, 18, 12, 11, 17, 15, 17, 13, 13
    ],
    'Turno2': [
        0, 5, 9, 8, 10, 11, 10, 7, 7, 13, 11, 8, 6, 4, 2, 15, 13, 8, 8, 7, 5,
        11, 9, 7, 9, 21, 3, 6, 8, 7, 18, 10, 4, 8, 7, 5, 6, 4, 15, 8
    ],
}

data_frame = pd.DataFrame(data)

intervalo_ideal_de_classes = 1 + 3.3 * np.log10(len(data_frame['Turno1']))

# print(intervalo_ideal_de_classes)

bplots = plt.boxplot(data_frame, vert=1)

turnos = ['Turno1', 'Turno2']
plt.xticks([1, 2], turnos)
plt.xlabel('Turnos')
plt.ylabel('Numero de molas com defeitos ')

plt.show()

print("Existem outliners no turno 2, são os de valores 18 e 21")

# construindo os histogramas com intervalos 5
intervals = np.linspace(
    min(min(data_frame['Turno1']), min(data_frame['Turno2'])),
    max(max(data_frame['Turno1']), max(data_frame['Turno2'])), 6)

plt.figure(figsize=(12, 5))
plt.subplot(1, 2, 1)
plt.hist(data_frame['Turno1'], bins=intervals, edgecolor='red', alpha=0.9)
plt.title("Histograma turno 1")
plt.xlabel("Molas com defeito")
plt.ylabel("Frequência ")
plt.ylim(0, max(intervals))
plt.subplot(1, 2, 2)
plt.hist(data_frame['Turno2'], bins=intervals, edgecolor='red', alpha=0.9)
plt.title("Histograma turno 2")
plt.xlabel("Molas com defeitos")
plt.ylabel("Frequência")
plt.ylim(0, max(intervals))
plt.tight_layout()
plt.show()


quantilesT1 = stat.quantiles(data_frame['Turno1'])
print("Dados em relação aos quantis do turno 1: ")
print(" Primeiro quantil: ", quantilesT1[0])
print(" Segundo quantil (mediana): ", quantilesT1[1])
print(" Terciro quantil: ", quantilesT1[2])
print("IQ: ", quantilesT1[2] - quantilesT1[0])


quantilesT2 = stat.quantiles(data_frame['Turno2'])
print("Dados em relação aos quantis do turno 2: ")
print(" Primeiro quantil: ", quantilesT2[0])
print("Segundo quantil (mediana): ", quantilesT2[1])
print("n Terciro quantil: ", quantilesT2[2])
print("\IQ: ", quantilesT2[2] - quantilesT2[0])

print("O cálculo dos quantis permite concluir sobre a dispersão dos dados e sobre sua concentração")

print(data_frame.describe())

print("Soma dos valores do turno 1: ",data_frame['Turno1'].to_numpy().sum())
print("Soma dos valores do turno 2: ",data_frame['Turno2'].to_numpy().sum())

print("Coeficiente de variação turno 1 :", (stat.stdev(data_frame['Turno1']) / stat.mean(data_frame['Turno1'])) * 100)
print("Coeficiente de variação turno 2 :", (stat.stdev(data_frame['Turno2']) / stat.mean(data_frame['Turno2'])) * 100)

print("Em conclusão: o  turno 1 é um pouco mais estável que o turno 2, mas ambos foram instáveis de maneira preocupante \n Além disso, o turno 1 teve 30 quebras a mais que no turno 2".)