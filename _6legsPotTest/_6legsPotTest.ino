#define potPin A0

#define moveTime 50
#define noOfLegs 6
byte legIndex[noOfLegs] = {0, 4, 8, 16, 20, 24};
volatile int i;

void setup() {
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  int pos;
  pos = analogRead(potPin);
  pos = map(pos, 0, 1023, 500, 2500);
  for(i = 0; i < noOfLegs; i++) {
    moveNoDelay(legIndex[i], pos, moveTime);
  }
  delay(moveTime);
  //move(15, 1200, 100);
}

void moveNoDelay(int servo, int position, int time) {
   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   Serial.print(" T");
   Serial.println(time);
   //delay(time);
}
