int ledPin = 10;
int interruptPin = 11;
volatile byte state = LOW;
int buttonState = 0;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
}      

void loop() {
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  delay(1000);
}

void blink() {
  state = !state;
  Serial.println("El estado es: ");
  Serial.println(state);
}
