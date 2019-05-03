int Time (int x , int y ) 
{
  /* 0X : 0Y time format */
  while ( 0 <= x <= 12 && 0 <= y <= 59 ) {
    y++ ; 
    delay(1000);
    if (y == 59){
      y = 0 ; 
      ++x; 
    }
    else if ( x == 12 && y == 59 ) {
      x = 0 ;
      y = 0 ; 
    }
  }
  Serial.print(x);
  Serial.print(":");
  Serial.println(y);
}



void setup() {
  //not needed 
}

void loop() {
  Time (5 , 0 ) ; 
}
