#include <Servo.h>

Servo baseServo;
Servo gateServo;

//3.1s 11ft
//3.55 ft/s

int gateClosed = 20;
int gateOpened = 100;
float velocityOfMarble = 3.55;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  baseServo.attach(9);
  gateServo.attach(10);


  gateServo.write(gateClosed);
  //timeUntilRelease = calculateTimeUntilRelease(distance, targetTime);






//--------------------------------------------------------------------------------------------------------------------------------
  // Insert angle, distance, and time here
    int angle = 0;
    int distance = 15;
    int targetTime = 30;
//--------------------------------------------------------------------------------------------------------------------------------






  
    
    float releaseDelay;

    releaseDelay = calculateTime(distance, targetTime);
    Serial.println(releaseDelay);
    digitalWrite(13, HIGH);
    baseServo.write(45 - angle);
    for (int i = 0; i < releaseDelay; i++) {
      delay(1000);
    }
    
    gateServo.write(gateOpened);
    delay(1000);
    
    gateServo.write(gateClosed);
    delay(100); 
}

void loop() {    
}

int calculateTime(int distance, int targetTime) {
  float rollTime = 0;
  rollTime = distance / velocityOfMarble;
  float finalTime = targetTime - rollTime;
  return finalTime - 9;
}
