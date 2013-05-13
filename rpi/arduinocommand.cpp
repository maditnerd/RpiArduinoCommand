/*
 Author: Sarrailh Remi
 Description: This program sends commands to a Arduino
 Licence : GplV3
 For More informations on this licence:
 http://www.tldrlegal.com/l/GPL3

 Usage: ./arduinocommand pin LOW/HIGH
 Ex: ./arduinocommand 12 HIGH
 
 You will need rcswitch-pi library / WiringPi
 https://github.com/r10r/rcswitch-pi
 
 To install WiringPI (it will clone the git in the current directory)
 wget http://smarturl.it/wiringpi
 chmod +x wiringpi
 ./wiringpi

 To compile it:
 gcc arduinocommand.cpp -o arduinocommand RCSwitch.cpp -lwiringPi

 Requirement : A RF Transmitter (on GPIO 7 / Pin 11) 
 ---------------
 GPIO references
 http://elinux.org/images/2/2a/GPIOs.png
 ---------------
 WiringPI reference
 http://pi.gadgetoid.com/WiringPi-GPIO-Pinout.png?v=1
*/

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int PIN = 11; //This is the pin of the transmitter
    char buffer[256]; //This variable serve as a buffer to copy the string

if (argc == 3) // Verify if there is enough arguments
	{
    //Copy Argument 1 in a string
	strcpy(buffer,"9");
    strcat(buffer,argv[1]);

    strcat(buffer,"9"); //Add two random number to dissociate Pin from LOW/HIGH
   
    if (!strcmp("LOW",argv[2]))
    {
    	printf("Pin %s changed to LOW \n",argv[1]);
	// Add 0 to the code
    	strcat(buffer,"0");
    }

    if (!strcmp("HIGH",argv[2]))
    {
    	printf("Pin %s changed to HIGH\n",argv[1]);
	// Add 1 to the code
    	strcat(buffer,"1");
    }

    //If Argument 2 is neither LOW or HIGH
    if (strcmp("LOW",argv[2]) && strcmp("HIGH",argv[2]))
    {
    	printf("Arduino Command\n");
    	printf("----------------\n");
    	printf("ERROR: You should use LOW or HIGH here\n");
    	printf("INFO: This is case sensitive");
    	printf("Ex: ./arduinocommand 12 HIGH\n");
    }

}
else
{
	printf("Arduino Command\n");
	printf("----------------\n");
	printf("ERROR: You didn't provide enough arguments!\n");
	printf("Ex: ./arduinocommand 12 HIGH\n");
}


    long code = strtol(buffer,NULL,10); // Convert argument to long
    printf("Code sended: %ld\n",code);

    if (wiringPiSetup () == -1) return 1;
        RCSwitch mySwitch = RCSwitch();
        mySwitch.enableTransmit(PIN);

        mySwitch.send(code,24); // Send code in decimal
        return 0;
}
