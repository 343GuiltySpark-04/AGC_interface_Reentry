#include <LiquidCrystal.h>


/* AGC Interface for Reentry: An Orbial Simulator.
    GitHub Repo: https://github.com/343GuiltySpark-04/AGC_interface_Reentry
    And don't forget to grab the Python client from its repo: https://github.com/343GuiltySpark-04/Reentry-AGC-Arduino
    Version: 0.6d
*/


// Global Variables
int index = 0;
byte Reg_Index = 0;
byte data_index = 0;

// Booleans
bool Reg_Read = false;
bool Reg_asm = false;
bool data_asm = false;
bool data_read = false;

// Arrays
char Reg_char[10];
char data_char[11];

// Strings
String data = " ";


// LCD Init
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
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
  } else if (c == '<') {
    Reg_Read = true;
    index++;

  } else if (c == '>') {
    Reg_Read = false;
    Reg_Index = 0;
    index++;
  } else if (Reg_Read == true) {

    Reg_char[Reg_Index] = c;
    Reg_Index++;
    index++;

  } else if (c == 'X') {
    data_read = true;
    index++;

  } else if (c == 'Z') {
    data_read = false;
    data_index = 0;
    index++;
  } else if (data_read == true) {
    data_char[data_index] = c;
    data_index++;
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








}
