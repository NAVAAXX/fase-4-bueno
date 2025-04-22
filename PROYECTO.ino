#include <SoftwareSerial.h>

// Configuración del Bluetooth HC-06
SoftwareSerial bluetooth(1,0); // RX en pin 10, TX en pin 11

char command; // Variable para almacenar comandos del módulo Bluetooth

bool oscilar = false; // Variable para controlar el bucle de oscilación

// Definición de pines para el primer L298N
int in1PinA = 9;
int in2PinA = 10; 
int enAPinA = 7;
int in1PinB = 11;
int in2PinB = 12;
int enBPinA = 8;

// Definición de pines para el segundo L298N
int in1PinC = 2;
int in2PinC = 3;
int enAPinB = 13; 
int in1PinD = 4;
int in2PinD = 5;
int enBPinB = 6;

void setup() {
  pinMode(in1PinA, OUTPUT);
  pinMode(in2PinA, OUTPUT);
  pinMode(enAPinA, OUTPUT);
  pinMode(in1PinB, OUTPUT);
  pinMode(in2PinB, OUTPUT);
  pinMode(enBPinA, OUTPUT);
  pinMode(in1PinC, OUTPUT);
  pinMode(in2PinC, OUTPUT);
  pinMode(enAPinB, OUTPUT);
  pinMode(in1PinD, OUTPUT);
  pinMode(in2PinD, OUTPUT);
  pinMode(enBPinB, OUTPUT);
  Serial.begin(9600); // Iniciar comunicación serie con el módulo Bluetooth
}

void loop() {
    command = Serial.read(); // Leer el comando del módulo Bluetooth

    switch (command) {
      case 'A': // Adelante
        Adelante();
        break;
      case 'B': // Atrás
        Atras();
        break;
      case 'D': // Izquierda
        Derecha();
        break;
      case 'C': // Derecha
        Izquierda();
        break;
      case 'E': // Adelante 3 segundos y parar
        Trespasos();
        oscilar = true; // Iniciar la oscilación
        break;
      case 'F': // Parar
        Parar();
        oscilar = false; // Detener la oscilación
        break;
      case 'G': // Paso de Semana Santa
        Oscilar();
         oscilar = true; // Iniciar la oscilación
        break;
      case 'H': // Girar izquierda mientras avanza
        Izquierdaavanza();
        break;
      case 'I': // Girar derecha mientras avanza
        Derechaavanza();
        break;
      case 'J': // Rotar sobre sí mismo
        Rotarsobresi();
        break;
    }
  }
if (oscilar) {
    Oscilar(); // Llamar a la función Oscilar si oscilar es verdadero
  }
}

void Adelante() {
  digitalWrite(in1PinA, HIGH);
  digitalWrite(in2PinA, LOW);
  analogWrite(enAPinA, 75); // Motor A máxima velocidad
  
  digitalWrite(in1PinB, HIGH);
  digitalWrite(in2PinB, LOW);
  analogWrite(enBPinA, 75); // Motor B máxima velocidad
  
  digitalWrite(in1PinC, HIGH);
  digitalWrite(in2PinC, LOW);
  analogWrite(enAPinB, 75); // Motor C máxima velocidad
  
  digitalWrite(in1PinD, HIGH);
  digitalWrite(in2PinD, LOW);
  analogWrite(enBPinB, 75); // Motor D máxima velocidad

}

void Atras() {
  digitalWrite(in1PinA, LOW);
  digitalWrite(in2PinA, HIGH);
  analogWrite(enAPinA, 75); // Motor A máxima velocidad
  
  digitalWrite(in1PinB, LOW);
  digitalWrite(in2PinB, HIGH);
  analogWrite(enBPinA, 75); // Motor B máxima velocidad
  
  digitalWrite(in1PinC, LOW);
  digitalWrite(in2PinC, HIGH);
  analogWrite(enAPinB, 75); // Motor C máxima velocidad
  
  digitalWrite(in1PinD, LOW);
  digitalWrite(in2PinD, HIGH);
  analogWrite(enBPinB, 75); // Motor D máxima velocidad

}

void Derecha() {
  // Girar a la izquierda
  digitalWrite(in1PinA, LOW);
  digitalWrite(in2PinA, HIGH);
  analogWrite(enAPinA, 75); // Motor A hacia atrás
  
  digitalWrite(in1PinB, HIGH);
  digitalWrite(in2PinB, LOW);
  analogWrite(enBPinA, 75); // Motor B hacia atrás
  
  digitalWrite(in1PinC, LOW);
  digitalWrite(in2PinC, HIGH);
  analogWrite(enAPinB, 75); // Motor C hacia adelante
  
  digitalWrite(in1PinD, HIGH);
  digitalWrite(in2PinD, LOW);
  analogWrite(enBPinB, 75); // Motor D hacia adelante

}

void Izquierda() {
  // Girar a la derecha
  digitalWrite(in1PinA, HIGH);
  digitalWrite(in2PinA, LOW);
  analogWrite(enAPinA, 75); // Motor A hacia adelante
  
  digitalWrite(in1PinB, LOW);
  digitalWrite(in2PinB, HIGH);
  analogWrite(enBPinA, 75); // Motor B hacia adelante
  
  digitalWrite(in1PinC, HIGH);
  digitalWrite(in2PinC, LOW);
  analogWrite(enAPinB, 75); // Motor C hacia atrás
  
  digitalWrite(in1PinD, LOW);
  digitalWrite(in2PinD, HIGH);
  analogWrite(enBPinB, 75); // Motor D hacia atrás

}

void Trespasos() {
  Adelante();
  delay(3000);
  Oscilar();

}

void Oscilar() {
  Izquierda();
  delay(500);
  Derecha();
  delay(500);
}

void Izquierdaavanza() {
   
  digitalWrite(in1PinA, HIGH);
  digitalWrite(in2PinA, LOW);
  analogWrite(enAPinA, 50); 

  digitalWrite(in1PinC, HIGH);
  digitalWrite(in2PinC, LOW);
  analogWrite(enAPinB, 75); 

  digitalWrite(in1PinB, HIGH);
  digitalWrite(in2PinB, LOW);
  analogWrite(enBPinA, 75); 

  digitalWrite(in1PinD, HIGH);
  digitalWrite(in2PinD, LOW);
  analogWrite(enBPinB, 50); 

}

void Derechaavanza() {
  
  digitalWrite(in1PinA, HIGH);
  digitalWrite(in2PinA, LOW);
  analogWrite(enAPinA, 75); 

  digitalWrite(in1PinC, HIGH);
  digitalWrite(in2PinC, LOW);
  analogWrite(enAPinB, 50); 

  digitalWrite(in1PinB, HIGH);
  digitalWrite(in2PinB, LOW);
  analogWrite(enBPinA, 50); 

  digitalWrite(in1PinD, HIGH);
  digitalWrite(in2PinD, LOW);
  analogWrite(enBPinB, 75); 

}

void Rotarsobresi() {
  
  digitalWrite(in1PinA, HIGH);
  digitalWrite(in2PinA, LOW);
  analogWrite(enAPinA, 60); 

  digitalWrite(in1PinC, HIGH);
  digitalWrite(in2PinC, LOW);
  analogWrite(enAPinB, 60); 

 
  digitalWrite(in1PinB, LOW);
  digitalWrite(in2PinB, HIGH);
  analogWrite(enBPinA, 60); 

  digitalWrite(in1PinD, LOW);
  digitalWrite(in2PinD, HIGH);
  analogWrite(enBPinB, 60); 

}

void Parar() {
  // Motores del lado izquierdo (A y C) detenidos
  digitalWrite(in1PinA, LOW);
  digitalWrite(in2PinA, LOW);
  analogWrite(enAPinA, 0); // Motor A detenido

  digitalWrite(in1PinC, LOW);
  digitalWrite(in2PinC, LOW);
  analogWrite(enAPinB, 0); // Motor C detenido

  // Motores del lado derecho (B y D) detenidos
  digitalWrite(in1PinB, LOW);
0  digitalWrite(in2PinB, LOW);
  analogWrite(enBPinA, 0); // Motor B detenido

  digitalWrite(in1PinD, LOW);
  digitalWrite(in2PinD, LOW);
  analogWrite(enBPinB, 0); // Motor D detenido
  }


