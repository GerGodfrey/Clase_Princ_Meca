//Maestro

#include <SoftwareSerial.h>
#include <math.h>
int rxPin = 3;
int txPin = 4;
SoftwareSerial xbee = SoftwareSerial(rxPin, txPin);

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  xbee.begin(9600);
  Serial.begin(9600);
  
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

int enviar;


void loop() {

  

  datoX1 = analogRead(A0);



  datoY1 = analogRead(A1);



  datoZ1 = analogRead(A2);




  
//  Serial.println("---------------");
//  Serial.println("X=");
//  Serial.println(datoX1);
//  
//  Serial.println("Y=");
//  Serial.println(datoY1);
//  
//  Serial.println("Z=");
//  Serial.println(datoZ1);
//  Serial.println("---------------");
//
//
  enviar = datoY1;
//  Serial.println("---------------");  
//  Serial.println("---------------");
//  Serial.println("Enviar:");  
//  Serial.println(enviar);
//  Serial.println("---------------");  
//  Serial.println("---------------");
  
//  xbee.beginTransmission(1);  

  if(xbee.available()){
    xbee.write(enviar);
    Serial.println("Enviar:");  
    Serial.println(enviar);  
  }
  
  
  
// xbee.endTransmission(1);

  delay(2000);
}
