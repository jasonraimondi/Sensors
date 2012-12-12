void clearLeds() {
  // Clear display array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 0;
    }
  }
}




// Interrupt routine
void displayOne() {
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









void clearLedsTwo() {
  // Clear display array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      ledsTwo[i][j] = 0;
    }
  }
}




void displayTwo() {
  digitalWrite(colsTwo[colTwo], HIGH);  // Turn whole previous column off
  colTwo++;
  if (colTwo == 8) {
    colTwo = 0;
  }
  for (int rowTwo = 0; rowTwo < 8; rowTwo++) {
    if (ledsTwo[colTwo][7 - rowTwo] == 1) {
      digitalWrite(rowsTwo[rowTwo], HIGH);  // This Value used to be LOW, I switched it to HIGH for Our LED MATRIX
    }
    else { 
      digitalWrite(rowsTwo[rowTwo], LOW); // This Value used to be HIGH, I switched it to LOW for Our LED MATRIX
    }
  }
  digitalWrite(colsTwo[colTwo], LOW); // Turn whole column on at once (for equal lighting times)
}





void slideLedsLeftTwo(int ledTurnTwo, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      ledsTwo[j][7] = ledsLeftTwo[ledLeftTwo][j][0 + l];
    }
    delay(del);
  }
}

void slideLedsRightTwo(int ledRightTwo, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        ledsTwo[j][i] = ledsTwo[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      ledsTwo[j][7] = ledsRightTwo[ledRightTwo][j][0 + l];
    }
    delay(del);
  }
}


void slideLedsOnTwo(int ledOnTwo, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        ledsTwo[j][i] = ledsTwo[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      ledsTwo[j][7] = ledsOnTwo[ledOnTwo][j][0 + l];
    }
    delay(del);
  }
}

void slideLedsOffTwo(int ledOffTwo, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        ledsTwo[j][i] = ledsTwo[j][i+1];
      }
    }
    for (int j = 0; j < 8; j++) {
      ledsTwo[j][7] = ledsOffTwo[ledOffTwo][j][0 + l];
    }
    delay(del);
  }
}

