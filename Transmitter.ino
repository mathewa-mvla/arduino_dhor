#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

 Serial.begin(9600);

 // Transmitter is connected to Arduino Pin #10 
 mySwitch.enableTransmit(2);

 // Optional set pulse length.
 mySwitch.setPulseLength(165);

 // set protocol (default is 1, will work for most outlets)
 // mySwitch.setProtocol(2);

 // Optional set number of transmission repetitions.
 // mySwitch.setRepeatTransmit(15);


}

void loop() {
 mySwitch.send("Hello World");
 Serial.println("transmitting...");
 delay(1000);
}
