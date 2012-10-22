
#include <FrequencyTimer2.h>
#include <avr/pgmspace.h>
#define DELAY 80

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

byte col = 0;
byte leds[8][8];

int pins[17]= {  // pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
  -1, 5, 4, 3, 2, 50, 51, 52, 53, 13, 12, 11, 10, 9, 8, 7, 6};
int cols[8] = {  // col[xx] of leds = pin yy on led matrix
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
int rows[8] = {  // row[xx] of leds = pin yy on led matrix
  pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};

char quietMessage01[] = "01 "; // 5 11 19 25 35 45
char quietMessage02[] = "02 "; // 29 51
char quietMessage03[] = "03 "; // 1 13 15 17 31 33 41 
char quietMessage04[] = "04 "; // 3 9 21 43 47
char quietMessage05[] = "05 "; // 7 23 27 37 39 49
char quietMessage06[] = "06 "; // 
char quietMessage07[] = "07 "; // 
char quietMessage08[] = "08 "; // 
char quietMessage09[] = "09 "; // 
char quietMessage10[] = "10 "; // 
char quietMessage11[] = "11 "; // 
char quietMessage12[] = "12 "; // 
char quietMessage13[] = "13 "; // 
char quietMessage14[] = "14 "; // 
char quietMessage15[] = "15 "; // 
char quietMessage16[] = "16 "; // 
char quietMessage17[] = "17 "; // 
char quietMessage18[] = "18 "; // 
char quietMessage19[] = "19 "; // 12 30 46
char quietMessage20[] = "20 "; // 32 40 44 48
char quietMessage21[] = "21 "; // 6 14 20 24 34 42 50
char quietMessage22[] = "22 "; // 4 8 16 26 28 36 52
char quietMessage23[] = "23 "; // 2 10 18 22 38
char quietMessage24[] = "24 "; // 

char loudMessage01[] = "L01 "; //
char loudMessage02[] = "L02 "; //
char loudMessage03[] = "L03 "; //
char loudMessage04[] = "L04 "; //
char loudMessage05[] = "L05 "; //
char loudMessage06[] = "L06 "; //
char loudMessage07[] = "L07 "; //
char loudMessage08[] = "L08 "; //
char loudMessage09[] = "L09 "; //
char loudMessage10[] = "L10 "; //
char loudMessage11[] = "L11 "; //
char loudMessage12[] = "L12 "; //

int scrollSpeed;

int analogPin = 0;          // set analog pin
int sensorValue = 0;        // store the value coming from the sensor
int mappedValue;            // store the new value remapped from 0 to 100
int volumeThreshold = 50;   // volume threshold out of 100
int microphoneBottom = 418;  // this is the bottom (0%) value for the microphone sensor input
int microphoneTop = 900;  // this is the top (100%) value for the microphone sensor input
int delayBetweenWords = 3000;  // delay time between words
int ledPinNum = 48;         // LED output pin
int ledTimeOn = 1;          // number of loops the LED is on
int numQuiet = 1;
int numQuietTotal = 2;
int numLoud = 1;
int numLoudTotal = 2;
int number = 1;

boolean largerSwitcherQuiet = true;
boolean switcherQuiet = true;
boolean switcherLoud = true;

void setup() {
  Serial.begin(9600);  
   // sets the pins as output
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // set up cols and rows
  for (int i = 1; i <= 8; i++) {
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
  pinMode(ledPinNum, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(analogPin);     
  // print out the value you read:
  digitalWrite(ledPinNum, HIGH);
  delay(10);
  digitalWrite(ledPinNum, LOW);
  mappedValue = map(sensorValue, microphoneBottom, microphoneTop, 0, volumeThreshold);
  printValues();
  if (mappedValue <= volumeThreshold) {
    int numQuiet = random(1,6);
    if (largerSwitcherQuiet){
      if (switcherQuiet) {
        if (numQuiet == 1){
          scrollMsg( quietMessage01 );
        }
        if (numQuiet == 2){
          scrollMsg( quietMessage02 );
        }
        if (numQuiet == 3){
          scrollMsg( quietMessage03 );
        }
        if (numQuiet == 4){
          scrollMsg( quietMessage04 );
        }
        if (numQuiet == 5){
          scrollMsg( quietMessage05 );
        }
        if (numQuiet == 6){
          scrollMsg( quietMessage06 );
        }
      }
      if (!switcherQuiet) {
        if (numQuiet == 1){
          scrollMsg( quietMessage07 );
        }
        if (numQuiet == 2){
          scrollMsg( quietMessage08 );
        }
        if (numQuiet == 3){
          scrollMsg( quietMessage09 );
        }
        if (numQuiet == 4){
          scrollMsg( quietMessage10 );
        }
        if (numQuiet == 5){
          scrollMsg( quietMessage11 );
        }
        if (numQuiet == 6){
          scrollMsg( quietMessage12 );
        }
      }
    }
    if (!largerSwitcherQuiet){
      if (switcherQuiet) {
        if (numQuiet == 1){
          scrollMsg( quietMessage13 );
        }
        if (numQuiet == 2){
          scrollMsg( quietMessage14 );
        }
        if (numQuiet == 3){
          scrollMsg( quietMessage15 );
        }
        if (numQuiet == 4){
          scrollMsg( quietMessage16 );
        }
        if (numQuiet == 5){
          scrollMsg( quietMessage17 );
        }
        if (numQuiet == 6){
          scrollMsg( quietMessage18 );
        }
      }
      if (!switcherQuiet) {
        if (numQuiet == 1){
          scrollMsg( quietMessage19 );
        }
        if (numQuiet == 2){
          scrollMsg( quietMessage20 );
        }
        if (numQuiet == 3){
          scrollMsg( quietMessage21 );
        }
        if (numQuiet == 4){
          scrollMsg( quietMessage22 );
        }
        if (numQuiet == 5){
          scrollMsg( quietMessage23 );
        }
        if (numQuiet == 6){
          scrollMsg( quietMessage24 );
        }
      }
    }
    largerSwitcherQuiet = !largerSwitcherQuiet;
    switcherQuiet = !switcherQuiet;
  }
  //LOUDNESS STRING
  if (mappedValue > volumeThreshold) {
    int numLoud = random(1,6);
    if (switcherLoud) {
      if (numLoud == 1){
        scrollMsg( loudMessage01 );
      }
      if (numLoud == 2)
        scrollMsg( loudMessage02 );
      }
      if (numLoud == 3){
        scrollMsg( loudMessage03 );
      }
      if (numLoud == 4){
        scrollMsg( loudMessage04 );
      }
      if (numLoud == 5){
        scrollMsg( loudMessage05 );
      }
      if (numLoud == 6){
        scrollMsg( loudMessage06 );
      }
    }
    if (!switcherLoud) {
      if (numLoud == 1){
        scrollMsg( loudMessage07 );
      }
      if (numLoud == 2){
        scrollMsg( loudMessage08 );
      }
      if (numLoud == 3){
        scrollMsg( loudMessage09 );
      }
      if (numLoud == 4){
        scrollMsg( loudMessage10 );
      }
      if (numLoud == 5){
        scrollMsg( loudMessage11 );
      }
      if (numLoud == 6){
        scrollMsg( loudMessage12 );
      }
    }
    switcherLoud = !switcherLoud;
  }
  delay(delayBetweenWords);
  number++;
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
    //if (leds[col][ row] == 1) {
      digitalWrite(rows[row], HIGH);  // Turn on this led
    }
    else {
      digitalWrite(rows[row], LOW); // Turn off this led
    }
  }
  digitalWrite(cols[col], LOW); // Turn whole column on at once (for equal lighting times)
}

void printValues() {
//  Serial.print("sensorValue: ");
//  Serial.println(sensorValue);   
//  Serial.println();    
//  Serial.print("map ");
//  Serial.print(microphoneBottom);
//  Serial.print(" - ");
//  Serial.print(microphoneTop);
//  Serial.print(" to 0 - ");
//  Serial.print(volumeThreshold);
//  Serial.print("                    : ");
//  Serial.println(mappedValue);
//  Serial.println();
}

void slideChar(char ch, int del) {
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
