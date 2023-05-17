#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.println("starting");
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(4,INPUT);
  pinMode(12,OUTPUT);

  
  mySwitch.enableTransmit(10);
  mySwitch.setPulseLength(165);
  
}

void loop() {
  digitalWrite(12,HIGH);
  if (digitalRead(7) == HIGH){

    mySwitch.send("000000000001010100010001");//5393
    Serial.println("button 1 pressed");

  }
  if(digitalRead(4)==HIGH){
    mySwitch.send("000000000001010100010100"); //5396
    Serial.println("button 2 pressed");
  }
  delay(100);



}
