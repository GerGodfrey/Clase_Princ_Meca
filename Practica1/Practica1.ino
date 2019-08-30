/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int led2 = 7;
int analogPin = A0;
int val = 0;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  val = analogRead (analogPin);
  delay (100);
  Serial.print("Valor de res ");
  Serial.println(val);
  Serial.println(val>1000);
  
  if(val>1000){
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(7, HIGH);
    //delay(1000);               // wait for a second
  } 
  
  else{
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(7, LOW);
    //delay(1000);
  }    // wait for a second
}
