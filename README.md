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
Concepts learned:
-`Digital input (reading a push button)`

-`Internal pull-up resistor (INPUT_PULLUP)`

-`Edge detection (HIGH → LOW)`

-`Boolean state toggling (state = !state)`

-`Simple software debounce`

-`Controlling digital output (LED)`

### 📝 How it works
- The button is connected to **pin 2** and uses an internal pull-up resistor.  
  - Not pressed → pin reads **HIGH**  
  - Pressed → pin is pulled to **LOW**  
- The code compares the current reading with the previous state.  
- A toggle happens **only** when the button transitions from HIGH → LOW.  
- A small 50 ms debounce delay prevents false triggers.
  
The file is located in:  
`day2_button_toggle/button_toggle.ino`

### 🖥️ Simulation
The project can be tested using Wokwi (Arduino Simulator).  
A push button press toggles the LED and prints `ON` or `OFF` in the Serial Monitor.


