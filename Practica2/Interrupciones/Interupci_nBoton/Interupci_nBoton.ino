int led=13;
int btn=2;
int cont=0;
int btns=0;
int band=0;
void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(btn, INPUT);
  
  cli();
  DDRD &= ~(1 << DDD1);
  PORTD |= (1 << PORTD1);
  EICRA |= (1 << ISC10);
  EIMSK |= (1 << INT1);
  sei();
}


void loop(){
  //btns=analogRead(btn);
  //Rutina de tiempo que hace parpadear 1 led a 1 Hz por segundo
  //if(btns>100){
    //Serial.println("Hola");
  //}
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}

//Rutina para contar cada que se oprime el botón
ISR(INT1_vect){
    cont++;
    Serial.println("EL CONTADOR ES:");
    Serial.println(cont);
}
