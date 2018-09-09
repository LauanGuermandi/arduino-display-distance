//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 8
#define pino_echo 7
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  Serial.begin(9600);
  
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);

  lcd.clear();
  lcd.setCursor(9, 0);
  lcd.print("cm");
  
}
 
void loop()
{

  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD;
  lcd.print(cmMsec);

  delay(1000);
 
}

