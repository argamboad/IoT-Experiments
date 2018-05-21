
const int analogPin = A0; //the analog pin of the potentiometer
const int ledPin = 9; //the number of the LED pin
int inputValue = 0; //variable to store the value coming from potentiometer
int outputValue = 0; //variable to store the output value

void setup()
{
}

void loop()
{
  inputValue = analogRead(analogPin); //read the value from the potentiometer
  outputValue = map(inputValue,0,1023,0,255); //convert from 0-1023 proportional to the number of a number of from 0 to 255
  analogWrite(ledPin,outputValue); //set the LED brightness from the output value
}