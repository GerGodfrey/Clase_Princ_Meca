void setup() {
  
  Serial.begin(9600);
  DDRB = DDRB | B11111111; //data direction register B: Inputs 0-4 , 6-7, Output 5 (0 entrada y 1 salida)
  DDRD = DDRD | B11111111;  
}

void loop() {
  asm volatile(
    //Duracion de 6 segundos en el led rojo
    "sbi 0x05,0x04 \n\t" //digitalwrite (high)
    "sbi 0x05,0x01 \n\t" //No sirve debe prender el semaforo del segundo semaforor
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "cbi 0x05,0x01 \n\t" //apaga el verde del segundo semaforo
    "call tiempo \n\t"
    "call tiempo \n\t"
    //Duración de 1 segundo led amarillo
    "cbi 0x05,0x04 \n\t" //digitalwrite (low)
    "sbi 0x05,0x05 \n\t"
    "call tiempo \n\t"
    //Duracion 4 segundos led verde
    "cbi 0x05,0x05 \n\t"
    "sbi 0x05,0x06 \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "cbi 0x05,0x06 \n\t"
    "call tiempo \n\t"

    "jmp main \n\t"

    //Tiempo nos da 2 segundo de delay
    "tiempo: \n\t"
    "LDI r22, 255 \n\t"
    "LOOP_3: \n\t"
    "LDI r21, 100 \n\t"
    "LOOP_2: \n\t"
    "LDI r20, 200 \n\t"
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
