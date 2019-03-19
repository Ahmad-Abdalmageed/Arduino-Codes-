int IR = A0 ; 

void setup() {
  
Serial.begin(9600);
}


void loop() {
  int detection = analogRead (IR ) ;
  Serial.print ("Value :"); 
  Serial.println (detection) ; 
  delay (1000) ; 
}
