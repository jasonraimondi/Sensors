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
    {0, 0, 0, 1, 0, 0, 0, 1}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 1, 0, 0}, \
    {1, 0, 0, 0, 1, 0, 0, 0}, \
    {1, 0, 0, 0, 1, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 1}  \
}
#define RIGHT { \
    {1, 0, 0, 0, 1, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 1}, \
    {0, 0, 0, 1, 0, 0, 0, 1}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 1, 0, 0}, \
    {1, 0, 0, 0, 1, 0, 0, 0}  \
}

byte col = 0;
byte leds[8][8];

int pins[17]= {  // pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
  -1, 5, 4, 3, 2, 50, 51, 52, 53, 13, 12, 11, 10, 9, 8, 7, 6};
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

int scrollSpeed;
const int rightButton = 40;     // the number of right hand button pin
int rightButtonState = 0;         // variable for reading the pushbutton status
const int leftButton = 41;     // the number of right hand button pin
int leftButtonState = 0;

void setup() {
  Serial.begin(9600);  
  pinMode(rightButton, INPUT);   // initialize the pushbutton pin as an input:
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
  rightButtonState = digitalRead(rightButton);
//  leftButtonState = digitalRead(leftButton);
  if (rightButtonState == LOW){
    for (int i = 1; i <= numLedsRight; i++){  //For those crazy moments when you're turning
      ledRight = ++ledRight % numLedsRight;
      scrollSpeed = 80;
      slideLedsRight(numLedsRight - ledRight -1, 60);
    }
    
  }
      for (int i = 1; i <= numLedsLeft; i++){  //For those crazy moments when you're turning
      ledLeft = ++ledLeft % numLedsLeft;
      scrollSpeed = 80;
      slideLedsLeft(numLedsLeft - ledLeft -1, 60);
    }
  
  clearLeds();
  
  

  
    // THIS IS TO REVERSE THE ORDER THAT THE CHARACTERS ARE DISPLAYED
    //slidePattern(numPatterns - pattern -1, 60);

  
}


void clearLeds() {
  // Clear display array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 0;
    }
  }
}

void setPattern(int ledOn) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = ledsOn[ledOn][i][j];
    }
  }
}

// Interrupt routine
void display() {
  digitalWrite(cols[col], HIGH);  // Turn whole previous column off
  col++;
  if (col == 8) {
    col = 0;
  }
  for (int row = 0; row < 8; row++) {
    if (leds[col][7 - row] == 1) {
      digitalWrite(rows[row], HIGH);  // This Value used to be LOW, I switched it to HIGH for Our LED MATRIX
    }
    else { 
      digitalWrite(rows[row], LOW); // This Value used to be HIGH, I switched it to LOW for Our LED MATRIX
    }
  }
  digitalWrite(cols[col], LOW); // Turn whole column on at once (for equal lighting times)
}

void slideLedsOn(int ledOn, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = ledsOn[ledOn][j][0 + l];
    }
    delay(del);
  }
}

void slideLedsOff(int ledOff, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = ledsOff[ledOff][j][0 + l];
    }
    delay(del);
  }
}

void slideLedsLeft(int ledLeft, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = ledsLeft[ledLeft][j][0 + l];
    }
    delay(del);
  }
}

void slideLedsRight(int ledRight, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = ledsRight[ledRight][j][0 + l];
    }
    delay(del);
  }
}




