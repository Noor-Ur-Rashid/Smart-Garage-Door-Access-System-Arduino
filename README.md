# Smart Garage Door Access System Using Arduino

## Overview

The Smart Garage Door Access System is an Arduino-based embedded security system designed to provide secure and automated vehicle access control. The system utilizes RFID authentication to verify authorized users, a servo motor to automate garage door operation, and visual and audible indicators to provide user feedback. In addition, the system incorporates a fire emergency override feature that automatically opens the garage door when an emergency signal is received, supporting safe evacuation during critical situations.

This project was developed as part of a larger Smart House Security System project, where multiple subsystems were integrated to enhance residential safety, security, and automation. My contribution focused on the design, development, and testing of the Garage Door Access System subsystem.

---

## Project Information

**Project Type:** Group Project (4 Members)

**Development Duration:** 4 Weeks

**My Role:** Garage Door Access System Developer

**Platform:** Arduino Uno

---

## My Contributions

* Designed and implemented RFID-based garage access control.
* Developed authorized and unauthorized user authentication logic.
* Integrated servo motor control for automatic garage door operation.
* Implemented manual override functionality using a push button.
* Developed fire emergency override integration for emergency evacuation support.
* Added LED indicators and buzzer alerts for system feedback.
* Performed system testing and debugging.
* Created Wokwi simulation and hardware prototype validation.

---

## System Features

### RFID Authentication

* Allows access only to authorized RFID cards.
* Prevents unauthorized entry attempts.
* Provides real-time access verification.

### Automatic Garage Door Control

* Opens the garage door automatically for authorized users.
* Closes the garage door after a predefined time interval.
* Reduces the need for manual operation.

### Emergency Fire Override

* Receives emergency signals from the Fire Safety subsystem.
* Automatically opens the garage door during fire emergencies.
* Supports safe evacuation procedures.

### Manual Override

* Allows garage door operation using a push button.
* Provides backup access when RFID is unavailable.

### Visual and Audible Feedback

* LED status indicators.
* Buzzer alerts for access events.
* Immediate user feedback for system status.

---

## Hardware Components

* Arduino Uno
* RFID RC522 Module
* Servo Motor
* Push Button
* LED Indicator
* Buzzer
* Jumper Wires
* Breadboard

---

## Software and Tools

* Arduino IDE
* Embedded C/C++
* Wokwi Simulator

---

## System Workflow

### Authorized Access

1. User scans an RFID card.
2. System verifies the card UID.
3. Access is granted if the UID matches an authorized card.
4. LED indicator activates.
5. Buzzer emits a confirmation beep.
6. Garage door opens automatically.
7. After a predefined delay, the garage door closes.

### Unauthorized Access

1. User scans an RFID card.
2. System verifies the card UID.
3. Access is denied if the UID is not recognized.
4. Garage door remains closed.
5. Warning buzzer pattern is activated.

### Fire Emergency Mode

1. Fire Safety subsystem sends an emergency signal.
2. Emergency signal is detected by the garage system.
3. Garage door automatically opens.
4. Exit path remains accessible for evacuation.
5. Door remains open until the emergency condition is cleared.

### Manual Override

1. User presses the manual access button.
2. Garage door opens automatically.
3. Door closes after the configured delay period.

---

## Project Architecture

The system consists of an Arduino Uno microcontroller connected to an RFID RC522 reader for authentication, a servo motor for garage door control, an LED indicator for visual feedback, and a buzzer for audible notifications. A push button provides manual access functionality, while an emergency input line receives fire emergency signals from another subsystem within the Smart House Security System.

---

## Screenshots

### Physical Prototype

Insert project prototype image here.

### Circuit Diagram

Insert circuit diagram image here.

### Wokwi Simulation

Insert Wokwi simulation screenshot here.

---

## Demonstration Video

A project demonstration video is available in the `Video_Demo` folder.

---

## Source Code

The complete Arduino source code for the Garage Door Access System is available in the `Source_Code` folder.

---

## Project Report

Detailed project documentation and design explanation are available in the `Report` folder.

---

## Results

The Smart Garage Door Access System successfully achieved the following objectives:

* Secure RFID-based access control.
* Automated garage door operation.
* Unauthorized access prevention.
* Manual override capability.
* Emergency evacuation support through fire integration.
* Reliable visual and audible user feedback.
* Successful hardware and simulation validation.

---

## Future Improvements

* Mobile application integration.
* IoT-based remote monitoring and control.
* Cloud database for user management.
* License plate recognition system.
* Mobile notifications and alerts.
* Access logging and event history storage.
* Integration with smart home platforms.

---

## Technologies Used

* Arduino Uno
* Embedded C/C++
* RFID Technology
* Servo Motor Control
* Embedded Systems Design
* Hardware Integration
* Wokwi Simulation

---

## Related Smart House Security System Subsystems

This project was developed as part of a larger Smart House Security System consisting of:

* RFID Door Access System
* Thief Burglar Detection System
* Climate Control System
* Smart Garage Door Access System (My Contribution)

---

## Author

**Noor Ur Rashid**

Bachelor of Computer Engineering

Asia Pacific University of Technology & Innovation (APU)

### Connect With Me

GitHub: https://github.com/Noor-Ur-Rashid

LinkedIn: https://www.linkedin.com/in/noor-ur-rashid-148b352a3/
