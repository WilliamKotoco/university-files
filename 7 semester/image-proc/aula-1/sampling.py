import numpy as np
import matplotlib.pyplot as plt
import math

RESOLUTION = 256

INTENSITY_LEVELS = 255

def show_img(img:np.array):
    plt.imshow(img, cmap='grey', vmin=0, vmax=INTENSITY_LEVELS)
    plt.show()

patches = int(input("Number of patches: "))

img = np.zeros((RESOLUTION, RESOLUTION), np.int32)


squares_per_axis = math.sqrt(patches)

if squares_per_axis.is_integer() == False:
    raise ValueError("Value should be perfect square")

squares_per_axis = int(squares_per_axis)
    


square_size = RESOLUTION // squares_per_axis


for k in range(patches):
    x = (k % squares_per_axis) * square_size
    y = (k//squares_per_axis) * square_size
    
    intensity_color = (k * INTENSITY_LEVELS//patches) % INTENSITY_LEVELS + 1
    
    img[x:x+square_size, y:y+square_size] = intensity_color


show_img(img)
