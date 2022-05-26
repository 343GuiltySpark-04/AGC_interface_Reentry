#include <LiquidCrystal.h>


/* AGC Interface for Reentry: An Orbial Simulator.
    GitHub Repo: https://github.com/343GuiltySpark-04/AGC_interface_Reentry
    And don't forget to grab the Python client from its repo: https://github.com/343GuiltySpark-04/Reentry-AGC-Arduino
    Version: 0.5c
*/


// Global Variables
int index = 0;
byte reg_sel = 0;
byte Reg_Index = 0;

// Booleans
bool Reg_Read = false;

// Arrays
char Reg[9];


// LCD Init
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A2, INPUT);

}


// TODO: allow VERB, NOUN, AND PROG to display at the same time as registers!

// TODO: Make the register select system less buggy!

void loop()
{

  //  if (digitalRead(A2) == HIGH) {
  //    reg_sel++;
  //    if (reg_sel > 3) {
  //      reg_sel = 0;
  //    }
  //    delay(100);
  //  }


  if (Serial.available() == 0) return;

  char c = (char)Serial.read();

  if (c == '#')
  {
    index = 0;
    lcd.clear();
    lcd.home();
  } else if (c == '<') {
    Reg_Read = true;
    index++;

  } else if (c == '>') {
    Reg_Read = false;
    Reg_Index = 0;
    index++;
  } else if (Reg_Read == true) {

    Reg[Reg_Index] = c;
    Reg_Index++;
    index++;

  }


  else if (index == 1)
  {
    analogWrite(6, c == '1' ? 255 : 0);

    if (c == '1') {
      lcd.setCursor(11, 0);
      lcd.print(" COMP");
      lcd.home();
    }

    index++;

  } else if (index == 2) {

    analogWrite(9, c == '1' ? 255 : 0);
    if (c == '1') {
      lcd.setCursor(11, 0);
      lcd.print(" UPLK");
      lcd.home();
    }
    index++;

  }




  else {
    lcd.setCursor(0, 2);
    for (int i = 0; i < 9; i++) {

      lcd.print(Reg[i]);

    }

    lcd.home();
    lcd.print(c);
  }



}
