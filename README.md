RpiArduinoCommand
=================

This program allow you to send command to the pin of a arduino

Demo:
https://www.youtube.com/watch?v=TlHfjvLdaBA


Wiring
----
By default : 
Pin 2 of an Arduino
GPIO 7 (Pin 11) of an Raspberry PI (the last one)

http://pi.gadgetoid.com/WiringPi-GPIO-Pinout.png?v=1
 http://elinux.org/images/2/2a/GPIOs.png



Arduino
-----

Just copy the code in the arduino directory into your arduino sketchbook directory (it contains the rc-switch library and a example programs)
Upload arduinocommand.ino for test purpose

All the explanation is inside the comments

Raspberry PI
-----

The program is already compiled.

It worked like this:
./arduinocommand PIN LOW/HIGH
Ex: ./arduinocommand 12 HIGH
