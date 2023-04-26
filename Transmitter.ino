// #include <RH_ASK.h> 

// RH_ASK driver;

// void setup()
// {
//     Serial.println("1");
//     Serial.begin(9600);	  // Debugging only
//     if (!driver.init())
//          Serial.println("init failed");

//     Serial.println("sucess setup");
// }

// void loop()
// {
//     const char *msg = "hello world!";
//     driver.send((uint8_t *)msg, strlen(msg));
//     Serial.println(msg);
//     driver.waitPacketSent();
    
//     delay(1000);
// }



/*
  Example for different sending methods
  
  https://github.com/sui77/rc-switch/
  
*/

// #include <RCSwitch.h>

// RCSwitch mySwitch = RCSwitch();

// void setup() {

//   Serial.begin(9600);
  
//   // Transmitter is connected to Arduino Pin #10  
//   mySwitch.enableTransmit(10);
  
//   // Optional set protocol (default is 1, will work for most outlets)
//   // mySwitch.setProtocol(2);

//   // Optional set pulse length.
//   // mySwitch.setPulseLength(320);
  
//   // Optional set number of transmission repetitions.
//   // mySwitch.setRepeatTransmit(15);
  
// }

// void loop() {

//   /* See Example: TypeA_WithDIPSwitches */
//   mySwitch.switchOn("11111", "00010");
//   delay(1000);
//   mySwitch.switchOff("11111", "00010");
//   delay(1000);

//   /* Same switch as above, but using decimal code */
//   mySwitch.send(5393, 24);
//   delay(1000);  
//   mySwitch.send(5396, 24);
//   delay(1000);  

//   /* Same switch as above, but using binary code */
//   mySwitch.send("000000000001010100010001");
//   delay(1000);  
//   mySwitch.send("000000000001010100010100");
//   delay(1000);

//   /* Same switch as above, but tri-state code */ 
//   mySwitch.sendTriState("00000FFF0F0F");
//   delay(1000);  
//   mySwitch.sendTriState("00000FFF0FF0");
//   Serial.println("Sent message");
//   delay(1000);

//   delay(2000);
// } 




#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

 Serial.begin(9600);

 // Transmitter is connected to Arduino Pin #10 
 mySwitch.enableTransmit(2);

 // Optional set pulse length.
 mySwitch.setPulseLength(321);

 // set protocol (default is 1, will work for most outlets)
 // mySwitch.setProtocol(2);

 // Optional set number of transmission repetitions.
 // mySwitch.setRepeatTransmit(15);

 pinMode(13,OUTPUT);

}

void loop() {
 mySwitch.send("100000101100100011001000");
 digitalWrite(13,HIGH);
 delay(500);
 digitalWrite(13,LOW);
 delay(10000); 
}
