int pressure = A0 ; 
int Vo ;


void setup() {
  Serial.begin(9600); 
}

void loop() {
  
  Vo = analogRead(pressure);
  Serial.print("Pressure : ") ;
  Serial.println(Vo);
  delay (200);
  
}
