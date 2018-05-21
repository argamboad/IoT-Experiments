
import RPi.GPIO as GPIO
import time

SDI   = 11 # Pin number for SDI (Serial Data Input) pin in 74HC595
RCLK  = 12 # Pin number for RCLK / SH_CP pin in 74HC595
SRCLK = 13 # Pin number for SRCLK / ST_CP pin in 74HC595

# Arrray of bytes in hexadecimal, the binary representation is as follows:
# 00000000,00000001,00000011 and so on until 0xff = 11111111 then continues like this 01111111, 00111111 and so on
# where 0s are turned off LEDs and 1s are turned on LEDs.
LEDs = [0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00]

def setup():
	GPIO.setwarnings(False)
	GPIO.setmode(GPIO.BOARD)	 # Use GPIO by physical location

	# Set the pins in 74HC595 as output
	GPIO.setup(SDI, GPIO.OUT)
	GPIO.setup(RCLK, GPIO.OUT)
	GPIO.setup(SRCLK, GPIO.OUT)

	# Initialize the pins in 74HC595 in LOW
	GPIO.output(SDI, GPIO.LOW)
	GPIO.output(RCLK, GPIO.LOW)
	GPIO.output(SRCLK, GPIO.LOW)

def hc595_in(dat): 
	for bit in range(0, 8):	# Set the byte's bits in the 74HC595 in serial
		GPIO.output(SDI, 0x80 & (dat << bit))
		GPIO.output(SRCLK, GPIO.HIGH)
		time.sleep(0.001)
		GPIO.output(SRCLK, GPIO.LOW)

def hc595_out(): # Refresh 74HC595
	GPIO.output(RCLK, GPIO.HIGH)
	time.sleep(0.001)
	GPIO.output(RCLK, GPIO.LOW)

def loop():
	ms = 0.1 # Milliseconds for the sleep period
	while True:
		for i in range(0, len(LEDs)): # //Send the bytes in the array to the 74HC595 to drive the LEDs according to each byte in the array
			hc595_in(LEDs[i])
			hc595_out()
			time.sleep(ms)
		
		for i in range(len(LEDs)-1, -1, -1): # //Send the bytes in the array to the 74HC595 to drive the LEDs according to each byte in the array in reverse order
			hc595_in(LEDs[i])
			hc595_out()
			time.sleep(ms)

def destroy():   # When program ending, the function is executed. 
	GPIO.cleanup()

if __name__ == '__main__': # Program starting from here 
	setup() 
	try:
		loop()  
	except KeyboardInterrupt:  
		destroy()  