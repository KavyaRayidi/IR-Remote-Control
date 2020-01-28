#include <IRremote.h>
int yellowLed = 6;
int greenLed = 5;
int whiteLed = 4;
int RECV_PIN = 11;
//IR Library stuff
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  //Set Led Pins
  pinMode(2,OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(whiteLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  //Enable serial usage and IR signal in
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); 
  Serial.println("Enabled IRin");
  
}
void loop() {
  digitalWrite(2,LOW);  if (irrecv.decode(&results)) {//irrecv.decode(&results) returns true if anything is recieved, and stores info in varible results
    unsigned int value = results.value; //Get the value of results as an unsigned int, so we can use switch case
    Serial.println(value);
    switch (value) {
      case 58747:
        digitalWrite(yellowLed, HIGH);
        digitalWrite(whiteLed, HIGH);
        digitalWrite(greenLed, HIGH);
        break;
      case 26775:
        digitalWrite(yellowLed, HIGH);
        digitalWrite(whiteLed, HIGH);
        digitalWrite(greenLed, HIGH);
        break;
      case 65535:
        digitalWrite(yellowLed, HIGH);
        digitalWrite(whiteLed, HIGH);
        digitalWrite(greenLed, HIGH);
        break;
      case 48703:
        digitalWrite(yellowLed, LOW);
        digitalWrite(whiteLed, LOW);
        digitalWrite(greenLed, LOW);
        break;
      case 255:
        digitalWrite(yellowLed, LOW);
        digitalWrite(whiteLed, LOW);
        digitalWrite(greenLed, LOW);
        break;
      case 12495:
        digitalWrite(yellowLed, LOW);
        digitalWrite(whiteLed, LOW);
        digitalWrite(greenLed, LOW);
        break;
        
        
        
    }
 irrecv.resume(); // Receive the next value
  }
}
