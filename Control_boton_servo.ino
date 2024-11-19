#include <Servo.h>

//comand word
String comd;

// Joystick 1
const int Boton_1_1 = 6;  // Botón para mover servo 1 a la derecha
const int Boton_1_2 = 7;  // Botón para mover servo 1 a la izquierda

// Joystick 2
const int Boton_2_1 = 8;  // Botón para mover servo 2 a la derecha
const int Boton_2_2 = 9;  // Botón para mover servo 2 a la izquierda

// Eliminamos el Boton_3 y Switch, como solicitaste

Servo myservo1; // Servo 1 (controla algo como un brazo o parte del robot)
Servo myservo2; // Servo 2 (controla otra parte como una garra, por ejemplo)

int servo1_pos = 90;  // Posición inicial del servo 1
int servo2_pos = 90;  // Posición inicial del servo 2

void setup() {
  // Conectar servos
  myservo1.attach(12);  // Servo 1 en pin 12 garra
  myservo2.attach(13);  // Servo 2 en pin 13

  // Configurar los pines de los botones
  pinMode(Boton_1_1, INPUT);  // Botón para mover servo 1 a la derecha
  pinMode(Boton_1_2, INPUT);  // Botón para mover servo 1 a la izquierda
  pinMode(Boton_2_1, INPUT);  // Botón para mover servo 2 a la derecha
  pinMode(Boton_2_2, INPUT);  // Botón para mover servo 2 a la izquierda

  Serial.begin(9600);  // Inicializar comunicación serial (opcional para depuración)
}

void loop() {
 
  if (Serial.available()){
    comd = Serial.readString();  //read until timeout
    comd.trim();                        // remove any \r \n whitespace at the end of the String
    Serial.println(comd);
          
    // Si el botón 1_1 está presionado, mover servo 1 a la derecha
    if (comd=="A") {
      if (servo1_pos < 180) {
        servo1_pos++;  // Mueve el servo 1 hacia la derecha
        myservo1.write(servo1_pos);
        delay(10);  // Retardo para evitar movimientos bruscos
      }
    }
  
    // Si el botón 1_2 está presionado, mover servo 1 a la izquierda
    if (comd=="B") {
      if (servo1_pos > 0) {
        servo1_pos--;  // Mueve el servo 1 hacia la izquierda
        myservo1.write(servo1_pos);
        delay(10);  // Retardo para evitar movimientos bruscos
      }
    }
  
    // Si el botón 2_1 está presionado, mover servo 2 a la derecha
    if (comd=="C") {
      if (servo2_pos < 180) {
        servo2_pos++;  // Mueve el servo 2 hacia la derecha
        myservo2.write(servo2_pos);
        delay(10);  // Retardo para evitar movimientos bruscos
      }
    }
  
    // Si el botón 2_2 está presionado, mover servo 2 a la izquierda
    if (comd=="D") {
      if (servo2_pos > 0) {
        servo2_pos--;  // Mueve el servo 2 hacia la izquierda
        myservo2.write(servo2_pos);
        delay(10);  // Retardo para evitar movimientos bruscos
      }
    }
    if(comd=="E"){
      
  }
    if(comd=="F"){
      
  }
    if(comd=="G"){
      
  }
    if(comd=="H"){
      
  }
    if(comd=="I"){
      
  }
}
