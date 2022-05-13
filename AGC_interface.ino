#include <LiquidCrystal.h>

// Global Variables
int index = 0;
byte reg_sel = 0;
byte R1_Index = 0;
byte R2_Index = 0;

// Booleans
bool R1_Read = false;
bool R2_Read = false;

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
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

}


// TODO: allow VERB, NOUN, AND PROG to display at the same time as registers!

// TODO: Make the register select system less buggy!

void loop()
{

  if (digitalRead(A2) == HIGH) {
      reg_sel++;
      if (reg_sel > 3){
        reg_sel = 0;
      }
      //Serial.print(reg_sel);
      delay(100);
  }

//  if (digitalRead(A2) == HIGH){
//    digitalWrite(LED_BUILTIN, HIGH);
//  } else {
//    digitalWrite(LED_BUILTIN, LOW);
//  }



  if (Serial.available() == 0) return;

  char c = (char)Serial.read();

  if (c == '#')
  {
    index = 0;
    lcd.clear();
    lcd.home();
  } else if (c == '<') {
    R1_Read = true;
    index++;

  } else if (c == '>') {
    R1_Read = false;
    R1_Index = 0;
    index++;
  } else if (R1_Read == true) {

    R1[R1_Index] = c;
    R1_Index++;
    index++;

  } else if (c == '$'){
    
    R2_Read = true;
    index++;
    
  } else if (c == '%'){
    
    R2_Read = false;
    R2_Index = 0;
    index++;
    
  } else if (R2_Read == true){
    R2[R2_Index] = c;
    R2_Index++;
    index++;
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

  } else if  (reg_sel == 1) {

    lcd.setCursor(0, 2);
    lcd.print("R1: ");
    for (int i = 0; i < 6; i++) {

      lcd.print(R1[i]);

    }

    lcd.home();
  }  else if (reg_sel == 2){
    lcd.setCursor(0, 2);
    lcd.print("R2: ");
    for (int i = 0; i < 6; i++) {

    lcd.print(R2[i]);
      
    }

    lcd.home();
    
  }
  
  else {
    lcd.print(c);
  }



}
