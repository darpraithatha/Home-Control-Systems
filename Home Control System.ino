#define echoPin 4 // Echo Pin
#define trigPin 5 // Trigger Pin
#define LEDPin 6 // Onboard LED
#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
int X=0;
int Y=0;
int z=0;
int f=0;
int t=0;
int g=1,h=0;
int i=0;
int maximumRange = 1000; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup()  
{ 
  pinMode(2,INPUT); //letter box
  pinMode(15,INPUT);
  pinMode(12,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);

  //*******curtain control*************//
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

  //***********fan**************//
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo.write(0);   

  //*************parking sensor******************//
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
  //*********************************************//
  Serial.begin(9600);  
}  


void loop()  
{ 
  //*********************parking sensor********************************//
  {       digitalWrite(trigPin, LOW); 
          delayMicroseconds(2); 
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10); 
          digitalWrite(trigPin, LOW);
          duration = pulseIn(echoPin, HIGH);
          //Calculate the distance (in cm) based on the speed of sound.
           distance = duration/58.2;
           if (distance >= maximumRange || distance <= minimumRange){
           /* Send a negative number to computer and Turn LED ON 
           to indicate "out of range" */
           Serial.println("-1");
           digitalWrite(LEDPin, LOW); 
          }
         else {
         /* Send the distance to the computer using Serial protocol, and
         turn LED OFF to indicate successful reading. */
          Serial.println(distance);
                 if(distance<=10){
                              digitalWrite(LEDPin, HIGH); 
                                }
                    else{ 
                           digitalWrite(LEDPin, LOW);
                        }
                 }
       //Delay 50ms before next reading.
      delay(50);
  }
  //******************************************************************// 
  int remote_val = remote();  // Call the remote function to get the value of the key pressed
  if(remote_val>0)  // check if the value is greater than 0. A 0 means that no signal was received by the TSOP
  {  
    Serial.println(remote_val);  
    delay(150); // A remote press will normally generate 3 signal trains. This is to avoid reading duplicates  
  }
  
//**********************letter box reset****************************//
if(remote_val== 229)
{
  i=remote_val;
}

//*********************Water level controller************************//
if (remote_val== 224)
{
  X=remote_val;
}
if (remote_val== 2979)
{
  X=remote_val;
}

//*********************light control*********************************//
if (remote_val== 223)
{
  Y=remote_val;
}
if (remote_val== 631)
{
  Y=remote_val;
}
if (remote_val== 146)
{
  c=remote_val;
}
if (remote_val== 147)
{
  c=remote_val;
}

//*************************Fan Control****************************//
if (remote_val== 128)
{
  f=remote_val;
}
if (remote_val== 129)
{
  f=remote_val;
}
if (remote_val== 130)
{
  f=remote_val;
}
if (remote_val== 131)
{
  f=remote_val;
}
if (remote_val== 132)
{
  f=remote_val;
}

//***************************Curtain control*********************************//
if (remote_val== 144)
{
  t=remote_val;
}
if (remote_val== 145)
{
  t=remote_val;
}

//********************fan control**********************************//
if (remote_val== 151)
{
   digitalWrite(1,HIGH);
}
if (remote_val== 165)
{
   digitalWrite(1,LOW);
}

//***************Water Level Controller********************************//
  a=analogRead(3); // Upper level
  b=analogRead(4); // Lower level
  
  if (a<1000 && b<1000)
{
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}
  if (a>1000 && b>1000)
{
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
}
 if (X== 224 && a >1000)
 {
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
 }

 if (X== 2979)
 {
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
 }

 //*****************************Light Control************************************//
if (Y==223)
{ 
  analogWrite(3,z);
}

if (remote_val==146 )
  {
    z=z+10;
  }
if (remote_val==147 )
  {
    z=z-10;
  }
if (Y==631)
{
  z=0;
  analogWrite (3,z);
}

//********************************Curtains Control***************************************************//
if (remote_val==144)
{
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  delay(50);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

if (remote_val==145)
{
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  delay(50);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
{
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

//******************************fan control**********************************//
  if (remote_val==128)
        {
          for(pos = 0; pos <= 30; pos += 1) 
        {                                  
           myservo.write(pos);              // tell servo to go to position in variable 'pos' 
           delay(15);                       // waits 15ms for the servo to reach the position 
        }                      // waits 15ms for the servo to reach the position 
        }
  if(remote_val==129){
       for(pos = 30; pos <= 60; pos += 1) 
        {                                  
           myservo.write(pos);              // tell servo to go to position in variable 'pos' 
           delay(15);                       // waits 15ms for the servo to reach the position 
        }                      // waits 15ms for the servo to reach the position 
 }
 if(remote_val==130){
       for(pos = 60; pos <= 90; pos += 1) 
        {                                  
           myservo.write(pos);              // tell servo to go to position in variable 'pos' 
           delay(15);                       // waits 15ms for the servo to reach the position 
        }                      // waits 15ms for the servo to reach the position 
 }
  if(remote_val==131){
       for(pos = 90; pos <= 120; pos += 1) 
        {                                  
           myservo.write(pos);              // tell servo to go to position in variable 'pos' 
           delay(15);                       // waits 15ms for the servo to reach the position 
        }                      // waits 15ms for the servo to reach the position 
 }
   if(remote_val==132){
       for(pos = 90; pos <= 120; pos += 1) 
        {                                  
           myservo.write(pos);              // tell servo to go to position in variable 'pos' 
           delay(15);                       // waits 15ms for the servo to reach the position 
        }                      // waits 15ms for the servo to reach the position 
 }

//*****************************Letter BOX***************************************//
g=digitalRead(2);
if (g==0)
{
    h=h+1;
}

if (h>0)
{
  digitalWrite(10,HIGH);//letter box led
  i=0;
}
if (remote_val=229)
{
 digitalWrite(10,LOW);
}

//****************************************************************************//
Serial.print("a=");
Serial.println(a);
Serial.print("b=");
Serial.println(b);
Serial.println(c);
Serial.println(d);
Serial.println(e);
Serial.println(X);
Serial.println(Y); 
Serial.println("  ");
Serial.println("  ");
Serial.println("  ");
}

int remote()  
{  
  int value = 0;  // a Variable to store our final calculated value
  int time = pulseIn(15,LOW);  // we need to look for the duration of the LOW pulse as TSOP will invert the incoming HIGH pulse
  if(time>2000) // Checking if the Start Bit has been received. Start Bit Duration is 2.4ms  
  {  
    for(int counter1=0;counter1<12;counter1++) // A loop to receive the next 12 bits The loop is in the inverse order as we will be receiving the MSB   
    {  
      if(pulseIn(15,LOW)>1000) // checking the duration of each pulse, if it is a '1' then we use it in our binary to decimal conversion, '0's can be ignored.  
      {  
        value = value + (1<< counter1);// binary to decimail conversion. 1<< i is nothing but 2 raised to the power of i  
      }  
    }  
  }  
  return value;  
}

