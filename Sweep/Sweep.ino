/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo myservo2;
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(9);
  Serial.begin(9600);
}

void loop() {
  int pos2 ;
  for (pos = 0,pos2 = 180; pos <= 180,pos2>=0; pos += 10,pos2-=10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);
    myservo2.write(pos2);
    // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(1000);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    myservo2.write(pos);// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
