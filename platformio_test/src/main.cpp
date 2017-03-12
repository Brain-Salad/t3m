#include "Arduino.h"

class Joint {
public:
  Joint(const int pin, const int maxPos, const int minPos)
    : p(pin), maxP(maxPos), minP(minPos) {}

    void move(int pos, long speed) {
      currentPos = pos;

      Serial.print("#");
      Serial.print(p);
      Serial.print(" P");
      Serial.print(currentPos);
      Serial.print(" S");
      Serial.println(speed);
    }

private:
    const int p;
    const int maxP;
    const int minP;

    int currentPos;
};

Joint l1j1(31, 2400, 600);
Joint l1j2(30, 2500, 500);
Joint l1j3(29, 2500, 500);

Joint l2j1(27, 2400, 600);
Joint l2j2(26, 2500, 500);
Joint l2j3(25, 2500, 500);

Joint l3j1(23, 2400, 600);
Joint l3j2(22, 2500, 500);
Joint l3j3(21, 2500, 500);

Joint l4j1(7, 2400, 600);
Joint l4j2(6, 2500, 500);
Joint l4j3(5, 2500, 500);

Joint l5j1(11, 2400, 600);
Joint l5j2(10, 2500, 500);
Joint l5j3(9, 2500, 500);

Joint l6j1(15, 2400, 600);
Joint l6j2(14, 2500, 500);
Joint l6j3(13, 2500, 500);

const int speed = 5000;

void moveAll(int i) {
    l1j1.move(i, speed);
    l1j2.move(i, speed);
    l1j3.move(i, speed);

    l2j1.move(i, speed);
    l2j2.move(i, speed);
    l2j3.move(i, speed);

    l3j1.move(i, speed);
    l3j2.move(i, speed);
    l3j3.move(i, speed);

    l4j1.move(i, speed);
    l4j2.move(i, speed);
    l4j3.move(i, speed);

    l5j1.move(i, speed);
    l5j2.move(i, speed);
    l5j3.move(i, speed);

    l6j1.move(i, speed);
    l6j2.move(i, speed);
    l6j3.move(i, speed);
}

void fullRangeMove() {
  for (int i = 2000; i >= 500; i-= 500)
  {
    moveAll(i);
  }
    delay(2000);
  for (int i = 500; i <= 2000; i+= 500)
  {
    moveAll(i);
  }
    delay(2000);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  fullRangeMove();
}
