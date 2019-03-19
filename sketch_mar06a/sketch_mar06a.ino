int IR_pin = A1 ;


void setup() {
  Serial.begin(9600);

}

void loop() {
  int IR = analogRead (IR_pin ) ;
  Serial.print ("Value :"); 
  Serial.println (IR) ; 
  delay(1000);

}
