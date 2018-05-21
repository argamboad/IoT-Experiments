int redPin = 11; //the number of the LED module red pin
int greenPin = 10; //the number of the LED module green pin
int val;    
int i;

void setup() 
{
    pinMode(redPin, OUTPUT); //initialize the LED red pin as output
    pinMode(greenPin, OUTPUT); //initialize the LED green pin as output
}

void loop() 
{
    //Blink between colors 5 times
    for(i=1; i<=5; i++)
    {
        digitalWrite(redPin, HIGH); //turn on the LED red
        digitalWrite(greenPin, LOW); //turn off the LED green
        delay(500); //wait for half a second
        digitalWrite(redPin, LOW); //turn off the LED red
        digitalWrite(greenPin, HIGH); //turn on the LED green
        delay(500); //wait for half a second
    }
    //Change color gradually increasing red while decreasing green
    for(val=1024; val>0; val--)
    {
        analogWrite(redPin, val); //set the brightness value of LED red
        analogWrite(greenPin, 255-val); //set the brightness value of LED green
        delay(10); //wait for 10 ms
    }
    //Change color gradually increasing green while decreasing red
    for(val=0; val<255; val++)
    {
        analogWrite(redPin, val); //set the brightness value of LED red
        analogWrite(greenPin, 255-val); //set the brightness value of LED green
        delay(10); //wait for 10 ms
    }

    delay(1000); //wait for a second
}