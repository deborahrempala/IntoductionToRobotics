#include <Servo.h>

// variables
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
void stopbot()
{

    speedLeft = speedRight = 1500;
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
 byte wLeft,wRight;
 int delta_speed =0;
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
   servoLeft.attach(13);
    servoRight.attach(12);  
    speedLeft = speedRight = 1500;
    servoLeft.writeMicroseconds(speedLeft);
    servoRight.writeMicroseconds(speedRight);
}
int distance =0;
void loop() {
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
cm = microsecondsToCentimeters(duration);


  for(int i = 0; i<=10; i++)
  {
  Forward(200);
  searching(cm);
  }


 if(cm <=15 && cm <=20)
{


  stopbot();
  delay(100);
  searching(cm);
  

}
delay(100);
  
}

bool searching(long cm )
{

  if(cm <= 15)
  {
   
  stopbot();
  
   turnRight(200);
   if(cm>=5)
   {
    Forward(200);
   }
   delay(100);
    
  }
}


long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
