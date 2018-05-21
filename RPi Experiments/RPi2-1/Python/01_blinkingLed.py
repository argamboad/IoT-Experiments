import RPi.GPIO as GPIO
import time

ledPin = 11 # physical pin number for the LED

def setup():
    GPIO.setwarnings(False) # don't show warnings if GPIO is in use
    GPIO.setmode(GPIO.BOARD) # use GPIO by physical location
    GPIO.setup(ledPin,GPIO.OUT) # initialize the LED pin as output
    GPIO.output(ledPin,GPIO.HIGH) # turn off led

def loop():
	while True:
		print "Led ON..."
		GPIO.output(ledPin,GPIO.LOW) # turn on led
		time.sleep(0.5) # wait for half a second
		print "Led OFF..."
		GPIO.output(ledPin,GPIO.HIGH) # turn off led
		time.sleep(0.5) # wait for half a second

def destroy():
	GPIO.output(ledPin,GPIO.HIGH) # turn off led
	GPIO.cleanup() # release resource

if __name__ == '__main__': # program start from here
	try:
		setup()
		loop()

	except KeyboardInterrupt: # when 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()