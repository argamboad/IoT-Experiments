#include<wiringPi.h>
#include<stdio.h>

#define ledPin 0 //wiringPi pin number for the LED
#define slidePin 1 //wiringPi pin number for the button

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("Setup wiring Pi failed!");
		return 1;
	}
	
	pinMode(ledPin,OUTPUT); //initialize the LED pin as output
	pinMode(slidePin,INPUT); //initialize the button pin as input
	
	while(1)
	{
		digitalWrite(ledPin, HIGH); //turn off the LED
		if(digitalRead(slidePin) == 0) //read the button state, 0 if pressed
		{
            digitalWrite(ledPin, LOW); //turn on the LED
		}
	}
	
	return 0;
}