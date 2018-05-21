import RPi.GPIO as GPIO
import time

ledPin = 11

def setup():
	GPIO.setmode(GPIO.BOARD)) # Numbers GPIOs by physical location
	GPIO.setup(ledPin,GPIO.OUT) # Set LedPin's mode is output
	GPIO.output(ledPin,GPIO.HIGH) # Set LedPin high(+3.3V) to off led


def loop():
	while True:
		print "...led ON"
		GPIO.output(ledPin,GPIO.LOW)
		time.sleep(2)
		print "...led OFF"
		GPIO.output(ledPin,GPIO.HIGH)
		time.sleep(2)

def destroy():
	GPIO.output(ledPin,GPIO.HIGH)
	GPIO.cleanup() # Release resource

if __name__ == '__main__': # Program start from here
	setup()
	try:
		loop()

	except KeyboardInterrupt: # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()
