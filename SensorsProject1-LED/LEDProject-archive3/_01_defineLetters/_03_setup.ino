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
