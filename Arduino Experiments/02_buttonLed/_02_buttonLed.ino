const int ledPin = 9; //the number of the LED pin
const int buttonPin = 11; //the number of the button module pin

void setup()
{
    pinMode(ledPin, OUTPUT); //initialize the LED pin as output
    pinMode(buttonPin, INPUT); //initialize the button module pin as input
}

void loop()
{
    boolean state = digitalRead(buttonPin); //read the button state, LOW if pressed

    if(state == HIGH)
    {
        digitalWrite(ledPin, LOW); //turn off the LED
    }
    else
    {
        digitalWrite(ledPin, HIGH); //turn on the LED        
    }
}