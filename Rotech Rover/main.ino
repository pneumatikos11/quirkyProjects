#include <NewPing.h>
#define trigpin 8
#define echopin 8
#define max_dist 400 //this is in cm 
#define MOTORCONST 0xfe
#define FWDCONST 0xf0
NewPing ultra(trigpin, echopin, max_dist);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = ultra.ping_cm();
  Serial.println(distance);
  if(ultra.ping_cm()>=10 || ultra.ping_cm() == 20 ){
    forward(1, 100);
    forward(2, 100);
  }else{
    forward(1, 0);
    forward(2, 0);
  }
}

void forward(int motorNum, int Speed) {
  Serial.write(MOTORCONST);
  Serial.write(motorNum);
  Serial.write(FWDCONST);
  Serial.write(Speed);
}
