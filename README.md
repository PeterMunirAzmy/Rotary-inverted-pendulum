# Rotary Inverted Pendulum (Furuta Pendulum) Control System

## Overview

This project demonstrates the design, simulation, and real-time control of a **Rotary Inverted Pendulum (Furuta Pendulum)**. The primary goal is to stabilize the pendulum in an upright position using a Linear Quadratic Regulator (LQR) control technique, even under disturbances.

## Key Features

- **Real-Time Control**: Achieved using motors and encoders for precise feedback.
- **LQR Controller**: Optimized performance with minimal overshoot and fast settling time.
- **Hardware Integration**: MATLAB/Simulink integration with ESP32 microcontroller for hardware-in-the-loop (HIL) simulation.
- **Custom Encoder Block**: Developed using MATLAB I/O Device Builder to overcome encoder reading issues.

---

## System Design

### 1. System Modeling
- The dynamics of the pendulum were modeled using physics equations.
- Parameters like mass, arm length, gear ratios, and damping were estimated and linearized around the upright unstable equilibrium point.

### 2. Control Goals
- Stabilize the pendulum at the upright position (θ = 0°).
- Ensure a fast, stable response with minimal overshoot.

### 3. LQR Design
- The LQR controller was tuned using MATLAB to minimize a cost function:
J = ∫ (xᵀQx + uᵀRu) dt
where `Q` penalizes state errors and `R` penalizes control effort.

---

## Components

### Hardware
- **Motor with Encoder**: 210 RPM with a gearbox (11:1 gear ratio, 500 PPR encoder).
- **Omron Encoder**: 600 PPR for pendulum feedback.
- **ESP32 Dev Kit**: Microcontroller for interfacing with MATLAB/Simulink.
- **Motor Driver (L293D)**: For motor control.
- **Power Supply**: 12V DC for motor and encoder.

### Software
- **MATLAB/Simulink**: For simulation, controller design, and hardware integration.
- **Custom Encoder Block**: Developed using MATLAB’s I/O Device Builder.

---

## Implementation

1. **Modeling and Parameter Estimation**
 - Collected data on motor performance and tuned system parameters using MATLAB's Parameter Estimation app.

2. **Control Design**
 - Implemented LQR controller with fine-tuned `Q` and `R` matrices for optimal performance.

3. **Hardware-in-the-Loop (HIL)**
 - Validated the control system on physical hardware with real-time feedback.

---

## Results
- Successfully stabilized the pendulum with the LQR controller.
- Addressed challenges with mechanical setup and encoder data consistency.
- Achieved robust performance with real-time control.


---

## References

- [Project Resources](https://drive.google.com/drive/folders/1wwDWVjdvz_e80hr_DS7koI7oqCSTRCa7?usp=drive_link)

---


