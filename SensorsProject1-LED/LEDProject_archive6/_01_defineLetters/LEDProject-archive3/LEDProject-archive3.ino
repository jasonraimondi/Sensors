
#include <FrequencyTimer2.h>


#define A  { \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}  \
}

#define B { \
    {0, 0, 1, 1, 0, 0, 0, 0},  \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0} \
}

#define C { \
    {0, 0, 0, 1, 1, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0} \
}

#define D { \
    {0, 0, 1, 1, 0, 0, 0, 0},  \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0} \
}

#define E { \
    {0, 0, 1, 1, 1, 1, 0, 0},  \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0} \
}

#define F { \
    {0, 0, 1, 1, 1, 1, 0, 0},  \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0} \
}

#define G { \
    {0, 0, 0, 1, 1, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 1, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 1, 0, 0} \
}

#define H { \
    {0, 0, 1, 0, 0, 1, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0} \
}

#define I { \
    {0, 1, 1, 1, 1, 1, 0, 0},  \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 0, 0} \
}

#define J { \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}  \
}

#define K { \
    {0, 0, 1, 0, 0, 1, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 1, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0} \
}

#define L { \
    {0, 0, 1, 0, 0, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0} \
}

#define M { \
    {1, 0, 0, 0, 0, 0, 1, 0},  \
    {1, 1, 0, 0, 0, 1, 1, 0}, \
    {1, 0, 1, 0, 1, 0, 1, 0}, \
    {1, 0, 0, 1, 0, 0, 1, 0}, \
    {1, 0, 0, 1, 0, 0, 1, 0}, \
    {1, 0, 0, 1, 0, 0, 1, 0}, \
    {1, 0, 0, 0, 0, 0, 1, 0}, \
    {1, 0, 0, 0, 0, 0, 1, 0} \
}

#define N { \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 1, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 1, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}  \
}

#define O { \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}  \
}

#define P { \
    {0, 0, 1, 1, 1, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0} \
}

#define Q { \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 1, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 1, 0}  \
}

#define R { \
    {0, 0, 1, 1, 1, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0} \
}

#define S { \
    {0, 0, 0, 1, 1, 1, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}  \
}

#define T { \
    {0, 1, 1, 1, 1, 1, 0, 0},  \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0} \
}

#define U { \
    {0, 0, 1, 0, 0, 1, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0} \
}

#define V { \
    {0, 0, 1, 0, 0, 0, 1, 0},  \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 1, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 1, 0, 0, 0} \
}

#define W { \
    {1, 0, 0, 0, 0, 0, 1, 0},  \
    {1, 0, 0, 0, 0, 0, 1, 0}, \
    {1, 0, 0, 0, 0, 0, 1, 0}, \
    {1, 0, 0, 0, 0, 0, 1, 0}, \
    {1, 0, 0, 1, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 1, 0, 1, 0}, \
    {0, 0, 1, 0, 1, 1, 1, 0}, \
    {0, 0, 0, 1, 0, 0, 1, 0} \
}

#define X { \
    {0, 1, 0, 0, 0, 0, 1, 0},  \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0} \
}

#define Y { \
    {0, 1, 0, 0, 0, 0, 1, 0},  \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0} \
}

#define Z { \
    {0, 1, 1, 1, 1, 1, 1, 0},  \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0} \
}

#define SPACE { \
    {0, 0, 0, 0, 0, 0, 0, 0},  \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0} \
}

#define HYPHEN { \
    {0, 0, 0, 0, 0, 0, 0, 0},  \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0} \
}

#define QUESTION { \
    {0, 0, 0, 1, 1, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0} \
}

byte col = 0;
byte leds[8][8];

int pins[17]= {  // pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
  -1, 5, 4, 3, 2, 50, 51, 52, 53, 13, 12, 11, 10, 9, 8, 7, 6};
int cols[8] = {  // col[xx] of leds = pin yy on led matrix
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
int rows[8] = {  // row[xx] of leds = pin yy on led matrix
  pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};

//Quiet Words
int pattern = 0;
const int numPatterns = 9;
byte patterns[numPatterns][8][8] = {
  SPACE,S,P,E,A,K,SPACE,U,P
};

int patternOne = 0;
const int numPatternsOne = 7;
byte patternsOne[numPatternsOne][8][8] = {
  SPACE,L,O,U,D,E,R
};

int patternTwo = 0;
const int numPatternsTwo = 6;
byte patternsTwo[numPatternsTwo][8][8] = {
  SPACE,T,I,M,I,D
};

int patternThree = 0;
const int numPatternsThree = 11;
byte patternsThree[numPatternsThree][8][8] = {
  SPACE,W,A,L,L,F,L,O,W,E,R
};

int patternFour = 0;
const int numPatternsFour = 10;
byte patternsFour[numPatternsFour][8][8] = {
  SPACE,I,N,T,R,O,V,E,R,T
};

int patternFive = 0;
const int numPatternsFive = 10;
byte patternsFive[numPatternsFive][8][8] = {
  SPACE,R,E,P,R,E,S,S,E,D
};

//Loudness Words
int patternSix = 0;
const int numPatternsSix = 17;
byte patternsSix[numPatternsSix][8][8] = {
  SPACE,M,U,S,I,C,SPACE,T,O,SPACE,M,Y,SPACE,E,A,R,S
};

int patternSeven = 0;
const int numPatternsSeven = 10;
byte patternsSeven[numPatternsSeven][8][8] = {
  SPACE,G,O,HYPHEN,G,E,T,T,E,R
};

int patternEight = 0;
const int numPatternsEight = 5;
byte patternsEight[numPatternsEight][8][8] = {
  SPACE,L,O,U,D
};

int patternNine = 0;
const int numPatternsNine = 10;
byte patternsNine[numPatternsNine][8][8] = {
  SPACE,E,X,T,R,O,V,E,R,T
};

int patternTen = 0;
const int numPatternsTen = 8;
byte patternsTen[numPatternsTen][8][8] = {
  SPACE,V,I,G,O,R,U,S
};

int patternEleven = 0;
const int numPatternsEleven = 10;
byte patternsEleven[numPatternsEleven][8][8] = {
  SPACE,E,X,U,B,E,R,A,N,T
};

int scrollSpeed;
int analogPin = 0;          // set analog pin
int sensorValue = 0;        // store the value coming from the sensor
int mappedValue;            // store the new value remapped from 0 to 255
int delayBetweenWords = 3000;          // delay time between words
int numLoops = 0;           // this is the 'start at' counter/current count number so it only samples the audio once every 'numLoopsTotal' loops
int numLoopsTotal = 2;      // samples the audio every this number of loops
int ledPinNum = 48;         // LED output pin
int ledTimeOn = 1;          // number of loops the LED is on
int numQuiet = 1;
int numQuietTotal = 2;
int numLoud = 1;
int numLoudTotal = 2;

boolean switcherQuiet = true;
boolean switcherLoud = true;

void setup() {
  Serial.begin(9600);  
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
  setPattern(pattern);
  pinMode(ledPinNum, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(analogPin);     
  // print out the value you read:
  digitalWrite(ledPinNum, HIGH);
  delay(10);
  digitalWrite(ledPinNum, LOW);
  mappedValue = map(sensorValue, 418, 900, 0, 255);
  printValues();

  //QUIET STRING
  if (mappedValue <= 128) {
    if (switcherQuiet) {
      if (numQuiet < numQuietTotal){
        for (int i = 1; i <= numPatterns; i++){
          pattern = ++pattern % numPatterns;
          scrollSpeed = 80;
          slidePattern(pattern, scrollSpeed);
        }
        Serial.println("numPatterns");
      }
      if (numQuiet == numQuietTotal){
        for (int i = 1; i <= numPatternsOne; i++){
          patternOne = ++patternOne % numPatternsOne;
          scrollSpeed = 80;
          slidePatternOne(patternOne, scrollSpeed); 
        }
        Serial.println("numPatternsOne");
      } 
      if (numQuiet > numQuietTotal) {
        delay(800);
        for (int i = 1; i <= numPatternsTwo; i++){
          patternTwo = ++patternTwo % numPatternsTwo;
          scrollSpeed = 80;
          slidePatternTwo(patternTwo, scrollSpeed);
        }
        Serial.println("numPatternsTwo");
        numQuiet = 0;
      }
    }
    if (!switcherQuiet) {
      if (numQuiet < numQuietTotal){
        //
        for (int i = 1; i <= numPatternsThree; i++){
          patternThree = ++patternThree % numPatternsThree;
          scrollSpeed = 80;
          slidePatternThree(patternThree, scrollSpeed);
        }
        Serial.println("numPatternsThree");
      }
      if (numQuiet == numQuietTotal){
        for (int i = 1; i <= numPatternsFour; i++){
          patternFour = ++patternFour % numPatternsFour;
          scrollSpeed = 80;
          slidePatternFour(patternFour, scrollSpeed); 
        }
        Serial.println("numPatternsFour");
      } 
      if (numQuiet > numQuietTotal) {
        delay(800);
        for (int i = 1; i <= numPatternsFive; i++){
          patternFive = ++patternFive % numPatternsFive;
          scrollSpeed = 80;
          slidePatternFour(patternFive, scrollSpeed);
        }
        Serial.println("numPatternsFive");
        numQuiet = 0;
      }
    }
    switcherQuiet = !switcherQuiet; 
    numQuiet++;
  }
  
  //LOUDNESS STRING
  if (mappedValue > 128) {
    if (switcherLoud) {
      if (numLoud < numLoudTotal){
        for (int i = 1; i <= numPatternsSix; i++){
          patternSix = ++patternSix % numPatternsSix;
          scrollSpeed = 80;
          slidePatternSix(patternSix, scrollSpeed);
        }
        Serial.println("numPatternsSix");
      }
      if (numLoud == numLoudTotal){
        for (int i = 1; i <= numPatternsSeven; i++){
          patternSeven = ++patternSeven % numPatternsSeven;
          scrollSpeed = 80;
          slidePatternSeven(patternSeven, scrollSpeed); 
        }
        Serial.println("numPatternsSeven");
      }
      if (numLoud > numLoudTotal) {
        delay(800);
        for (int i = 1; i <= numPatternsEight; i++){
          patternEight = ++patternEight % numPatternsEight;
          scrollSpeed = 80;
          slidePatternEight(patternEight, scrollSpeed);
        }
        Serial.println("numPatternsEight");
        numLoud = 0;
      }
    }
    if (!switcherLoud) {
      if (numLoud < numLoudTotal){
        for (int i = 1; i <= numPatternsNine; i++){
          patternNine = ++patternNine % numPatternsNine;
          scrollSpeed = 80;
          slidePatternNine(patternNine, scrollSpeed);
        }
        Serial.println("numPatternsNine");
      }
      if (numLoud == numLoudTotal){
        for (int i = 1; i <= numPatternsTen; i++){
          patternTen = ++patternTen % numPatternsTen;
          scrollSpeed = 100;
          slidePatternTen(patternTen, scrollSpeed); 
        }
        Serial.println("numPatternsTen");
      }
      if (numLoud > numLoudTotal) {
        delay(800);
        for (int i = 1; i <= numPatternsEleven; i++){
          patternEleven = ++patternEleven % numPatternsEleven;
          scrollSpeed = 100;
          slidePatternEleven(patternEleven, scrollSpeed);
        }
        Serial.println("numPatternsEleven");
        numLoud = 0;
      }
    }
    numLoops++;
    numLoud++;
  }
  delay(delayBetweenWords);
}

void clearLeds() {
  // Clear display array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 0;
    }
  }
}

void setPattern(int pattern) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = patterns[pattern][i][j];
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


void printValues() {
  Serial.print("sensorValue: ");
  Serial.println(sensorValue);   
  Serial.println();    
  Serial.print("map 418 - 900 to 0 - 255                    : ");
  Serial.println(mappedValue);
  Serial.println();
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


void slidePatternOne(int patternOne, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsOne[patternOne][j][0 + l];
    }
    delay(del);
  }
}

void slidePatternTwo(int patternTwo, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsTwo[patternTwo][j][0 + l];
    }
    delay(del);
  }
}

void slidePatternThree(int patternThree, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsThree[patternThree][j][0 + l];
    }
    delay(del);
  }
}

void slidePatternFour(int patternFour, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsFour[patternFour][j][0 + l];
    }
    delay(del);
  }
}

void slidePatternFive(int patternFive, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsFive[patternFive][j][0 + l];
    }
    delay(del);
  }
}

void slidePatternSix(int patternSix, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsSix[patternSix][j][0 + l];
    }
    delay(del);
  }
}

void slidePatternSeven(int patternSeven, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsSeven[patternSeven][j][0 + l];
    }
    delay(del);
  }
}

void slidePatternEight(int patternEight, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsEight[patternEight][j][0 + l];
    }
    delay(del);
  }
}

void slidePatternNine(int patternNine, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsNine[patternNine][j][0 + l];
    }
    delay(del);
  }
}

void slidePatternTen(int patternTen, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsTen[patternTen][j][0 + l];
    }
    delay(del);
  }
}

void slidePatternEleven(int patternEleven, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = patternsEleven[patternEleven][j][0 + l];
    }
    delay(del);
  }
}

