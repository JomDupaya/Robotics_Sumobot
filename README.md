# 🤖 Sumobot Project

## Overview
The **Sumobot Project** is a robotic system designed for sumo-style robot competitions. In this competition, the objective of the robot is to find and push out its opponent while staying within bounds. This project combines hardware design, control systems, and algorithms for intelligent behavior to create a competitive and robust sumobot.

---

## 🏆 Recognitions
- 🥈 **2nd Place** - **Sumobot Competition**  
  *CPE Days - Technological Institute of the Philippines*  
  **Date**: May 2023  

- 🏅 **Champion** - **ARENA Category**  
  *Cyber Fighter Ultimate Sumobot Competition - University of Santo Tomas (UST)*  
  **Date**: February 2024  

- 🎨 **Best Sumobot Design**  
  *Cyber Fighter Ultimate Sumobot Competition - University of Santo Tomas (UST)*  
  **Date**: February 2024  

---

## ✨ Features
- 🚀 **Autonomous Operation**: Fully automated behavior during competition using sensors and decision-making algorithms.
- 🔍 **Obstacle Detection**: Equipped with proximity and infrared sensors to detect opponents and avoid boundaries.
- ⚡ **High Torque Motors**: Ensures strong pushing power and fast movement.
- 🛡️ **Compact and Durable Design**: Optimized for agility and robustness in competitive environments.

---

## 🧩 Components Used

### 🛠️ Hardware
- **Microcontroller**: Arduino Nano  
- **Motor Driver**: TB6612FNG  
- **Voltage Regulators**:
  - DC-DC Boost Converter LM2577 / XL6009 for motor driver  
  - Constant Current Buck Converter XL4015 for Arduino Nano  
- **Motors**: DC Gear Motor 12V 250RPM - SGM25-370  
- **Wheels**: 65mm Rubber Wheel Silver  
- **Sensors**:
  - QTR-1RC Reflectance Sensor 2-Pack for line detection  
  - Ultrasonic sensor HC-SR04 for proximity detection (left and right)  
  - Sharp IR Infrared Distance Sensor (20–150 cm) for long-range opponent detection at the front  
- **Power Supply**: 3.7V Lithium-ion 18650 Battery  
- **PCB**: FR4 Universal Protoboard PCB - Double Sided  
- **Buttons**: Tactile Button Switch for strategy mode selection  
- **Connectors**:  
  - 3-Pin Terminal Block for power supply entry points to the motor driver and microcontroller  
  - 2-Pin Terminal Block for DC motor connections to the motor driver  
- **Capacitors**: Electrolytic 100uF 16V for DC motor stabilization  
- **Chassis and Body**: Aluminum Alloy 

### 💻 Software
- **Programming Language**: C++

---

## 🛠️ Design Considerations
- ⚖️ **Speed vs Power**: Balanced the torque and speed of motors to ensure effective pushing power without sacrificing mobility.
- 📍 **Sensor Placement**: Positioned sensors strategically to maximize detection accuracy for both the opponent and ring boundaries.
- ⚙️ **Weight Optimization**: Kept the design under the maximum allowed weight limit for competitions.

---

## 🔧 Code Overview
The main program is divided into the following sections:
1. 🛠️ **Initialization**: Sets up sensors, motors, and initial states.
2. 🕵️ **Opponent Detection**: Uses ultrasonic sensors to locate the opponent.
3. 🚧 **Edge Avoidance**: Monitors infrared sensors to prevent the robot from leaving the ring.
4. 🕹️ **Movement Strategy**: Implements algorithms for offensive and defensive maneuvers.
5. 🔄 **Control Loop**: Continuously updates sensor readings and executes decisions in real-time.

---

## 📝 Usage Instructions
1. **Setup**:
   - 🛠️ Assemble the hardware components according to the design.
   - 📤 Upload the program to the Arduino Nano.
2. **Testing**:
   - 🧪 Place the robot in the ring and power it on.
   - 🔍 Test sensor readings and motor responses in a controlled environment.
3. **Competition Mode**:
   - 🔋 Ensure the battery is fully charged.
   - 🏁 Place the robot within the starting area of the sumo ring.
   - 🤖 Start the match and let the robot operate autonomously.

---

## ⚠️ Challenges Faced
- 🎛️ **Sensor Calibration**: Fine-tuning the sensors to avoid false readings during matches.
- 🔄 **Motor Synchronization**: Ensuring consistent and smooth motor operation for optimal maneuvering.
- 🚧 **Ring Boundary Detection**: Improving edge detection reliability on varying competition surfaces.

---

## 🚀 Future Improvements
- 🧠 **Enhanced AI**: Implementing machine learning algorithms for adaptive strategies.
- 🛠️ **Improved Sensors**: Adding a wider range of sensors for better opponent detection.
- 🔋 **Energy Efficiency**: Optimizing power consumption to extend operational time.
- 🎯 **Advanced Tactics**: Developing complex movement patterns for more competitive performance.

---

## 🙏 Acknowledgments
This project was made possible through the collaboration of dedicated team members and mentors. Special thanks to our competition organizers and supporters for providing this learning opportunity.

---

## 📞 Contact
For inquiries, feedback, or collaboration, please reach out to:
**Name**: Jom Dupaya  
**Email**: [jomariedupaya@gmail.com](mailto:jomariedupaya@gmail.com)

---
