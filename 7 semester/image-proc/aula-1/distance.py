import cv2
import math


dots= []

def click_event(event, x, y, flags, param):
    if event == cv2.EVENT_LBUTTONDOWN:
        dots.append((x, y))
        print(f"Coordenada {len(dots)}: ({x}, {y})")
        cv2.circle(img, (x, y), 5, (0, 0, 255), -1)
        cv2.imshow('Imagem', img)
        
        if len(dots) == 2:
            cv2.destroyAllWindows()

# Carregar imagem
img = cv2.imread('naruto.jpg')
cv2.imshow('Imagem', img)
cv2.setMouseCallback('Imagem', click_event)
cv2.waitKey(0)


point1, point2 = dots[0], dots[1]


euclidian = math.dist(point1, point2)

print(f"Euclidean distance is: {euclidian}")

city_block = sum(abs(p-q) for p,q in zip(point1, point2))

print(f"City block distance is {city_block}")

chessboard_distance = max(abs(point1[0] - point2[0]), abs(point1[1] - point2[1]))

print(f"Chessboard distance is {chessboard_distance}")