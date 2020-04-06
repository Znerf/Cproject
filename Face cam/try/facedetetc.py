import cv2
import numpy as np

facecascade=cv2.CascadeClassifier('superman.xml')

#eyecascade=cv2.CascadeClassifier('eye.xml')

cap=cv2.VideoCapture(0)
while (cap.isOpened()):
    _,img=cap.read()
    img=cv2.flip(img,1)
    gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    
    faces=facecascade.detectMultiScale(gray,1.3,5)
    for(x,y,w,h) in faces:
            cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
            roi_gray=gray[y:y+h,x:x+w]
            roi_color=img[y:y+h,x:x+w]
            #eye=facecascade.detectMultiScale(roi_gray)
            #for(ex,ey,ew,eh) in eye:
             #   cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)
    cv2.imshow('',img)
    k=cv2.waitKey(20)&0xff
    if k==27: break

cap.release
cv2.destroyAllWindows()
