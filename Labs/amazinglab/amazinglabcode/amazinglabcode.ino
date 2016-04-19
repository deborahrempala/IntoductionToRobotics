
// variables 
#include <Servo.h>

Servo servoLeft, servoRight;
 int speedLeft, speedRight, mag =0, incr =5;

 const int pingPin = 13;

void Forward(int mag)
  {
    if(mag > 200)
      mag = 200;
    else if(mag < 0)
      mag =0;

   speedLeft = 1500 + mag;
   speedRight = 1500 - mag;
   servoLeft.writeMicroseconds(speedLeft);
   servoRight.writeMicroseconds(speedRight);

   
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

void turnLeft (int mag)
{
   if(mag > 200)
      mag = 200;
    else if(mag < 0)
      mag =0;

   speedLeft = 1500 - mag;
   speedRight = 1500 - mag;
   servoLeft.writeMicroseconds(speedLeft);
   servoRight.writeMicroseconds(speedRight);
}  

 int delta_speed =0;

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
    long duration, inches, cm;
     wLeft = digitalRead(5);
  wRight = digitalRead(7);

  Serial.print(wLeft);
  Serial.println(wRight);

 while(wLeft != 0 && wRight != 0)
 {

  Forward(200);

   if(wLeft == 0 && wRight == 0)
 {
      Backward(5);
      turnLeft(5);
  }
if(wLeft == 01) {
  Backward(5);
  turnRight(5);
  
}

if(wRight == 10){
Backward(5);
turnLeft(5);
}

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  if(cm - 25 < 0)
  {
    delta_speed= max(-200,(cm -25) * 10);
  }

else
{
 delta_speed= min(200,(cm -25) * 10);
 
  
  }
  if (abs(cm-25) <= 2)
     delta_speed = 0;

  speedLeft = 1500 + delta_speed;
   speedRight = 1500 - delta_speed;
   servoLeft.writeMicroseconds(speedLeft);
   servoRight.writeMicroseconds(speedRight);


  //delay(100);
  
}
 
  
 }

 

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
