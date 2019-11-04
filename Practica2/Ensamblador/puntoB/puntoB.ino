  int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(led4, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, HIGH);
  delay(70);
  digitalWrite(led4, LOW);
  delay(230);
  digitalWrite(led4, HIGH);
  digitalWrite(led3, LOW);
  delay(400);
  digitalWrite(led4, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led2, LOW);
  delay(800);
  digitalWrite(led4, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW);
  delay(1000);
  
}
