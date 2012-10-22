
/*
 * Uses FrequencyTimer2 library to
 * constantly run an interrupt routine
 * at a specified frequency. This
 * refreshes the display without the
 * main loop having to do anything.
 */


byte col = 0;
byte leds[8][8];

// pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
int pins[17]= {
  -1, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};

// col[xx] of leds = pin yy on led matrix
int cols[8] = {
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};

// row[xx] of leds = pin yy on led matrix
int rows[8] = {
  pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};

int scrollSpeed;

const int numPatterns = 11;        // set number of characters in string
byte patterns[numPatterns][8][8] = {    // set string
  SPACE,H,E,L,L,O,SPACE,Y,O,U,SPACE
};

const int numPatternsOne = 11;
byte patternsOne[numPatternsOne][8][8] = {
  SPACE,S,P,E,A,K,SPACE,U,P,SPACE
};

const int numPatternsTwo = 11;
byte patternsTwo[numPatternsTwo][8][8] = {
  SPACE,J,A,S,O,N,SPACE,Y,E,SPACE
};

int pattern = 0;
int patternOne = 0;
int analogPin = 4;          // set analog pin
int sensorValue     = 0;    // store the value coming from the sensor
int mappedValue;            // store the new value remapped from 0 to 255
int delayTime = 0;          // delay time between letters
int numLoops = 10;           // counter so it only samples the audio once every 'numLoopsTotal'
int numLoopsTotal = 15;     // samples the audio every this number of loops
int ledPinNum = 19;          // LED output pin
int ledTimeOn = 2;          // number of loops the LED is on

int patternLoop = 0;
int patternLoopOne = 0;
int patternLoopTwo = 0;

boolean switcher = false;


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

  setPattern(pattern);

  pinMode(ledPinNum, OUTPUT);
}





void loop() {
  if (numLoops >  (numLoopsTotal - ledTimeOn))
    digitalWrite(ledPinNum, HIGH);  

  if (numLoops > numLoopsTotal) {
    int sensorValue = analogRead(analogPin);     
    // print out the value you read:
    Serial.print("sensorValue: ");
    Serial.println(sensorValue);   
    Serial.println();     
    mappedValue = map(sensorValue, 418, 900, 0, 255);
    Serial.print("map 418 - 900 to 0 - 255                    : ");
    Serial.println(mappedValue);
    Serial.println();
    delay(delayTime);
    numLoops = 0;
    digitalWrite(ledPinNum, LOW);
  }


  numLoops++;


  //if (mappedValue <= 128) {
    
    for (int i = 1; i <= numPatterns; i++){
      pattern = ++pattern % numPatterns;
      scrollSpeed = 60;
      slidePattern(pattern, scrollSpeed);
      // the code below can be used to reverse the direction of the scroll
      // slidePattern(numPatterns - pattern -1, 60);
    }
 // }

//  if (mappedValue > 128) {
    for (int i = 1; i <= numPatternsOne; i++){
      patternOne = ++patternOne % numPatternsOne;
      scrollSpeed = 60;
      slidePatternOne(patternOne, scrollSpeed);
      // the code below can be used to reverse the direction of the scroll
      // slidePatternOne(numPatternsOne - pattern -1, 60);  
    }
//
//  }

  //switcher = !switcher; 
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
      // This Value used to be LOW, I switched it to HIGH for 
      digitalWrite(rows[row], HIGH);  // Our LED MATRIX
      // Turn on this led
    }
    else {  
      // This Value used to be HIGH, I switched it to LOW for 
      digitalWrite(rows[row], LOW); // Our LED MATRIX
      // Turn on this led
    }
  }
  digitalWrite(cols[col], LOW); // Turn whole column on at once (for equal lighting times)
}


