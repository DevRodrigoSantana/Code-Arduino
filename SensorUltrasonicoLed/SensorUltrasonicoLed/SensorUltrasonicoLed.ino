#include <NewPing.h> // essa é uma das  bibliotecas do sensor Ultrassonico
#define led 10

NewPing sonar(12, 7, 200); //chama um função da biblioteca NewPing

void setup()
  {
   pinMode(led,OUTPUT);
  Serial.begin(9600);
 
  
  }

  void loop()
    {
       delay(50);//tempo de cada valor aparecer 
       digitalWrite(led,LOW);

        unsigned int distancia = sonar.ping_cm();

        if(distancia<10){

          Serial.println("Distancia :");
          Serial.println(distancia);
           digitalWrite(led,HIGH);
          
          }

    
    }
  
