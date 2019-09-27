int led=20;
int ban=0;

void setup(){
  //Configuración del timer1 a 1Hz
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
 }
ISR(TIMER1_OVF_vect){
  //Simulación del semaforo mediante interrupciones del contador

}
void loop(){
  
}
