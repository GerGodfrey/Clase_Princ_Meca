//Maestro

#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  pinMode(30,INPUT);
  pinMode(31,INPUT);

}

byte dato0 = 0;
byte dato1 = 0;


void loop() {

  dato0 = digitalRead(30);
  dato1 = digitalRead(31);
  
  Wire.beginTransmission(1);
  
  Wire.write(dato0);
  Wire.write(dato1);
  
  Wire.endTransmission(1);

  delay(1000);
}
