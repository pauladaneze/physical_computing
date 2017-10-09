int ledDigitalOne[] = {9, 10, 11};
// 9 IS RED, 10 IS green, 11 is blue
int buttonRed = 2;
int buttonGreen = 7; 
int buttonBlue = 4;
int A, B, C;

int red;       // 0-1023 (in theory)
int green;       // 0-1023 (in theory)
int blue;  

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
  for(int i = 0; i <3; i++){
    digitalWrite(led[i], color[i]);
  }
}
  
void loop(){

  red = digitalRead(buttonRed);       // 0-1023 (in theory)
  green = digitalRead(buttonGreen);       // 0-1023 (in theory)
  blue = digitalRead(buttonBlue);      // 0-1

  if (red != HIGH && green != HIGH && blue != HIGH) {
    for(int i = 0; i< 8; i++)
    {
    setColor(ledDigitalOne, COLORS[i]);
    delay(500);}
    return;  
  }
  if (red == LOW) {
  setColor(ledDigitalOne, RED);}
  
  if (green == LOW) {
  setColor(ledDigitalOne, GREEN);}

  if (blue == LOW) {
  setColor(ledDigitalOne, BLUE);}

  if (red == LOW && green == LOW && blue == HIGH) {
  setColor(ledDigitalOne, YELLOW);}

  if (red == LOW && blue == LOW && green == HIGH) {
  setColor(ledDigitalOne, MAGENTA);}

  if (green == LOW && blue == LOW && red == HIGH) {
  setColor(ledDigitalOne, CYAN);}

  if (red == LOW && green == LOW && blue == LOW) {
  setColor(ledDigitalOne, WHITE);}

  A = digitalRead(buttonRed);       // 0-1023 (in theory)
  B = digitalRead(buttonGreen);       // 0-1023 (in theory)
  C = digitalRead(buttonBlue);      // 0-1

  Serial.print(A);
  Serial.print(",");
  Serial.print(B);
  Serial.print(",");
  Serial.println(C);

}



