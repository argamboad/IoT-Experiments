import RPi.GPIO as GPIO
import time
import PCF8591 as ADC

ledPin = 11 # physical pin number for the LED

def setup():
    GPIO.setwarnings(False) # don't show warnings if GPIO is in use
    GPIO.setmode(GPIO.BOARD) # use GPIO by physical location
    GPIO.setup(ledPin,GPIO.OUT) # initialize the LED pin as output
    ADC.setup(0x48)

def loop():
    while True:
        value = ADC.read(0) # read the potentiometer value
        ms = float(value) / 1000
        print 'Milliseconds: ' + str(ms)
        ADC.write(ms)
        print "Led ON..."
        GPIO.output(ledPin,GPIO.LOW) # turn on led
        time.sleep(ms) # wait for the number of seconds in ms
        print "Led OFF..."
        GPIO.output(ledPin,GPIO.HIGH) # turn off led
        time.sleep(ms) # wait for the number of seconds in ms

def destroy():
    ADC.write(0)
    GPIO.output(ledPin,GPIO.HIGH) # turn off led
    GPIO.cleanup() # release resource

if __name__ == '__main__': # program start from here
    try:
        setup()
        loop()

    except KeyboardInterrupt: # when 'Ctrl+C' is pressed, the child program destroy() will be  executed.
        destroy()