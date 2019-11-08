int ledPin = 10;
const byte interruptPin = 2;
volatile byte state = LOW;
int buttonState = 0;
int contador = 0 ;
void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), count, FALLING);
}

void loop() {
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  delay(1000);
}

void count() {
  contador = contador + 1;  
  Serial.println(contador);
}
