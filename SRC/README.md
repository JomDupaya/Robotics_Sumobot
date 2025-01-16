## 📂 Source Code

The source code for the Sumobot project is organized into a single file, which contains the initialization of the system, motor control, sensor readings, and movement logic. The code is modular, making it easy to update or add new features.

### Code Structure:
- **Sumobotmain.ino**: The main file that contains the core logic for controlling the Sumobot:
  - Motor control for movement (forward, reverse, turning)
  - Reading from line sensors, ultrasonic sensors, and infrared sensors
  - Implementing movement strategies based on sensor data
  - Handling input from strategy selection buttons
  - Decision-making logic for navigating the sumo ring and avoiding obstacles

The robot operates in three predefined strategies:
- **Strategy1**: Line following and basic obstacle avoidance.
- **Strategy2**: Distance measurement and opponent detection.
- **Strategy3**: Reactive movement based on proximity and positioning in the ring.

---

### Key Components:
- **Motor Control**: The motors are controlled using PWM pins, with motor drivers for the left and right wheels. The robot can move forward, reverse, turn left, or turn right with adjustable speeds.
- **Sensor Logic**: The robot uses QTR sensors for line-following, ultrasonic sensors for distance measurement, and an infrared sensor to detect objects at close range.
- **Movement Strategy**: The robot adapts its movement strategy based on real-time sensor data, enabling it to follow lines, avoid obstacles, and detect opponents.

Feel free to explore the code, make modifications, and adapt it to suit your needs or competition rules. If you make improvements or have ideas for new features, feel free to submit a pull request.

## 🛠️ Installation

To use this code, you’ll need:
- Arduino IDE or compatible development environment
- Compatible hardware: Arduino board (e.g., Arduino Uno)
- Motor drivers and sensors (QTR sensors, ultrasonic sensor, infrared sensor)
- Appropriate wiring and power supply for your Sumobot

1. Clone or download this repository.
2. Open the `Sumobotmain.ino` file in Arduino IDE.
3. Upload the code to your Arduino board.
4. Connect the motors, sensors, and button switches according to your hardware setup.

---

## 🧪 Testing and Debugging

Testing and debugging are essential steps to ensure that the Sumobot operates as expected during competitions. This section outlines the testing procedures and debugging tips for the Sumobot project.

---

### 🔧 **Testing Instructions**

1. **Hardware Testing:**
   - Before running the code, ensure all components are correctly assembled. Double-check the wiring for the motor driver, sensors, and microcontroller connections.
   - Test each motor individually by running the motor test code (`motor_test.ino`) to verify that the motors are functioning correctly.
   - Test the sensors (ultrasonic, infrared, and reflectance) to confirm they are providing accurate readings. Use the sensor test code (`sensor_test.ino`) to observe the sensor outputs.

2. **Code Testing:**
   - Upload the code to the Arduino Nano and observe the behavior of the Sumobot in a controlled environment.
   - Verify that the robot responds to sensor inputs by testing edge detection, opponent detection, and obstacle avoidance functionalities.
   - Check if the movement algorithms work as expected, and ensure the robot follows the correct strategy based on the sensor data.

3. **Edge Case Testing:**
   - Test the Sumobot in various conditions such as different ring surfaces, distances from opponents, and different lighting conditions for sensors.
   - Ensure that the robot reliably avoids the ring edges and accurately detects the opponent's position in a variety of scenarios.

---

### 🐞 **Debugging Tips**

1. **Serial Monitor:**
   - Use the **Serial Monitor** in the Arduino IDE to print debug messages during execution. This will help you track sensor readings, motor states, and decision-making processes.
   - For example, print the distance detected by the ultrasonic sensor, or log motor control commands to see if they align with the expected behavior.

2. **Check Sensor Accuracy:**
   - If sensors are not behaving as expected, verify the wiring and sensor calibration. Sensors such as the ultrasonic and infrared sensors can give inaccurate readings if they are not calibrated properly.
   - Adjust sensor sensitivity and test again in different conditions to ensure consistent behavior.

3. **Motor and Movement Issues:**
   - If the robot is not moving as expected, check the motor wiring and ensure the motor driver is receiving the correct control signals.
   - Use the motor test code to test each motor's rotation and response individually.

4. **Power Supply:**
   - Insufficient or unstable power supply can cause erratic behavior. Ensure the battery is fully charged and the voltage regulators are properly handling the power distribution.

5. **Code Debugging:**
   - If the robot’s behavior is erratic, check the control loops in the code. Ensure that the logic for decision-making, such as avoiding boundaries and detecting opponents, is executing correctly.

---

### 🛠️ **Troubleshooting Checklist**
- [ ] **Motors not spinning:** Check motor wiring and motor driver connections.
- [ ] **Sensors not reading correctly:** Verify sensor wiring and calibration.
- [ ] **Sumobot leaving the ring:** Adjust the edge detection logic and sensor positioning.
- [ ] **Unreliable movement:** Test the motor control code for consistency and check for power supply issues.

---

### 🧑‍💻 **Further Testing and Improvements**

As the Sumobot project evolves, you can continuously improve the code by implementing more advanced debugging methods or adding additional sensors for enhanced accuracy. Experiment with different strategies and movements during practice runs to see how the robot responds under competition conditions.

---

## 📜 License

This project is open-source and released under the [License](https://github.com/JomDupaya/Robotics_Sumobot/blob/e8f7132bed7ddc537f46a0e22422b6b8f175e030/LICENSE).

