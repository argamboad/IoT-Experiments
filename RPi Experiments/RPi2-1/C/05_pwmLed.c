#include<wiringPi.h>
#include<stdio.h>

#define ledPin 1 //wiringPi pin number for the LED, only 1 and 24 support PWM

int main(void)
{
	int i;

	if(wiringPiSetup() == -1)
	{
		printf("Setup wiring Pi failed!"); //when initialize wiring failed,print messageto screen
		return 1;
	}
	
	pinMode(ledPin, PWM_OUTPUT); //initialize the LED pin as PWM output
	
	while(1)
	{
		for (i=1024; i>=0; i--) //loop from 1024 to 0 (duty cycle counts)
		{
			pwmWrite(ledPin, i); //set the brightness value of LED
			delay(5); //wait for 5 ms
		}
		for (i=0; i<=1024; i++) //loop from 0 to 1024  (duty cycle counts)
		{
			pwmWrite(ledPin, i); //set the brightness value of LED
			delay(5); //wait for 5 ms
		}

		delay(1000); //wait for 1 second
	}
	
	return 0;
}