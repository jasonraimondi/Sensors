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

#define TURN { \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}  \
}

#define BREAK { \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0, 0, 0, 0}  \
}


byte col = 0;
byte leds[8][8];



int pins[17]= {
  -1, 5, 4, 19, 18, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};
int cols[8] = {
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
int rows[8] = {
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

int ledTurn = 0;
const int numLedsTurn = 1;
byte ledsTurn[numLedsTurn][8][8] = {
  TURN
};

int ledBreak = 0;
const int numLedsBreak = 1;
byte ledsBreak[numLedsBreak][8][8] = {
  BREAK
};


int scrollSpeed;

int button_brake = 2;
int button_turn = 3;



void setup() {
  Serial.begin(9600);  

  pinMode(button_turn, INPUT);   // initialize the pushbutton pin as an input:
  digitalWrite(button_turn, HIGH);
  pinMode(button_brake, INPUT);   // initialize the pushbutton pin as an input:
  digitalWrite(button_brake, HIGH);
  for (int i = 1; i <= 16; i++)
    pinMode(pins[i], OUTPUT);
  for (int i = 1; i <= 8; i++)
    digitalWrite(cols[i - 1], LOW);
  for (int i = 1; i <= 8; i++) 
    digitalWrite(rows[i - 1], LOW);
  clearLeds();
  // Turn off toggling of pin 1
  FrequencyTimer2::disable();
  FrequencyTimer2::setPeriod(2000);
  FrequencyTimer2::setOnOverflow(display);
}

void loop(){
  int turn_status = digitalRead(button_turn);
  int break_status = digitalRead(button_brake);
  if (break_status == LOW)
    for (int i = 1; i <= numLedsOn; i++){  //For those crazy moments when you're turning
      ledOn = ++ledOn % numLedsOn;
      scrollSpeed = 1;
      slideLedsOn(ledOn, scrollSpeed);  //Turn Left
    }
  else if (turn_status == HIGH) {
    for (int i = 1; i <= numLedsTurn; i++){  //For those crazy moments when you're turning
      ledTurn = ++ledTurn % numLedsTurn;
      scrollSpeed = 80;
      slideLedsTurn(ledTurn, scrollSpeed);  //Turn Left
    }
  }
  else if ((break_status == HIGH) && (turn_status == LOW)) {
    clearLeds();
  }
}



void clearLeds() {
  // Clear display array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 0;
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



void slideLedsTurn(int ledTurn, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = ledsTurn[ledTurn][j][0 + l];
    }
    delay(del);
  }
}

void slideLedsBreak(int ledBreak, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = ledsBreak[ledBreak][j][0 + l];
    }
    delay(del);
  }
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



