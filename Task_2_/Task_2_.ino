// Servo Declarations
#include <Servo.h>
Servo myservo_right;
Servo myservo_left ;
//Sensors
int pressure = A0 ;
int Vo ;

int right_wing = 9 ;
int pos_right = 90 ;
int left_wing = 10 ;
int pos_left = 90 ;

//Gyro
#include<Wire.h>
const int MPU_addr = 0x68;
int16_t axis_X, axis_Y, axis_Z;

int minVal = 265;
int maxVal = 402;

double x;
double y;
double z;

//Motors
int motor = 6;
int led = 8;
//Functions
void setup()
{
  
  //Servo Attachment
  myservo_right.attach(right_wing);
  myservo_left.attach(left_wing);

  //Gyro Attachment
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  //MOTOR
  pinMode(motor , OUTPUT);
  pinMode(led , OUTPUT);
}

void loop()
{
  
  //Sensor Logic
  Vo = analogRead(pressure);
  Serial.println (Vo);
  
  //Gyro Logic

  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);
  axis_X = Wire.read() << 8 | Wire.read();
  axis_Y = Wire.read() << 8 | Wire.read();
  axis_Z = Wire.read() << 8 | Wire.read();
  int xAng = map(axis_X, minVal, maxVal, -90, 90);
  int yAng = map(axis_Y, minVal, maxVal, -90, 90);
  int zAng = map(axis_Z, minVal, maxVal, -90, 90);
  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);
  Serial.print("Angle of inclination in X axis = ");
  Serial.print(x);
  Serial.println((char)176);
  Serial.print("Angle of inclination in Y axis= ");
  Serial.print(y);
  Serial.println((char)176);
  Serial.println("-------------------------------------------");
  delay(1000) ;  
  digitalWrite(led , HIGH);
  if (Vo > 0 ) {
    
    //LOGIC
    if ( x >= 20 && x<=50 )
    {
      
      //turn right 
      myservo_left.write(pos_left +40);
      myservo_right.write(pos_right+30);
     }
     else if (x >= 328 && x<=350)
     {
            //Turn left
      myservo_left.write(pos_left - 40) ;
      myservo_right.write(pos_right -30) ;
     }
     else if (y >= 10 && y <= 30 ) 
     {
      //pitch down 
      myservo_left.write(pos_left +50) ; 
      myservo_right.write(pos_right-50);

      }
     else if (y >= 300 && y<= 350) 
     {
            //pitch up
      myservo_left.write(pos_left -30) ; 
      myservo_right.write(pos_right+30);
      
      } 
     else {
      myservo_left.write(pos_left);
      myservo_right.write(pos_right);
      }
      //Fadel code el FSR
      //Motor
    }
    //get above water
    else if (Vo > 1010 ) {
      //Get out 
      
      myservo_right.write(pos_right);
      myservo_left.write(pos_left); 
      } 
  
    
}
