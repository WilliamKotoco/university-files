import numpy as np
import matplotlib.pyplot as plt
import cv2 


# img = cv2.imread("naruto.jpg", cv2.IMREAD_GRAYSCALE,)
# img = cv2.resize(img, (254,254))


img2 = cv2.imread("jujutsu.jpg", cv2.IMREAD_GRAYSCALE)
img2 = cv2.resize(img2, (254,254))


img3 = cv2.imread("texture.jpeg", cv2.IMREAD_GRAYSCALE)


img3 = cv2.resize(img3, (254,254))

# Clareando a imagem da textura
img3 = cv2.add(img3, 50)



# Transformando em float para evitar overflow
img2,img3 =  np.float32(img2), np.float32(img3)
#img3 = img3 * 3



result_div = img2 // img3
result_mult = img2 * img3
# Normalizando o resultado
result_div = cv2.normalize(
    result_div, None, alpha=0, beta=255, norm_type=cv2.NORM_MINMAX)

result_mult = cv2.normalize(
    result_mult, None, alpha=0, beta=255, norm_type=cv2.NORM_MINMAX)




plt.figure(figsize=(10, 5))

# Subplot para a divisão
plt.subplot(1, 4, 4)
plt.title("Divisão")
plt.imshow(result_div, cmap='gray', interpolation='nearest')
plt.axis('off')

# Subplot para a multiplicação
plt.subplot(1, 4, 3)
plt.title("Multiplicação")
plt.imshow(result_mult, cmap='gray', interpolation='nearest')
plt.axis('off')

# Subplot para a imagem original de Jujutsu
plt.subplot(1, 4, 1)
plt.title("Imagem Jujutsu")
plt.imshow(img2, cmap='gray', interpolation='nearest')
plt.axis('off')

plt.subplot(1, 4, 2)
plt.title("Imagem Textura")
plt.imshow(img3, cmap='gray', interpolation='nearest')
plt.axis('off')

# Mostrar as imagens
plt.tight_layout()
plt.show()

reverse_img = img2
for i in range(254):    
    for j in range(254):
        if(reverse_img[i][j] == 0):
            reverse_img[i][j] = 255
        elif reverse_img[i][j] == 255:
            reverse_img[i][j] = 0

result_inverse = cv2.normalize(
    reverse_img, None, alpha=0, beta=255, norm_type=cv2.NORM_MINMAX)
plt.title("Jujutsu ineverse")
plt.imshow(result_inverse, cmap='gray', interpolation='nearest')
plt.axis('off')  # Esconde os eixos
plt.show()


    