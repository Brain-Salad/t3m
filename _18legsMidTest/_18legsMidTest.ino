#define potPin A0

#define moveTime 50000
#define noOfLegs 6

#define first_joint_lower_limit  600
#define first_joint_higher_limit 2400

#define second_joint_lower_limit 500
#define second_joint_higher_limit  2500

#define third_joint_lower_limit 500
#define third_joint_higher_limit 2500


#define mid_point 1500

byte legIndex[noOfLegs] = {1, 5, 9, 17, 21, 25};
volatile int i;

void setup() {
  pinMode(potPin,INPUT);
  moveNoDelay(0, mid_point, moveTime);
  moveNoDelay(1, mid_point, moveTime);
  moveNoDelay(2, mid_point, moveTime);
  moveNoDelay(4, mid_point, moveTime);
  moveNoDelay(5, mid_point, moveTime);
  moveNoDelay(6, mid_point, moveTime);
  moveNoDelay(8, mid_point, moveTime);
  moveNoDelay(9, mid_point, moveTime);
  moveNoDelay(10, mid_point, moveTime);
  moveNoDelay(16, mid_point, moveTime);
  moveNoDelay(17, mid_point, moveTime);
  moveNoDelay(18, mid_point, moveTime);
  moveNoDelay(20, mid_point, moveTime);
  moveNoDelay(21, mid_point, moveTime);
  moveNoDelay(22, mid_point, moveTime);
  moveNoDelay(24, mid_point, moveTime);
  moveNoDelay(25, mid_point, moveTime);
  moveNoDelay(26, mid_point, moveTime);
  delay(moveTime/1000);
  Serial.begin(9600);
}

void loop() {
  int pos;
  pos = analogRead(potPin);
  pos = map(pos, 0, 1023, second_joint_lower_limit, second_joint_higher_limit);
  for(i = 0; i < noOfLegs; i++) {
  //  moveNoDelay(legIndex[i], pos, moveTime);
  }
  moveNoDelay(0, mid_point, moveTime);
  moveNoDelay(1, mid_point, moveTime);
  moveNoDelay(2, mid_point, moveTime);
  moveNoDelay(4, mid_point, moveTime);
  moveNoDelay(5, mid_point, moveTime);
  moveNoDelay(6, mid_point, moveTime);
  moveNoDelay(8, mid_point, moveTime);
  moveNoDelay(9, mid_point, moveTime);
  moveNoDelay(10, mid_point, moveTime);
  moveNoDelay(16, mid_point, moveTime);
  moveNoDelay(17, mid_point, moveTime);
  moveNoDelay(18, mid_point, moveTime);
  moveNoDelay(20, mid_point, moveTime);
  moveNoDelay(21, mid_point, moveTime);
  moveNoDelay(22, mid_point, moveTime);
  moveNoDelay(24, mid_point, moveTime);
  moveNoDelay(25, mid_point, moveTime);
  moveNoDelay(26, mid_point, moveTime); 
  delay(moveTime/1000);
  //move(15, 1200, 100);
}

void moveNoDelay(int servo, int position, long time) {
   Serial.print("#");
   Serial.print(servo);
   Serial.print(" P");
   Serial.print(position);
   Serial.print(" S");
   Serial.println(time);
   //delay(time);
}
