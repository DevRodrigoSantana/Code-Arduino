#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
//Define LCD 16 colunas por 2 linhas
lcd.begin(16, 2);

//Posiciona o cursor na coluna 0, linha 0;
lcd.setCursor(0,0);
//Envia o texto entre aspas para o LCD
lcd.print("Ola, meu nome e:");

//Posiciona o cursor na coluna 1, linha 1;
lcd.setCursor(1,1);
//Envia o texto entre aspas para o LCD
lcd.print("Squids Arduino");
}

void loop() {

} 
