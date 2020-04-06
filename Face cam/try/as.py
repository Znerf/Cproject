import cv2
import numpy as np
import matplotlib.pyplot as plt

img=cv2.imread('any.jpg',cv2.IMREAD_GRAYSCALE)
#IMREAD_COLOR=1
#IMREAD_UNCHANGED=-1


#cv2.imshow('image',img)
#cv2.waitKey(0)
#cv2.destroyAllWindows()

#plt.imshow(img,cmap='gray')#,interpolation='bicubic')
#plt.show();



cap=cv2.VideoCapture(0)
while True:
    ret,frame=cap.read()
    cv2.imshow('frame',frame)

    if cv2.waitKey(1)& 0xFF == ord('q'):
        break
cap.release
cv2.destroyAllWindows()
