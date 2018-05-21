import RPi.GPIO as GPIO
import time

ledPin = 11 # physical pin number for the LED
slidePin = 12 # physical pin number for the button

def setup():
    GPIO.setwarnings(False) # don't show warnings if GPIO is in use
    GPIO.setmode(GPIO.BOARD) # use GPIO by physical location
    GPIO.setup(ledPin,GPIO.OUT) # initialize the LED pin as output
    GPIO.setup(slidePin,GPIO.IN, pull_up_down=GPIO.PUD_UP) # initialize the button pin as input and use internal resistor
    GPIO.output(ledPin,GPIO.HIGH) # turn off led
    
def handleLed(ev=None):
    if GPIO.input(slidePin):
        GPIO.output(ledPin,GPIO.HIGH) # turn off led
    else:
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