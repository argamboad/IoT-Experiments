import RPi.GPIO as GPIO
import time

pins = [7, 11, 13, 15, 12, 16, 18, 22] # physical pin numbers for the LEDs
invertedPins = [22, 18, 16, 12, 15, 13, 11, 7] # physical pin numbers for the LEDs in reverse order

def setup():
    GPIO.setwarnings(False) # don't show warnings if GPIO is in use
    GPIO.setmode(GPIO.BOARD)        # use GPIO by physical location
    for pin in pins:                # iterate throug all pin numbers
        GPIO.setup(pin, GPIO.OUT)   # initialize the LED pin as output
        GPIO.output(pin, GPIO.HIGH) # turn off LED

def loop():
    while True:
        ms = 0.2
        for pin in pins: # turn on LEDs from left to right
            GPIO.output(pin, GPIO.LOW)	
            time.sleep(ms)
        for pin in invertedPins: # turn off LEDs from right to left
            GPIO.output(pin, GPIO.HIGH)
            time.sleep(ms)
        for pin in invertedPins: # turn on LEDs from right to left
            GPIO.output(pin, GPIO.LOW)	
            time.sleep(ms)
        for pin in pins: # turn off LEDs from left to right
            GPIO.output(pin, GPIO.HIGH)	
            time.sleep(ms)

def destroy():
	for pin in pins:
		GPIO.output(pin, GPIO.HIGH)    # turn off all LEDs
	GPIO.cleanup()                     # release resource

if __name__ == '__main__':     # program start from here
	setup()
	try:
		loop()
	except KeyboardInterrupt:  # when 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()
