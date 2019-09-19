int rojo = 10;
int amarillo = 11;
int verde = 12;
void setup() {
 pinMode(rojo,OUTPUT);
 pinMode(amarillo,OUTPUT);
 pinMode(verde,OUTPUT);
}
void loop() {
 /**
 * El rojo dura 10 segundos
 * El verde dura 15 segundos
 * El amarillo se enciende los ́ultimos 3 segundos del verde
 *
 * Al apagarse el amarillo se prende el rojo y al apagarse el rojo se prende el verde
 */
 digitalWrite(rojo, HIGH);
delay(6000);
 digitalWrite(rojo, LOW);
 digitalWrite(amarillo, HIGH);
 delay(1000);
 digitalWrite(amarillo, LOW);
 digitalWrite(verde, HIGH);
 delay(4000);
digitalWrite(verde, LOW);
}
