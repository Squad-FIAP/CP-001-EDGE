#include <Arduino.h>

const int RED_LED_PIN = 7;
const int YELLOW_LED_PIN = 4;
const int GREEN_LED_PIN = 2;
const int LDR_PIN = A0;
const int BUZZER_PIN = 8;

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);  
  pinMode(LDR_PIN, INPUT);
  Serial.begin(9600);
}

void turnOffAllLeds() {
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
}

void buzz() {
  tone(8, 1000, 3000);
  delay(3000);
  noTone(8);
}

void calculateStatusOfWineyard() {
  int reading = analogRead(LDR_PIN);
  int mappedReading = map(reading, 160, 600, 1, 8);
  Serial.println(reading);
  Serial.println(mappedReading);
  if (mappedReading <= 3){
    turnOffAllLeds();
    digitalWrite(GREEN_LED_PIN, HIGH);
  } else if (mappedReading > 3 && mappedReading < 7){
    turnOffAllLeds();
    digitalWrite(YELLOW_LED_PIN, HIGH);
  } else if (mappedReading >= 7) {
    turnOffAllLeds();
    digitalWrite(RED_LED_PIN, HIGH);
    buzz();
  } 
}

void loop() {
  calculateStatusOfWineyard();
  delay(1000);
}
