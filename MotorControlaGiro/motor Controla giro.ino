
#define enA 9   
#define in1 10  
#define in2 11  

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  // Inicialmente, desliga o motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  // Habilita o motor com velocidade zero
  analogWrite(enA, 0);
}

void loop() {
  // Gira o motor para frente
  motorForward(255);  
  delay(2000);        
  
  // Para o motor
  motorStop();
  delay(1000);        
  
  // Gira o motor para trás
  motorBackward(200); 
  delay(2000);        
  
  // Para o motor
  motorStop();
  delay(1000);        
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
