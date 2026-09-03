# R2 Robot — Mecanum Drive & Autonomous Control

A multi-functional **4-wheel mecanum robotic platform** built around an ESP32, integrating wireless PS5 control, omnidirectional drive, IMU-based orientation sensing, ultrasonic distance measurement, relay-controlled mechanisms, and automated motion sequences.

The project was developed as a modular control system for combining **manual teleoperation with sensor-assisted and autonomous behaviors**.

## 🚀 Features

* **4-wheel mecanum drive** for forward, backward, lateral and rotational movement
* **PS5 wireless controller** for real-time robot control
* **ESP32 Wi-Fi + WebSocket** communication for transmitting robot telemetry
* **MPU6050 IMU** with Kalman filtering for stable pitch and roll estimation
* **Ultrasonic sensing** for front and ground-distance measurement
* **Relay-controlled mechanisms** operated directly from the PS5 controller
* **Automated motion sequence** using ultrasonic and IMU feedback
* **Orientation-based motion control** using pitch stability detection
* **Emergency stop** through controller input

## 🧠 System Architecture

```text
                 ┌─────────────────┐
                 │   PS5 Controller │
                 └────────┬────────┘
                          │
                          ▼
                 ┌─────────────────┐
                 │   ESP32 Control │
                 │     System      │
                 └────────┬────────┘
                          │
        ┌─────────────────┼─────────────────┐
        ▼                 ▼                 ▼
 ┌─────────────┐   ┌─────────────┐   ┌─────────────┐
 │ Mecanum     │   │ MPU6050 IMU │   │ Ultrasonic  │
 │ Drive       │   │ + Kalman    │   │ Sensors     │
 └──────┬──────┘   └──────┬──────┘   └──────┬──────┘
        │                 │                 │
        ▼                 ▼                 ▼
   4 DC Motors       Orientation       Distance
                     Feedback          Feedback
        │
        ▼
 ┌─────────────┐
 │  Mechanisms │
 │   Relays    │
 └─────────────┘
```

## 🛠️ Hardware

* ESP32
* 4 DC geared motors
* 4 mecanum wheels
* Motor driver
* PS5 controller
* MPU6050 IMU
* Ultrasonic sensors
* Relay modules
* Robot-mounted mechanical actuators
* Battery / power system

## 🎮 Manual Control

The PS5 controller provides direct control of the robot:

| Input         | Function                  |
| ------------- | ------------------------- |
| Left Stick    | Robot translation         |
| Right Stick X | Rotation                  |
| D-Pad         | Relay / mechanism control |
| Circle        | Start automation          |
| Square        | Stop motors               |

The drive-control layer maps joystick input into directional commands and PWM motor control.

## 🧭 IMU & Orientation

The MPU6050 is used to estimate the robot's **pitch, roll and yaw**.

A Kalman filter combines accelerometer and gyroscope measurements to obtain more stable pitch and roll estimates. The system also supports zero-offset calibration and orientation-based motion control.

The `mpuDelay()` routine allows the robot to continue a motion until a selected orientation reaches the desired target and remains stable within a specified tolerance.

## 📡 Wireless Communication

The ESP32 connects to Wi-Fi and starts a **WebSocket server on port 81**.

The robot can transmit live orientation information, including current and maximum pitch values, to a connected client.

## 📏 Distance Sensing

Ultrasonic sensors provide:

* **Front distance** for obstacle/approach detection
* **Ground distance** for detecting the robot's position relative to the ground

Distance is calculated from the measured echo pulse duration.

## 🤖 Autonomous Sequence

The project also includes an automated operating sequence combining **motor control, ultrasonic sensing, relays and IMU feedback**.

The sequence can:

1. Approach an object using front-distance feedback
2. Stop at a defined distance
3. Actuate mechanical components through relays
4. Use IMU pitch feedback to control motion
5. Perform a climbing sequence
6. Detect ground position
7. Execute the return/descent sequence

The automation routine coordinates these actions through sensor-based conditions rather than relying only on fixed timing.

## 📂 Repository Structure

```text
MQTT_R2_Drive/
│
├── KalmanMPU6050.cpp        # MPU6050 Kalman filter implementation
├── KalmanMPU6050.h          # IMU class definition
├── Relay.ino                # Relay / mechanism control
├── automate.ino             # Automated operating sequence
├── drive_conditions.ino     # Joystick-based drive conditions
├── drive_control_mapping.ino# Joystick-to-speed mapping
├── macnum_wheel_drive_asmi.ino
│                             # Main integrated robot control
├── mpuDelay.ino             # Orientation-based motion control
├── run_motor.ino            # Four-motor drive control
└── ultrasonic.ino            # Ultrasonic distance sensing
```

## 🔧 Technologies

**ESP32 · Embedded C/C++ · Mecanum Drive · PS5 Controller · Wi-Fi · WebSocket · MPU6050 · Kalman Filter · Ultrasonic Sensors · PWM Motor Control · Relay Control · Robotics · Autonomous Control**

## 📌 Project Outcome

Developed an integrated robotic control system capable of combining **omnidirectional manual driving, wireless communication, orientation feedback, distance sensing, mechanism control and autonomous motion sequences** on a single ESP32-based platform.

## 🔮 Future Improvements

* Closed-loop wheel velocity control
* Encoder-based odometry
* Improved autonomous navigation
* Sensor fusion with additional IMUs/encoders
* More robust obstacle detection
* Modular ROS/ROS 2 integration
* Improved WebSocket telemetry and remote monitoring
