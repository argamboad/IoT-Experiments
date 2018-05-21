import RPi.GPIO as GPIO
import time

ledPin = 12 # physical pin number for the LED, only 12 and 35 support PWM

def setup():
	global p
	GPIO.setwarnings(False) # don't show warnings if GPIO is in use
	GPIO.setmode(GPIO.BOARD) # use GPIO by physical location
	GPIO.setup(ledPin,GPIO.OUT) # initialize the LED pin as output

	p = GPIO.PWM(ledPin, 100) # setup the pin for PWM, 100 Hz is enough not to see a blinking
	p.start(0) # start the PWM instance with 0 duty cycle

def loop():
	while True:
		for dc in range(100, -1, -1): # loop the duty cycle from 100% to 0%
			p.ChangeDutyCycle(dc) # set the brightness, changing duty cycle to the value of dc
			time.sleep(0.05) #wait for 50 ms

		for dc in range(0, 101, 1): # loop the duty cycle from 0% to 100%
			p.ChangeDutyCycle(dc) # set the brightness, changing duty cycle to the value of dc
			time.sleep(0.05) #wait for 50 ms

		time.sleep(1) #wait for 1 second

def destroy():
	p.stop() # stop the PWM instance
	GPIO.output(ledPin,GPIO.HIGH) # turn off LED
	GPIO.cleanup() # release resource

if __name__ == '__main__': # program start from here
	try:
		setup()
		loop()

	except KeyboardInterrupt: # when 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()