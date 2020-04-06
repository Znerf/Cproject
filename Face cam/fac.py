import sys
import cv2
import serial
import numpy
import time

class FaceFinder(object):
    def __init__(self):
        self.face_cascade = cv2.CascadeClassifier(
            'haarcascade_frontalface_alt.xml')
        self.video_stream = cv2.VideoCapture(0)
        self.half_height = int(self.video_stream.get(4) / 2.0)
        self.half_width = int(self.video_stream.get(3) / 2.0)

    def loop(self):
        while True:
            ret, frame = self.video_stream.read()
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            faces = self.face_cascade.detectMultiScale(gray, 1.3, 5)
            for (x, y, w, h) in faces:
                cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
                print "Current Face XY location is:", x, y     
            cv2.imshow('Video', frame)
            if cv2.waitKey(1)&0xFF ==ord('q'):
                self.end_stream()
                break
    def end_stream(self):
        self.video_stream.release()
        cv2.destroyAllWindows()
        
if __name__ == "__main__":
    f = FaceFinder()
    f.loop()
