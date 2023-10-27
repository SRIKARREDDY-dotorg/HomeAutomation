#include "LiquidCrystal.h"
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Home Automation :)=)");
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT); 
}

void loop() {

  if(Serial.available()>0) {
    char data = Serial.read();
    Serial.println(data);

    if(data == 'b'){
      digitalWrite(7,HIGH);
      Serial.println("Bulb on ");
      lcd.setCursor(0,1);
      lcd.print("    Bulb On        ");
    }

    if(data == 'c'){
      digitalWrite(7,LOW);
      Serial.println("Bulb Off ");
      lcd.setCursor(0,1);
      lcd.print("    Bulb Off        ");
    }

    if(data == 'f'){
      analogWrite(3,127);
      Serial.println("Fan On ");
      lcd.setCursor(0,1);
      lcd.print("    Fan On        ");
    }

    if(data == 'o'){
      analogWrite(3,0);
      Serial.println("Fan Off ");
      lcd.setCursor(0,1);
      lcd.print("    Fan Off        ");
    }
  }
}
