////////////////////////////////////////////////////////////////////////////////////
//Color Sensor 


#define S0 12
#define S1 13
#define S2 0
#define S3 1
#define sensorOut 8
int frequency = 0;
int R = 0 ;
int G = 0 ; 
int B = 0 ; 

//////////////////////////////////////////////////////////////////////////////////
// Lcd 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);





//////////////////////////////////////////////////////////////////////////////////
////Weight 
//int fsrPin = A0;     // the FSR and 10K pulldown are connected to A2
//int fsrReading;     // the analog reading from the FSR resistor divider
//int fsrVoltage;     // the analog reading converted to voltage
//unsigned long fsrResistance;  // The voltage converted to resistance, can be very big so make "long"
//unsigned long fsrConductance; 
//long fsrForce;       // Finally, the resistance converted to force
//
//long Vcc     = 5000;    // 5V=5000mV, 3.3V = 3300 mV
//float voltageMax = 0.98 * Vcc;
//float forceMax = 100.0;
//
//float force_value;
//float mass_reading ;
//
//void FSRRead();


//////////////////////////////////////////////////////////////////////////////////
////Humedity 
//
//
//#include "DHT.h"
//
//DHT dht;
//



//////////////////////////////////////////////////////////////////////////////////

void setup() 
{
//  //LCD 
//    Serial.begin(9600);
//    lcd.begin(16, 2);
  //Color 
     pinMode(S0, OUTPUT);
     pinMode(S1, OUTPUT);
     pinMode(S2, OUTPUT);
     pinMode(S3, OUTPUT);
     pinMode(sensorOut, INPUT);
     
     // Setting frequency-scaling to 20%
     digitalWrite(S0,HIGH);
     digitalWrite(S1,LOW);
    
     // DHT 
     
     Serial.println();
     Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");

//     dht.setup(A1); // data pin 2

     // set up the LCD's number of columns and rows:
//     lcd.begin(16, 2);
//  

}

void loop() 
{
//    FSRRead();
//    delay(500);

  
   // Setting red filtered photodiodes to be read
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
    //Remaping the value of the frequency to the RGB Model of 0 to 255
    // Printing the value on the serial monitor
    
    Serial.print("R= ");//printing name
    Serial.print(frequency);//printing RED color frequency
    Serial.print("  ");
    R = frequency ; 
   
    
    delay(100);
  // Setting Green filtered photodiodes to be read
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
  // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  // Printing the value on the serial monitor
  
    Serial.print("G= ");//printing name
    Serial.print(frequency);//printing RED color frequency
    Serial.print("  ");
    G = frequency ; 
 
    delay(100);
  
  // Setting Blue filtered photodiodes to be read
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
  // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  // Printing the value on the serial monitor
 
     
    Serial.print("B= ");//printing name
    Serial.print(frequency);//printing RED color frequency
    Serial.println("  ");

    B = frequency ; 
    
  
    delay(1000);
//This Code uses lines above to predict juandice 
//  delay(dht.getMinimumSamplingPeriod());
//
//  float humidity = dht.getHumidity();
//  float temperature = dht.getTemperature();
//  lcd.setCursor(0, 1);
//  lcd.print(humidity) ;
//  lcd.setCursor(1, 1);
//  
//  lcd.print(temperature) ;
//  
//  Serial.print(dht.getStatusString());
//  Serial.print("\t");
//  Serial.print(humidity, 1);
//  Serial.print("\t\t");
//  Serial.print(temperature, 1);
//  Serial.println("\t\t");
//
//
//  delay(1000) ;
//  
//  //Calculate mass
//  if (mass_reading < 2.5 ) 
//  {
//    Serial.println("Low Weight , one symptom of jaundice") ;
//    delay(100);
//    if( R > B && G > B ) 
//    {
//      Serial.println("Yellow Color detected");
//      Serial.println("Turn on Jaundice Treatment");
//      
//    }
//  }
//  
    
}
/*
void FSRRead()
{
  fsrReading = analogRead(fsrPin);  
  // Serial.print("Analog1 reading = ");
  // Serial.println(fsr1Reading);
 
  // analog voltage reading ranges from about 0 to 1023 which maps to 0V to 5V (= 5000mV)
  fsrVoltage = map(fsrReading, 0, 1023, 0, 5000);
  // Serial.print("Voltage reading in mV = ");
  // Serial.println(fsr1Voltage);  
 
  if (fsrVoltage == 0) {
    Serial.println("No pressure ");  
  } else {
    // The voltage = Vcc * R / (R + FSR) where R = 10K and Vcc = 5V
    // so FSR = ((Vcc - V) * R) / V        yay math!
    fsrResistance = 5000 - fsrVoltage;     // fsrVoltage is in millivolts so 5V = 5000mV
    fsrResistance *= 10000;                // 10K resistor
    fsrResistance /= fsrVoltage;
    // Serial.print("FSR1 resistance in ohms = ");
    // Serial.println(fsr1Resistance);
    
    force_value = (forceMax/voltageMax) * fsrVoltage;
    if ( fsrVoltage < voltageMax ) {
           if ( force_value <= 1.00 ) {
              fsrForce = 0.0;            
           } else {
             fsrForce = log10(force_value);  
           }
        } else {
           fsrForce = log10(forceMax);
           // Serial.print("Cut off activated for FSR");
        }
    Serial.print("Force in Newton = ");
    Serial.print(force_value);
    Serial.print(" ");
    Serial.print("Mass in Kg = ");
    mass_reading = force_value / 9.8 ;
    Serial.println(mass_reading);
      
  delay(200);

        
  }
}*/
