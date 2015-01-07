
#include <Wire.h>
int sensorPin_A0 = A0;
int sensorPin_A2 = A2;
//--------------------------
int sensorValue_A0 = 0;
int sensorValue_A2 = 0;
//--------------------------
int count_A0 = 0;
int count_A2 =0;
//--------------------------
int front_A0 = 0;
int front_A2 = 0;
//--------------------------
char ch;
//--------------------------
void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);           // start serial for output
  analogReference(EXTERNAL);
}




void loop()
{

 sensorValue_A0 = analogRead(sensorPin_A0); 
 sensorValue_A2 = analogRead(sensorPin_A2); 
 Serial.print(sensorValue_A0);
 Serial.print("----------");
 Serial.print(sensorValue_A2);
 Serial.println(""); 
 
  if (sensorValue_A0 > 150 )
  {
    front_A0 = 1;
  
   //Serial.println(sensorValue_A0);
   //Serial.print("=====");
  

  } 
  if (sensorValue_A0 < 150 and front_A0 == 1 )
  {
   count_A0++;
   front_A0 = 0; 
   // Serial.print(sensorValue_A0);
  //  Serial.print("=====");
  //  Serial.print(count_A0); 
  //   Serial.println(""); 
    
  }  

  //ch = Serial.read();
   delay(200);
   
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}

void requestEvent()
{
  //sensorValue = analogRead(sensorPin);
  //Wire.write(byte (count)); // respond with message of 6 bytes
    //Serial.print(ch);                   // as expected by master
}
