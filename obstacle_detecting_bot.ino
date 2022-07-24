#include <Servo.h> 
#include <NewPing.h>

const int LeftForward = 11;
const int LeftBackward = 10;
const int RightForward = 12;
const int RightBackward = 13;

#define trig_pin A0 
#define echo_pin A1 


Servo servo_motor;

void setup(){
  pinMode(trig_pin , OUTPUT);
  pinMode(echo_pin , INPUT);
  pinMode(RightForward, OUTPUT);
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  servo_motor.attach(7); //servo pin
  servo_motor.write(90);
  delay(3000);
}
int distance;
void loop() {
  findDistance() ;

  if (distance > 35) {
    forward();
    delay(60);
  } else {
    delay(60);
    findDistance();
    if (distance > 35) {
      forward();
    } else {
      Stop();
      servo_motor.write(40);
      delay(500);
      findDistance();
      if (distance>35){
        servo_motor.write(90);
        delay(500);
        rightward();
        delay(500);
        Stop();
      }else{
        servo_motor.write(130);
        delay(500);
        findDistance();
        if (distance>35){
          servo_motor.write(90);
          delay(500);
          leftward();
          delay(500);
          Stop();
        }else{
          servo_motor.write(90);
          backward();
          delay(500);
          Stop();
          
        }
      }
    }
  }
}
void forward() {
  digitalWrite(LeftForward, HIGH);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);
}
void backward() {
  digitalWrite(LeftForward, LOW);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, HIGH);
}
void leftward() {
  digitalWrite(LeftForward, HIGH);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, HIGH);
}
void rightward() {
  digitalWrite(LeftForward, LOW);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);
}
void Stop() {
  digitalWrite(LeftForward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, LOW);
}

void findDistance() {
  int duration;
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  distance = (1 / 29.1) * (duration / 2);
  delay(60);

}
