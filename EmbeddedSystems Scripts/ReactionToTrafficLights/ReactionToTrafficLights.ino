#include <NewPing.h>

// Define the pins for the ultrasonic sensor
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200

//Define variables for operations
const unsigned long INTERVAL = 7000;
static unsigned long lastTime;
int isGreen = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Define the pins for the traffic light
#define red 10
#define yellow 9
#define green 8

void setup() {
  // Initialize the pins for the traffic light as outputs
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  if (lastTime == 0) {
    lastTime = millis();
  }
  if (millis() - lastTime < INTERVAL) {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    isGreen = 0;
  } else if (millis() - lastTime < INTERVAL * 2) {
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    isGreen = 0;
  } else if (millis() - lastTime < INTERVAL * 3) {
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    isGreen = 1;
  } else {
    lastTime = 0;
  }

  if (isGreen) {
    int distance = sonar.ping_cm();
    if (distance > 0 && distance <= 10) {
      Serial.println("DON'T CROSS!");
    }
  }
}
