void setup() {
  
  Serial.begin(9600);
  DDRB = DDRB | B11111111; //data direction register B: Inputs 0-4 , 6-7, Output 5 (0 entrada y 1 salida)
}

void loop() {
  asm volatile(
    //Duracion de 6 segundos en el led rojo
    "sbi 0x05,0x04 \n\t" //digitalwrite (high)
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    //Duración de 1 segundo led amarillo
    "cbi 0x05,0x04 \n\t" //digitalwrite (low)
    "sbi 0x05,0x05 \n\t"
    "call tiempo \n\t"
    "cbi 0x05,0x05 \n\t"
    "sbi 0x05,0x06 \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "cbi 0x05,0x06 \n\t"

    "jmp main \n\t"

    //Tiempo nos da 2 segundo de delay
    "tiempo: \n\t"
    "LDI r22, 255 \n\t"
    "LOOP_3: \n\t"
    "LDI r21, 155 \n\t"
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
