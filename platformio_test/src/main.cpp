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

void setup() {

}

void loop() {

}
