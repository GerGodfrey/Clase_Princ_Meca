//*Pin de salida del led
const int ledPinV2 = 13;
const int boton = 2;
volatile int ISRCounter = 0;
volatile byte state = LOW;
unsigned int lec = 0;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(ledPinV2, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
  Serial.begin(9600);
  cli();
  DDRD &= ~(1 << DDD1);
  PORTD |= (1 << PORTD1);
  EICRA |= (1 << ISC10);
  EIMSK |= (1 << INT1);
  sei();//set global interrupt enable  
  attachInterrupt(digitalRead(boton), interruptCount, RISING);
}

void loop() {

int IdStatusA = analogRead(ledPinV2);
lec = analogRead(A0);
//Serial.println(lec);
 
//Serial.println(IdStatusA);
  delay(250);
  //PIN VERDDE 1 CADA 1 SEGUNDO
    digitalWrite(ledPinV2, HIGH);
         delay(500);
    digitalWrite(ledPinV2, LOW);
         delay(500);

}
  
void interruptCount()
{
    ISRCounter++;
    
    Serial.println(ISRCounter);
}
