#include <FrequencyTimer2.h>

#define ON { \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}  \
}
#define OFF { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}  \
}

#define LEFT { \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}  \
}

#define RIGHT { \
    {0, 0, 0, 0, 1, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 1}, \
    {0, 0, 0, 0, 0, 0, 0, 1}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 1, 0, 0, 0}  \
}


byte col = 0;
byte leds[8][8];


int pins[17]= {  // pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
  -1, 5, 4, 3, 18, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};
int cols[8] = {  // col[xx] of leds = pin yy on led matrix
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
int rows[8] = {  // row[xx] of leds = pin yy on led matrix
  pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};




int ledOn = 0;
const int numLedsOn = 1;
byte ledsOn[numLedsOn][8][8] = {
  ON
};

int ledOff = 0;
const int numLedsOff = 1;
byte ledsOff[numLedsOff][8][8] = {
  OFF
};

int ledTurnLeft = 0;
const int numLedsTurnLeft = 1;
byte ledsTurnLeft[numLedsTurnLeft][8][8] = {
  LEFT
};

int ledTurnRight = 0;
const int numLedsTurnRight = 1;
byte ledsTurnRight[numLedsTurnRight][8][8] = {
  RIGHT
};

int scrollSpeed;
int button = 2;     // the number of right hand button pin


void setup() {
  Serial.begin(9600);  

  pinMode(button, INPUT);   // initialize the pushbutton pin as an input:
  digitalWrite(button, HIGH);

  for (int i = 1; i <= 16; i++) {  // sets the pins as output
    pinMode(pins[i], OUTPUT);
  }
  for (int i = 1; i <= 8; i++) {  // set up cols and rows
    digitalWrite(cols[i - 1], LOW);
  }
  for (int i = 1; i <= 8; i++) {
    digitalWrite(rows[i - 1], LOW);
  }

  clearLeds();
  // Turn off toggling of pin 11
  FrequencyTimer2::disable();
  // Set refresh rate (interrupt timeout period)
  FrequencyTimer2::setPeriod(2000);
  // Set interrupt routine to be called
  FrequencyTimer2::setOnOverflow(display);
  //  setPattern(pattern);
}

void loop(){
  int state = digitalRead(button);
  if (state == HIGH) {
    for (int l = 1; l <= 2; l++){
      for (int i = 1; i <= numLedsTurnRight; i++){  //For those crazy moments when you're turning
        ledTurnRight = ++ledTurnRight % numLedsTurnRight;
        scrollSpeed = 40;
        slideLedsTurnRight(numLedsTurnRight - ledTurnRight -1, 60); //Turn Right
      }
    }
  }
  else {
    for (int i = 1; i <= numLedsOff; i++){  //For those crazy moments when you're turning
      ledOff = ++ledOff % numLedsOff;
      scrollSpeed = 80;
      slideLedsOff(ledOff, scrollSpeed);  //Turn Left 
    }
  }
}

//boolean handle_button()
//{
//  int button_pressed = !digitalRead(button); // pin low -> pressed
//  return button_pressed;
//}







