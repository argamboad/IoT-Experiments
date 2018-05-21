const int ledPin = 9;//the number of the LED pin

void setup()
{
    pinMode(ledPin, OUTPUT); //initialize the LED pin as output TEST
}

void loop()
{
    digitalWrite(ledPin, HIGH); //turn on the LED
    delay(500); //wait for half a second
    digitalWrite(ledPin, LOW); //turn off the LED
    delay(500); //wait for half a second
}
