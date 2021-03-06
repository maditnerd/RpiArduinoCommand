/*
 Author: Sarrailh Remi
 Description: This program receive commands from an Raspberry PI
 Licence : GplV3
 For More informations on this licence:
 http://www.tldrlegal.com/l/GPL3

You will need rcswitch library
http://code.google.com/p/rc-switch/

Wiring:
You put any composants (ex a LED) on pin 8/9/10 to test it!
You must have a RF Receiver on pin 2
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int Pin8 = 8;
int Pin9 = 9;
int Pin10 = 10;

int high_or_low;
int pin_selected;
int verification_number;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  pinMode(Pin8, OUTPUT);
  pinMode(Pin9, OUTPUT);
  pinMode(Pin10, OUTPUT); 
}

void loop() {

  if (mySwitch.available()) { //If a message is sended with RF Code
   unsigned long value = mySwitch.getReceivedValue(); // Copy the value 
   high_or_low = value % 10; //Retrieving last number from the code
   
   
   //If the Pin is 2 digits
   if (value > 9999) // If the code is 5 digits (Pin 10 to 99)
   {
     verification_number = value / 10 % 10; //Retrieve verification number
     pin_selected = value / 100 % 100; // Retrieve Pin
   }
   else // If the code is not 5 digits
   {
      verification_number = value / 1000 % 10; //Retrieve verification number
      pin_selected = value / 100 % 10; // Retrieve Pin
   }
   
   //Verify the verification_number
   if (verification_number == 9)
   {
 
   Serial.print("Pin ");
   Serial.print(pin_selected);
   Serial.print(" changed to ");
     if (high_or_low == 1)
     {
     Serial.println("HIGH");
     }
     
     if (high_or_low == 0)
     {
     Serial.println("LOW");
     }
   
     digitalWrite(pin_selected,high_or_low); //Change PIN status
     }
   
   Serial.print("Code Received: ");
   Serial.println(value);

   
   
   
  }
  mySwitch.resetAvailable();
  
}
