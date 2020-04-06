import cv2
import numpy as np


img=cv2.imread('any.jpg',cv2.IMREAD_COLOR)
cv2.line(img, (0,0),(150,150),(255,14,34),15)#line pixel
pts=np.array([[10,5],[20,30],[50,5],[12,12]],np.int32)

cv2.polylines(img,[pts],True,(0,0,225),4)

font=cv2.FONT_HERSHEY_SIMPLEX

cv2.putText(img,'OPENCV TUts',(0,130),font,1,(200,250,1),2,cv2.CV_AA)

cv2.imshow("image",img)
cv2.waitKey(0)
cv2.destroyAllWindows()

