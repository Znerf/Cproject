import numpy as np
import cv2

img1=cv2.imread("logo.jpg")
img2=cv2.imread("1.jpg")
rows,cols,channels=img1.shape
roi=img1[0:rows,0:cols]

img2gray=cv2.cvtColor(img1,cv2.COLOR_BGR2GRAY)
ret, mask=cv2.threshold(img2gray,220,255,cv2.THRESH_BINARY_INV)

mask_inv=cv2.bitwise_not(mask)

cv2.imshow("mask",mask)
#cv2.imshow("mask",mask_inv)


cv2.waitKey(0)
cv2.destroyAllWindows()
