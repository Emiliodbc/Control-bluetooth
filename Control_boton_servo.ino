#include <Servo.h>

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
  myservo1.attach(2);  // Servo 1 en pin 2
  myservo2.attach(3);  // Servo 2 en pin 3

  // Configurar los pines de los botones
  pinMode(Boton_1_1, INPUT);  // Botón para mover servo 1 a la derecha
  pinMode(Boton_1_2, INPUT);  // Botón para mover servo 1 a la izquierda
  pinMode(Boton_2_1, INPUT);  // Botón para mover servo 2 a la derecha
  pinMode(Boton_2_2, INPUT);  // Botón para mover servo 2 a la izquierda

  Serial.begin(9600);  // Inicializar comunicación serial (opcional para depuración)
}

void loop() {
  // Leer el estado de los botones para servo 1
  bool boton_1_1_estado = digitalRead(Boton_1_1);
  bool boton_1_2_estado = digitalRead(Boton_1_2);

  // Si el botón 1_1 está presionado, mover servo 1 a la derecha
  if (boton_1_1_estado == HIGH) {
    if (servo1_pos < 180) {
      servo1_pos++;  // Mueve el servo 1 hacia la derecha
      myservo1.write(servo1_pos);
      delay(10);  // Retardo para evitar movimientos bruscos
    }
  }

  // Si el botón 1_2 está presionado, mover servo 1 a la izquierda
  if (boton_1_2_estado == HIGH) {
    if (servo1_pos > 0) {
      servo1_pos--;  // Mueve el servo 1 hacia la izquierda
      myservo1.write(servo1_pos);
      delay(10);  // Retardo para evitar movimientos bruscos
    }
  }

  // Leer el estado de los botones para servo 2
  bool boton_2_1_estado = digitalRead(Boton_2_1);
  bool boton_2_2_estado = digitalRead(Boton_2_2);

  // Si el botón 2_1 está presionado, mover servo 2 a la derecha
  if (boton_2_1_estado == HIGH) {
    if (servo2_pos < 180) {
      servo2_pos++;  // Mueve el servo 2 hacia la derecha
      myservo2.write(servo2_pos);
      delay(10);  // Retardo para evitar movimientos bruscos
    }
  }

  // Si el botón 2_2 está presionado, mover servo 2 a la izquierda
  if (boton_2_2_estado == HIGH) {
    if (servo2_pos > 0) {
      servo2_pos--;  // Mueve el servo 2 hacia la izquierda
      myservo2.write(servo2_pos);
      delay(10);  // Retardo para evitar movimientos bruscos
    }
  }
}

