int redled = 7 ;
int yellowled = 4 ; 
int greenled = 13 ; 

void setup() {
  Serial.begin(9600);
  pinMode(redled,OUTPUT);
  pinMode(yellowled,OUTPUT);
  pinMode(greenled,OUTPUT);
}
void loop() {
  Serial.println("A2");
  Serial.println(analogRead(A2));
  Serial.println("A1");
  Serial.println(analogRead(A1));
  Serial.println("A3");
  Serial.println(analogRead(A3));
  if (analogRead(A2) > 50 && analogRead(A1) <50  && analogRead(A3) <50){
    Serial.println ("Low Level"); 
    digitalWrite(redled,HIGH);
    digitalWrite(yellowled,LOW);
    digitalWrite(greenled,LOW);

    }
  else if (analogRead(A2) > 50 && analogRead(A1) > 50 && analogRead(A3) < 50 ){
    Serial.println ("Average Level"); 
    digitalWrite(yellowled,HIGH);  
    digitalWrite(redled, LOW);
    digitalWrite(greenled,LOW);
     
    }
   else if (analogRead(A2) > 50 && analogRead(A1) > 50 && analogRead(A3) > 50 ){
    Serial.println ("High Level"); 
    digitalWrite(yellowled,LOW);  
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
   }
   else {
    digitalWrite(yellowled,LOW);  
    digitalWrite(redled, LOW);
    digitalWrite(greenled, LOW);
    }  
    
}       
