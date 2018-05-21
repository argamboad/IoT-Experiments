#!/usr/bin/env python
import RPi.GPIO as GPIO
import time

redPin = 11 # physical pin number for the LED red
greePin = 12 # physical pin number for the LED green
bluePin = 13 # physical pin number for the LED blue

def setup():
    global pR
    global pG
    global pB

    GPIO.setwarnings(False) # don't show warnings if GPIO is in use
    GPIO.setmode(GPIO.BOARD) # use GPIO by physical location

    GPIO.setup(redPin, GPIO.OUT) # initialize the LED red pin as output
    GPIO.setup(greePin, GPIO.OUT) # initialize the LED green pin as output
    GPIO.setup(bluePin, GPIO.OUT) # initialize the LED blue pin as output

    GPIO.output(redPin, GPIO.HIGH) # turn off LED red
    GPIO.output(greePin, GPIO.HIGH) # turn off LED green
    GPIO.output(bluePin, GPIO.HIGH) # turn off LED blue

    pR = GPIO.PWM(redPin, 100) # setup the LED red pin for PWM, 100 Hz is enough not to see a blinking
    pG = GPIO.PWM(greePin, 100) # setup the LED green  pin for PWM, 100 Hz is enough not to see a blinking
    pB = GPIO.PWM(bluePin, 100) # setup the LED blue pin for PWM, 100 Hz is enough not to see a blinking

    pR.start(0) # start the PWM instance with 0 duty cycle
    pG.start(0) # start the PWM instance with 0 duty cycle
    pB.start(0) # start the PWM instance with 0 duty cycle

# Color generating function 
def ledColorSet(red, green, blue):  
	pR.ChangeDutyCycle(red) # set the brightness of LED red   
	pG.ChangeDutyCycle(green) # set the brightness of LED green
	pB.ChangeDutyCycle(blue) # set the brightness of LED blue

def loop():
    s = 1
    while True:
        # Basic colors:
        ledColorSet(100, 0, 0) # turn the RGB LED red
        time.sleep(s)
        ledColorSet(0, 100, 0) # turn the RGB LED green
        time.sleep(s)
        ledColorSet(0, 0, 100) # turn the RGB LED blue
        time.sleep(s)
        #Blended colors:
        ledColorSet(95, 52, 0) # turn the RGB LED orange
        time.sleep(s)
        ledColorSet(100, 90, 0) # turn the RGB LED yellow
        time.sleep(s)
        ledColorSet(0, 18, 40) # turn the RGB LED indigo
        time.sleep(s)
        ledColorSet(50, 0, 50) # turn the RGB LED purple
        time.sleep(s)
		
def destroy():
	pR.stop() # stop the PWM instance
	pG.stop() # stop the PWM instance
	pB.stop() # stop the PWM instance
	GPIO.output(redPin, GPIO.HIGH) # turn off LED red
	GPIO.output(greePin, GPIO.HIGH) # turn off LED green
	GPIO.output(bluePin, GPIO.HIGH) # turn off LED blue
	GPIO.cleanup() # release resource

if __name__ == '__main__': # program start from here
	try:
		setup()
		loop()

	except KeyboardInterrupt: # when 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()