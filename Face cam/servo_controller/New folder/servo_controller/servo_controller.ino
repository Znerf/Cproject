#include <Servo.h>

Servo upDown;
Servo leftRight;

int valu=upDown.read();
int vall=leftRight.read();

void setup() {
  upDown.attach(3); //tilt servo attached to pin 3
  int x=upDown.read();
  int i,val;
  if(x>180)
      upDown.writeMicroseconds(1300);    
  else if(x<180)
      upDown.writeMicroseconds(1700); 


  
  leftRight.attach(4); //tilt servo attached to pin 3
  x=leftRight.read();
  if(x>180)
    leftRight.writeMicroseconds(1300);    
  else if(x<180)
    leftRight.writeMicroseconds(1700); 
  
  valu=upDown.read();
  vall=leftRight.read();
  
  Serial.begin(9600); //Serial port which will have recieved chars from Python
  
}


void loop(){
 
  
  switch (Serial.read()){
   case 'u':
     valu -=2;
     upDown.write(valu);
     break;
   case 'd':
     valu +=2;
     upDown.write(valu);
     break;
   case 'l':
     vall -=4;
     leftRight.write(vall);
     break;
   case 'r':
     vall +=4;
     leftRight.write(vall);
    
  }
   
 
}
