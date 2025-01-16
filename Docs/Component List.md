# Components List

This document provides a detailed list of components used in the Sumobot project. It includes both hardware and software components, as well as their specifications and functions.

---

## 🛠️ **Hardware Components**

| **Component**                                | **Description**                                                     | **Specification/Model**                           | **Purpose**                                                  |
|----------------------------------------------|---------------------------------------------------------------------|---------------------------------------------------|--------------------------------------------------------------|
| **Microcontroller**                          | The main control unit of the Sumobot.                              | Arduino Nano                                      | Controls all sensors, motors, and decision-making algorithms. |
| **Motor Driver**                             | Used to control the motors in the robot.                           | TB6612FNG                                          | Provides motor control by amplifying signals from the Arduino. |
| **Voltage Regulators**                       | Regulates the voltage for components.                              | LM2577/XL6009 (for motor driver), XL4015 (for Arduino Nano) | Ensures stable power supply for motor driver and microcontroller. |
| **Motors**                                   | Provides movement power for the robot.                             | DC Gear Motor 12V 250RPM - SGM25-370               | Drives the robot’s wheels for movement.                      |
| **Wheels**                                   | Allows the robot to move on the surface.                           | 65mm Rubber Wheel Silver                          | Provides traction and mobility.                              |
| **Reflectance Sensor**                       | Detects the edge of the sumo ring.                                | QTR-1RC Reflectance Sensor 2-Pack                  | Used for line detection to prevent the robot from leaving the ring. |
| **Ultrasonic Sensor**                        | Measures the distance to nearby objects.                           | HC-SR04                                            | Detects opponent position and proximity to the edges of the ring. |
| **Infrared Distance Sensor**                 | Measures long-range distance for opponent detection.               | Sharp IR Distance Sensor (20-150 cm)              | Used for detecting opponent position in front of the robot.  |
| **Battery**                                  | Powers the robot and components.                                   | 3.7V Lithium-ion 18650 Battery                     | Provides power to the microcontroller and motors.             |
| **PCB**                                      | Connects all electronic components.                               | FR4 Universal Protoboard PCB - Double Sided       | Allows for easy component connections and circuit setup.     |
| **Buttons**                                  | Input for switching between different robot modes.                 | Tactile Button Switch                             | Used to switch between different operational modes of the robot. |
| **Connectors**                               | Connects wires to the motor driver and microcontroller.            | 3-Pin Terminal Block, 2-Pin Terminal Block         | Provides secure connections for power and motor signals.      |
| **Capacitors**                               | Stabilizes motor voltage to avoid power fluctuations.              | Electrolytic 100uF 16V                            | Smoothens out voltage spikes and dips in the motor circuit.  |
| **Chassis and Body**                         | Provides structure and protection for components.                  | Aluminum Alloy                                     | Offers strength, durability, and light weight for the robot.  |

---

## 💻 **Software Components**

| **Component**                                | **Description**                                                     | **Purpose**                                                  |
|----------------------------------------------|---------------------------------------------------------------------|--------------------------------------------------------------|
| **Programming Language**                     | Language used to program the robot.                                | C++                                                       | Main programming language for Arduino sketch and control.    |
| **Development Environment**                  | Platform used for writing and uploading code to the Arduino.       | Arduino IDE                                              | Used to write code and upload to the microcontroller.         |

---

## 📦 **Tools and Accessories**

| **Component**                                | **Description**                                                     | **Purpose**                                                  |
|----------------------------------------------|---------------------------------------------------------------------|--------------------------------------------------------------|
| **Soldering Iron**                           | Used to solder components to the PCB.                              | Helps in connecting components to the circuit board.         |
| **Wire Strippers**                           | Used for preparing wires before connections.                       | Ensures proper wire preparation for safe and effective connections. |
| **Breadboard**                               | Temporary platform for assembling components before soldering.     | Used for testing circuits before permanent assembly.         |
| **Power Supply**                             | External power source for the testing environment.                 | Powers the robot during testing without relying on batteries. |
| **Multimeter**                               | Measures voltage, current, and resistance.                         | Used for testing and troubleshooting electrical connections.  |

---

## 📝 **References and Further Reading**
- [Arduino Nano Official Documentation](https://www.arduino.cc/en/Guide/ArduinoNano)
- [TB6612FNG Motor Driver Datasheet](https://www.toshiba.semicon-storage.com/info/docget.jsp?did=2720&prodName=TB6612FNG)
- [Sharp IR Sensor Datasheet](https://www.sharp.co.jp/products/device/ir-sensor/pdf/data-sheets/sharp-ir-sensor-20cm-to-150cm.pdf)

---

This components list covers all hardware and software used in the Sumobot project. It is important to source reliable and compatible components to ensure smooth functionality and high performance during competitions.
