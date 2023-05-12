#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);


  mySwitch.enableTransmit(10);
  mySwitch.setPulseLength(165);
  Serial.println("starting");
}

void loop() {
  if (digitalRead(7) == HIGH){
    Serial.println("button pressed");
    mySwitch.send("Hello World");
    Serial.println("transmitting...");
  }
  else{
    Serial.println("button off");
  }
  delay(100);



}
