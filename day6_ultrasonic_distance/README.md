# Day 6 – Ultrasonic Distance Measurement and RGB Feedback

## Objective
Measure distance using an ultrasonic sensor and visualize the result using an RGB LED.

## Concepts Learned
- Digital I/O control
- Ultrasonic time-of-flight measurement
- pulseIn() usage
- Distance calculation using speed of sound
- Moving average filtering
- Sensor-based decision logic

## Description
The HC-SR04 ultrasonic sensor emits an ultrasonic pulse and measures the echo return time.
The measured pulse duration is converted into distance.

To improve measurement stability, a moving average filter is applied.
The filtered distance is then used to control an RGB LED, providing intuitive visual feedback.

## Files
- ultrasonic_distance.ino  
  Basic ultrasonic distance measurement.
- moving average filter.ino  
  Distance measurement with moving average filtering applied.
- ultrasonic_rgb.ino  
  Filtered distance measurement with RGB LED feedback.
- wiring.png  
  Basic ultrasonic sensor wiring.
- wiring2(ultrasonic_rgb).png  
  Ultrasonic sensor with RGB LED wiring diagram.

## Distance Status Logic
- Green: Safe distance
- Yellow: Caution
- Orange: Alert
- Red (blinking): Danger
- Blue: No echo / out of range
