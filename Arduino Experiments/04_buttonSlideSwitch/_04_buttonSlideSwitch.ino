const int ledPin = 9; //the number of the LED pin
const int slidePin = 11; //the number of the slide pin

void setup()
{
    pinMode(ledPin, OUTPUT); //initialize the LED pin as output
    pinMode(slidePin, INPUT); //initialize the slide pin as input
}

void loop()
{
    boolean state = digitalRead(slidePin); //read the slide right position state, LOW if pressed

    if(state == HIGH)
    {
        digitalWrite(ledPin, LOW); //turn off the LED
    }
    else
    {
        digitalWrite(ledPin, HIGH); //turn on the LED        
    }
}