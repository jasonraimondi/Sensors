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
int button = 2;     // the number of right hand button pin


void setup() {
  Serial.begin(9600);  
  pinMode(button, INPUT);   // initialize the pushbutton pin as an input:
  digitalWrite(button, HIGH);
}

void loop(){
  matrixOne();
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
    for (int i = 1; i <= numLedsOff; i++){  //For those crazy moments when you're turning
      ledOff = ++ledOff % numLedsOff;
      scrollSpeed = 80;
      slideLedsOff(ledOff, scrollSpeed);  //Turn Left 
    }
  }
}





