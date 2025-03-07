import cv2
import numpy as np 
import matplotlib.pyplot as plt 


matriz = np.zeros((14,14))



matriz[1][2:6] = 1
matriz[2][3:5] = 1

matriz[2:7, 9:11] = 1
matriz[5:7, 7:11] = 1


matriz[7][4:7] = 1
matriz[8][3:8] = 1
matriz[9][4:7] = 1
matriz[10][5] = 1

print(matriz)

plt.imshow(matriz, cmap='gray', interpolation='nearest')
plt.axis('off')  # Esconde os eixos
plt.show()

def color_n4(matriz, i, j, color):

    if matriz[i][j] == 0:
        return
    
    if matriz[i][j] == color:
        return
    
    if i >= 14 or i < 0 or j >= 14 or j < 0:
        return 
    
    matriz[i][j] = color 
    color_n4(matriz, i+1,j, color)
    color_n4(matriz, i,j+1, color)
    color_n4(matriz, i-1,j, color)
    color_n4(matriz, i,j-1, color)


def color_n8(matriz, i, j, color):

    if matriz[i][j] == 0:
        return
    
    if matriz[i][j] == color:
        return
    
    if i >= 14 or i < 0 or j >= 14 or j < 0:
        return 
    
    matriz[i][j] = color 
    color_n8(matriz, i+1,j, color)
    color_n8(matriz, i,j+1, color)
    color_n8(matriz, i-1,j, color)
    color_n8(matriz, i,j-1, color)
    color_n8(matriz, i+1,j+1, color)
    color_n8(matriz, i-1,j+1, color)
    color_n8(matriz, i-1,j-1, color)
    color_n8(matriz, i+1,j-1, color)



num_objects = 0
color = num_objects + 5
for i in range(14):
    for j in range(14):
        if matriz[i][j] == 1:
            color_n8(matriz, i,j, color)
            color += 5
            num_objects += 1




plt.imshow(matriz, cmap='gray', interpolation='nearest')
plt.axis('off')  # Esconde os eixos
plt.show()

print(matriz)