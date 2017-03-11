#include "Joint.h"

Joint l2j1(16, 2400, 600);
Joint l2j2(17, 2500, 500);
Joint l2j3(18, 2500, 500);

Joint l3j1(8, 2400, 600);
Joint l3j2(9, 2500, 500);
Joint l3j3(10, 2500, 500);

Joint l4j1(4, 2400, 600);
Joint l4j2(5, 2500, 500);
Joint l4j3(6, 2500, 500);

Joint l5j1(0, 2400, 600);
Joint l5j2(1, 2500, 500);
Joint l5j3(2, 2500, 500);

const int speed = 5000;

void setup() {
  Serial.begin(9600);
}

void loop() {

}

void fullRangeMove() {
  for (int i = 2400; i >= 500; i-= 200)
  {
    moveAll(i);
  }
    delay(20);
  for (int i = 500; i <= 2400; i+= 200)
  {
    moveAll(i);
  }
    delay(20);
}

void moveAll(int i) {
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
}

