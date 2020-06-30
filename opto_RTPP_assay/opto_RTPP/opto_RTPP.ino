// RTPP Optogenetics stimulation

#define leftinstructionPin 6
#define rightinstructionPin 10
#define leftstimulationPin 13
#define rightstimulationPin 5

void setup() {
  pinMode(leftinstructionPin,INPUT);   // Receives inputs from Bonsai-connected Arduino
  pinMode(rightinstructionPin,INPUT);   // Receives inputs from Bonsai-connected Arduino
  pinMode(leftstimulationPin,OUTPUT); // Trigger Output for the Laser
  pinMode(rightstimulationPin,OUTPUT); // Trigger Output for the Laser
  Serial.begin(57600);
}

void loop() {
while (digitalRead(leftinstructionPin) == HIGH && digitalRead(rightinstructionPin) == HIGH){
 digitalWrite(leftstimulationPin, HIGH);   // turn the Laser on 
  digitalWrite(rightstimulationPin, HIGH);   // turn the Laser on 
}
 while (digitalRead(leftinstructionPin) == LOW && digitalRead(rightinstructionPin) == HIGH ){
 digitalWrite(leftstimulationPin, LOW);   // turn the Laser on 
  digitalWrite(rightstimulationPin, HIGH);   // turn the Laser on 
 }
 while (digitalRead(leftinstructionPin) == HIGH && digitalRead(rightinstructionPin) == LOW){
  digitalWrite(leftstimulationPin, HIGH);   // turn the Laser on 
   digitalWrite(rightstimulationPin, LOW);   // turn the Laser on 
 }
  // Laser is off otherwise
digitalWrite(leftstimulationPin, LOW); 
digitalWrite(rightstimulationPin, LOW); 
}
