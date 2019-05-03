// LCD
  
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// time

#include "RTClib.h"
#include <Wire.h>         // this #include still required because the RTClib depends on it

RTC_Millis rtc;
// leds 
int timeled = 6 ; 


// buzzer 

int buz = 7 ;

//Servo 

#include <Servo.h> 
Servo myservo;
int pos = 0;

//button 

int button = 13 ; 
int butVal = 0 ;  

//sensor 

int sensorPin = A0 ; 
int sensorVal = 0 ;

//Ma3ad El Dawa 

int h = 14 ;
int m = 2 ;
int s = 0 ; 

// Laser 

int laser = 8 ; 

int flag = 1;

void setup() {
  Serial.begin(9600);
  //myservo.write(90);
  //LCD
  lcd.begin(16, 2);
  
  // time 
  rtc.begin(DateTime(F(__DATE__), F(__TIME__))); 
  
  //sensor 
  pinMode(sensorPin, INPUT);
  
  //buzzer
  pinMode(buz, OUTPUT); 
  
  //Servo
  myservo.attach(9);
  myservo.write(0);
  //Laser 
  pinMode(laser , OUTPUT);
  
  //button 
  pinMode(button , INPUT);
  digitalWrite(buz, LOW);
  pinMode(timeled , OUTPUT) ;
}

void loop() {
  //digitalWrite(buz , LOW);
  myservo.write(pos);
  //RTC output
  DateTime now = rtc.now();
  lcd.setCursor(0, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  
 //sensor
 //delay(3000);
  sensorVal = analogRead(sensorPin);
  Serial.println(sensorVal);
  
  //laser
  digitalWrite(laser , HIGH);
  
  //push button 
  butVal=digitalRead(button);
  Serial.println(butVal);
      
  //logic
  delay(300);
  if (now.hour() == h && now.minute()== m && now.second()<=6 && sensorVal >= 100) {
    Serial.print("1 condition ");
    digitalWrite(buz,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Hands on X");
    // It`s the pill time 
    // Patient should put his hand on the mark so that he could take his pill 
  } else if(sensorVal < 100) 
  {
    Serial.print("2 condition ");
    digitalWrite(buz, LOW);
    delay(300);   
    myservo.attach(9);
    pos += 10;
    lcd.clear();
    DateTime now = rtc.now();
    lcd.setCursor(0, 0);
    lcd.print(now.hour());
    lcd.print(":");
    lcd.print(now.minute());
    lcd.print(":");
    lcd.print(now.second());  
    delay(200);
  }
  if (now.hour() == h && now.minute()== m+1 && flag == 1) {
    Serial.print("3 condition ");
    digitalWrite(buz , HIGH);

    //lcd
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Push if You ");
    lcd.setCursor(0,1);
    lcd.print("Took your pill?"); 

    while(flag){
      Serial.print("button");
      Serial.println(butVal);
      butVal = digitalRead(button);
    
      if (butVal == 1 ) {
        lcd.clear();
        lcd.print("Get Well <3");
        digitalWrite(timeled,HIGH);
        digitalWrite(buz, LOW);
        delay(3000);
        lcd.clear() ;
        flag = 0;
        myservo.detach();
      }
    }
    digitalWrite(buz, LOW);
  }
}  
