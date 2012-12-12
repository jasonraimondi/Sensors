#include <FrequencyTimer2.h>

//#define ON { \
//    {1, 1, 1, 1, 1, 1, 1, 1}, \
//    {1, 1, 1, 1, 1, 1, 1, 1}, \
//    {1, 1, 1, 1, 1, 1, 1, 1}, \
//    {1, 1, 1, 1, 1, 1, 1, 1}, \
//    {1, 1, 1, 1, 1, 1, 1, 1}, \
//    {1, 1, 1, 1, 1, 1, 1, 1}, \
//    {1, 1, 1, 1, 1, 1, 1, 1}, \
//    {1, 1, 1, 1, 1, 1, 1, 1}  \
//}
//#define OFF { \
//    {0, 0, 0, 0, 0, 0, 0, 0}, \
//    {0, 0, 0, 0, 0, 0, 0, 0}, \
//    {0, 0, 0, 0, 0, 0, 0, 0}, \
//    {0, 0, 0, 0, 0, 0, 0, 0}, \
//    {0, 0, 0, 0, 0, 0, 0, 0}, \
//    {0, 0, 0, 0, 0, 0, 0, 0}, \
//    {0, 0, 0, 0, 0, 0, 0, 0}, \
//    {0, 0, 0, 0, 0, 0, 0, 0}  \
//}
//
//#define LEFT { \
//    {0, 0, 0, 1, 0, 0, 0, 0}, \
//    {0, 0, 1, 0, 0, 0, 0, 0}, \
//    {0, 1, 0, 0, 0, 0, 0, 0}, \
//    {1, 0, 0, 0, 0, 0, 0, 0}, \
//    {1, 0, 0, 0, 0, 0, 0, 0}, \
//    {0, 1, 0, 0, 0, 0, 0, 0}, \
//    {0, 0, 1, 0, 0, 0, 0, 0}, \
//    {0, 0, 0, 1, 0, 0, 0, 0}  \
//}
//
//#define RIGHT { \
//    {0, 0, 0, 0, 1, 0, 0, 0}, \
//    {0, 0, 0, 0, 0, 1, 0, 0}, \
//    {0, 0, 0, 0, 0, 0, 1, 0}, \
//    {0, 0, 0, 0, 0, 0, 0, 1}, \
//    {0, 0, 0, 0, 0, 0, 0, 1}, \
//    {0, 0, 0, 0, 0, 0, 1, 0}, \
//    {0, 0, 0, 0, 0, 1, 0, 0}, \
//    {0, 0, 0, 0, 1, 0, 0, 0}  \
//}

#define BUTTON_PIN        2  // Button

#define LONGPRESS_LEN    20  // Min nr of loops for a long press

enum { 
  EV_NONE=0, EV_SHORTPRESS, EV_LONGPRESS };

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
  LEFT
};

int scrollSpeed;
boolean button_was_pressed; // previous state
int button_pressed_counter; // press running duration


void setup() {

  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH); // pull-up
  Serial.begin(9600);
  button_was_pressed = false;
  button_pressed_counter = 0;

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

int handle_button()
{
  int event;
  int button_now_pressed = !digitalRead(BUTTON_PIN); // pin low -> pressed
  if (!button_now_pressed && button_was_pressed) {
    if (button_pressed_counter < LONGPRESS_LEN)
      event = EV_SHORTPRESS;
    else
      event = EV_LONGPRESS;
  }
  else
    event = EV_NONE;
  if (button_now_pressed)
    ++button_pressed_counter;
  else
    button_pressed_counter = 0;
  button_was_pressed = button_now_pressed;
  return event;
}

void loop(){
  boolean event = handle_button();
  switch (event) {
  case EV_NONE:
    break;
  case EV_SHORTPRESS:
    for (int l = 1; l <= 2; l++){
      for (int i = 1; i <= numLedsTurnRight; i++){  //For those crazy moments when you're turning
        ledTurnRight = ++ledTurnRight % numLedsTurnRight;
        scrollSpeed = 10;
        slideLedsTurnRight(numLedsTurnRight - ledTurnRight -1, 60); //Turn Right
      }
    }
    clearLeds();
    break;
  case EV_LONGPRESS:
    for (int i = 1; i <= numLedsOn; i++){  //For those crazy moments when you're turning
      ledOn = ++ledOn % numLedsOn;
      scrollSpeed = 10;
      slideLedsOn(ledOn, scrollSpeed);  //Turn Left 
    }
    clearLeds();
  }    
}

