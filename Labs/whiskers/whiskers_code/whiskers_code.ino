
// variables 
#include <Servo.h>

Servo servoLeft, servoRight;
 int speedLeft, speedRight, mag =0, incr =5;


void forward(int percentage, float timeinSeconds)
{
  int leftSpeed, rightSpeed, milliseconds;
  milliseconds = (int)(timeinSeconds * 100);
  if(percentage > 100)
      percentage = 100;
  else if(percentage < 0)
      percentage = 0;
  leftSpeed = 1500 + (percentage *2);
  rightSpeed = 1500 - (percentage * 2);
  servoLeft.writeMicroseconds(leftSpeed);
  servoRight.writeMicroseconds(rightSpeed);
  delay(milliseconds);
    
}
  
void turnLeft (int percentage, float timeinSeconds)
{
   int leftSpeed, rightSpeed, milliseconds;
  milliseconds = (int)(timeinSeconds * 100);
  if(percentage > 100)
      percentage = 100;
  else if(percentage < 0)
      percentage = 0;
  leftSpeed = 1500 - (percentage *2);
  rightSpeed = 1500 - (percentage * 2);
  servoLeft.writeMicroseconds(leftSpeed);
  servoRight.writeMicroseconds(rightSpeed);
  delay(milliseconds);
    
}

 void Backward (int mag)
 {
     if(mag > 200)
      mag = 200;
    else if(mag < 0)
      mag =0;

   speedLeft = 1500 - mag;
   speedRight = 1500 + mag;
   servoLeft.writeMicroseconds(speedLeft);
   servoRight.writeMicroseconds(speedRight);
 }
void turnRight (int mag)
{
   if(mag > 200)
      mag = 200;
    else if(mag < 0)
      mag =0;

   speedLeft = 1500 + mag;
   speedRight = 1500 + mag;
   servoLeft.writeMicroseconds(speedLeft);
   servoRight.writeMicroseconds(speedRight);
}  


  byte wLeft;
  byte wRight;
void setup() {
  delay(1000);
  pinMode(7,INPUT);
  pinMode(5,INPUT);
  pinMode(8,OUTPUT);
  pinMode(2,OUTPUT);
  
  Serial.begin(9600);
   servoLeft.attach(13);
    servoRight.attach(12); 
}

void loop() {
   
  wLeft = digitalRead(5);
  wRight = digitalRead(7);

  Serial.print(wLeft);
  Serial.println(wRight);

 if(wLeft == 0 && wRight == 0)
 {
Backward(5);
   turnLeft(100,56.5);
  }
if(wLeft == 01) {
  Backward(5);
  turnRight(5);
  
}

if(wRight == 10){
Backward(5);
}
  forward(100,2);


}
