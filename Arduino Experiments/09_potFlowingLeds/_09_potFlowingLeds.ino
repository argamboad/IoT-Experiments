const int analogPin = A0; //the analog pin of the potentiometer
const int lowestPin = 2; //the lowest number of the LED pins
const int highestPin = 9; //the highest number of the LED pins

int inputValue = 0; //variable to store the value coming from potentiometer

void setup()
{
    //set pins 2 through 9 as output  
    for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++)
    {
        pinMode(thisPin,OUTPUT); //initialize pin as an output
    }
} 

void loop()
{
    //iterate over the pins
    //turn the led on from lowest to the highest
    for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++)
    {
        inputValue = analogRead(analogPin); //read the value from the potentiometer
        digitalWrite(thisPin,HIGH);//turn led on
        delay(inputValue);//wait for ms
    }
    //fade from the highest to the lowest
    for(int thisPin = highestPin;thisPin>=lowestPin;thisPin--)
    {
        inputValue = analogRead(analogPin); //read the value from the potentiometer
        digitalWrite(thisPin,LOW);//turn led off
        delay(inputValue);//wait for ms
    }
    //turn the led on from highest to the lowest
    for(int thisPin = highestPin;thisPin>=lowestPin;thisPin--)
    {
        inputValue = analogRead(analogPin); //read the value from the potentiometer
        digitalWrite(thisPin,HIGH);//turn led on
        delay(inputValue);//wait for ms
    }
    //fade from the lowest to the highest
    for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++)
    {
        inputValue = analogRead(analogPin); //read the value from the potentiometer
        digitalWrite(thisPin,LOW);//turn led off
        delay(inputValue);//wait for ms
    }
}