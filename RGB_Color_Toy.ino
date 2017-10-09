int ledDigitalOne[] = {9, 10, 11};
// 9 IS RED, 10 IS green, 11 is blue
int buttonRed = 2;
int buttonGreen = 7; 
int buttonBlue = 4;

const boolean ON = LOW;
const boolean OFF = HIGH; 

const boolean RED[] = {ON, OFF, OFF};
const boolean GREEN[] = {OFF, ON, OFF};
const boolean BLUE[] = {OFF, OFF, ON};
const boolean YELLOW[] = {ON, ON, OFF};
const boolean CYAN[] = {OFF, ON, ON};
const boolean MAGENTA[] = {ON, OFF, ON};
const boolean WHITE[] = {ON, ON, ON};
const boolean BLACK[] = {OFF, OFF, OFF};

const boolean* COLORS[] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, BLACK};

void setup(){
  for(int i = 0; i < 3; i++){
    pinMode(ledDigitalOne[i], OUTPUT);
    pinMode(buttonRed, INPUT);
    pinMode(buttonGreen, INPUT);
    pinMode(buttonBlue, INPUT);
  }
  Serial.begin(9600);
}

void setColor(int* led, boolean* color){
  for(int i = 0; i <8; i++){
    digitalWrite(led[i], color[i]);
  }
}
  
void loop(){
  if (digitalRead(buttonRed) != HIGH && digitalRead(buttonGreen) != HIGH && digitalRead(buttonBlue) != HIGH) {
    for(int i = 0; i< 8; i++)
    {
    setColor(ledDigitalOne, COLORS[i]);
    delay(500);}
    return;  
  }
  if (digitalRead(buttonRed) == LOW) {
  setColor(ledDigitalOne, RED);}
  
  if (digitalRead(buttonGreen) == LOW) {
  setColor(ledDigitalOne, GREEN);}

  if (digitalRead(buttonBlue) == LOW) {
  setColor(ledDigitalOne, BLUE);}

  if (digitalRead(buttonRed) == LOW && digitalRead(buttonGreen) == LOW && digitalRead(buttonBlue) == HIGH) {
  setColor(ledDigitalOne, YELLOW);}

  if (digitalRead(buttonRed) == LOW && digitalRead(buttonBlue) == LOW && digitalRead(buttonGreen) == HIGH) {
  setColor(ledDigitalOne, MAGENTA);}

  if (digitalRead(buttonGreen) && digitalRead(buttonBlue) == LOW && digitalRead(buttonRed) == HIGH) {
  setColor(ledDigitalOne, CYAN);}

  if (digitalRead(buttonRed) == LOW && digitalRead(buttonGreen) == LOW && digitalRead(buttonBlue) == LOW) {
  setColor(ledDigitalOne, WHITE);}
  Serial.write(buttonRed);
  Serial.write(buttonBlue);
  Serial.write(buttonGreen);
}



