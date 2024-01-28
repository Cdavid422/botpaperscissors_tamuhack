int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

int motor3pin1 = 6;
int motor3pin2 = 7;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);

  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(A0, INPUT);

  Serial.begin(9600);
}

void ROCK() {
  analogWrite(9, 200);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  delay(240);
  analogWrite(9, 0);
  delay(1500);
  analogWrite(9, 200);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  delay(240);
  analogWrite(9, 0);
}


void SCISSORS() {
  analogWrite(10, 200);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(280);
  analogWrite(10, 0);
  delay(1500);
  analogWrite(10, 200);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(220);
  analogWrite(10, 0);
}


void PAPER() {
  analogWrite(8, 200); //Changed
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  delay(270);
  analogWrite(8, 0);
  delay(1500);
  analogWrite(8, 200); //Changed
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  delay(240);
  analogWrite(8, 0);
}


void RPS() {
  for(int i = 0; i < 3; i++) {
    //Controlling speed (0 = off and 255 = max speed):
    analogWrite(9, 200); //ENA pin
    analogWrite(10, 200); //ENB pin
    analogWrite(8, 200); //ENA2 pin

    //Controlling spin direction of motors:
    digitalWrite(motor1pin1, HIGH);  
    digitalWrite(motor1pin2, LOW);   
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    digitalWrite(motor3pin1, HIGH);
    digitalWrite(motor3pin2, LOW);
    delay(260);
    digitalWrite(motor1pin1, LOW);   
    digitalWrite(motor1pin2, HIGH);  
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, HIGH);
    delay(225);
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(8, 0);

    delay(300);
  }
}


void SHOOT() {
  int choice = random(0, 3);
  if (choice == 0) {
    ROCK();
  } else if (choice == 1) {
    PAPER();
  } else if (choice == 2) {
    SCISSORS();
  }
}


void loop() {
  // put your main code here, to run repeatedly:  
  int motion = digitalRead(A0);
  Serial.println(motion);
  if (motion) {
    delay(1000);
    RPS();
    SHOOT();
    delay(3000);
  }
}