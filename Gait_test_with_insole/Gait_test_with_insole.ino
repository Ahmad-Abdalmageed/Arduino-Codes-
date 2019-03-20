//Written by Ahmad Mahdy
//Task_2 Measurement
//Measuring Gait using insole
//Hardware used : 3FSR,Gyroscope,Bluetooth modul

#include <Wire.h> //Required to MPU-6050 (Gyroscope)

//intilizing pins
char fsr_1 = A0;  //FSR1 connected to A0 PIN
char fsr_2 = A1;  //FSR2 connected to A1 PIN
char fsr_3 = A2;  //FSR3 connected to A2 PIN

//////////////////////////FSR ///////////////////////////
int fsr_1Reading, fsr_2Reading, fsr_3Reading;
long Vcc     = 5000;    // 5V=5000mV, 3.3V = 3300 mV
float voltageMax = 0.98 * Vcc; //max volt assumed to be 98%
float forceMax = 100.0;   //Max force from Internet

//Intilizing Gyroscope (copied)
const int MPU_addr = 0x68;  //Adrress of Gyro
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ, xAng, yAng, zAng;

int minVal = 265;
int maxVal = 402;

double z; //Gyro Angle

void setup() {
  ////////////////////Gyro. Setup///////////////////////////////
  Wire.begin(); //Begin the wire communication
  Wire.beginTransmission(MPU_addr); //Begin, Send the slave address (hex 68)
  Wire.write(0x6B); //Make the reset ( 0 in 6B register)
  Wire.write(0);
  Wire.endTransmission(true); //End the transmission

  Serial.begin(9600);
  /////////////////////////EXCEL SHEET Setup/////////////////////
  Serial.println("CLEARDATA"); //Clear Excel Sheet
  Serial.println("LABEL,Time,Timer,Angle,Heel,FirstMT,LastMT"); //Write Labels
  Serial.println("RESETTIMER"); //Reset Timer

}

void loop() {
  Serial.print("DATA,TIME,TIMER,"); //Writes the time in the first column and the time since the measurement started in the second column

  //////////////////////////Gyro. Input///////////////////////////
  Wire.beginTransmission(MPU_addr); //Begin Transmission with Gyro Address
  Wire.write(0x3B);                 //Read from register (Hex 3B)
  Wire.endTransmission(false);      //Restart Transmission (FALSE)
  Wire.requestFrom(MPU_addr, 6, true);  // Request from Gyro data (6 byte "registers")
  AcX = Wire.read() << 8 | Wire.read(); // Read recieved data (1 byte each time)
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  int xAng = map(AcX, minVal, maxVal, -90, 90); //re-scaling [-90,90]
  int yAng = map(AcY, minVal, maxVal, -90, 90);
  int zAng = map(AcZ, minVal, maxVal, -90, 90);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);  //from RAD to DEG
  //Serial.print("Ankle angle = ");
  Serial.print(z); //Prints Ankle angle
  Serial.print(",");

  /////////////////FSR Input////////////////////
  fsr_1Reading = analogRead(fsr_1); //Heel Pressure
  //Serial.print("Heel Pressure = ");
  fsr_1Reading = map(fsr_1Reading, 0, 1023, 0, 5000); // scaling from analog to voltage
  fsr_1Reading = (forceMax / voltageMax) * (fsr_1Reading); //from voltage to froce
  Serial.print(fsr_1Reading); //Prints Heel pressure
  Serial.print(",");

  fsr_2Reading = analogRead(fsr_2); //Right (First MT) Pressure
  //Serial.print("First MT Pressure = ");
  fsr_2Reading = map(fsr_2Reading, 0, 1023, 0, 5000);
  fsr_2Reading = (forceMax / voltageMax) * (fsr_2Reading);
  Serial.print(fsr_2Reading); //Prints First MT pressure
  Serial.print(",");

  fsr_3Reading = analogRead(fsr_3); //Left (Last MT) Pressure
  //Serial.print("Last MT Pressure = ");
  fsr_3Reading = map(fsr_3Reading, 0, 1023, 0, 5000);
  fsr_3Reading = (forceMax / voltageMax) * (fsr_3Reading);
  Serial.println(fsr_3Reading); //Prints Second MT pressure

  //Serial.println("-----------------------------------------");
  delay(1000);
}
