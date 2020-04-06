import numpy as np
import cv2


frame1 = cv2.VideoCapture(0)
while 1:
    ret, frame = frame1.read()

    #frame=cv2.flip(frame,1)

    
    cv2.imshow("fun321",frame)
    if cv2.waitKey(1)&0xFF ==ord('q'):        
        break
    



frame1.release()
cv2.destroyAllWindows()
