// Project 33
// Power connections
#define Left 8
#define Bottom 9
#define Right 10
#define Top 11
// Left (X1) to digital pin 8
// Bottom (Y2) to digital pin 9
// Right (X2) to digital pin 10
// Top (Y1) to digital pin 11
// Analog connections
#define topInput 0   // Top (Y1) to analog pin 0
#define rightInput 1 // Right (X2) to analog pin 1
int coordX = 0, coordY = 0;
void setup()
{
  Serial.begin(38400);
}
void loop(){

  if (touch())  // If screen touched, print co-ordinates
  {
    Serial.print(coordX);
    Serial.print("  ");
    Serial.println(coordY);
    delay(250);
  }
}

boolean touch(){

  boolean touch = false;
  // get horizontal co-ordinates
  pinMode(Left, OUTPUT);
  digitalWrite(Left, LOW); // Set Left to Gnd
  pinMode(Right, OUTPUT); // Set right to +5v
  digitalWrite(Right, HIGH);
  pinMode(Top, INPUT); // Top and Bottom to high impedance
  pinMode(Bottom, INPUT);
  delay(3);
  coordX = analogRead(topInput);
  // get vertical co-ordinates
  pinMode(Bottom, OUTPUT); // set Bottom to Gnd
  digitalWrite(Bottom, LOW);
  pinMode(Top, OUTPUT); // set Top to +5v
  digitalWrite(Top, HIGH);
  pinMode(Right, INPUT); // left and right to high impedance
  pinMode(Left, INPUT);
  delay(3);
  coordY = analogRead(rightInput);

  if(coordX < 1000 && coordX > 0 && coordY < 1000 && coordY > 0) {
    touch = true;
  }
  return touch;
  // if co-ordinates read are less than 1000 and greater than 0 then the screen has been touched
}

