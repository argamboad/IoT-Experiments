#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define uchar unsigned char

#define redPin 0 //the number of the LED module red pin
#define greenPin 1 //the number of the LED module green pin
#define bluePin 2 //the number of the LED module blue pin

void ledInit(void)
{
	softPwmCreate(redPin, 0, 100); //initialize the LED red pin as pwm output
	softPwmCreate(greenPin, 0, 100); //initialize the LED green pin as pwm output
	softPwmCreate(bluePin, 0, 100); //initialize the LED blue pin as pwm output
}

//Color generating function 
void ledColorSet(uchar red, uchar green, uchar blue)
{
	softPwmWrite(redPin, red); //set the brightness of LED red  
	softPwmWrite(greenPin, green); //set the brightness of LED green 
	softPwmWrite(bluePin, blue); //set the brightness of LED blue 
}

int main(void)
{
    int i;
    int ms;

    if(wiringPiSetup() == -1)
    { 
		printf("setup wiringPi failed !"); //when initialize wiring failed,print messageto screen
		return 1; 
	}
	
	ledInit();

    while(1)
    {
        ms = 1000;
        //Basic colors:
		ledColorSet(0xff,0x00,0x00); //turn the RGB LED red	
		delay(ms);
		ledColorSet(0x00,0xff,0x00); //turn the RGB LED green
		delay(ms);
		ledColorSet(0x00,0x00,0xff); //turn the RGB LED blue
		delay(ms);
        //Blended colors:
		ledColorSet(0xed,0x6d,0x00); //turn the RGB LED orange
		delay(ms);
		ledColorSet(0xff,0xd7,0x00); //turn the RGB LED yellow
		delay(ms);
		ledColorSet(0x00,0x2e,0x5a); //turn the RGB LED indigo
		delay(ms);
		ledColorSet(0x80,0x00,0x80); //turn the RGB LED purple
		delay(ms);
	}

	return 0;
}