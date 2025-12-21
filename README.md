# MicrocontrollerBasics

Arduino-based projects developed step by step to build a solid foundation in  
**microcontroller programming, embedded systems, and basic electronics**.

This repository documents a structured learning progression, starting from simple
digital output control and advancing toward sensor-based systems with signal
processing and filtering.

Each folder represents a self-contained mini-project with clear documentation,
source code, and wiring diagrams.

---

## 📚 Project Overview

The projects cover fundamental concepts commonly used in embedded systems,
automation, robotics, and applied electronics.

Covered topics include:
- Digital output control (`pinMode`, `digitalWrite`)
- Timing and delays
- Digital input reading and software debouncing
- PWM (Pulse Width Modulation) and duty cycle control
- Analog input acquisition (`analogRead`)
- Mapping analog signals to PWM outputs
- Multi-channel PWM control (RGB LEDs)
- Ultrasonic distance measurement (HC-SR04)
- Time-of-flight principle
- Basic signal filtering (moving average)
- Sensor → logic → actuator pipelines

---

## 🧪 Hardware Used
- Arduino Uno
- LEDs and RGB LED
- Push button
- Potentiometer
- HC-SR04 ultrasonic distance sensor
- Current-limiting resistors (220Ω)

---

## 📁 Project Structure

- **Day 1 – Blink**  
  Digital output basics and timing control.

- **Day 2 – Button Toggle with Debounce**  
  Digital input reading, edge detection, and software debouncing.

- **Day 3 – PWM LED Fade**  
  LED brightness control using PWM.

- **Day 4 – Potentiometer to PWM**  
  Analog input processing and real-time actuator control.

- **Day 5 – RGB LED PWM Control**  
  Multi-channel PWM and color mixing.

- **Day 6 – Ultrasonic Distance Measurement**  
  Time-of-flight distance measurement, signal filtering, and RGB feedback.

Each project folder contains its own `README.md` with a detailed explanation.

---

## 🎯 Motivation

This repository was created to gain **hands-on experience with embedded systems**
and to strengthen practical skills relevant for
**research-oriented student assistant (HiWi) positions**.

The focus is on:
- understanding system behavior
- clean and reproducible setups
- structured documentation
- gradual complexity increase

---

## 🛠 Tools & Environment
- Arduino IDE
- C / C++ (embedded-oriented)
- Git & GitHub
- Wokwi (simulation)

---

## 📌 Notes
The projects emphasize clarity and learning progression rather than optimized or
production-ready code.
