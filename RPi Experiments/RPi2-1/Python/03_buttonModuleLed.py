import RPi.GPIO as GPIO
import time

ledPin = 11 # physical pin number for the LED
buttonPin = 12 # physical pin number for the button module

def setup():
    GPIO.setwarnings(False) # don't show warnings if GPIO is in use
    GPIO.setmode(GPIO.BOARD) # use GPIO by physical location
    GPIO.setup(ledPin,GPIO.OUT) # initialize the LED pin as output
    GPIO.setup(buttonPin,GPIO.IN) # initialize the button module pin as input
    GPIO.output(ledPin,GPIO.HIGH) # turn off led
    GPIO.add_event_detect(buttonPin, GPIO.BOTH, callback=handleLed, bouncetime=200) # create event for button press/release
    
def handleLed(ev=None):
    if GPIO.input(buttonPin):
        print 'Button Released!!'
        GPIO.output(ledPin,GPIO.HIGH) # turn off led
    else:
        print 'Button Pressed!!'
        GPIO.output(ledPin,GPIO.LOW) # turn on led

def loop():
	while True:
		pass

def destroy():
	GPIO.output(ledPin,GPIO.HIGH) # turn off led
	GPIO.cleanup() # release resource

if __name__ == '__main__': # program start from here
	try:
        setup()
		loop()

	except KeyboardInterrupt: # when 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()