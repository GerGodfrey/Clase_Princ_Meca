//Esclavo

#include <SoftwareSerial.h>
rxPin = 10;
txPin = 11;
SoftwareSerial xbee = SoftwareSerial(rxPin, txPin);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  xbee.begin(9600)
}
  int derecha = 0;
  int izquierda = 0;
  int movderecha = 0;
  int movizquierda = 0;
  int derechaTot = 0;
  int izquierdaTot = 0;
  int vel = 0;
  int angulo = 0;
  
void loop() {
  // put your main code here, to run repeatedly:
  //Aumento de velocidad
  delay(1000);
  Serial.println("-----------------");
  Serial.println("");
  Serial.print("DerechaTot");
  Serial.print(derechaTot);
  Serial.println("");
  Serial.print("IzquierdaTot");
  Serial.print(izquierdaTot);
  Serial.println("");
  
  

  if(derechaTot==0 || izquierdaTot ==0)
    vel =0;
    
  if(derechaTot==1 || izquierdaTot ==1)
    vel =50;

  if(derechaTot==2 || izquierdaTot ==2)
    vel =100;
    
  if(derechaTot==3 || izquierdaTot ==3)
    vel =150;

  if(derechaTot==4 || izquierdaTot ==4)
    vel =200;

  Serial.println("");
  Serial.println("velocidad:");
  Serial.println(vel);
  Serial.println("");
  
  if(derechaTot>0){
    movderecha = HIGH;
    movizquierda = LOW;
  }
  if(izquierdaTot>0)
  {
    movderecha = LOW;
    movizquierda= HIGH;
  }
  if(izquierdaTot == 0 )
  {
   movderecha = LOW;
   movizquierda = LOW;
   derechaTot = 0;
   izquierdaTot = 0;
   vel = 0;
  }
  
    
  Serial.println("");
  Serial.println("movderecha=");
  Serial.println(movderecha);
  Serial.println("");

  Serial.println("");
  Serial.println("movizquierda=");
  Serial.println(movizquierda);
  Serial.println("");

  
  digitalWrite(6,movderecha);
  digitalWrite(7,movizquierda);
  digitalWrite(3,vel);

}

  
void recibido(int a){


  
//  if(Wire.available()>0){
//    derecha = Wire.read();
//    Serial.println("");
//    Serial.print("dato0: ");
//    Serial.print(derecha);
//    Serial.println("");
//  }
//  
//  
//  if(Wire.available()<0){
//    izquierda = Wire.read();
//    Serial.println("");
//    Serial.print("dato1: ");
//    Serial.print(izquierda);
//    Serial.println("");
//  }

  if(xbee.available()){
    angulo = xbee.read();
    Serial.println("");
    Serial.print("Angulo: ");
    Serial.print(angulo);
    Serial.println("");
  }
  
  if(angulo > 0){
    derechaTot = derechaTot+1;
    izquierdaTot = izquierdaTot - 1;
    }
  if(angulo < 0){
    derechaTot = derechaTot - 1;
    izquierdaTot = izquierdaTot + 1;
    }
  else{
    if (derechaTot!=0){
      derechaTot = derechaTot - 1;
    }
    if(izquierdaTot!=0){
      izquierdaTot = izquierdaTot - 1;
    }
  }
}
