/*
 * Show messages on an 8x8 led matrix,
 * scrolling from right to left.
 *
 * Uses FrequencyTimer2 library to
 * constantly run an interrupt routine
 * at a specified frequency. This
 * refreshes the display without the
 * main loop having to do anything.
 *
 */
 
#include 
#include &amp;amp;quot;font5x7.h&amp;amp;quot;
 
#define DELAY 80
 
int incomingByte = 0;   // for incoming serial data
String incomingString; // for the incomming serial data string
char message[] = &amp;amp;quot;&amp;amp;quot;; // define the message
 
byte col = 0;
byte leds[8][8];
 
// pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
int pins[17]= {-1, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};

// col[xx] of leds = pin yy on led matrix
int cols[8] = {
  pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
 
int rows[8] = {
  pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};
 
 
void setup() {
   
  // sets the pins as output
  for (int i = 1; i  0) {
 
                // read the incoming byte:
                char incomingByte = (char)Serial.read();  
                
                incomingString += incomingByte;
                 
                if (incomingByte == &amp;amp;#039;~&amp;amp;#039;) {
                  // using a tilda ~ clears the string 
               
                incomingString = &amp;amp;quot;&amp;amp;quot;;  
                   
                }
                 
                // check string for command variables
                 
                incomingString.toCharArray(message, 160);
                 
           
                 
                }
                 
                
      
      
      
  scrollMsg( message ); 
   
  
   
   
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
    unsigned char bt = pgm_read_byte(&amp;amp;amp;(smallFont [(ch-32)*5 + i] ));
    for (int j = 0; j < 8; j++) {
      leds[j][i+1] = (bt &amp;amp;amp; 0x01);
      bt = bt >> 1;
    }
  }
}
 
void slideChar(char ch, int del) {
  for (int l = 0; l < 5; l++) {
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1];
      }
    }
    unsigned char bt = pgm_read_byte(&amp;amp;amp;(smallFont [(ch-32)*5 + l] ));
    for (int j = 0; j < 8; j++) {
      leds[j][7] = (bt &amp;amp;amp; 0x01);
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
 
 
// Interrupt routine
void display() {
  digitalWrite(cols[col], HIGH);  // Turn whole previous column off
  col++;
  if (col == 8) {
    col = 0;
  }
  for (int row = 0; row < 8; row++) {
    //    if (leds[col][7 - row] == 1) {
    if (leds[col][ row] == 1) {
      digitalWrite(rows[row], HIGH);  // Turn on this led
    }
    else {
      digitalWrite(rows[row], LOW); // Turn off this led
    }
  }
  digitalWrite(cols[col], LOW); // Turn whole column on at once (for equal lighting times)
}
