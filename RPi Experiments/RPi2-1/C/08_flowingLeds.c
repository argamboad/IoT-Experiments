#include <wiringPi.h>
#include <stdio.h>

//turn on led_n
void led_on(int n)
{
	digitalWrite(n, LOW);
}

//turn off led_n
void led_off(int n)
{
	digitalWrite(n, HIGH);
}

int main(void)
{
    int i;
    int pins[8] = {7, 0, 2, 3, 1, 4, 5, 6}; //wiringPi pin numbers for the LEDs


    if(wiringPiSetup() == -1)
    { 
		printf("setup wiringPi failed !");
		return 1; 
	}

    for(i=0;i<8;i++) //iterate trough all pins
    {       
        pinMode(pins[i], OUTPUT); //initialize the LED pin as output
        led_off(pins[i]);
	}

    while(1)   
    {
        int ms = 200;
        //iterate over the pins
        //turn the led on from lowest to the highest
        for(i=0;i<8;i++)
        {   
			led_on(pins[i]);
			delay(ms); //wait for ms
        }
        //fade from the highest to the lowest
        for(i=8;i>=0;i--)
        {  
            led_off(pins[i]);
			delay(ms); //wait for ms			
        }
        //turn the led on from highest to the lowest
        for(i=8;i>=0;i--)
        {  
            led_on(pins[i]);
			delay(ms); //wait for ms		
        }
        //fade from the lowest to the highest
        for(i=0;i<8;i++)
        {   
			led_off(pins[i]);
			delay(ms); //wait for ms
        }
	}

	return 0;
}