# SMD version of Bastl Kompas

As an attempt to learn kicad I decided to take the open source Bastl Kompas eurorack module, which is a 5hp through-hole soldering project, and redesign it as a 4hp SMD soldering project.

## hardware modifications

The SMD version has a different pin mapping which should be described in the code. The reason for this is the following:

### exposing MOSI/MISO/SCK/SS for on-pcb bootloader flashing

With the original Kompas you can take the ATMEGA328 chip, place it on a breadboard, and flash the Arduino bootloader onto it by wiring the MOSI/MISO/SCK/SS pins up to a normal Arduino or another ISP programmer.
With the SMD ATMEGA328-AU chip, you can't put it on a breadboard, so the normal way for flashing these with the arduino bootloader 

### exposing SDA/SCL pins as extension pins for integration with sensors

This project is based off the ATMEGA328-AU chip, which has 2 additional analog input pins when compared to the ATMEGA328-P that the Bastl Kompas uses.


### different pins
### more exposed pins for extensions

## hardware resources

kicad

schematic pdf
kicad files
panel gerbers
pcb top gerbers
pcb bottom gerbers

## alternative firmwares

### window comparator

### probabilistic latch / burst generator

