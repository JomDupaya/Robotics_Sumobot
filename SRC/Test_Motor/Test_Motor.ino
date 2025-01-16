// Motor right
#define PWMA 3
#define AIN1 4
#define AIN2 2
#define STBY 6

// Motor left
#define BIN1 7
#define BIN2 8
#define PWMB 9

void setup() {
  Serial.begin(9600);
  
  // Motor Pins
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  Serial.println("Testing Motors...");
  delay(1000);
}

void loop() {
  // Test motor movement: Forward, Reverse, Left, Right
  forward(255);
  delay(2000);
  
  stop();
  delay(1000);

  reverse(255);
  delay(2000);
  
  stop();
  delay(1000);
  
  left(255);
  delay(2000);

  stop();
  delay(1000);

  right(255);
  delay(2000);

  stop();
  delay(1000);
}

void stop() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void forward(int speed) {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, speed);
}

void reverse(int speed) {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, speed);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, speed);
}

void left(int speed) {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, speed);
}

void right(int speed) {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, speed);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, speed);
}
