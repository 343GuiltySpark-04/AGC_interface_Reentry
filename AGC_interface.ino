#include <LiquidCrystal.h>


/* AGC Interface for Reentry: An Orbial Simulator.
    GitHub Repo: https://github.com/343GuiltySpark-04/AGC_interface_Reentry
    And don't forget to grab the Python client from its repo: https://github.com/343GuiltySpark-04/Reentry-AGC-Arduino
    Version: 0.5c
*/


// Global Variables
int index = 0;
byte reg_sel = 0;
byte R1_Index = 0;
byte R2_Index = 0;
byte R3_Index = 0;

// Booleans
bool R1_Read = false;
bool R2_Read = false;
bool R3_Read = false;

// Arrays
char R1[6];
char R2[6];
char R3[6];

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

  } else if  (reg_sel == 1) {

    lcd.setCursor(0, 2);
    lcd.print("R1: ");
    for (int i = 0; i < 6; i++) {

      lcd.print(R1[i]);

    }

    lcd.home();
  }  else if (reg_sel == 2) {
    lcd.setCursor(0, 2);
    lcd.print("R2: ");
    for (int i = 0; i < 6; i++) {

      lcd.print(R2[i]);

    }

    lcd.home();

  } else if (reg_sel == 3) {
    lcd.setCursor(0, 2);
    lcd.print("R3: ");
    for (int i = 0; i < 6; i++) {
      lcd.print(R3[i]);

    }

    lcd.home();

  }

  else {
    lcd.print(c);
  }



}
