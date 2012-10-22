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
