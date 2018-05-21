const int ledPin = 9;//the number of the LED pin

void setup()
{
    pinMode(ledPin, OUTPUT); //initialize the LED pin as output
}

void loop()
{
    for (int a=0; a<=255; a++) //loop from 0 to 255
    {
        analogWrite(ledPin, a); //set the brightness value of LED
        delay(10); //wait for 10 ms
    }

    for (int a=255; a>=0; a--) //loop from 255 to 0
    {
        analogWrite(ledPin, a); //set the brightness value of LED
        delay(10); //wait for 10 ms
    }

    delay(1000); //wait for 1 second
}
