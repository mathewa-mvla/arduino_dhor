#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);

  mySwitch.enableTransmit(13);
  mySwitch.setPulseLength(165);
  Serial.println("starting");
}

void loop() {
  digitalWrite(12,HIGH);
  if (digitalRead(7) == HIGH){
    Serial.println("button pressed");
    digitalWrite(4,HIGH);
    mySwitch.send("Hello World");
    Serial.println("transmitting...");
  }
  else{
    digitalWrite(4,LOW);
    Serial.println("button off");
  }
  delay(100);



}
