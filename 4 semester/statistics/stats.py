import statistics

size = int(input("Enter data size: "))

data = []
for i in range(0, size):
    num = float(input("Enter data: "))
    data.append(num)


mean = statistics.mean(data)
median = statistics.median(data)
mode = statistics.mode(data)
variance = statistics.variance(data)
stdev = statistics.stdev(data)
quants = statistics.quantiles(data)
maximum = max(data)
minimum = min(data)
amplitude = maximum - minimum

cv = (variance/mean) * 100

print("***************************************************** \n \n")

print(f"Média: {mean}")
print(f"Mediana: {median}")
print(f"Moda: {mode}")
print(f"Variância: {variance}")
print(f"Desvio Padrão: {stdev}")
print(f"Coeficiente de variância: {cv}")
print(f"primeiro quantil: {quants[0]}")
print(f"terceiro quantil: {quants[2]}")
print(f" IQ: {quants[0] - quants[2]}")
print(f"amplitude: {amplitude}")

