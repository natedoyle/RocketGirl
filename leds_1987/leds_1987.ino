void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  // turn on some lights, or don't. It doesn't matter to me.
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

// ----------------------------------------------------------------------
// Set blink time
// ----------------------------------------------------------------------

int blinkstart = millis();

int blinkonwidth = 1000;
int blinkoffwidth = 1000;

// ----------------------------------------------------------------------
// Set brightness with PWM
// ----------------------------------------------------------------------
// Once working, we'll take the brightness off of analog input A0
// which will read the voltage (0-5V) from a potentiometer (aka pot).
  int brightness = analogRead(A0);  // goes from 0 to 1023
  //int brightness = 750;
  int fullbright = 1023;
  int brightwidth = 25;
  float brightpercent = float(brightness) / float(fullbright);
  int brightondelay = brightwidth * brightpercent;
  int brightoffdelay = brightwidth - brightondelay;
  Serial.println(brightness);

  int blinkcurrent = 0;
  while (blinkcurrent < blinkonwidth) {  
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(brightondelay);              // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(brightoffdelay);              // wait for a second
    blinkcurrent = millis() - blinkstart;
  }
  
  delay(blinkoffwidth);
}
