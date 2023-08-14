matrix = [
    [3, 2, 4],
    [1, 1, 2],
    [4, 3, -2]
]

B = [1,2,3]

# matrix = [
#     [1,2],
#     [3,4]
# ]

print(len(matrix))
# k is the step
for k in range(0, len(matrix) -1  ):
    for j in range(k+1, len(matrix)):
        multiplicador = matrix[j][k] / matrix[k][k]


        for l in range(k, len(matrix)):
            matrix[j][l] -= (matrix[k][l] * multiplicador)
        B[j] -= B[k] * multiplicador
        
print(matrix)


solucao = []
for i in range(0, len(matrix)):
    solucao.append(0)


solucao[len(matrix) -1 ] = B[len(matrix) -1]/matrix[len(matrix)-1][len(matrix)-1]

for i in range(len(matrix) - 2, -1  , -1):
    sum = 0
    for j in range(i + 1, len(matrix)):
        sum +=  (matrix[i][j] * solucao[j])
    solucao[i] = (B[i] - sum)/matrix[i][i]


print(solucao)
