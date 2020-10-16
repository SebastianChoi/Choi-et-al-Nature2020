// Optogenetics-coupled RTPP

#define leftinstructionPin 6
#define rightinstructionPin 10
#define leftstimulationPin 13
#define rightstimulationPin 5

void setup() {
  pinMode(leftinstructionPin,INPUT);   // Receives inputs from Bonsai-connected Arduino (left chamber)
  pinMode(rightinstructionPin,INPUT);   // Receives inputs from Bonsai-connected Arduino (right chamber)
  pinMode(leftstimulationPin,OUTPUT); // Triggers Output to an LED driver input (left chamber)
  pinMode(rightstimulationPin,OUTPUT); // Triggers Output to another LED driver input (right chamber)
  Serial.begin(57600);
}

void loop() {
while (digitalRead(leftinstructionPin) == HIGH && digitalRead(rightinstructionPin) == HIGH){
 digitalWrite(leftstimulationPin, HIGH);   // Triggers Output to an LED driver input (left chamber)
  digitalWrite(rightstimulationPin, HIGH);   // Triggers Output to another LED driver input (right chamber) 
}
 while (digitalRead(leftinstructionPin) == LOW && digitalRead(rightinstructionPin) == HIGH ){
 digitalWrite(leftstimulationPin, LOW);   // No Output to LED driver (left chamber)
  digitalWrite(rightstimulationPin, HIGH);   // Triggers Output to another LED driver input (right chamber)
 }
 while (digitalRead(leftinstructionPin) == HIGH && digitalRead(rightinstructionPin) == LOW){
  digitalWrite(leftstimulationPin, HIGH);   // Triggers Output to an LED driver input (left chamber)
   digitalWrite(rightstimulationPin, LOW);   //  No Output to LED driver (right chamber)
 }
  // No output to LED driver otherwise
digitalWrite(leftstimulationPin, LOW); 
digitalWrite(rightstimulationPin, LOW); 
}
