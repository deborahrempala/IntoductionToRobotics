// Final Lab
// Doug Grunder & Deborah Rempala



// variables 
#include <Servo.h>

Servo servoLeft, servoRight;
 int speedLeft, speedRight, mag =0, incr =5;
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

// Functions
    // Move Forward
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


  // Move Backward
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

 // Turn Right
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

// Turn Left
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



long randNumber =0;
void setup()
{
  // setup for speaker
    Serial.begin(9600);
  // setup for movement
    servoLeft.attach(13);
    servoRight.attach(12); 
    // random number setup
     randomSeed(analogRead(0));
}
void loop()
{
unsigned long startMillis= millis(); // Start of sample window
unsigned int peakToPeak = 0; // peak-to-peak level
unsigned int signalMax = 0;
unsigned int signalMin = 1024;
// collect data for 50 mS
while (millis() - startMillis < sampleWindow)
{
sample = analogRead(0);
if (sample < 1024) // toss out spurious readings
{
if (sample > signalMax)
{
signalMax = sample; // save just the max levels
}
else if (sample < signalMin)
{
   signalMin = sample;
}
}
}
peakToPeak = signalMax - signalMin;
double volts = (peakToPeak * 3.3) /1024;
Serial.println(volts);

// if no sound or little sound, stop moving 
if(volts >= 0 && volts <=.12)
{
    
      Forward(0);
     Backward(0);

}

// if medium sound, Move forward
if(volts >=.20 && volts <=.30)

{

Serial.println("Medium Sound");
  Forward(200);
  // random movement with a random number generator
       randNumber = random(1, 10);
           Forward(100);
        // Turn forward left with 1-3
            if(randNumber >=1 || randNumber <=3)
            {
              turnLeft(200);
            }
        // speed up with a 4 or 5
         if(randNumber ==4|| randNumber ==5)
            {
              Forward(250);
            }
        
        // Turn forward right with a 6 or 7
          if(randNumber ==6|| randNumber ==7)
            {
              turnRight(200);
            }
        
        // else spin in a right circle 
        else
        {
           turnLeft(200);
          
        }
}

if( volts>=.40 && volts <=.50)  
    {
      Backward(200);
// if loud sound, move backwards
    // random movemet with a random number generator
Serial.println("Loud Sound");
  Forward(200);
  // random movement with a random number generator
       randNumber = random(1, 10);
           Backward(100);
        // Turn forward left with 1-3
            if(randNumber >=1 || randNumber <=3)
            {
              turnLeft(200);
            }
        // speed up with a 4 or 5
         if(randNumber ==4|| randNumber ==5)
            {
              Backward(250);
            }
        
        // Turn forward right with a 6 or 7
          if(randNumber ==6|| randNumber ==7)
            {
              turnRight(200);
            }
        
        // else spin in a right circle 
        else
        {
           turnRight(200);
          
        }
    
    
    
    }
else
{
   turnRight(200);
  
}





delay(50);
}
