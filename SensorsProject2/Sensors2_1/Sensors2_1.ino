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

const int numPatterns = 10;
byte patterns[numPatterns][1][1] = {
  RIGHT
};

//Sets up all of the Keyboard Characters using ASCII Binary
static const unsigned char smallFont[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00 ,   // sp
  0x00, 0x00, 0x2f, 0x00, 0x00 ,   // !
  0x00, 0x07, 0x00, 0x07, 0x00 ,   // "
  0x14, 0x7f, 0x14, 0x7f, 0x14 ,   // #
  0x24, 0x2a, 0x7f, 0x2a, 0x12 ,   // $
  0x61, 0x66, 0x08, 0x33, 0x43 ,   // %
  0x36, 0x49, 0x55, 0x22, 0x50 ,   // &
  0x00, 0x05, 0x03, 0x00, 0x00 ,   // '
  0x00, 0x1c, 0x22, 0x41, 0x00 ,   // (
  0x00, 0x41, 0x22, 0x1c, 0x00 ,   // )
  0x14, 0x08, 0x3E, 0x08, 0x14 ,   // *
  0x08, 0x08, 0x3E, 0x08, 0x08 ,   // +
  0x00, 0x00, 0x50, 0x30, 0x00 ,   // ,
  0x10, 0x10, 0x10, 0x10, 0x10 ,   // -
  0x00, 0x60, 0x60, 0x00, 0x00 ,   // .
  0x20, 0x10, 0x08, 0x04, 0x02 ,   // /
  0x3E, 0x51, 0x49, 0x45, 0x3E ,   // 0
  0x00, 0x42, 0x7F, 0x40, 0x00 ,   // 1
  0x42, 0x61, 0x51, 0x49, 0x46 ,   // 2
  0x21, 0x41, 0x45, 0x4B, 0x31 ,   // 3
  0x18, 0x14, 0x12, 0x7F, 0x10 ,   // 4
  0x27, 0x45, 0x45, 0x45, 0x39 ,   // 5
  0x3C, 0x4A, 0x49, 0x49, 0x30 ,   // 6
  0x01, 0x71, 0x09, 0x05, 0x03 ,   // 7
  0x36, 0x49, 0x49, 0x49, 0x36 ,   // 8
  0x06, 0x49, 0x49, 0x29, 0x1E ,   // 9
  0x00, 0x36, 0x36, 0x00, 0x00 ,   // :
  0x00, 0x56, 0x36, 0x00, 0x00 ,   // ;
  0x08, 0x14, 0x22, 0x41, 0x00 ,   // <
  0x14, 0x14, 0x14, 0x14, 0x14 ,   // =
  0x00, 0x41, 0x22, 0x14, 0x08 ,   // >
  0x02, 0x01, 0x51, 0x09, 0x06 ,   // ?
  0x32, 0x49, 0x59, 0x51, 0x3E ,   // @
  0x7E, 0x11, 0x11, 0x11, 0x7E ,   // A
  0x7F, 0x49, 0x49, 0x49, 0x36 ,   // B
  0x3E, 0x41, 0x41, 0x41, 0x22 ,   // C
  0x7F, 0x41, 0x41, 0x22, 0x1C ,   // D
  0x7F, 0x49, 0x49, 0x49, 0x41 ,   // E
  0x7F, 0x09, 0x09, 0x09, 0x01 ,   // F
  0x3E, 0x41, 0x49, 0x49, 0x7A ,   // G
  0x7F, 0x08, 0x08, 0x08, 0x7F ,   // H
  0x00, 0x41, 0x7F, 0x41, 0x00 ,   // I
  0x20, 0x40, 0x41, 0x3F, 0x01 ,   // J
  0x7F, 0x08, 0x14, 0x22, 0x41 ,   // K
  0x7F, 0x40, 0x40, 0x40, 0x40 ,   // L
  0x7F, 0x02, 0x0C, 0x02, 0x7F ,   // M
  0x7F, 0x04, 0x08, 0x10, 0x7F ,   // N
  0x3E, 0x41, 0x41, 0x41, 0x3E ,   // O
  0x7F, 0x09, 0x09, 0x09, 0x06 ,   // P
  0x3E, 0x41, 0x51, 0x21, 0x5E ,   // Q
  0x7F, 0x09, 0x19, 0x29, 0x46 ,   // R
  0x46, 0x49, 0x49, 0x49, 0x31 ,   // S
  0x01, 0x01, 0x7F, 0x01, 0x01 ,   // T
  0x3F, 0x40, 0x40, 0x40, 0x3F ,   // U
  0x1F, 0x20, 0x40, 0x20, 0x1F ,   // V
  0x3F, 0x40, 0x38, 0x40, 0x3F ,   // W
  0x63, 0x14, 0x08, 0x14, 0x63 ,   // X
  0x07, 0x08, 0x70, 0x08, 0x07 ,   // Y
  0x61, 0x51, 0x49, 0x45, 0x43 ,   // Z
  0x00, 0x7F, 0x41, 0x41, 0x00 ,   // [
  0x55, 0x2A, 0x55, 0x2A, 0x55 ,   // checker pattern
  0x00, 0x41, 0x41, 0x7F, 0x00 ,   // ]
  0x04, 0x02, 0x01, 0x02, 0x04 ,   // ^
  0x40, 0x40, 0x40, 0x40, 0x40 ,   // _
  0x00, 0x01, 0x02, 0x04, 0x00 ,   // '
  0x20, 0x54, 0x54, 0x54, 0x78 ,   // a
  0x7F, 0x48, 0x44, 0x44, 0x38 ,   // b
  0x38, 0x44, 0x44, 0x44, 0x20 ,   // c
  0x38, 0x44, 0x44, 0x48, 0x7F ,   // d
  0x38, 0x54, 0x54, 0x54, 0x18 ,   // e
  0x08, 0x7E, 0x09, 0x01, 0x02 ,   // f
  0x0C, 0x52, 0x52, 0x52, 0x3E ,   // g
  0x7F, 0x08, 0x04, 0x04, 0x78 ,   // h
  0x00, 0x44, 0x7D, 0x40, 0x00 ,   // i
  0x20, 0x40, 0x44, 0x3D, 0x00 ,   // j
  0x7F, 0x10, 0x28, 0x44, 0x00 ,   // k
  0x00, 0x41, 0x7F, 0x40, 0x00 ,   // l
  0x7C, 0x04, 0x18, 0x04, 0x78 ,   // m
  0x7C, 0x08, 0x04, 0x04, 0x78 ,   // n
  0x38, 0x44, 0x44, 0x44, 0x38 ,   // o
  0x7C, 0x14, 0x14, 0x14, 0x08 ,   // p
  0x08, 0x14, 0x14, 0x18, 0x7C ,   // q
  0x7C, 0x08, 0x04, 0x04, 0x08 ,   // r
  0x48, 0x54, 0x54, 0x54, 0x20 ,   // s
  0x04, 0x3F, 0x44, 0x40, 0x20 ,   // t
  0x3C, 0x40, 0x40, 0x20, 0x7C ,   // u
  0x1C, 0x20, 0x40, 0x20, 0x1C ,   // v
  0x3C, 0x40, 0x30, 0x40, 0x3C ,   // w
  0x44, 0x28, 0x10, 0x28, 0x44 ,   // x
  0x0C, 0x50, 0x50, 0x50, 0x3C ,   // y
  0x44, 0x64, 0x54, 0x4C, 0x44 ,   // z
  0x00, 0x06, 0x09, 0x09, 0x06     // Degree symbol
};

// Define Quiet Messages
char quietMessage01[] = "Speak up, Introvert ";
char loudMessage13[] = "Born to be a leader "; 

byte col = 0;
byte leds[8][8];

int pins[17]= {  // pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
  -1, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};
int cols[8] = {  // col[xx] of leds = pin yy on led matrix
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
int rows[8] = {  // row[xx] of leds = pin yy on led matrix
  pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};


int analogPin = 0;              // set analog pin

int scrollSpeed;

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
       scrollMsg( quietMessage01 );
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

void slidePattern(int pattern, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patterns[pattern][j][0 + l];
    }
    delay(del);
  }
}
