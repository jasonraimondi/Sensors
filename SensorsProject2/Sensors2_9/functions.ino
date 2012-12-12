void clearLeds() {
  // Clear display array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 0;
    }
  }
}


void matrixOne() {
  int pins[17]= {-1, 5, 4, 3, 18, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};
  int cols[8] = {
    pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
  int rows[8] = {
    pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};
  for (int i = 1; i <= 16; i++)
    pinMode(pins[i], OUTPUT);
  for (int i = 1; i <= 8; i++)
    digitalWrite(cols[i - 1], LOW);
  for (int i = 1; i <= 8; i++)
    digitalWrite(rows[i - 1], LOW);
  clearLeds();
  // Turn off toggling of pin 11
  FrequencyTimer2::disable();
  // Set refresh rate (interrupt timeout period)
  FrequencyTimer2::setPeriod(2000);
  // Set interrupt routine to be called
  FrequencyTimer2::setOnOverflow(display);
  //  setPattern(pattern);
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




void slideLedsLeft(int ledTurn, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = ledsLeft[ledLeft][j][0 + l];
    }
    delay(del);
  }
}

void slideLedsRight(int ledRight, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      leds[j][7] = ledsRight[ledRight][j][0 + l];
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

