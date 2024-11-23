#include <Servo.h>

//comand word
String comd;
int mode;
int prev;
int garaOC;


Servo myservo1; // Servo 1 (controla giro)
Servo myservo2; // Servo 2 (controla subir/bajar)
Servo myservo3; // Servo 3 (controla garra)

int servo1_pos = 90;  // Posición inicial del servo 1
int servo2_pos = 90;  // Posición inicial del servo 2
int servo3_pos = 90;  // Posición inicial del servo 3

void setup() {
  // Conectar servos
  myservo1.attach(11);  // Servo 1 en pin 11 GIRO
  myservo2.attach(12);  // Servo 2 en pin 12 SUBIR/BAJAR
  myservo3.attach(13);  // Servo 2 en pin 13 GARRA

  Serial.begin(9600);  // Inicializar comunicación serial (opcional para depuración)
}

void loop() {
 
  if (Serial.available()){
    comd = Serial.readString();  //read until timeout
    comd.trim();                        // remove any \r \n whitespace at the end of the String
    Serial.println(comd);

    // cambiar entre manejar y garra 
    
  if (comd=="A"){
    Serial.print("detecto comando A");
    if (mode==0){
      mode=1;
    } else {
      mode=0;
    }
  }
  // 0 -> garra, 1-> coche
  if (mode==0){
       // Si el botón 1_1 está presionado, mover servo 1 a la derecha
      if (comd=="B") {
        Serial.print("detecto comando B");
        if (servo1_pos < 180) {
          servo1_pos++;  // Mueve el servo 1 hacia la derecha
          myservo1.write(servo1_pos);
          delay(10);  // Retardo para evitar movimientos bruscos
        }
      }
    
      // Si el botón 1_2 está presionado, mover servo 1 a la izquierda
      if (comd=="C") {
        Serial.print("detecto comando C");
        if (servo1_pos > 0) {
          servo1_pos--;  // Mueve el servo 1 hacia la izquierda
          myservo1.write(servo1_pos);
          delay(10);  // Retardo para evitar movimientos bruscos
        }
      }
    
      // Si el botón 2_1 está presionado, mover servo 2 a la derecha
      if (comd=="D") {
        Serial.print("detecto comando D");
        if (servo2_pos < 180) {
          servo2_pos++;  // Mueve el servo 2 hacia la derecha
          myservo2.write(servo2_pos);
          delay(10);  // Retardo para evitar movimientos bruscos
        }
      }
    
      // Si el botón 2_2 está presionado, mover servo 2 a la izquierda
      if (comd=="E") {
        Serial.print("detecto comando E");
        if (servo2_pos > 0) {
          servo2_pos--;  // Mueve el servo 2 hacia la izquierda
          myservo2.write(servo2_pos);
          delay(10);  // Retardo para evitar movimientos bruscos
        }
      }
      //TOGGLE CLOSE OR OPEN CLAW
      if(comd=="F"){
        Serial.print("detecto comando F");
        if (garaOC==0){
         while(servo3_pos<180){
            servo3_pos++;  // Mueve el servo 3 hacia la derecha
            myservo3.write(servo_3pos);
            delay(10);  // Retardo para evitar movimientos bruscos
          }
          mode=1;
        } else {
          while(servo_3pos>0){
            servo3_pos--;  // Mueve el servo 3 hacia la derecha
            myservo3.write(servo3_pos);
            delay(10);  // Retardo para evitar movimientos bruscos
          }
          mode=0;
        }
        if (servo2_pos < 180) {
          
        }
      }
    } else if (mode==1){
      // Controlar el movimiento según el botón presionado
      if (comd="B") {
        // Ambas llantas hacia adelante
        digitalWrite(2, HIGH);  // Dirección hacia adelante para llanta 1
        analogWrite(5, 100);    // Velocidad de la llanta 1
        digitalWrite(4, LOW);  // Dirección hacia adelante para llanta 2
        analogWrite(6, 100);    // Velocidad de la llanta 2
      } 
      else if (comd="C") {
        // Ambas llantas hacia atrás
        digitalWrite(2, LOW);   // Dirección hacia atrás para llanta 1
        analogWrite(5, 100);    // Velocidad de la llanta 1
        digitalWrite(4, HIGH);   // Dirección hacia atrás para llanta 2
        analogWrite(6, 100);    // Velocidad de la llanta 2
      } 
      else if (comd="D") {
        // Solo la llanta derecha hacia adelante
        digitalWrite(2, HIGH);  // Dirección hacia adelante para llanta 1
        analogWrite(5, 100);    // Velocidad de la llanta 1
        analogWrite(6, 0);      // Detener la llanta 2
      } 
      else if (comd="E") {
        // Solo la llanta izquierda hacia adelante
        digitalWrite(4, LOW);  // Dirección hacia adelante para llanta 2
        analogWrite(6, 100);    // Velocidad de la llanta 2
        analogWrite(5, 0);      // Detener la llanta 1
      } 
      else {
        // Detener ambas llantas si no hay botones presionados
        analogWrite(5, 0);      // Detener llanta 1
        analogWrite(6, 0);      // Detener llanta 2
      }
    }
  }
}
