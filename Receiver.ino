// #include <RH_ASK.h>
// #include <SPI.h> 

// RH_ASK driver;
// void setup() {
//   Serial.begin(9600);
//   // put your setup code here, to run once:
//   if (!driver.init())
//     Serial.println("init failed");
//   Serial.println("checkpoint1");

// }

// void loop() {

//   // put your main code here, to run repeatedly:
//   uint8_t buf[12];
//   uint8_t buflen = sizeof(buf);

//   if (driver.recv(buf, &buflen))
//     {
//       Serial.print("Message: ");
//       Serial.println((char*)buf);
//     }

// }


// #include <RH_ASK.h> 
// #ifdef RH_HAVE_HARDWARE_SPI
// #include <SPI.h>
// #endif

// RH_ASK driver;

// void setup()
// {
//   #ifdef RH_HAVE_SERIAL
//   Serial.begin(9600);
//   Serial.println("setup driver");
//   #endif
//   if (!driver.init())
//   #ifdef RH_HAVE_SERIAL
//          Serial.println("init failed");
//   #else
// 	;
//   #endif
// }

// void loop()
// {
//     uint8_t buf[12];
//     uint8_t buflen = sizeof(buf);

//     if (driver.recv(buf, 12)) {
// 	  int i;

// 	  // Message with a good checksum received, dump it.

//     Serial.println(("Got:" + buf[0] + buflen));
//     Serial.println("received something");
//     } 
 
// }



/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      Serial.print("Received ");
      Serial.print( mySwitch.getReceivedValue() );
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch.getReceivedProtocol() );
    }

    mySwitch.resetAvailable();
  }
}
