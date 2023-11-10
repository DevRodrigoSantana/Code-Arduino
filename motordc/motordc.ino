#include <NewPing.h>

int in1 = 8;
int in2 = 9;
#define TRIG  7  // Pino de transmissão
#define ECHO  6  // Pino de recepção
#define distancia 200 // Distância máxima em centímetros (ajuste conforme necessário)

NewPing golfinho(TRIG, ECHO, distancia); 

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(1000); 
  unsigned int distance = golfinho.ping_cm();   
  
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 8) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
  if (distance > 8 && distance <= 30) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  if (distance > 30) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
}
