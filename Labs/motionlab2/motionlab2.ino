#include <Servo.h>

// variables 
Servo servoLeft, servoRight;



// functions
void stopbot()
{
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  
}

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
  stopbot();   
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
  stopbot();   
}


void setup() {
     servoLeft.attach(13);
    servoRight.attach(12);  
     stopbot();
     forward(100,190);
     delay(500);
     turnLeft(100,56.5);
     delay(500); 
     forward(100,178);

}

void loop() {
 // forward(100,2);
 
}
