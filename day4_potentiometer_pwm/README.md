# Day 4 – Potentiometer Controlled PWM Output

## Objective
Control the brightness of an LED using a potentiometer as an analog input.

## Concepts Learned
- Analog-to-Digital Conversion (ADC)
- analogRead() usage (0–1023)
- Mapping analog input to PWM output
- analogWrite() and duty cycle control
- Sensor → actuator signal flow

## Description
A potentiometer is used as a voltage divider to generate a variable analog voltage.
This voltage is read using the Arduino's ADC and mapped to a PWM value to control
the brightness of an LED in real time.

This project demonstrates a fundamental embedded systems concept:
**continuous sensor input controlling an actuator output**.

## Files
- map_pwm.ino  
  Reads the potentiometer value and maps it to a PWM output.
- imagespot_setup.png  
  Wiring diagram of the potentiometer and LED circuit.

