// Day 6 – Ultrasonic Distance Measurement (HC-SR04)
// Measures distance in centimeters using TRIG/ECHO timing + speed of sound.

const int trigPin = 9;
const int echoPin = 10;

long durationUs;      // Echo pulse length in microseconds (µs)
float distanceCm;     // Calculated distance in centimeters

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  Serial.println("Day 6 - Ultrasonic distance measurement started");
}

void loop() {
  // 1) Ensure TRIG is LOW (clean start)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 2) Send a 10 µs trigger pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 3) Measure how long ECHO stays HIGH (round-trip time)
  durationUs = pulseIn(echoPin, HIGH);

  // 4) Convert time to distance
  // speed of sound ≈ 0.034 cm/µs
  // divide by 2 because the wave travels to the object AND back
  distanceCm = durationUs * 0.034f / 2.0f;

  // 5) Print result
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  delay(200);
}
