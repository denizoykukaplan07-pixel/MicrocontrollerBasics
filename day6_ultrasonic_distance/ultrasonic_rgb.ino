// Day 6 – Ultrasonic Distance Measurement (HC-SR04)
// Commit 3: Moving average + RGB distance indicator (status colors)

const int trigPin = 9;
const int echoPin = 10;

const long timeoutUs = 30000;  // 30 ms timeout (~5 meters)
const int N = 5;               // moving average window size

// RGB LED pins (PWM)
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

float samples[N];
int sampleIndex = 0;
bool bufferFilled = false;

void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

// Measure one distance reading in cm.
// Returns -1 if out of range / no echo.
float readDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long durationUs = pulseIn(echoPin, HIGH, timeoutUs);
  if (durationUs == 0) return -1.0f;

  return durationUs * 0.034f / 2.0f;
}

void addSample(float d) {
  samples[sampleIndex] = d;
  sampleIndex++;

  if (sampleIndex >= N) {
    sampleIndex = 0;
    bufferFilled = true;
  }
}

float movingAverage() {
  int count = bufferFilled ? N : sampleIndex;
  if (count == 0) return -1.0f;

  float sum = 0.0f;
  for (int i = 0; i < count; i++) sum += samples[i];
  return sum / count;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  setColor(0, 0, 0); // start OFF

  Serial.begin(9600);
  Serial.println("Day 6 - Ultrasonic (filtered) + RGB status indicator");
}

void loop() {
  float d = readDistanceCm();

  if (d < 0) {
    Serial.println("Out of range / No echo detected");
    setColor(0, 0, 255); // Blue = "no reading"
    delay(200);
    return;
  }

  addSample(d);
  float avg = movingAverage();

  // Print values
  Serial.print("Raw: ");
  Serial.print(d);
  Serial.print(" cm  |  Filtered(avg): ");
  Serial.print(avg);
  Serial.println(" cm");

  // RGB status based on FILTERED distance
  if (avg > 100) {
    setColor(0, 255, 0);   // Green: safe
    delay(200);
  } 
  else if (avg > 50) {
    setColor(255, 255, 0); // Yellow: caution
    delay(200);
  } 
  else if (avg > 20) {
    setColor(255, 80, 0);  // Orange: alert
    delay(200);
  } 
  else {
    // Red blinking: danger (too close)
    setColor(255, 0, 0);
    delay(80);
    setColor(0, 0, 0);
    delay(80);
  }
}
