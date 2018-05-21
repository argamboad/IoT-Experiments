import RPi.GPIO as GPIO
import time
import PCF8591 as ADC

ledPin = 12 # physical pin number for the LED, only 12 and 35 support PWM

def setup():
    global p
    GPIO.setwarnings(False) # don't show warnings if GPIO is in use
    GPIO.setmode(GPIO.BOARD) # use GPIO by physical location
    GPIO.setup(ledPin,GPIO.OUT) # initialize the LED pin as output
    ADC.setup(0x48)

    p = GPIO.PWM(ledPin, 100) # setup the pin for PWM, 100 Hz is enough not to see a blinking
    p.start(0) # start the PWM instance with 0 duty cycle

def loop():
    while True:
        value = ADC.read(0) # read the potentiometer value
        dc = value / 2.55 # duty cycle goes from 0 to 100, the potentiometer value from 0 to 255
        print 'Value: ' + str(value)
        print 'DC: ' + str(dc)
        p.ChangeDutyCycle(dc) # set the brightness, changing duty cycle to the value of dc 
        ADC.write(value)
        time.sleep(0.05) # wait for 50 ms

def destroy():
    p.stop() # stop the PWM instance
    ADC.write(0)
    GPIO.output(ledPin,GPIO.HIGH) # turn off led
    GPIO.cleanup() # release resource

if __name__ == '__main__': # program start from here
    try:
        setup()
        loop()

    except KeyboardInterrupt: # when 'Ctrl+C' is pressed, the child program destroy() will be  executed.
        destroy()