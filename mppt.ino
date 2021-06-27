#include<LiquidCrystal.h>
#define VOLT A0
#define LUX A1            //connect The LDR on Pin A1
const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
LiquidCrystal lcd(2,3,4,5,6,7);

float volt,lux;
int value1;

float voltage = 0.0;
float temp=0.0;
int analog_value0;

void setup()
{
   lcd.begin(16, 2); 
   lcd.setCursor (0,0);
   lcd.print(" Arduino Based ");
   lcd.setCursor(0,1); 
   lcd.print("HARSHITA Project");
   delay(2000);


   Serial.begin(9600);
   pinMode(ledPin1, OUTPUT);  //initialize the LED pin1 as an output
   pinMode(ledPin2, OUTPUT);  //initialize the LED pin2 as an output
   pinMode(ledPin3, OUTPUT);  //initialize the LED pin3 as an output
   pinMode(lux, INPUT);       //initialize the LDR pin as an input
}


void loop() 
{

 /*---------Voltage----------*/
   analog_value0 = analogRead(A0);
   voltage = (analog_value0 * 5.0) / 1024.0; 

   if (voltage < 0.1) 
   {
     voltage=0.0;
   } 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voltage= ");
    lcd.print(voltage);
    lcd.setCursor(12,0);
    lcd.print(" V");
    delay(30);


/*-----Light Intensity------*/

   value1=analogRead(LUX);
   volt=(value1/1023.0)*5;
   lux=((2500/volt)-500)/3.3;
   delay(30);
  //check if the LDR status is >= 300
  //if it is, the LED1 is HIGH

   if (value1 >=300) {

    digitalWrite(ledPin1, HIGH);               //turn LED on
    Serial.println("LDR is low, LED is ON");
    
   }
  else {

    digitalWrite(ledPin1, LOW);          //turn LED off
    Serial.println("---------------");
  }

   //check if the LDR status is <= 500
   //if it is, the LED2 is HIGH
    
    if (value1 <=500) {

    digitalWrite(ledPin2, HIGH);               //turn LED on
    Serial.println("LDR is medium, LED is ON");
    
   }
  else {

    digitalWrite(ledPin2, LOW);          //turn LED off
    Serial.println("---------------");
  }

   //check if the LDR status is <= 800
   //if it is, the LED3 is HIGH
    
    if (value1 <=800) {

    digitalWrite(ledPin3, HIGH);               //turn LED on
    Serial.println("LDR is bright, LED is ON");
    
   }
  else {

    digitalWrite(ledPin3, LOW);          //turn LED off
    Serial.println("---------------");
  }

 /*------Display Result------*/
    
    lcd.setCursor(0,1);
    lcd.print("Intens= ");
    lcd.print((int)lux);
    lcd.print(" Lux");
   
   Serial.println((int)lux);
   delay(500);

   
}
