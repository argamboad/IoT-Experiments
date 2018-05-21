#include <wiringPi.h>
#include <stdio.h>

#define redPin 1 //wiringPi pin number for the LED red, only 1 and 24 support PWM
#define greenPin 24 //wiringPi pin number for the LED green, only 1 and 24 support PWM

int main(void)
{
    int i;
    int val;

    if(wiringPiSetup() == -1)
    { 
		printf("setup wiringPi failed !"); //when initialize wiring failed,print messageto screen
		return 1; 
	}
    
    

    while(1)
    {
        pinMode(redPin, OUTPUT); //initialize the LED red pin as output
        pinMode(greenPin, OUTPUT); //initialize the LED green pin as output

        //Blink between colors 5 times
        for(i=1;i<=5;i++)
        {    
            digitalWrite(redPin, LOW); //turn on the LED red
            digitalWrite(greenPin, HIGH); //turn off the LED green
            printf("Red ON, Green OFF...\n");
            delay(500); //wait for half a second
            digitalWrite(redPin, HIGH); //turn off the LED red
            digitalWrite(greenPin, LOW); //turn on the LED green
            printf("Red OFF, Green ON...\n");
            delay(500); //wait for half a second
        }

        pinMode(redPin, PWM_OUTPUT); //initialize the LED red pin as PWM output
        pinMode(greenPin, PWM_OUTPUT); //initialize the LED green pin as PWM output

        printf("Now fading...\n");

        //Change color gradually increasing red while decreasing green
        for(val=1024; val>=0; val--)
        {
            pwmWrite(redPin, val); //set the brightness value of LED red
            pwmWrite(greenPin, 1024 - val); //set the brightness value of LED green
            delay(5); //wait for 10 ms
        }
        //Change color gradually increasing green while decreasing red
        for(val=0; val<=1024; val++)
        {
            pwmWrite(redPin, val); //set the brightness value of LED red
            pwmWrite(greenPin, 1024 - val); //set the brightness value of LED green
            delay(5); //wait for 10 ms
        }

        delay(1000); //wait for a second
	}

	return 0;
}
