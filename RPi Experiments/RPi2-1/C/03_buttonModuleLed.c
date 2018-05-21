#include<wiringPi.h>
#include<stdio.h>

#define ledPin 0 //wiringPi pin number for the LED
#define buttonPin 1 //wiringPi pin number for the button module

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("Setup wiring Pi failed!");
		return 1;
	}
	
	pinMode(ledPin,OUTPUT); //initialize the LED pin as output
	pinMode(buttonPin,INPUT); //initialize the button module pin as input
	
	while(1)
	{
		digitalWrite(ledPin,HIGH); //turn off the LED
		if(digitalRead(buttonPin) == 0) //read the button state, 0 if pressed
		{
			printf("Button Pressed!!");
            digitalWrite(ledPin,LOW); //turn on the LED
		}
	}
	
	return 0;
}