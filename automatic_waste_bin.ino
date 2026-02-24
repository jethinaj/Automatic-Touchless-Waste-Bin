#include <Servo.h>

Servo myservo;

const int trigPin = 9;  // connect ultrasonic trig pin to 9
const int echoPin = 10; // connect ultrasonic echo pin to 10

long duration;
float distance;

void setup() {
  Serial.begin(9600);
  myservo.attach(8);     // connect servo data pin to 8

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    Serial.println("Out of range");
    return;
  }

  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 20) {
    myservo.write(0);
    delay(1000);
  } else {
    myservo.write(90);
  }

  delay(300);
}