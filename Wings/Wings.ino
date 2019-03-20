
#include <Servo.h>
Servo myservo_right;
Servo myservo_left ; 
int pos ;
int right_wing = 9 ;
int left_wing = 10 ;

void setup() {
  myservo_right.attach(10) ; 
}

void loop() 
{
  for (pos = 0 ; pos <= 180 ; ++pos ) 
  {
    myservo_right.write(pos);
    delay(10);
  }
  
  for (pos = 180 ; pos >= 0 ; --pos ) 
  {
    myservo_right.write(pos);
    delay(10);
  }
  
}
