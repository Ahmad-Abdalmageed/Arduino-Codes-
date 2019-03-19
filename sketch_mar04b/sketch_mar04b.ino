int ThermistorPin = A0;
float Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

int laserPin = 10;

void setup() {
Serial.begin(9600);
pinMode (laserPin, OUTPUT); // define the digital output interface 13 feet
}

void loop() {
  digitalWrite (laserPin, HIGH); // Turn Laser On
   

  Vo = (analogRead(ThermistorPin)/1023 )*5;
  Serial.print (Vo);
  ;
  
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;

  Serial.print("Temperature: "); 
  Serial.print(Tc);
  Serial.println(" C");   

  delay(500);
}
