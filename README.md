# Laser Security System with Gate Control

## Overview

This Arduino project integrates an IR Proximity Sensor, LDR, and servo motors to create a laser security system with gate control. The system opens the gates and activates lights when an object breaks the laser beam.

![20231126_102213](https://github.com/shreyaskbkukke/Bridge_Pass/assets/96857515/de13ab09-316e-444d-b446-9d32c640600a)

![20231126_102205](https://github.com/shreyaskbkukke/Bridge_Pass/assets/96857515/4bf9ead7-6b09-410a-84f0-d52d7623e0d9)

## Components

- 2 Servo Motors
- LDR Sensor
- IR Proximity Sensor
- Laser Diode
- Buzzer
- LED Lights
- Arduino Board

## Pin Configuration

- IR Sensor: Pin 5
- LDR Sensor: Pin A0
- Laser Diode: Pin 4
- Gate Servo 1: Pin 6
- Gate Servo 2: Pin 7
- Red Light: Pin 8
- Yellow Light: Pin 9
- Green Light: Pin 10
- Buzzer: Pin 11

## Usage

1. The system detects an object breaking the laser beam using the IR sensor.
2. If the LDR sensor detects light, the gates open, and the green light turns on.
3. If no light is detected, the red light blinks, and the gates remain closed.

## Configuration

- Adjust the LDR threshold value and servo angles as needed.

Feel free to modify the code for specific requirements.
