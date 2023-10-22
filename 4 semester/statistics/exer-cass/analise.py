from os import read
import statistics
import pandas as pd
import matplotlib.pyplot as plt


def read_tsv(file_path):
    data = pd.read_csv(file_path, delimiter='\t')
    return data


def filtrate_data(data):
    filtered_data = data.loc[(data['VALOR DA CASA'] <= 350000)
                             & (data['NÚMERO DE QUARTOS'].isin(['>=4', '3']))]

    preferable_data = filtered_data.loc[
        (filtered_data['NÚMERO DE BANHEIROS'] > 2)
        & (filtered_data['TEM EDÍCULA?'] == 'Sim')]

    return filtered_data, preferable_data


def calculate_info(data, lugar):
    filtered_data, preferable_data = filtrate_data(data)
    print(
        "Resumo dos dados das casas na região {} que satisfazem os requisitos mínimos:"
        .format(lugar))
    print_data(filtered_data)
    print(
        "Resumo dos dados das casas na região {} que satisfazem todos os requisitos:"
        .format(lugar))
    print_data(preferable_data)


def print_data(data):
    if data.empty:
        print("Não há nenhuma informação assim: ")
        return
    link = data.loc[data['VALOR DA CASA'] == min(data['VALOR DA CASA']),
                    'LINK DA CASA'].values[0]
    data = data['VALOR DA CASA']
    mean = statistics.mean(data)
    median = statistics.median(data)
    mode = statistics.mode(data)
    variance = statistics.variance(data)
    stdev = statistics.stdev(data)
    quants = statistics.quantiles(data)
    maximum = max(data)
    minimum = min(data)
    amplitude = maximum - minimum

    cv = (variance / mean) * 100
    print(f"Média: {mean}")
    print(f"Mediana: {median}")
    print(f"Moda: {mode}")
    print(f"Variância: {variance}")
    print(f"Desvio Padrão: {stdev}")
    print(f"Coeficiente de variância: {cv}")
    print(f"primeiro quantil: {quants[0]}")
    print(f"terceiro quantil: {quants[2]}")
    print(f" IQ: {quants[0] - quants[2]}")
    print("Máximo: ", maximum)
    print("Mínimo: ", minimum)
    print(f"amplitude: {amplitude}")
    print("Link da casa: ", link)


central_file_path = 'central.tsv'
north_file_path = 'norte.tsv'
south_file_path = 'sul.tsv'
base_file_path = 'base.tsv'
east_file_path = 'leste.tsv'
west_file_path = 'oeste.tsv'

central_data = read_tsv(central_file_path)
north_data = read_tsv(north_file_path)
south_data = read_tsv(south_file_path)
base_data = read_tsv(base_file_path)
east_data = read_tsv(east_file_path)
west_data = read_tsv(west_file_path)

calculate_info(central_data, "centro")
calculate_info(north_data, "norte")
calculate_info(south_data, "sul")
calculate_info(east_data, "oeste")
calculate_info(west_data, "leste")

central_filtered_data, central_preferable_data = filtrate_data(central_data)
north_filtered_data, north_preferable_data = filtrate_data(north_data)
west_filtered_data, west_preferable_data = filtrate_data(west_data)
south_filtered_data, south_preferable_data = filtrate_data(south_data)
east_filtered_data, east_preferable_data = filtrate_data(east_data)


# Limites personalizados para cada região
# Seu código existente
central_filtered_data = central_filtered_data['VALOR DA CASA']
north_filtered_data = north_filtered_data['VALOR DA CASA']
south_filtered_data = south_filtered_data['VALOR DA CASA']
west_filtered_data = west_filtered_data['VALOR DA CASA']
east_filtered_data = east_filtered_data['VALOR DA CASA']



colors = ['blue', 'orange', 'green', 'red', 'black']
data_length = [
    central_filtered_data, west_filtered_data, south_filtered_data,
    east_filtered_data, north_filtered_data
]
bplots = plt.boxplot(data_length, vert=1)
c = 0
for i, bplot in enumerate(bplots['boxes']):
    bplot.set(color=colors[c], linewidth=3)
    c += 1

# Definindo os rótulos das regiões
regions = ['Central', 'West', 'South', 'East', 'North']
plt.xticks([1, 2, 3, 4, 5], regions)

plt.title("Boxplot dos dados com os requisitos mínimos para cada região", loc='center')
plt.xlabel("Regiões")
plt.ylabel("Preço")

plt.show()