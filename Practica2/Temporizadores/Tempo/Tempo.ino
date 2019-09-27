int led=11;
int ban=0;
int cont=0;

void setup(){
  //Configuración del timer1 a 1Hz
  DDRB = DDRB | B11111111;
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;//inicializamos el contador en 0
  // Registro de comparación a 1Hz
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (<65536)
  // modo CTC 
  TCCR1B |= (1 << WGM12);
  // preescalador de 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);  //Se cambian dos registros porque se manejan 16 bits
  // Habilitamos la interrupción por comparación
  TIMSK1 |= (1 << OCIE1A);
  sei();
  
 }
ISR(TIMER1_OVF_vect){
  //Simulación del semaforo mediante interrupciones del contador
  cont++;
  Serial.print(cont);
  Serial.print("dd");
}
void loop(){
  if(cont=12){
    cont=1;
  }
  if(cont=1){
    asm volatile(
      //Duracion de 6 segundos en el led rojo
      "sbi 0x05,0x04 \n\t" //digitalwrite (high)
      "sbi 0x05,0x01 \n\t" //No sirve debe prender el semaforo del segundo semaforor
     
      );
  }
  if(cont=4){
     asm volatile(
      "cbi 0x05,0x01 \n\t"
     );
  }
  if(cont=6){
     asm volatile(
      "cbi 0x05,0x04 \n\t" //digitalwrite (low)
      "sbi 0x05,0x05 \n\t"
    ); 
  }

  if(cont=7){
    asm volatile(
      "cbi 0x05,0x05 \n\t"
      "sbi 0x05,0x06 \n\t"
    );
  }
  if(cont=11){
    asm volatile(
      "cbi 0x05,0x06 \n\t"
    );
  }
  
}
