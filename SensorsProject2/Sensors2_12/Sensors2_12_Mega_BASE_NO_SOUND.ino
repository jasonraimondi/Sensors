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

int ledTurn = 0;
const int numLedsTurn = 1;
byte ledsTurn[numLedsTurn][8][8] = {
  TURN
};

int pins[17]= {
  -1, 41, 40, 39, 38, 50, 51, 52, 53, 49, 48, 47, 46, 45, 44, 43, 42};
int cols[8] = {
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
int rows[8] = {
  pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};
  



int scrollSpeed;
int button_brake = 2;
int button_turn = 3;

void setup() {
  Serial.begin(9600);  

  pinMode(button_turn, INPUT); 
  digitalWrite(button_turn, HIGH);
  
  pinMode(button_brake, INPUT);
  digitalWrite(button_brake, HIGH);
  
  for (int i = 1; i <= 16; i++)
    pinMode(pins[i], OUTPUT);
  for (int i = 1; i <= 8; i++)
    digitalWrite(cols[i - 1], LOW);
  for (int i = 1; i <= 8; i++) 
    digitalWrite(rows[i - 1], LOW);
  clearLeds();

  FrequencyTimer2::disable();
  FrequencyTimer2::setPeriod(2000);
  FrequencyTimer2::setOnOverflow(display);
}

void loop(){

  int turn_status = digitalRead(button_turn);
  int break_status = digitalRead(button_brake);


  if (break_status == HIGH){
    for (int i = 1; i <= numLedsOn; i++){
      ledOn = ++ledOn % numLedsOn;
      scrollSpeed = 1;
      slideLedsOn(ledOn, scrollSpeed);
    }
  }
  else if (turn_status == HIGH) {
    for (int i = 1; i <= numLedsTurn; i++){
      ledTurn = ++ledTurn % numLedsTurn;
      scrollSpeed = 80;
      slideLedsTurn(ledTurn, scrollSpeed);
    }
  }
  
}

