#include <LiquidCrystal.h>




byte incomingData = 0;

// to allow for ease of adding more events
int AGCcodes[] = {49, 50};


// LCD init 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
 
}

void loop()
{


  int on = 255;

  int off = 0;


  if (Serial.available() > 0) {

    incomingData = Serial.read();


    Serial.print("I received: ");
    Serial.println(incomingData, DEC);
    Serial.println("-----------------");
    Serial.flush();

  }


  if (incomingData == AGCcodes[0]) {


    analogWrite(6, on);

  } else {

    analogWrite(6, off);
    
  }

  if (incomingData == 50){

  lcd.begin(16, 2);
  lcd.print("V37");
  lcd.setCursor(0,1);
  lcd.print("N00");
 
    
  } 
 

}
