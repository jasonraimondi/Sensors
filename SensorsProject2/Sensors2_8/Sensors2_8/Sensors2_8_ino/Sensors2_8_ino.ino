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
          -1, 5, 4, 3, 2, 50, 51, 52, 53, 13, 12, 11, 10, 9, 8, 7, 6};
int cols[8] = {  // col[xx] of leds = pin yy on led matrix
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
int rows[8] = {  // row[xx] of leds = pin yy on led matrix
  pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};

byte colTwo = 0;
byte ledsTwo[8][8];
int pinsTwo[17]= {  // pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
          -2, 41, 40, 39, 38, 37, 36, 35, 34, 49, 48, 47, 46, 45, 44, 43, 42};
int colsTwo[8] = {  // col[xx] of leds = pin yy on led matrix
  pinsTwo[13], pinsTwo[3], pinsTwo[4], pinsTwo[10], pinsTwo[06], pinsTwo[11], pinsTwo[15], pinsTwo[16]};
int rowsTwo[8] = {  // row[xx] of leds = pin yy on led matrix
  pinsTwo[9], pinsTwo[14], pinsTwo[8], pinsTwo[12], pinsTwo[1], pinsTwo[7], pinsTwo[2], pinsTwo[5]};




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

int ledLeft = 0;
const int numLedsLeft = 1;
byte ledsLeft[numLedsLeft][8][8] = {
  LEFT
};

int ledRight = 0;
const int numLedsRight = 1;
byte ledsRight[numLedsRight][8][8] = {
  RIGHT
};







int ledOnTwo = 0;
const int numLedsOnTwo = 1;
byte ledsOnTwo[numLedsOnTwo][8][8] = {
  ON
};

int ledOffTwo = 0;
const int numLedsOffTwo = 1;
byte ledsOffTwo[numLedsOffTwo][8][8] = {
  OFF
};

int ledLeftTwo = 0;
const int numLedsLeftTwo = 1;
byte ledsLeftTwo[numLedsLeftTwo][8][8] = {
  LEFT
};

int ledRightTwo = 0;
const int numLedsRightTwo = 1;
byte ledsRightTwo[numLedsRightTwo][8][8] = {
  RIGHT
};

int scrollSpeed;
int button = 22;     // the number of right hand button pin


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
  FrequencyTimer2::setOnOverflow(displayOne);
  //  setPattern(pattern);
  
  
  clearLedsTwo();
  // Turn off toggling of pin 11
  FrequencyTimer2::disable();
  // Set refresh rate (interrupt timeout period)
  FrequencyTimer2::setPeriod(2000);
  // Set interrupt routine to be called
  FrequencyTimer2::setOnOverflow(displayTwo);
  //  setPattern(pattern);
}

void loop(){
  
  
  int state = digitalRead(button);
  if (state == HIGH) {
      for (int i = 1; i <= numLedsRight; i++){  //For those crazy moments when you're turning
        ledRight = ++ledRight % numLedsRight;
        scrollSpeed = 90;
        slideLedsLeft(numLedsLeft - ledLeft -1, scrollSpeed); //Turn Right
//        slideLedsRight(ledRight, scrollSpeed);  //Turn Left 
    }
    delay(10);
  }
  else {
    for (int i = 1; i <= numLedsOnTwo; i++){  //For those crazy moments when you're turning
      ledOnTwo = ++ledOnTwo % numLedsOnTwo;
      scrollSpeed = 80;
      slideLedsOnTwo(ledOnTwo, scrollSpeed);  //Turn Left 
    }
  }
}






