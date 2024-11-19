#include <Servo.h>

//comand word
String comd;
int mode;
int prev;
int garaOC;


Servo myservo1; // Servo 1 (controla giro)
Servo myservo2; // Servo 2 (controla subir/bajar)
Servo myservo2; // Servo 3 (controla garra)

int servo1_pos = 90;  // Posición inicial del servo 1
int servo2_pos = 90;  // Posición inicial del servo 2
int servo3_pos = 90;  // Posición inicial del servo 3

void setup() {
  // Conectar servos
  myservo1.attach(11);  // Servo 1 en pin 11 GIRO
  myservo2.attach(12);  // Servo 2 en pin 12 SUBIR/BAJAR
  myservo2.attach(13);  // Servo 2 en pin 13 GARRA

  Serial.begin(9600);  // Inicializar comunicación serial (opcional para depuración)
}

void loop() {
 
  if (Serial.available()){
    comd = Serial.readString();  //read until timeout
    comd.trim();                        // remove any \r \n whitespace at the end of the String
    Serial.println(comd);

    // cambiar entre manejar y garra 
    
  if (comd=="A"){
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
        if (servo1_pos < 180) {
          servo1_pos++;  // Mueve el servo 1 hacia la derecha
          myservo1.write(servo1_pos);
          delay(10);  // Retardo para evitar movimientos bruscos
        }
      }
    
      // Si el botón 1_2 está presionado, mover servo 1 a la izquierda
      if (comd=="C") {
        if (servo1_pos > 0) {
          servo1_pos--;  // Mueve el servo 1 hacia la izquierda
          myservo1.write(servo1_pos);
          delay(10);  // Retardo para evitar movimientos bruscos
        }
      }
    
      // Si el botón 2_1 está presionado, mover servo 2 a la derecha
      if (comd=="D") {
        if (servo2_pos < 180) {
          servo2_pos++;  // Mueve el servo 2 hacia la derecha
          myservo2.write(servo2_pos);
          delay(10);  // Retardo para evitar movimientos bruscos
        }
      }
    
      // Si el botón 2_2 está presionado, mover servo 2 a la izquierda
      if (comd=="E") {
        if (servo2_pos > 0) {
          servo2_pos--;  // Mueve el servo 2 hacia la izquierda
          myservo2.write(servo2_pos);
          delay(10);  // Retardo para evitar movimientos bruscos
        }
      }
      //TOGGLE CLOSE OR OPEN CLAW
      if(comd=="F"){
        if (garaOC==0){
         while(servo_3pos<180){
            servo3_pos++;  // Mueve el servo 3 hacia la derecha
            myservo3.write(servo3_pos);
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
      
    }
  }
