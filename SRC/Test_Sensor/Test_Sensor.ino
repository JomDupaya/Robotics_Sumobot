#include <QTRSensors.h>

const int lineR = A4;
const int lineL = A5;

const int trigR = A0;
const int echoR = A1;

const int trigL = A2;
const int echoL = A3;

const int IRsensor = A7;

long durationL = 0;
long durationR = 0;
int distanceLL = 0;
int distanceRR = 0;
int distanceIR = 0;

int leftLineSensor;
int rightLineSensor;

QTRSensors qtr;
const uint8_t SensorCount = 2;
uint16_t sensorValues[SensorCount];

void setup() {
  Serial.begin(9600);

  // Line Sensors
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){lineR, lineL}, SensorCount);
  qtr.setEmitterPin(2);

  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);
  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);
  pinMode(IRsensor, INPUT);

  Serial.println("Testing Sensors...");
}

void loop() {
  // Read Line Sensors
  qtr.read(sensorValues);
  rightLineSensor = sensorValues[0];
  leftLineSensor = sensorValues[1];
  
  // Read Ultrasonic Sensors
  readUltraSonicLeft();
  readUltraSonicRight();
  
  // Read IR Sensor
  readIRSensor();

  // Print values for debugging
  Serial.print("Left Line Sensor: ");
  Serial.print(leftLineSensor);
  Serial.print("\tRight Line Sensor: ");
  Serial.println(rightLineSensor);

  Serial.print("Distance Left: ");
  Serial.print(distanceLL);
  Serial.print("\tDistance Right: ");
  Serial.println(distanceRR);

  Serial.print("IR Distance: ");
  Serial.println(distanceIR);

  delay(500); // Delay between readings
}

void readUltraSonicLeft() {
  digitalWrite(trigL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigL, HIGH);
  durationL = pulseIn(echoL, HIGH);
  distanceLL = durationL * 0.034 / 2;
}

void readUltraSonicRight() {
  digitalWrite(trigR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigR, HIGH);
  durationR = pulseIn(echoR, HIGH);
  distanceRR = durationR * 0.034 / 2;
}

void readIRSensor() {
  float volts = analogRead(IRsensor) * 0.0048828125;
  distanceIR = 13 * pow(volts, -1);
}
