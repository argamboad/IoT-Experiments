const int redPin = 8; //the number of the LED module red pin
const int greenPin = 9; //the number of the LED module green pin 
const int bluePin = 10; //the number of the LED module blue pin 

int ms;

void setup()
{ 
  pinMode(redPin, OUTPUT); //initialize the LED red pin as output
  pinMode(greenPin, OUTPUT); //initialize the LED green pin as output
  pinMode(bluePin, OUTPUT); //initialize the LED blue pin as output
}    

void loop()  // run over and over again  
{    
    ms = 1000;
    //Basic colors:  
    color(255, 0, 0); //turn the RGB LED red 
    delay(ms); //delay for ms  
    color(0,255, 0); //turn the RGB LED green  
    delay(ms); //delay for ms   
    color(0, 0, 255); //turn the RGB LED blue  
    delay(ms); //delay for ms  
    //Blended colors:  
    color(237,109,0); //turn the RGB LED orange  
    delay(ms); //delay for ms   
    color(255,215,0); //turn the RGB LED yellow  
    delay(ms); //delay for ms   
    color(0,46,90); //turn the RGB LED  indigo 
    delay(ms); //delay for ms 
    color(128,0,128); //turn the RGB LED purple  
    delay(ms); //delay for ms 
}     

//Color generating function  
void color (unsigned char red, unsigned char green, unsigned char blue)     
{    
    analogWrite(redPin, red); //set the brightness of LED red  
    analogWrite(greenPin, green); //set the brightness of LED green 
    analogWrite(bluePin, blue); //set the brightness of LED blue 
}

