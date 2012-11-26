#include <TrueRandom.h>
#include <FrequencyTimer2.h>
#include <avr/pgmspace.h>
#define DELAY 80

#define LEDON  { \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}  \
}

#define LEDOFF { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}  \
}

byte col = 0;
byte leds[8][8];

int pins[17]= {  // pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
  -1, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};
int cols[8] = {  // col[xx] of leds = pin yy on led matrix
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
int rows[8] = {  // row[xx] of leds = pin yy on led matrix
  pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};

int scrollSpeed;

int MatrixOn = 0;
const int numMatrixsOn = 4;
byte MatrixsOn[numMatrixsOn][1][1] = {
  LEDON,LEDON,LEDON,LEDON
};

int MatrixOff = 0;
const int numMatrixsOff = 1;
byte MatrixsOff[numMatrixsOff][1][1] = {
  LEDOFF,LEDOFF,LEDOFF,LEDOFF
};


void setup() {
  Serial.begin(9600);  //Set up Serial Read
  for (int i = 1; i <= 16; i++) // sets the pins as output
    pinMode(pins[i], OUTPUT);
 
  for (int i = 1; i <= 8; i++) // set up cols
    digitalWrite(cols[i - 1], LOW);
  for (int i = 1; i <= 8; i++) // set up rows
    digitalWrite(rows[i - 1], LOW);
  clearLeds();
  FrequencyTimer2::disable(); // Turn off toggling of pin 11  
  FrequencyTimer2::setPeriod(2000); // Set refresh rate (interrupt timeout period)
  FrequencyTimer2::setOnOverflow(display); // Set interrupt routine to be called
}

void loop() {    

       for (int i = 1; i <= numMatrixsOn; i++){
          MatrixOn = ++MatrixOn % numMatrixOn;
          scrollSpeed = 80;
          slideMatrixOn(MatrixOn, scrollSpeed);
        } 
       // THIS IS TO REVERSE THE ORDER THAT THE CHARACTERS ARE DISPLAYED
       //slidePattern(numPatterns - pattern -1, 60);
     }





void scrollMsg( char *msg ) {
  char *ptr = msg;
  clearLeds();
  while( *ptr ) {
    slideChar( *ptr++, DELAY );
  }
  // A final space
  slideChar( ' ', DELAY) ;
}

void clearLeds() {
  // Clear display array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 0;
    }
  }
}

void setChar(char ch) {
  for (int i = 0; i < 5; i++) {
    unsigned char bt = pgm_read_byte(&(smallFont [(ch-32)*5 + i] ));
    for (int j = 0; j < 8; j++) {
      leds[j][i+1] = (bt & 0x01);
      bt = bt >> 1;
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
      //if (leds[col][ row] == 1) { //This will reverse the characters so they appear 'mirror like'
      digitalWrite(rows[row], HIGH);  // Turn on this led
    }
    else {
      digitalWrite(rows[row], LOW); // Turn off this led
    }
  }
  digitalWrite(cols[col], LOW); // Turn whole column on at once (for equal lighting times)
}

void slideChar(char ch, int del) { //code to make the letters move
  for (int l = 0; l < 5; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    unsigned char bt = pgm_read_byte(&(smallFont [(ch-32)*5 + l] ));
    for (int j = 0; j < 8; j++) {
      leds[j][7] = (bt & 0x01);
      bt = bt >> 1;
    }
    delay(del);
  }
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 8; j++) {
      leds[j][i] = leds[j][i+1];
    }
  }

  for (int j = 0; j < 8; j++) {
    leds[j][7] = 0;
  }
  delay(del);
}












void setPattern(int pattern) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = patterns[pattern][i][j];
    }
  }
}


void slideMatrixOn(int MatrixOn, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = MatrixOn[MatrixOn][j][0 + l];
    }
    delay(del);
  }
}

void slideMatrixOff(int MatrixOff, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = MatrixOff[MatrixOff][j][0 + l];
    }
    delay(del);
  }
}

