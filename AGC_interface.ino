


byte incoming = 0;

int AGCcodes[] = {49, 50};



void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
}

void loop()
{


  int on = 255;

  int off = 0;


  if (Serial.available() > 0) {

    incoming = Serial.read();


    Serial.print("I received: ");
    Serial.println(incoming, DEC);
    Serial.println("-----------------");
    Serial.flush();

  }


  if (incoming == AGCcodes[0]) {


    analogWrite(11, on);

  } else {

    analogWrite(11, off);
    
  }

 

}
