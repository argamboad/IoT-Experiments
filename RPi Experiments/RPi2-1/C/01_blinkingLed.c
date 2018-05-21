#include<wiringPi.h>
#include<stdio.h>

#define ledPin 0 //wiringPi pin number for the LED

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("Setup wiring Pi failed!"); //when initialize wiring failed,print messageto screen
		return 1;
	}
	
	pinMode(ledPin,OUTPUT); //initialize the LED pin as output
	
	while(1)
	{
		digitalWrite(ledPin,HIGH); //turn on the LED
		printf("Led ON...\n");
		delay(500); //wait for half a second
		digitalWrite(ledPin,LOW); //turn off the LED
		printf("Led OFF...\n"); 
		delay(500); //wait for half a second
	}
	
	return 0;
}