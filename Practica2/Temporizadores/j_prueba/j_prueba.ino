int led = 13;
int ban = 0;
int cont = 0;

void setup() {
  Serial.begin(9600);
  DDRB = DDRB | B11111111; //data direction register B: Inputs 0-4 , 6-7, Output 5 (0 entrada y 1 salida)
  DDRD = DDRD | B11111111; 
  cli  ();
  TCCR1B = 0;
  TCCR1A = 0;
  TCCR1B |= (1 << CS12);
  TCNT1 = 0;
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (<65536)
  TIMSK1 |= (1 << TOIE1);
  sei ();
}
ISR(TIMER1_OVF_vect){
  cont = cont +1;
  Serial.print(cont);
}

void loop() {
//  asm volatile (
//    "sbi 0x05,0x04 \n\t" //Rojo C
//    "sbi 0x05,0x06 \n\t" //verde C
//    "sbi 0x05,0x05 \n\t" //Amarillo C
//    "sbi 0x05,0x00 \n\t" //Verde F
//    "sbi 0x05,0x01 \n\t" //Amarillo F
//    "sbi 0x05,0x02 \n\t" //Rojo F
//    );
  if(cont==12){
    cont=1;
  }
  if(cont==1){
    asm volatile(
      //Duracion de 6 segundos en el led rojo
      "sbi 0x05,0x06 \n\t" //P Verde C
      "sbi 0x05,0x02 \n\t" //P Rojo F
      );
  }
  if(cont==4){
     asm volatile(
      "cbi 0x05,0x06 \n\t" //A Verde C 
      "sbi 0x05,0x05 \n\t"// P Amarillo C
     );
  }
  if(cont==6){
     asm volatile(
      "cbi 0x05,0x05\n\t" //A Amarillo C
      "cbi 0x05,0x02 \n\t" //A Rojo F
      "sbi 0x05,0x00 \n\t" //P Verde F 
      "sbi 0x05,0x04 \n\t" //P Rojo C
    ); 
  }

  if(cont==7){
    asm volatile(
      "cbi 0x05,0x00 \n\t" //A Verde F
      "sbi 0x05,0x01 \n\t"// P Amarillo F
    );
  }
  if(cont==11){
    asm volatile(
      "cbi 0x05,0x01 \n\t"//A Amarillo F
      "cbi 0x05,0x04 \n\t" //A Rojo C
      "sbi 0x05,0x02 \n\t"// P Rojo F
      "sbi 0x05,0x06 \n\t"// P Verde C
      //"sbi 0x05,0x05 \n\t"
    );
  } 
}
