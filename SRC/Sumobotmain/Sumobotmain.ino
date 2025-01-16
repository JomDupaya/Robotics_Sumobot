#include <QTRSensors.h>

const int lineR = A4;
const int lineL = A5;

const int trigR = A0;
const int echoR = A1;

const int trigL = A2;
const int echoL = A3;

const int reverseSpeed = 255;
const int delayTime = 5000;

int randomDelay, randomNum;
int strategy = 0;


// Motor right
#define PWMA 3
#define AIN1 4
#define AIN2 2

#define STBY 6

// Motor left
#define BIN1 7
#define BIN2 8
#define PWMB 9

#define IRsensor A7

int lineRValue = 0;
int lineLValue = 0;
long durationL = 0;
long durationR = 0;
int distanceLL = 0;
int distanceRR = 0;
int distanceIR = 0;

#define SWITCH_BUTTON1 10 // Pin for Strategy Switch 1
#define SWITCH_BUTTON2 11 // Pin for Strategy Switch 2
#define SWITCH_BUTTON3 12 // Pin for Strategy Switch 3

int low_speed = 150;
int high_speed = 250;
int ultraDistance = 75;

int leftLineSensor;
int rightLineSensor;

// Set button states, default is 0.
int button1State = 0;
int button2State = 0;
int button3State = 0;
int defaultButtonState = 1;

QTRSensors qtr;

const uint8_t SensorCount = 2;
uint16_t sensorValues[SensorCount];

void setup() 
{
  Serial.begin(9600);

  //Line Sensors
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){lineR, lineL}, SensorCount);
  qtr.setEmitterPin(2);

  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);
  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);

  // Left Motor
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  //Right Motor
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);


  // Strategy Buttons
  pinMode(SWITCH_BUTTON1, INPUT_PULLUP); 
  pinMode(SWITCH_BUTTON2, INPUT_PULLUP);
  pinMode(SWITCH_BUTTON3, INPUT_PULLUP);

  
  // // Buttons
  // button1State = digitalRead(SWITCH_BUTTON1);
  // button2State = digitalRead(SWITCH_BUTTON2);
  // button3State = digitalRead(SWITCH_BUTTON3);

  Serial.println("Pick button");

  while(digitalRead(SWITCH_BUTTON1) == LOW || digitalRead(SWITCH_BUTTON2) == LOW || digitalRead(SWITCH_BUTTON2) == LOW)
  {
    // wait
  }

  while(strategy == 0)
  {
    if(digitalRead(SWITCH_BUTTON1) == LOW)
    {
      strategy = 1;
    }

    else if(digitalRead(SWITCH_BUTTON2) == LOW)
    {
      strategy = 2;
    }

    else if(digitalRead(SWITCH_BUTTON3) == LOW)
    {
      strategy = 3;
    }

    else
    {
      strategy = 0;
    }
  }

  delay(4000);

}
 
void stop() //stop()
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,LOW);
}

void forward(int speed) // forward
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed-10);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, speed);
}


void reverse(int speed) //reverse()
{ 
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  analogWrite(PWMA, speed);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
  analogWrite(PWMB, speed);
}

void right(int speed) //right()
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  analogWrite(PWMA, speed);
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
  analogWrite(PWMB, speed);
}

void forward_right(int speed)
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  analogWrite(PWMA, 30);
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
  analogWrite(PWMB, speed);
}

void forward_left(int speed)
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  analogWrite(PWMA, speed);
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
  analogWrite(PWMB, 30);
}

void reverse_left(int speed)
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 100);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
  analogWrite(PWMB, speed);
}

void reverse_right(int speed)
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, speed);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
  analogWrite(PWMB, 100);
}

void left(int speed) //left()
{ 
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  analogWrite(PWMA, speed);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
  analogWrite(PWMB, speed);
}

void setMotorSpeed(int leftSpeed, int rightSpeed) 
{
  digitalWrite(PWMA, leftSpeed);
  digitalWrite(PWMB, rightSpeed);
}

void readLineSensors()
{
  qtr.read(sensorValues);

  rightLineSensor = sensorValues[0];
  leftLineSensor = sensorValues[1];
}

void readUltraSonicLeft()
{
  digitalWrite(trigL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigL, HIGH);
  durationL = pulseIn(echoL, HIGH);
  distanceLL = durationL * 0.034 / 2;
}

void readUltraSonicRight()
{

  digitalWrite(trigR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigR, HIGH);
  durationR = pulseIn(echoR, HIGH);
  distanceRR = durationR * 0.034 / 2;
}

void readIRSensor()
{
  float volts = analogRead(IRsensor) * 0.0048828125;
  distanceIR = 13 * pow(volts, -1);
}

void Strategy1()
{
  readUltraSonicLeft();
  readUltraSonicRight();
  readIRSensor();
  readLineSensors();

  Serial.print(leftLineSensor);
  Serial.print("\t");
  Serial.print(rightLineSensor);
  Serial.print("\t");
  Serial.print(distanceLL);
  Serial.print("\t");
  Serial.print(distanceRR);
  Serial.print("\t");
  Serial.println(distanceIR);

  if(leftLineSensor <= 2300)  
  {
    reverse(reverseSpeed);
    delay(400);
    right(255);
    delay(300);
  }

  else if(rightLineSensor <= 2000) 
  {
    reverse(reverseSpeed);
    delay(500);
    left(255);
    delay(300);
  }

  else if(leftLineSensor <= 2300 && rightLineSensor <= 2000)
  {
    randomDelay = random(100, 251);
    randomNum = random(1, 3);
    
    if(randomNum == 1)
    {
      reverse(reverseSpeed);
      delay(500);
      right(255);
      delay(randomDelay);
    }
    
    if(randomNum == 2)
    {
      reverse(reverseSpeed);
      delay(500);
      left(255);
      delay(randomDelay);
    }
  }

  if(leftLineSensor == 2500 && rightLineSensor == 2500) // if inside the ring 
  {
    if(distanceIR < 12)
    {
      forward(255);
    }

    else if(distanceLL <= ultraDistance)
    {
      left(255);
    }

    else if(distanceRR <= ultraDistance)
    {
      right(255);
    }

    else
    {
      forward(175);
    }
  }

}

void Strategy2()
{   
  readUltraSonicLeft();
  readUltraSonicRight();
  readIRSensor();
  readLineSensors();

  Serial.println("Commencing Strategy 2");

  if(leftLineSensor <= 2300)  
  {
    reverse(reverseSpeed);
    delay(400);
    right(200);
    delay(450);
  }

  else if(rightLineSensor <= 2000) 
  {
    reverse(reverseSpeed);
    delay(400);
    left(200);
    delay(450);
  }

  else if(leftLineSensor <= 2300 && rightLineSensor <= 2000)
  {
    randomDelay = random(100, 251);
    randomNum = random(1, 3);
    
    if(randomNum == 1)
    {
      reverse(reverseSpeed);
      delay(500);
      right(255);
      delay(randomDelay);
    }
    
    if(randomNum == 2)
    {
      reverse(reverseSpeed);
      delay(500);
      left(255);
      delay(randomDelay);
    }
  }

  if(leftLineSensor == 2500 && rightLineSensor == 2500) // if inside the ring 
  {
    if(distanceIR < 12)
    {
      forward(255);
    }

    else if(distanceLL <= ultraDistance)
    {
      left(255);
    }

    else if(distanceRR <= ultraDistance)
    {
      right(255);
    }

    else
    {
      forward(175);
    }
  }
}

void Strategy3()
{  
  readUltraSonicLeft();
  readUltraSonicRight();
  readIRSensor();
  readLineSensors();

  Serial.println("Commencing Strategy 3");

  if(leftLineSensor <= 2300) // if left sense
  {
    reverse(reverseSpeed);
    delay(300);
    reverse_right(reverseSpeed);
    delay(550);
  }

  else if(rightLineSensor <= 2000) // if right sense
  {
    reverse(reverseSpeed);
    delay(300);
    reverse_left(reverseSpeed);
    delay(550);
  }

  else if(leftLineSensor <= 2300 && rightLineSensor <= 2000) // if both sense
  {
    randomDelay = random(100, 251);
    randomNum = random(1, 3);
    
    if(randomNum == 1)
    {
      reverse(reverseSpeed);
      delay(500);
      right(255);
      delay(randomDelay);
    }
    
    if(randomNum == 2)
    {
      reverse(reverseSpeed);
      delay(500);
      left(255);
      delay(randomDelay);
    }
  }

  if(leftLineSensor == 2500 && rightLineSensor == 2500) // if inside the ring 
  {
    if(distanceIR < 15)
    {
      forward(255);
    }

    else if(distanceLL <= ultraDistance)
    {
      left(255);
    }

    else if(distanceRR <= ultraDistance)
    {
      right(255);
    }

    else
    {
      forward(175);
    }
  }
}

void loop() 
{

  switch(strategy)
  {
    case 1: 
      Strategy1();
      break;   
    case 2:
      Strategy2();
      break;
    case 3:
      Strategy3();
      break;
  }
}
