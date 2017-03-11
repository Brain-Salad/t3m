#include "Joint.h"

Joint l2j1(16, 2400, 600);
Joint l3j1(8, 2400, 600);
Joint l4j1(4, 2400, 600);
Joint l5j1(0, 2400, 600);

const int speed = 5000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 2400; i >= 600; i-= 200)
  {
    l2j1.move(i, speed);
    l3j1.move(i, speed);
    l4j1.move(i, speed);
    l5j1.move(i, speed);
  }
    delay(20);
  for (int i = 600; i <= 2400; i+= 200)
  {
    l2j1.move(i, speed);
    l3j1.move(i, speed);
    l4j1.move(i, speed);
    l5j1.move(i, speed);
  }
    delay(20);
}
