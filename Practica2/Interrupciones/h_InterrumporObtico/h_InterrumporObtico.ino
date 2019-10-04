// led pin
int led_pin = 13;

// interrupt pin
int interrupt_pin = 2;

// counter
float counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  pinMode(interrupt_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin), count, FALLING );
}

void loop() {
  asm (
    "inicio: \n\t"
    "sbi 0x05, 7 \n\t"
    
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"

    "cbi 0x05, 7 \n\t"

    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    
    "jmp inicio \n\t"
    
    "tiempo: \n\t"
    "LDI r22, 40 \n\t"
    "LOOP_3: \n\t"
    "LDI r21, 255 \n\t"
    "LOOP_2: \n\t"
    "LDI r20, 255 \n\t"
    "LOOP_1: \n\t"
    "DEC r20 \n\t"
    "BRNE LOOP_1 \n\t"
    "DEC r21 \n\t"
    "BRNE LOOP_2 \n\t"
    "DEC r22 \n\t"
    "BRNE LOOP_3 \n\t"
    "ret \n\t"
  );
}

void count() {
  counter = counter + 1;
  Serial.println(counter);
}


///*
//  Blink
//  Turns on an LED on for one second, then off for one second, repeatedly.
// 
//  This example code is in the public domain.
// */
// 
//// Pin 13 has an LED connected on most Arduino boards.
//// give it a name:
//int led = 13;
//int cont = 0;
//int button = 12;
////int valBut = 0;
//
//// the setup routine runs once when you press reset:
//void setup() {
//  Serial.begin(9600);
//  pinMode(led, OUTPUT);
//  cli();
//  DDRB =  DDRB | B11111111;
//  DDRD &= ~(1 << DDD1);
//  PORTD |= (1 << PORTD1);
//  EICRA |= (1 << ISC10);
//  EIMSK |= (1 << INT1);
//  sei();
//}
//
//ISR(INT1_vect) {
//  cont = cont + 1;
//  Serial.println(cont);
//
//}
//
//// the loop routine runs over and over again forever:
//void loop() {
//  Serial.println(cont);
//  asm volatile(
//    "inicio: \n\t" 
//    
//    "sbi 0x05,0x07 \n\t"
//    "call tiempo \n\t"
//    "cbi 0x05,0x07 \n\t"
//    "call tiempo \n\t"
//    "jmp main \n\t"
//    
//    "tiempo: \n\t"
//    "LDI r22, 80 \n\t"
//    "LOOP_3: \n\t"
//    "LDI r21, 253 \n\t"
//    "LOOP_2: \n\t"
//    "LDI r20, 255 \n\t"
//    "LOOP_1: \n\t"
//    "DEC r20 \n\t"
//    "BRNE LOOP_1 \n\t"
//    "DEC r21 \n\t"
//    "BRNE LOOP_2 \n\t"
//    "DEC r22 \n\t"
//    "BRNE LOOP_3 \n\t"
//    "ret \n\t"
//  );
//}
