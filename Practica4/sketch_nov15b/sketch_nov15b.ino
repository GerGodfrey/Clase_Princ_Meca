#include <PID_v1.h>
#define PIN_INPUT 7
#define PIN_OUTPUT 9

int speeddata[7],speedmax,i; 

double Kp=3.6324, Ki=1452.96, Kd=0.00227025;

PID nuevoPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  TCCR1B = TCCR1B & B11111000 | B00000010; 
  
  Serial.begin(9600);

  Input=map(frecuencia,0,150,0,255); // map input

  Setpoint = 100
  
  nuevoPID.SetMode(AUTOMATIC);
}

void loop()
{
  prueba=pulseIn(PIN_INPUT,HIGH,250000);
  if (prueba==0){
    frecuencia=1;
  } 
  else{
    frecuencia = 1/(2*prueba*pow(10,-6));
  } 
  for(i=6;i>=0;i--){
    velocidades[i]=velocidades[i-1];
  }

   velocidades[0]=frecuencia; 
   velocidadMax=encuentraMaxima();
   
   
   Input=map(frecuencia,0,150,0,255); 
 
   nuevoPID.Compute();
 
   analogWrite(PIN_OUTPUT, Output); 
 
 
}

int encuentraMaxima(){
  velocidadMax=velocidades[0];
  for(i=0;i<=6;i++){ 
  if (velocidades[i]>velocidadMax){velocidadMax=velocidades[i];}
  }
  return velocidadMax;
}
