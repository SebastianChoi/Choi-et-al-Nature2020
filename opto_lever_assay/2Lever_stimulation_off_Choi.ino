// Lever-pressing Optogenetic stimulation

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
  pinMode(stimulationPin,OUTPUT); // Triggers Output through LED driver
  pinMode(rightleverstatePin,INPUT); // Receives right (active) lever state
  pinMode(leftleverstatePin,INPUT); // Receives left (inactive) lever state
  pinMode(rightleverreportPin,OUTPUT); // Reports right (active) lever state to Bonsai
  pinMode(leftleverreportPin,OUTPUT); // Reports left (inactive) lever state to Bonsai
  pinMode(rightleverLEDPin,OUTPUT); // Reports right (active)lever state and turns on Red LED
  pinMode(leftleverLEDPin,OUTPUT); // Reports left (inactive) lever state and turns on Green LED
  Serial.begin(57600);
}

void loop() {

  while (digitalRead(instructionPin) == HIGH){
     // checks to see if Bonsai code started
  rightleverstate = digitalRead(rightleverstatePin);
  leftleverstate = digitalRead(leftleverstatePin);
    if (rightleverstate == HIGH) {
      // The right (active) lever is not pressed
    digitalWrite(rightleverreportPin, LOW); // Reports "lever-not-pressed" signal to Bonsai
    digitalWrite(stimulationPin, LOW);   // No ouputs to LED driver
    digitalWrite(rightleverLEDPin, LOW);   // Turns the Red LED off
  }
    else  {
       // The right (active) lever is pressed
    digitalWrite(rightleverreportPin, HIGH); // Reports "lever-pressed" signal to Bonsai
    digitalWrite(stimulationPin, HIGH);   // Trigger ouput to LED driver
    digitalWrite(rightleverLEDPin, HIGH);   // Turns the Red LED on
    }

   if (leftleverstate == HIGH) {
      // The left (inactive) lever is not pressed
    digitalWrite(leftleverreportPin, LOW); // Reports "lever-not-pressed" signal to Bonsai
    digitalWrite(leftleverLEDPin, LOW);   // Turns the Green LED off
  }
    else  {
       // The left (inactive) lever is pressed
    digitalWrite(leftleverreportPin, HIGH); // Reports "lever-pressed" signal to Bonsai
    digitalWrite(leftleverLEDPin, HIGH);   // Turns the Green LED on
    }
  }
  // No ouput and nothing is reported to Bonsai otherwise
  digitalWrite(rightleverreportPin, LOW);  // Reports "lever-not-pressed" signal to Bonsai
  digitalWrite(leftleverreportPin, LOW);  // Reports "lever-not-pressed" signal to Bonsai
  digitalWrite(stimulationPin, LOW);   // No output to LED driver
  digitalWrite(rightleverLEDPin, LOW);   // Turns the Red LED off
  digitalWrite(leftleverLEDPin, LOW);   // Turns the Green LED off
}
