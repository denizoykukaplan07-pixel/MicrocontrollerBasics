// Day 5 – RGB LED PWM Color Fading
// This project demonstrates multi-channel PWM control by smoothly
// transitioning between colors on a common-cathode RGB LED.

int redPin   = 9;   // Red channel (PWM pin)
int greenPin = 10;  // Green channel (PWM pin)
int bluePin  = 11;  // Blue channel (PWM pin)

// Helper function to send a color to the RGB LED.
// r, g, b values range from 0–255 (PWM duty cycle).
void setColor(int r, int g, int b) {
  analogWrite(redPin,   r);  // Red brightness
  analogWrite(greenPin, g);  // Green brightness
  analogWrite(bluePin,  b);  // Blue brightness
}

void setup() {
  // Configure all RGB pins as outputs
  pinMode(redPin,   OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin,  OUTPUT);

  Serial.begin(9600);
  Serial.println("Day 5 - RGB LED PWM Fading started");
}

void loop() {

  // 1) Fade from RED → GREEN
  // Red decreases from 255 → 0
  // Green increases from 0 → 255
  for (int i = 0; i <= 255; i++) {
    setColor(255 - i, i, 0);
    delay(10);  // Adjust transition speed
  }

  // 2) Fade from GREEN → BLUE
  for (int i = 0; i <= 255; i++) {
    setColor(0, 255 - i, i);
    delay(10);
  }

  // 3) Fade from BLUE → RED
  for (int i = 0; i <= 255; i++) {
    setColor(i, 0, 255 - i);
    delay(10);
  }

  // Loop repeats, creating a continuous color cycle.
}
