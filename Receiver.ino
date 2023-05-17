#include <RCSwitch.h>
#include <Servo.h>
#include <ezButton.h>

// constants won't change
 // Arduino pin connected to button's pin
const int SERVO_PIN  = 3; // Arduino pin connected to servo motor's pin
int angle = 0;
 // create ezButton object that attach to pin 7;
Servo servo;  


RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  Serial.println("started");
  pinMode(12, OUTPUT);
      // initialize serial
 // set debounce time to 50 milliseconds
  // servo.attach(SERVO_PIN);    // attaches the servo on pin 9 to the servo object

  // servo.write(angle);
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
      // Serial.print("Received ");
      // Serial.print(value);
      if (value==5396){
        Serial.println("left button is  pressed");
      }
      else if (value==5393){
        Serial.println("right button is pressed");
      }
      else{
        Serial.println(value);
      }
      // Serial.print(" / ");
      // Serial.print(mySwitch.getReceivedBitlength());
      // Serial.print("bit ");
      // Serial.print("Protocol: ");
      // Serial.println(mySwitch.getReceivedProtocol());
      // digitalWrite(12,HIGH);
      // delay(500);
      // digitalWrite(12,LOW);
      // while (angle <= 90) {
      //   delay(25);
      //   angle=angle+1;
      //   servo.write(angle); 
      // }
      // delay(1000);
      // Serial.println("completed servo loop");
    }

    mySwitch.resetAvailable();
  }

  delay(1000);

}
