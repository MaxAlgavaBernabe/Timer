//Timer
//@Max Algava

#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

#include <Wire.h>





int horas = 0;
int minutos = 0;
int segundos = 0;
int decimas = 0;
int centecimas =0;
long milisegundos = 0;
int inicio = 10;
int pausa = 9;

void setup(){
  Serial.begin(9600);
  pinMode(inicio, INPUT);
  digitalWrite(inicio, LOW);
  pinMode(pausa, INPUT);
  digitalWrite(pausa, LOW);
  lcd.begin(16,2);
  while(digitalRead(inicio) == LOW){
  lcd.setCursor(0,0);
  lcd.print("00:00:00");
 }
}
 

void loop(){
   
  if(digitalRead(inicio) == HIGH){ 
    horas = 0;
    minutos = 0;
    segundos = 0;
    decimas = 0;
    lcd.clear();
  }
  
  if(digitalRead(pausa) == HIGH){
    delay(200);
    while(digitalRead(pausa) == LOW);
    lcd.setCursor(0,1);
   if(horas < 10){ lcd.print("0");}
    lcd.print(horas);
    lcd.print(":");
   if(minutos < 10){ lcd.print("0");}
    lcd.print(minutos);
    lcd.print(":");
   if(segundos < 10){ lcd.print("0");}
    lcd.print(segundos);
    lcd.print(":");
    lcd.print(decimas);
    delay(200);
  }
  milisegundos = millis();
  if(milisegundos % 10 == 0){  
    decimas++;
    if(decimas == 100){ 
      decimas = 0;
      segundos++;
    }
    if(segundos == 60){ 

      segundos = 0;
      minutos++;
    }
    if(minutos == 60){
      minutos = 0;
      horas++;
    }
  
    lcd.setCursor(0,0);
   if(horas < 10){ 
    lcd.print("0");
   }
    lcd.print(horas);
    lcd.print(":");
    lcd.setCursor(3,0);
   if(minutos < 10){
     lcd.print("0");
    }
    lcd.print(minutos);
    lcd.print(":");
    lcd.setCursor(6,0);
   if(segundos < 10){
     lcd.print("0");
    }
    lcd.print(segundos);
    lcd.print(":");
    lcd.setCursor(9,0);
    lcd.print(decimas);
  }
}
