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
  lcd.cursor();
  lcd.blink();
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);

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

    if (c == '1') {
      lcd.setCursor(0, 2);
      lcd.print("COMP ACVTY");
      lcd.home();
    }

    index++;

  } else if (index == 1) {

    if (c == '1') {
      lcd.setCursor(0, 2);
      lcd.print("STBY");
      lcd.home();

    }

    index++;

  } else if (index == 2) {

    analogWrite(9, c == '1' ? 255 : 0);
    if (c == '1') {
      lcd.setCursor(0, 2);
      lcd.print("UPLINK ACVTY");
      lcd.home();
    }
    index++;

  } else if (index == 3) {

    if (c == '1') {
      lcd.setCursor(0, 2);
      lcd.print("OPR ERR");
      lcd.home();
    }

    index++;

  } else if (index == 4) {

    if (c == '1') {
      lcd.setCursor(0, 2);
      lcd.print("KEY REL");
      lcd.home();
    }

    index++;

  } else if (index == 5) {
    if (c == '1') {


      lcd.setCursor(0, 2);
      lcd.print("NO ATT");
      lcd.home();
    }

    index++;

  } else if (index == 6) {
    if (c == '1') {

      lcd.setCursor(0, 2);
      lcd.print("TEMP");
      lcd.home();

    }

    index++;

  } else if (index == 7) {
    if (c == '1') {
      lcd.setCursor(0, 2);
      lcd.print("GIMBAL LOCK");
      lcd.home();
    }

    index++;

  } else if (index == 8) {
    if (c == '1') {
      lcd.setCursor(0, 2);
      lcd.print("PROG");
      lcd.home();
    }

    index++;

  } else if (index == 9) {
    if (c == '1') {
      lcd.setCursor(0, 2);
      lcd.print("RESTART");
      lcd.home();
    }

    index++;

  } else if (index == 10) {
    if (c == '1') {
      lcd.setCursor(0, 2);
      lcd.print("TRACKER");
      lcd.home();
    }

    index++;

  } else {
    lcd.print(c);
  }





}
