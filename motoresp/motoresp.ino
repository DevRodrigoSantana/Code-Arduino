
#define enA D1   // Pino de habilitação do motor A
#define in1 D2   // Pino de controle 1 do motor A
#define in2 D3   // Pino de controle 2 do motor A

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  // Habilita o motor com velocidade zero
  analogWrite(enA, 0);
}

void loop() {
  
  motorForward(255);  // Velocidade máxima
  delay(2000);        // Mantém o motor ligado por 2 segundos
  
  // Para o motor
  motorStop();
  delay(1000);        // Pausa por 1 segundo
  
  // Gira o motor para trás
  motorBackward(200); // Velocidade reduzida
  delay(2000);        // Mantém o motor ligado por 2 segundos
  
  // Para o motor
  motorStop();
  delay(1000);        // Pausa por 1 segundo
}

// Função para girar o motor para frente
void motorForward(int speed) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
}

// Função para girar o motor para trás
void motorBackward(int speed) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);
}

// Função para parar o motor
void motorStop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
}
