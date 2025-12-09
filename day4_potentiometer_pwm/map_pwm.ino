int potPin = A0;    // Potentiometer input
int ledPin = 9;     // PWM output pin

int potValue = 0;   // Raw analog input (0-1023)
int ledValue = 0;   // Scaled PWM value (0-255)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);           // Read sensor
  ledValue = map(potValue, 0, 1023, 0, 255); // Scale to PWM range
  analogWrite(ledPin, ledValue);           // Output to LED

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print("  -> PWM: ");
  Serial.println(ledValue);

  delay(10);
}
