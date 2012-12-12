// Project 12 - Piezo Sounder Melody Player

#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_A4  440
#define NOTE_AS4 466

#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.125
#define SIXTEENTH 0.0625


int tune[12] = { 
NOTE_F4, NOTE_D4, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_D4};

float duration[12] = { 
EIGHTH, EIGHTH, QUARTER, QUARTER, EIGHTH, EIGHTH, EIGHTH, EIGHTH, QUARTER, QUARTER, QUARTER, QUARTER};

int length;
int horn_pin = 12;
int button_horn = 8;

void setup() {
        pinMode(button_horn, INPUT);   // initialize the pushbutton pin as an input:
        digitalWrite(button_horn, HIGH);
  	pinMode(horn_pin, OUTPUT);
  	length = sizeof(tune) / sizeof(tune[0]);
}

void loop() {
  int horn_status = digitalRead(button_horn);
    if (horn_status == LOW)
  	for (int x=0; x<length; x++) {
    		tone(horn_pin, tune[x]);
    		delay(1500 * duration[x]);
    		noTone(horn_pin);
                delay(5);
  	}
}
