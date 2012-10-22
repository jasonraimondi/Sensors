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
