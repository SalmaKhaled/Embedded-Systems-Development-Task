# Embedded-Systems-Development-Task
Filtration task for XIOT

An arduino function to control one input and output (IO Pins) the input pin is a switch as interrupt once it pressed it should lighting the led connected to output pin.
if the switch pressed it sends “pressed” to the serial monitor only one time also send the LED states ”ON” or “OFF”
the whole function could be used many times in the program without interfering each-other
The program can send continuous serial data comes from temperature sensor with 3 second rate at the same time.


Assumptions:

- Switch is connected to pin 2
- LED is connected to pin 13
- Temprature sensor is connected to pin 0

