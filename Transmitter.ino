#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(4,INPUT);
  pinMode(12,OUTPUT);


  mySwitch.enableTransmit(10);
  mySwitch.setPulseLength(165);
  Serial.println("starting");
}

void loop() {
  digitalWrite(12,HIGH);
  if (digitalRead(7) == HIGH){

    mySwitch.send("000000000001010100010001");//5393

  }
  if(digitalRead(4)==HIGH){
    mySwitch.send("000000000001010100010100"); //5396
  }
  delay(100);



}
