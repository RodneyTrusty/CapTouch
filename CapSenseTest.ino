#include <CapacitiveSensor.h>

/*
Basic Capacitive touch Demo
When the Capacitive touch is read above a defined threshold it will trigger an LED on pin 8
*/

//You will most likely need to adjust this number to work for your own setup 
#define CAP_LIMIT       3000

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);

void setup()                    
{

    cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
    
    Serial.begin(9600);
    
    pinMode(8, OUTPUT);
   
}

void loop()                    
{
  
    long total1 =  cs_4_2.capacitiveSensor(30);
    
    Serial.println(total1); 

    //Turn LED on if capSense value is above threshold
    if(total1 > CAP_LIMIT){
        
        digitalWrite(8, HIGH);
        
      }

    //Otherwiae Turn the LED off
    else{
        
        digitalWrite(8, LOW);
      
      }
      
    delay(10);
   
}
