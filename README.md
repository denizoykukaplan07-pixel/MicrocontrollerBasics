# MicrocontrollerBasics
Arduino / Wokwi projects for learning microcontroller programming, embedded systems, and basic electronics.

## Day 1 – Blink (LED Toggle)

- Simulated on Wokwi using Arduino Uno.
- Implemented a simple LED blinking program using:
  - `pinMode()`
  - `digitalWrite()`
  - `delay()`
- This is the foundational step for understanding timing and digital output control in microcontrollers.

## Day 2 – Button Toggle with Debounce
This example reads a push button using INPUT_PULLUP and toggles the built-in LED (pin 13) on each button press.  
To prevent multiple triggers caused by mechanical bouncing, a 50 ms software debounce is used.  
Only the HIGH → LOW transition (“new press event”) toggles the LED state.


