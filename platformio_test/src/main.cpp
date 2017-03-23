#include "Arduino.h"

class Joint {
public:
  Joint(const int pin, const int maxPos, const int minPos)
    : p(pin), maxP(maxPos), minP(minPos) {}

    void move(int pos, long speed) {
      currentPos = pos > maxP ? maxP : pos < minP ? minP : pos;

      Serial.print("#");
      Serial.print(p);
      Serial.print(" P");
      Serial.print(currentPos);
      Serial.print(" T");
      Serial.println(speed);
    }

private:
    const int p;
    const int maxP;
    const int minP;

    int currentPos;
};

Joint l1j1(31, 2400, 600);
Joint l1j2(30, 2000, 900);
Joint l1j3(29, 2000, 900);

Joint l2j1(27, 2400, 600);
Joint l2j2(26, 2000, 900);
Joint l2j3(25, 2000, 900);

Joint l3j1(23, 2400, 600);
Joint l3j2(22, 2000, 900);
Joint l3j3(21, 2000, 900);

Joint l4j1(7,  2400, 600);
Joint l4j2(6,  2000, 900);
Joint l4j3(5,  2000, 900);

Joint l5j1(11, 2400, 600);
Joint l5j2(10, 2000, 900);
Joint l5j3(9,  2000, 900);

Joint l6j1(15, 2400, 600);
Joint l6j2(14, 2000, 900);
Joint l6j3(13, 2000, 900);

const int speed = 500;

void moveJoint1(int i) {
  l1j1.move(i, speed);
  l2j1.move(i, speed);
  l3j1.move(i, speed);
  l4j1.move(i, speed);
  l5j1.move(i, speed);
  l6j1.move(i, speed);
}
void moveJoint2(int i) {
  l1j2.move(i, speed);
  l2j2.move(i, speed);
  l3j2.move(i, speed);
  l4j2.move(i, speed);
  l5j2.move(i, speed);
  l6j2.move(i, speed);
}
void moveJoint3(int i) {
  l1j3.move(i, speed);
  l2j3.move(i, speed);
  l3j3.move(i, speed);
  l4j3.move(i, speed);
  l5j3.move(i, speed);
  l6j3.move(i, speed);
}

void moveAll(int i) {
  moveJoint1(i);
  moveJoint2(i);
  moveJoint3(i);
}

void fullRangeMove() {
  for (int i = 2400; i >= 600; i-= 300)
  {
    moveAll(i);
    delay(speed);
  }
  // delay(4000);

  for (int i = 600; i <= 2400; i+= 300)
  {
    moveAll(i);
    delay(speed);
  }
  // delay(4000);
}

void readAndMove() {
  int rPos = analogRead(A0);
  rPos =  map(rPos, 0, 900, 500, 2500);
  moveAll(rPos);
  delay(50);
}

#define MID 1500
#define UP 2500
#define DOWN 500
#define LONG_DELAY speed

void moveStanding() {
  moveJoint1(MID);
  moveJoint3(1500);
  moveJoint2(DOWN);
}
void step() {
  moveStanding();
  delay(speed);
  l1j2.move(UP, speed);
  l3j2.move(UP, speed);
  l5j2.move(UP, speed);
  delay(LONG_DELAY);
  l1j1.move(2000, speed);
  l3j1.move(2000, speed);
  l5j1.move(1000, speed);
  delay(LONG_DELAY);
  l1j2.move(DOWN, speed);
  l3j2.move(DOWN, speed);
  l5j2.move(DOWN, speed);
  delay(LONG_DELAY);
  l2j2.move(UP, speed);
  l4j2.move(UP, speed);
  l6j2.move(UP, speed);
  delay(LONG_DELAY);
  l1j1.move(MID, speed);
  l3j1.move(MID, speed);
  l5j1.move(MID, speed);
  delay(LONG_DELAY);
  l2j2.move(DOWN, speed);
  l4j2.move(DOWN, speed);
  l6j2.move(DOWN, speed);
  delay(LONG_DELAY);

}

void setup() {
  Serial.begin(9600);
  pinMode (A0, INPUT);
  Serial.println("Starting in 5 seconds");
  delay(5000);
}

void loop() {
  // fullRangeMove();
  // readAndMove();
  step();
}
