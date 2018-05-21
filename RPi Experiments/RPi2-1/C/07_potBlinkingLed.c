#include<wiringPi.h>
#include<stdio.h>
#include<pcf8591.h>

#define PCF 120 //base pin for pcf8591
#define ledPin 0 //wiringPi pin number for the LED

int main(void)
{
    int value;
    int dc;

    if(wiringPiSetup() == -1)
	{
		printf("Setup wiring Pi failed!");
		return 1;
    };
	
	pinMode(ledPin, OUTPUT); //initialize the LED pin as output
    
    pcf8591Setup(PCF, 0x48); //setup pcf8591 on address 0x48

    while(1)
    {
        value = analogRead(PCF + 0); //read the value from potentiometer
        printf("Milliseconds: %d\n", value);
        analogWrite(PCF + 0, value);
        digitalWrite(ledPin,HIGH); //turn on the LED
		printf("Led ON...\n");
		delay(value); //wait for the number of ms in value
		digitalWrite(ledPin,LOW); //turn off the LED
		printf("Led OFF...\n"); 
		delay(value); //wait for the number of ms in value
    }

    return 0;
}