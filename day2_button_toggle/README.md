# Day 2 – Button Toggle with Software Debounce

## Objective
Toggle an LED using a push button while handling mechanical bouncing.

## Concepts Learned
- Digital input reading
- INPUT_PULLUP
- Edge detection (HIGH → LOW)
- Software debounce
- Boolean state toggling

## Description
The push button is read using the internal pull-up resistor.  
The LED toggles only when a valid button press is detected.  
A 50 ms debounce delay prevents false triggers caused by contact bouncing.

## File
- button_toggle.ino
