

//setup default LED on pin 13
const int buzzerPin =  2;
//setup touch sensor on pin 3
const int touchPin = 8;
 
//store the time when last event happened
unsigned long lastEvent = 0;
//store the state of LED
boolean buzzerOn = false;
 
//setup pins
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(touchPin, INPUT);
}
 
void loop(){
  //read touch sensor state
  int touchState = digitalRead(touchPin);
 
  //only interested in the HIGH signal
  if (touchState == HIGH) {
    //if 50ms have passed since last HIGH pulse, it means that the
    //touch sensor has been touched, released and touched again
    if (millis() - lastEvent > 50) {
      //toggle LED and set the output
      buzzerOn = !buzzerOn;
      digitalWrite(buzzerPin, buzzerOn ? HIGH : LOW);
      Serial.println(buzzerOn);
    }
 
    //remember when last event happened
    lastEvent = millis();
  }
}
