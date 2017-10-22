
/*  PulseSensor™ Starter Project   http://www.pulsesensor.com
 *   
This an Arduino project. It's Best Way to Get Started with your PulseSensor™ & Arduino. 
-------------------------------------------------------------
1) This shows a live human Heartbeat Pulse. 
2) Live visualization in Arduino's Cool "Serial Plotter".
3) Blink an LED on each Heartbeat.
4) This is the direct Pulse Sensor's Signal.  
5) A great first-step in troubleshooting your circuit and connections. 
6) "Human-readable" code that is newbie friendly." 

*/


//  Variables
int PulseSensor = A0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED8 = 8;   //  The on-board Arduion LED
int LED7 = 7;


int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 80;            // Determine which Signal to "count as a beat", and which to ingore.  
int Threshold2 = 130; 
int outputValue;


// The SetUp Function:
void setup() {
  pinMode(LED8,OUTPUT);         // pin that will blink to your heartbeat!
  pinMode(LED7,OUTPUT);
   Serial.begin(9600);         // Set's up Serial Communication at certain speed. 
   
}

// The Main Loop Function
void loop() {

  Signal = analogRead(PulseSensor);  // Read the PulseSensor's value. 
  outputValue = map(Signal, 0, 1023, 0, 200);

                                           

   Serial.println(outputValue);   // Send the Signal value to Serial Plotter.
   
   if(outputValue > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.  
     digitalWrite(LED8,HIGH);          
   } else {
     digitalWrite(LED8,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
   }
   if(outputValue > Threshold2){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.  
     digitalWrite(LED7,HIGH);          
   } else {
     digitalWrite(LED7,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
   }

delay(500);
   
   
}




