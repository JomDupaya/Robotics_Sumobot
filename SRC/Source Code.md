## 📂 Source Code

The source code for the Sumobot project is organized into a single file, which contains the initialization of the system, motor control, sensor readings, and movement logic. The code is modular, making it easy to update or add new features.

### Code Structure:
- **main.ino**: The main file that contains the core logic for controlling the Sumobot:
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

## 📜 License

This project is open-source and released under the [MIT License](LICENSE).
