
#include <RCSwitch.h>
#include <Servo.h>
//#include <ezButton.h>

RCSwitch mySwitch = RCSwitch();
const int SERVO_PIN  = 8; 
//const int LED_PIN = 13;
const int INITIAL_ANG = 0;
const int FINAL_ANG = 90;
Servo servo;
int ang;
//RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  Serial.println("started");
  pinMode(12, OUTPUT);
  ang = 0;
  servo.attach(SERVO_PIN);
  servo.write(0);

}

void loop() {
  // angle = 26;

  if (mySwitch.available()) {
    // Serial.println("switch is available");
    int value = mySwitch.getReceivedValue();

    if (value == 0) {
      Serial.print("Unknown encoding");
    } 
    else {
      Serial.print(value);
      if (value==5396){
        Serial.println("left button is  pressed");
        //open
        ang = 0;
        while (ang <= 90) {
          delay(100);
          ang = ang + 10;
          servo.write(ang);
          Serial.println("in loop");
          Serial.println(ang);
        }
      }
      else if (value==5393){
        Serial.println("right button is pressed");
        ang = 90;
        while (ang >= 0) {
          delay(100);
          ang = ang - 10;
          servo.write(ang);
          Serial.println(ang);

    }

      }
      else{
        Serial.println(value);
      }
    }

    mySwitch.resetAvailable();
  }

  delay(1000);

}
