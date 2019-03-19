// Servo Declarations 
#include <Servo.h>
Servo myservo;
//Sensors 
int pressure = A0 ; 
int Vo ;
//Gyro 
#include<Wire.h>
const int MPU_addr=0x68;
int16_t axis_X,axis_Y,axis_Z;
int minVal=265;
int maxVal=402;
double x;
double y;
double z;
 
void setup() 
{
  //Servo Attachment
  myservo.attach(9);
  myservo.attach(8);
  //Gyro Attachment
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);

}

void loop() 
{
  //Gyro Logic 
  
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);
  axis_X=Wire.read()<<8|Wire.read();
  axis_Y=Wire.read()<<8|Wire.read();
  axis_Z=Wire.read()<<8|Wire.read();
  int xAng = map(axis_X,minVal,maxVal,-90,90);
  int yAng = map(axis_Y,minVal,maxVal,-90,90);
  int zAng = map(axis_Z,minVal,maxVal,-90,90);
  x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
  y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
  z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
  Serial.print("Angle of inclination in X axis = ");
  Serial.print(x);
  Serial.println((char)176);
  Serial.print("Angle of inclination in Y axis= ");
  Serial.print(y);
  Serial.println((char)176);   
  Serial.println("-------------------------------------------");
  delay(1000);
  //Sensor Logic 
  Vo = analogRead(pressure);
  Serial.println (Vo);
  /*
   * 
   * some Logic for calculating pressure  
   */
   //Some Logic for servos 
  
}
