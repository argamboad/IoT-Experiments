#include<wiringPi.h>
#include<stdio.h>
#include<pcf8591.h>

#define PCF 120 //base pin for pcf8591
#define ledPin 1 //wiringPi pin number for the LED, only 1 and 24 support PWM

int main(void)
{
    int value;
    int dc;

    if(wiringPiSetup() == -1)
	{
		printf("Setup wiring Pi failed!");
		return 1;
    }
	
	pinMode(ledPin, PWM_OUTPUT); //initialize the LED pin as PWM output
    
    pcf8591Setup(PCF, 0x48); //setup pcf8591 on address 0x48

    while(1)
    {
        value = analogRead(PCF + 0); //read the value from potentiometer
        dc = value * 4; //duty cycle counts goes from 0 to 1024, the potentiometer value from 0 to 255
        printf("Value: %d\n", value);
        printf("DC: %d\n", dc);
        pwmWrite(ledPin, dc); //set the LED brightness, the duty cycle counts range goes from 0 to 1024, the potentiometer value from 0 to 255
        analogWrite(PCF + 0, value);
        delay(50); //wait for 50 ms
    }

    return 0;
}