// so and s1 are for frequency scaling,s2and s3 to make combinations to activate specific color filters to pass color to photodiode that converts it to current
//then to converter that converts it into voltage or frequency ,the outpin is input for arduino.


#define S0 2
#define S1 4
#define S2 6
#define S3 7
#define sensorOut 9

int frequency1 = 0;
int frequency2 = 0;
int frequency3 = 0;


void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
 
  // Reading the output frequency,when color gets stronger it's high pulse width increase
  frequency1 = pulseIn(sensorOut, LOW);//we are going to print the low pulse width value so when color gets stronger adrop down happened in readings
  //Remaping the value of the frequency to the RGB Model of 0 to 255 as 0 indicates complete absence of color (detected by black paper) and 255 
  //is complete presence of color(detected by using pure color paper for each color of RGB)
  frequency1 = map(frequency1, 52,400,255,0);
  frequency1=constrain(frequency1,255,0);
  
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency1);//printing RED color frequency
  Serial.print("  ");
  delay(1000);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency2 = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency2 = map(frequency2, 70,394,255,0);
  frequency2=constrain(frequency2,255,0);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency2);//printing RED color frequency
  Serial.print("  ");
  delay(1000);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency3 = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency3 = map(frequency3, 54,256,255,0);
  frequency3=constrain(frequency3,255,0);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency3);//printing RED color frequency
  Serial.println("  ");
  delay(1000);
  if((frequency1>frequency3)&&(frequency2>frequency3))//if ((frequency1>200)&&(frequency2>150)&&(frequency3<170)),this range was detected from readings of color used
  {
    
    Serial.print("jaundice detected");
  }
}
