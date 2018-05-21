
const int analogPin = A0; //the analog pin of the potentiometer
const int ledPin = 9; //the number of the LED pin

int inputValue = 0; //variable to store the value coming from potentiometer

void setup()
{
    pinMode(ledPin,OUTPUT); //initialize the LED pin as output
}

void loop()
{
  inputValue = analogRead(analogPin); //read the value from the potentiometer

  digitalWrite(ledPin,HIGH); //turn on the LED
  delay(inputValue); //wait for the number of ms in inputValue
  digitalWrite(ledPin,LOW); //turn off the LED
  delay(inputValue); //wait for the number of ms in inputValue
}