const byte ledPin = 10;
const byte interruptPin = 11;
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  digitalWrite(ledPin, state);
  delay(500);
}

void blink() {
  state = !state;
  Serial.print("El estado es: ");
  Serial.println(state);
  
}
