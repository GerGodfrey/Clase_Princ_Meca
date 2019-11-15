//Maestro

#include <Wire.h>
#include <math.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);

}

double datoX = 0;
double datoY = 0;
double datoZ = 0;

int datoX1 = 0;
int datoY1 = 0;
int datoZ1 = 0;

int datoX2 = 0;
int datoY2 = 0;
int datoZ2 = 0;

float angulo1 = 0;
float angulo2 = 0;
float anguloF = 0;

int enviar = 0;


void loop() {

  

  datoX1 = analogRead(A0);



  datoY1 = analogRead(A1);



  datoZ1 = analogRead(A2);




  
  Serial.println("---------------");
  Serial.println("X=");
  Serial.println(datoX1);
  
  Serial.println("Y=");
  Serial.println(datoY1);
  
  Serial.println("Z=");
  Serial.println(datoZ1);
  Serial.println("---------------");

//  //angulo1 = (datoY1/datoX1);
//  angulo1 = atan2(datoY1,datoZ1);
//
//  //angulo2 = (datoY2/datoZ2)*10;
//  angulo2 = atan2(datoY2,datoZ2);
//
//  anguloF = (angulo2 - angulo1)*80;
//  
//  Serial.println("---------------");  
//  Serial.println("---------------");
//  Serial.print("Angulo1:");
//  Serial.println(angulo1);
//  Serial.print("Angulo2:");
//  Serial.println(angulo2);
//  Serial.print("AnguloF:");
//  Serial.println(anguloF);
//  Serial.println("---------------");  
//  Serial.println("---------------");
//  
//
  enviar = datoY1;
  Serial.println("---------------");  
  Serial.println("---------------");
  Serial.println("Enviar:");  
  Serial.println(enviar);
  Serial.println("---------------");  
  Serial.println("---------------");
  
  Wire.beginTransmission(1);  
  
  Wire.write(enviar);
  
  Wire.endTransmission(1);

  delay(1000);
}
