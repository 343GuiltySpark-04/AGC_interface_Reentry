#include <LiquidCrystal.h>

// golbal Variables
int index = 0;


// LCD init
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(6, OUTPUT);

}

void loop()
{


  if (Serial.available() == 0) return;

  char c = (char)Serial.read();

  if (c == '#')
  {
    index = 0;
    lcd.clear();
    lcd.home();
  }
  else if (index == 0)
  {
    analogWrite(6, c == '1' ? 255 : 0);
    index++;
  }
  else
  {
    lcd.print(c);
  }





}
