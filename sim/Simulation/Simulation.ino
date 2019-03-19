//Declarations & Libraries

#include <Servo.h>
Servo myservo;

//Pins
int ThermistorPin = A0;
int IR_pin = A1 ;
int fan_relay = 8 ;
int water_pump = 4 ;

//Thermistor`s equation
int Vo;
float R1 = 10000 ;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

//Constants
int fire_temp = 70 ;
int fire_detection = 500 ;
int pos = 0 ;

void setup() {
  //Beginig  transmission
  Serial.begin(9600);
  //Identifying pins
  pinMode(fan_relay , OUTPUT);
  pinMode(water_pump , OUTPUT);
  //Servo attachment
  myservo.attach(9);

}

void loop() {
  // Thermistor`s Setup

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0 );
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Tc = T - 273.15;

  //Thermistor`s OUTPUT

  /* Serial.print("Temperature: ");
    Serial.print(Tc);
    Serial.println(" C");
    delay(500);*/

  //IR OUTPUT

  int IR = analogRead (IR_pin ) ;
  /* Serial.print ("Value :");
    Serial.println (IR) ; */



  // OUR LOGIC

  if (Tc >= fire_temp )                       // Fire in the room
  {
    //Fan is on and Search for the fire
    digitalWrite(fan_relay , HIGH) ;
    digitalWrite(9,HIGH);
   /* for (pos = 0; pos <= 90; pos += 1)
    {
      myservo.write(pos);
      delay(15);
    }
    for (pos = 90; pos >= 0; pos -= 1)
    {
      myservo.write(pos);
      delay(15);
    }
*/
    if (IR == HIGH )
    {
      //Serial.print ("Found Fire");
     // myservo.detach();
     digitalWrite(9,LOW);                     //Stop servo
      digitalWrite(water_pump , HIGH);        // Water Pump on
    }
  }
  else
  {
    //Serial.print ("NO FIRE" ) ;
    digitalWrite(water_pump , LOW);             //Turn the pump off
    digitalWrite(fan_relay ,  LOW);             //Turn the fan off

    //myservo.attach(9) ;
    digitalWrite(9,HIGH);                       //Reattach Servo

  }

}
