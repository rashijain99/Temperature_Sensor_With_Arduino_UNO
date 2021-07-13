#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd = LiquidCrystal(2, 3, 7, 6, 5, 4); //creating a object name lcd
int tempsensor = A0;

byte degree[8] = {
 B01110,
  B01110,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte celsius[8] = {
  B00000,
  B01111,
  B10000,
  B10000,
  B10000,
  B10000,
  B01111,
  B00000
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);

  lcd.createChar(1, degree);
  lcd.createChar(2, celsius);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int a = analogRead(tempsensor); //a stores digital number
  float volt = a * (0.004887586);
  Serial.print("Digital number :\t");
  Serial.println(a);
  
  Serial.print("Input voltage : \t");
  Serial.print(volt, 6);
  Serial.println();
  
  float temp = volt / 0.01;
  Serial.print("Input Temperature : \t");
  Serial.print(temp);
  Serial.println();
  delay(1000);

  lcd.blink();
  lcd.setCursor(2, 0);
  lcd.write("TEMPERATURE");
  delay(1000);

  lcd.setCursor(3, 1);
  lcd.print(temp);

  lcd.setCursor(8, 1);
  lcd.write(byte(1));

  lcd.setCursor(9, 1);
  lcd.write(byte(2));
  delay(1000);
}
