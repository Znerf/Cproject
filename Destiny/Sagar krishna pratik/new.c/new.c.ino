#define lmotor1 0
#define lmotor2 1
#define rmotor1 2
#define rmotor2 3

#define green 7 
#define red 5
 
#define s5 8 //leFT
#define s4 9 
#define s3 10
#define s2 11
#define s1 12 //right


void setup() {
  pinMode(lmotor1,OUTPUT);
  pinMode(lmotor2,OUTPUT);
  pinMode(rmotor1,OUTPUT);
  pinMode(rmotor2,OUTPUT);
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  pinMode(s5,INPUT);
}
//white high
void loop() {
  int lsensor= digitalRead(s1);
  int lmsensor= digitalRead(s2);
  int msensor=digitalRead(s3);
  int rmsensor=digitalRead(s4);
  int rsensor=digitalRead(s5);  


if (lsensor== LOW && lmsensor== LOW && rmsensor == LOW  && rsensor== LOW && msensor == LOW) uturn(msensor);
else if (lsensor == HIGH && rsensor==LOW) lleft(msensor);
else if (lsensor == LOW && rsensor==HIGH) rright(msensor);
else if (lsensor == HIGH && rsensor== HIGH) rright(msensor);

else if (lmsensor== LOW && rmsensor == LOW && msensor == HIGH) forward();
else if(lmsensor== HIGH && rmsensor == LOW ) left();
else if(lmsensor== LOW && rmsensor == HIGH) right();
  

}



void forward()
{
  
  digitalWrite(lmotor1,HIGH);
  digitalWrite(lmotor2,LOW);

  digitalWrite(rmotor1,HIGH);
  digitalWrite(rmotor2,LOW);
  
  
  
}

void left()
{
  
  digitalWrite(lmotor1,LOW);
  digitalWrite(lmotor2,HIGH);

  digitalWrite(rmotor1,HIGH);
  digitalWrite(rmotor2,LOW);
}

void right()
{
  
  digitalWrite(rmotor1,LOW);
  digitalWrite(rmotor2,HIGH);

  digitalWrite(lmotor1,HIGH);
  digitalWrite(lmotor2,LOW);
  
}


void brake()
{
  digitalWrite(green,HIGH);
  forward();
  delay(100);
  
  digitalWrite(rmotor1,LOW);
  digitalWrite(rmotor2,LOW);

  digitalWrite(lmotor1,LOW);
  digitalWrite(lmotor2,LOW);
  while(1)
  {
    digitalWrite(6,HIGH);
    digitalWrite(green,HIGH);
    }
  
}

void lleft(int msensor)
{
  digitalWrite(red,HIGH);
  
  forward();
  delay(200);
  left();
  while (msensor ==LOW)
  {
    msensor=digitalRead(s3); 
    left();
  }
 // delay(500);
  
  digitalWrite(red,LOW);
 
}

void rright(int msensor)
{
  digitalWrite(red,HIGH);
  
  forward();
  delay(200);

  
  delay(20);
  
  int lsensor= digitalRead(s1);
  int lmsensor= digitalRead(s2);
  int rmsensor=digitalRead(s4);
  int rsensor=digitalRead(s5);
  
  if (lsensor== HIGH && lmsensor==HIGH && rmsensor== HIGH && rsensor==HIGH) {
    brake();
  }

  
  right();

  while(msensor==LOW) 
  {
    msensor = digitalRead(s3);
    right();
  }
  delay(500);//700
  
  digitalWrite(red,LOW);
}

void uturn(int msensor)
{
  forward();
  delay(100);

  while(msensor==LOW)
  {
    msensor=digitalRead(s3);
    left();
  }  
 // delay(1000);
}


