#include <Servo.h>

// variables
  Servo servoLeft, servoRight;
  int speedLeft, speedRight, mag =0, incr =5;
  
  // functions
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

  

void setup() {
  // put your setup code here, to run once:
    servoLeft.attach(13);
    servoRight.attach(12);  
    speedLeft = speedRight = 1500;
    servoLeft.writeMicroseconds(speedLeft);
    servoRight.writeMicroseconds(speedRight);

}

void loop() {
  // put your main code here, to run repeatedly:
    //servoLeft.writeMicroseconds(1700);
     Forward(200);
     delay(1000);
     Forward(0);
     delay(1000);
     Backward(200);
     delay(1000);
     Backward(0);
     delay(1000);
     turnLeft(200);
     delay(1000);
     turnLeft(0);
     delay(1000);
     turnRight(200);
     delay(1000);
     turnRight(0);
     delay(1000);
     
    


    
}
