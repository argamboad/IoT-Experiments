const int latchPin = 9;     //Pin connected to ST_CP of 74HC595
const int clockPin = 10;    //Pin connected to SH_CP of 74HC595 
const int dataPin = 8;      //Pin connected to DS of 74HC595

byte leds = 0;

void setup()
{
    //initialize pins as output
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
} 

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void loop()
{
    int ms = 100;
    
    leds = 0;

    updateShiftRegister();

    delay(ms);

    for (int i = 0; i < 8; i++)
    {
        bitSet(leds, i);
        updateShiftRegister();
        delay(ms);
    }

    for (int i = 0; i < 8; i++)
    {
        bitClear(leds, i);
        updateShiftRegister();
        delay(ms);
    }

    for (int i = 7; i >= 0; i--)
    {
        bitSet(leds, i);
        updateShiftRegister();
        delay(ms);
    }

    for (int i = 7; i >= 0; i--)
    {
        bitClear(leds, i);
        updateShiftRegister();
        delay(ms);
    }
}