const int lowestPin = 2; //the lowest number of the LED pins
const int highestPin = 9; //the highest number of the LED pins

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
    int ms = 100;
    //iterate over the pins
    //turn the led on from lowest to the highest
    for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++)
    {
        digitalWrite(thisPin,HIGH);//turn led on
        delay(ms);//wait for ms
    }
    //fade from the highest to the lowest
    for(int thisPin = highestPin;thisPin>=lowestPin;thisPin--)
    {
        digitalWrite(thisPin,LOW);//turn led off
        delay(ms);//wait for ms
    }
    //turn the led on from highest to the lowest
    for(int thisPin = highestPin;thisPin>=lowestPin;thisPin--)
    {
        digitalWrite(thisPin,HIGH);//turn led on
        delay(ms);//wait for ms
    }
    //fade from the lowest to the highest
    for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++)
    {
        digitalWrite(thisPin,LOW);//turn led off
        delay(ms);//wait for ms
    }
}