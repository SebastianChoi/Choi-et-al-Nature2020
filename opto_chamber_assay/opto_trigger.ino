// Trigger Optogenetic stimulation through programmed LED driver

#define instructionPin 6
#define stimulationPin 13

void setup() {
  pinMode(instructionPin,INPUT);   // Receives inputs from Bonsai-connected Arduino
  pinMode(stimulationPin,OUTPUT); // Triggers Output for the programmed LED driver
  Serial.begin(57600);
}

void loop() {
while (digitalRead(instructionPin) == HIGH){
 digitalWrite(stimulationPin, HIGH);   // Bonsai-triggered output to the programmed LED driver  
}
  // No output to the programmed LED driver otherwise
digitalWrite(stimulationPin, LOW); 
}
