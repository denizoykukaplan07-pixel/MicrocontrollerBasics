// Day 6 – Ultrasonic Distance Measurement (HC-SR04)
// Commit 3: Added moving average filter + keeps timeout handling

const int trigPin = 9;
const int echoPin = 10;

const long timeoutUs = 30000;   // 30 ms timeout (~5 meters)
const int N = 5;                // moving average window size

float samples[N];               // last N distance samples (cm)
int sampleIndex = 0;            // circular buffer index
bool bufferFilled = false;      // becomes true after N samples

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  Serial.println("Day 6 - Ultrasonic measurement (timeout + moving average)");
}

// Measure one distance reading in cm.
// Returns -1 if out of range / no echo.
float readDistanceCm() {
  // Clean TRIG signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10 µs trigger pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo pulse with timeout
  long durationUs = pulseIn(echoPin, HIGH, timeoutUs);

  if (durationUs == 0) return -1.0f;  // no echo / out of range

  // Convert time to distance (cm)
  return durationUs * 0.034f / 2.0f;
}

// Add a sample to the buffer (only valid samples).
void addSample(float d) {
  samples[sampleIndex] = d;
  sampleIndex++;

  if (sampleIndex >= N) {
    sampleIndex = 0;
    bufferFilled = true;
  }
}

// Compute moving average of stored samples.
float movingAverage() {
  int count = bufferFilled ? N : sampleIndex;
  if (count == 0) return -1.0f;

  float sum = 0.0f;
  for (int i = 0; i < count; i++) sum += samples[i];
  return sum / count;
}

void loop() {
  float d = readDistanceCm();

  if (d < 0) {
    Serial.println("Out of range / No echo detected");
  } else {
    addSample(d);

    float avg = movingAverage();

    Serial.print("Raw: ");
    Serial.print(d);
    Serial.print(" cm  |  Filtered(avg): ");
    Serial.print(avg);
    Serial.println(" cm");
  }

  delay(200);
}
