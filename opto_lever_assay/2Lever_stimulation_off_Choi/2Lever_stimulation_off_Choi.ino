// Lever-pressing Optogenetics stimulation

#define instructionPin 6
#define stimulationPin 13
#define rightleverstatePin 2
#define leftleverstatePin 3
#define rightleverreportPin 4
#define leftleverreportPin 5
#define rightleverLEDPin 8
#define leftleverLEDPin 9
int rightleverstate = 0;
int leftleverstate = 0;

void setup() {
  pinMode(instructionPin,INPUT);   // Receives inputs from Bonsai-connected Arduino
  pinMode(stimulationPin,OUTPUT); // Trigger Output for the Laser
  pinMode(rightleverstatePin,INPUT); // Receives inputs from right lever
  pinMode(leftleverstatePin,INPUT); // Receives inputs from left lever
  pinMode(rightleverreportPin,OUTPUT); // Report right lever state to Bonsai
  pinMode(leftleverreportPin,OUTPUT); // Report left lever state to Bonsai
  pinMode(rightleverLEDPin,OUTPUT); // Report right lever state and turn on LED
  pinMode(leftleverLEDPin,OUTPUT); // Report left lever state and turn on LED
  Serial.begin(57600);
}

void loop() {

  while (digitalRead(instructionPin) == HIGH){
     // checks to see if Bonsai code started
  rightleverstate = digitalRead(rightleverstatePin);
  leftleverstate = digitalRead(leftleverstatePin);
    if (rightleverstate == HIGH) {
      // The right lever is not pressed
    digitalWrite(rightleverreportPin, LOW); // Report lever-not-pressed signal to Bonsai
    digitalWrite(stimulationPin, LOW);   // turn the Laser off
    digitalWrite(rightleverLEDPin, LOW);   // turn the LED off
  }
    else  {
       // The right lever is pressed
    digitalWrite(rightleverreportPin, HIGH); // Report lever-pressed signal to Bonsai
    digitalWrite(stimulationPin, HIGH);   // turn the Laser on
    digitalWrite(rightleverLEDPin, HIGH);   // turn the LED on
    }

   if (leftleverstate == HIGH) {
      // The left lever is not pressed
    digitalWrite(leftleverreportPin, LOW); // Report lever-not-pressed signal to Bonsai
    digitalWrite(leftleverLEDPin, LOW);   // turn the LED off
  }
    else  {
       // The left lever is pressed
    digitalWrite(leftleverreportPin, HIGH); // Report lever-pressed signal to Bonsai
    digitalWrite(leftleverLEDPin, HIGH);   // turn the LED on
    }
  }
  // Laser is off and nothing is reported to Bonsai otherwise
  digitalWrite(rightleverreportPin, LOW);  // Report lever-not-pressed signal to Bonsai
  digitalWrite(leftleverreportPin, LOW);  // Report lever-not-pressed signal to Bonsai
  digitalWrite(stimulationPin, LOW);   // turn the Laser off
  digitalWrite(rightleverLEDPin, LOW);   // turn the LED off
  digitalWrite(leftleverLEDPin, LOW);   // turn the LED off
}
