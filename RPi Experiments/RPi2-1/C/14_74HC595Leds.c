#include<wiringPi.h>
#include<stdio.h>

#define SDI 0	//wiringPi pin number for SDI (Serial Data Input) pin in 74HC595
#define RCLK 1	//wiringPi pin number for RCLK / SH_CP pin in 74HC595
#define SRCLK 2	//wiringPi pin number for SRCLK / ST_CP pin in 74HC595

//Arrray of bytes in hexadecimal, the binary representation is as follows:
//00000000,00000001,00000011 and so on until 0xff = 11111111 then continues like this 01111111, 00111111 and so on
//where 0s are turned off LEDs and 1s are turned on LEDs.
unsigned char LED[17] = {0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00};

void pulse(int pin) //Refresh 74HC595
{
	digitalWrite(pin,0);
	digitalWrite(pin,1);
}

void SIPO(unsigned char byte)
{
	int i;
	for(i = 0;i < 8;i++) //Set the byte's bits in the 74HC595 in serial 
	{
		digitalWrite(SDI,((byte & (0x80>>i)) > 0));
		pulse(SRCLK);
	}
}

void init(void)
{
	//Set the pins in 74HC595 as output
	pinMode(SDI,OUTPUT);
	pinMode(RCLK,OUTPUT);
	pinMode(SRCLK,OUTPUT);
	
	//Initialize the pins in 74HC595 in LOW
	digitalWrite(SDI,0);
	digitalWrite(RCLK,0);
	digitalWrite(SRCLK,0);
}

int main(void)
{
	int i;
	
	if(wiringPiSetup() == -1)
	{
		printf("Setup wiring Pi failed!");
		return 1;
	}
	
	init();	
	
	while(1)
	{
		for(i = 0;i < 17;i++) //Send the bytes in the array to the 74HC595 to drive the LEDs according to each byte in the array
		{
			SIPO(LED[i]);
			pulse(RCLK);
			delay(100);
		}

		for(i = 17;i >= 0;i--) //Send the bytes in the array to the 74HC595 to drive the LEDs according to each byte in the array in reverse order
		{
			SIPO(LED[i]);
			pulse(RCLK);
			delay(100);
		}
	}
	
	return 0;
}