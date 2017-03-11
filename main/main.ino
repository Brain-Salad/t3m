class Joint {
public:
  Joint(const int pin, const int maxPos, const int minPos)
    : p(pin), maxP(maxPos), minP(minPos)
    {}

  void move(int pos, long speed)
  {
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
