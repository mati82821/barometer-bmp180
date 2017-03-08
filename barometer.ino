#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27
Adafruit_BMP085 bmp;
int mode = 0;
int button = 12;
void setup() {
  pinMode(12, INPUT_PULLUP);
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Barometr");
  delay(1000);
  lcd.clear();
  if (!bmp.begin()) {
  lcd.setCursor(0,0);
  lcd.print("Nie odnaleziono");
  lcd.setCursor(0,1);
  lcd.print("czujnika BMP180!");
  delay(1000);
  lcd.clear();
  while (1) {}
  }
}

void loop() {

  switch(mode){
  case 0:
  lcd.setCursor(0,0);
  lcd.print("Temperatura:");
  lcd.setCursor(0,1);
  lcd.print(bmp.readTemperature());
  lcd.print("*C");
  break;
  case 1:
  lcd.setCursor(0,0);
  lcd.print("Cisnienie:");
  lcd.setCursor(0,1);
  lcd.print(bmp.readPressure()/100);
  lcd.print(" hPa");
  break;
  case 2:
  lcd.print("Wysokosc:");
  lcd.setCursor(0,1);
  lcd.print(bmp.readAltitude());
  lcd.print(" metrow");
  break;
  case 3:
  lcd.print("Wysokosc r.:");
  lcd.setCursor(0,1);
  lcd.print(bmp.readAltitude(102520));
  lcd.print(" metrow");
  break;
  case 4:
  lcd.setCursor(0,0);
  lcd.print("Cisnienie:");
  lcd.setCursor(0,1);
  lcd.print(bmp.readPressure());
  lcd.print(" Pa");
  break;
  }
  delay(2000);
  lcd.clear();
    if(digitalRead(12) == 0){
    mode++;
    if(mode==5) mode = 0;
    delay(1);
  }
}
