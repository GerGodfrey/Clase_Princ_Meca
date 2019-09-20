int led=5;
int btn=A9;
int cont=0;
int btns=0;
int band=0;
void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(btn, INPUT);
  
  cli();
  DDRD = B11111110;
  PORTD |= (1 << PORTD1);
  EICRA |= (1 << ISC11);
  EIMSK |= (1 << INT1);
  sei();
}


void loop(){
  btns=analogRead(btn);
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
