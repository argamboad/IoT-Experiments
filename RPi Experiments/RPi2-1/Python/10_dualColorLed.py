import RPi.GPIO as GPIO
import time

redPin = 12 # physical pin number for the LED, only 12 and 35 support PWM
greenPin = 35 # physical pin number for the LED, only 12 and 35 support PWM

def setup():
    global p1
    global p2
    GPIO.setwarnings(False) # don't show warnings if GPIO is in use
    GPIO.setmode(GPIO.BOARD) # use GPIO by physical location
    GPIO.setup(redPin,GPIO.OUT) # initialize the LED red pin as output
    GPIO.setup(greenPin,GPIO.OUT) # initialize the LED green pin as output

    p1 = GPIO.PWM(redPin, 100) # setup the red pin for PWM, 100 Hz is enough not to see a blinking
    p1.start(0) # start the PWM instance with 0 duty cycle

    p2 = GPIO.PWM(greenPin, 100) # setup the green pin for PWM, 100 Hz is enough not to see a blinking
    p2.start(0) # start the PWM instance with 0 duty cycle

def loop():
    while True:
        #Blink between colors 5 times
        for i in range(0,5):
            print "Red ON, Green OFF..."
            p1.ChangeDutyCycle(0) # set the brightness of LED red
            p2.ChangeDutyCycle(100) # set the brightness of LED green
            time.sleep(0.5) # wait for half a second
            print "Red OFF, Green ON..."
            p1.ChangeDutyCycle(100) # set the brightness of LED red
            p2.ChangeDutyCycle(0) # set the brightness of LED green
            time.sleep(0.5) # wait for half a second

        print "Now fading..."

        # Change color gradually increasing red while decreasing green
        for dc in range(100, -1, -1): # loop the duty cycle from 100% to 0%
            p1.ChangeDutyCycle(dc) # set the brightness of LED red
            p2.ChangeDutyCycle(100 - dc) # set the brightness of LED green
            time.sleep(0.05) #wait for 50 ms
        # Change color gradually increasing green while decreasing red
        for dc in range(0, 101, 1): # loop the duty cycle from 0% to 100%
            p1.ChangeDutyCycle(dc) # set the brightness of LED red
            p2.ChangeDutyCycle(100 - dc) # set the brightness of LED green
            time.sleep(0.05) #wait for 50 ms

        time.sleep(1) #wait for 1 second

def destroy():
    p1.stop() # stop the PWM instance
    p2.stop() # stop the PWM instance
    GPIO.output(redPin,GPIO.HIGH) # turn off LED red
    GPIO.output(greenPin,GPIO.HIGH) # turn off LED green
    GPIO.cleanup() # release resource

if __name__ == '__main__': # program start from here
	try:
		setup()
		loop()

	except KeyboardInterrupt: # when 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()