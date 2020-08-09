# Arduino library for the running two Pololu Dual VNH5019 Motor Driver Shields on an Arduino Mega

Version: 3.2.0-dualsheilds<br>
Release Date: 2019-11-09<br>
[www.pololu.com](http://www.pololu.com/)<br>
[![Build Status](https://travis-ci.org/photodude/DualVNH5019MotorShieldMod3.svg?branch=master)](https://travis-ci.org/photodude/DualVNH5019MotorShieldMod3)

## Summary
-------

This is a custom library for the [Arduino](http://www.pololu.com/catalog/product/2191) that interfaces with two Pololu [Dual VNH5019 Motor Driver Shields](http://www.pololu.com/catalog/product/2507) with an Arduino Mega. It makes it simple to drive four brushed, DC motors from 2 shields on an Arduino Mega.

## Supported platforms

This library is designed to work with the Arduino IDE versions 1.6.x or later; we have not tested it with earlier versions.  This library should support any Arduino-Mega-compatible boards

## Getting Started
---------------

### Hardware

Two Dual VNH5019 Motor Driver Shield can be purchased on [Pololu’s website](http://www.pololu.com/catalog/product/2507). See the [motor shield user’s guide](http://www.pololu.com/docs/0J49) for more details.

-   for the best stability, and the least conflicts with other libraries, you need cut and move the PWM pins on the shields
    -   for use with the Mega: 
      - for best results avoid using pins 4, 9, 10, 13 for PWM
      - Recommended to use the PWMServo library for servos to avoid timer and interupt conflicts
        - if using the standard Servo library for servos avoid using pins 44, 45, or 46 for PWM: more information in the Notes About Timers and Conflicts
    -   information on how to move the pins is in the pololu DualVNH5019MotorShield user guide

### Software

If you are using version 1.6.2 or later of the [Arduino software (IDE)](https://www.arduino.cc/en/Main/Software), you can use the Library Manager to install this library:

1. In the Arduino IDE, open the "Sketch" menu, select "Include Library", then "Manage Libraries...".
2. Search for "DualVNH5019MotorShieldMod3".
3. Click the DualVNH5019MotorShieldMod3 entry in the list.
4. Click "Install".

If this does not work, you can manually install the library:

1. Download the [latest release archive from GitHub](https://github.com/photodude/DualVNH5019MotorShieldMod3/releases) and decompress it.
2. Rename the folder "DualVNH5019MotorShieldMod3-xxxx" to "DualVNH5019MotorShieldMod3".
3. Drag the "DualVNH5019MotorShieldMod3" folder into the "libraries" directory inside your Arduino sketchbook directory.  You can view your sketchbook location by opening the "File" menu and selecting "Preferences" in the Arduino IDE.  If there is not already a "libraries" folder in that location, you should make the folder yourself.
4. After installing the library, restart the Arduino IDE.

## Example Program
---------------

An example sketch is available that shows how to use the library. You can access it from the Arduino IDE by opening the "File" menu, selecting "Examples", and then selecting "DualVNH5019MotorShieldMod3". If you cannot find these examples, the library was probably installed incorrectly and you should retry the installation instructions above.

### Demo

Open this example code sketch by selecting File-&gt;Examples-&gt;DualVNH5019MotorShieldMod3-&gt;Demo.

The demo ramps motor 1 from stopped to full speed forward, ramps down to full speed reverse, and back to stopped. Then, it does the same with the other motors. Current readings for each motor are sent over serial and can be seen with the serial monitor. If a fault is detected, a message is sent over serial.

### Test\_Motors

Open this example code sketch by selecting File-&gt;Examples-&gt;DualVNH5019MotorShieldMod3-&gt;Test\_Motors.

The Test\_Motors starts motor 1 from stopped to full speed forward, cost to full speed reverse, and back to stopped. Then, it does the same with the other motors.

## Documentation
-----------------

- `DualVNH5019MotorShieldMod3()`<br>Default constructor, selects the default pins as connected by the motor shields.

- `DualVNH5019MotorShieldMod3(unsigned char INA3, unsigned char INB3, unsigned char EN3DIAG3,
                              unsigned char CS3, unsigned char PWM3, unsigned char INA4, unsigned char INB4,
                              unsigned char EN4DIAG4, unsigned char CS4, unsigned char PWM4)`  
<br>Alternate constructor for shield connections remapped by user. default pins for motor shield 1, custom pins for motor shield 2

- `DualVNH5019MotorShieldMod3(unsigned char INA1, unsigned char INB1, unsigned char EN1DIAG1,
                              unsigned char CS1, unsigned char INA2, unsigned char INB2, 
                              unsigned char EN2DIAG2, unsigned char CS2)`  
<br>Alternate constructor for shield connections remapped by user. PWM1 and PWM2 cannot be remapped because the library assumes PWM is on timer1.

- `DualVNH5019MotorShieldMod3(unsigned char INA1, unsigned char INB1, unsigned char EN1DIAG1, 
                              unsigned char CS1, unsigned char INA2, unsigned char INB2, 
                              unsigned char EN2DIAG2, unsigned char CS2, unsigned char INA3, 
                              unsigned char INB3, unsigned char EN3DIAG3, unsigned char CS3, 
                              unsigned char INA4, unsigned char INB4, unsigned char EN4DIAG4, 
                              unsigned char CS4)`  
<br>Alternate constructor for shield connections remapped by user, all custom pins setup (note: assumes PWM pins are not remapped)

- `DualVNH5019MotorShieldMod3(unsigned char INA1, unsigned char INB1, unsigned char EN1DIAG1, 
                              unsigned char CS1, unsigned char INA2, unsigned char INB2, unsigned char EN2DIAG2, 
                              unsigned char CS2, unsigned char INA3, unsigned char INB3, unsigned char EN3DIAG3, 
                              unsigned char CS3, unsigned char INA4, unsigned char INB4, unsigned char EN4DIAG4, 
                              unsigned char CS4, unsigned char PWM1, unsigned char PWM2, unsigned char PWM3, unsigned char PWM4)`  
<br>Alternate constructor for shield connections remapped by user, all custom pins setup

- `void init()`  
Initialize pinModes and timers.

- `void setM1Speed(int speed)`  
Set speed and direction for motor 1. Speed should be between –400 and 400. 400 corresponds to motor current flowing from M1A to M1B. –400 corresponds to motor current flowing from M1B to M1A. 0 corresponds to full coast.

- `void setM2Speed(int speed)`  
Set speed and direction for motor 2. Speed should be between –400 and 400. 400 corresponds to motor current flowing from M2A to M2B. –400 corresponds to motor current flowing from M2B to M2A. 0 corresponds to full coast.

- `void setM3Speed(int speed)`  
Set speed and direction for motor 3. Speed should be between –400 and 400. 400 corresponds to motor current flowing from M3A to M3B. –400 corresponds to motor current flowing from M3B to M3A. 0 corresponds to full coast.

- `void setM4Speed(int speed)`  
Set speed and direction for motor 4. Speed should be between –400 and 400. 400 corresponds to motor current flowing from M4A to M4B. –400 corresponds to motor current flowing from M4B to M4A. 0 corresponds to full coast.

- `void setSpeeds(int m1Speed, int m2Speed, int m3Speed, int m4Speed)`  
Set speed and direction for motor 1, 2, 3, 4.

- `void setM1Brake(int brake)`  
Set brake for motor 1. Brake should be between 0 and 400. 0 corresponds to full coast, and 400 corresponds to full brake.

- `void setM2Brake(int brake)`  
Set brake for motor 2. Brake should be between 0 and 400. 0 corresponds to full coast, and 400 corresponds to full brake.

- `void setM3Brake(int brake)`  
Set brake for motor 3. Brake should be between 0 and 400. 0 corresponds to full coast, and 400 corresponds to full brake.

- `void setM4Brake(int brake)`  
Set brake for motor 4. Brake should be between 0 and 400. 0 corresponds to full coast, and 400 corresponds to full brake.

- `void setBrakes(int m1Brake, int m2Brake, int m3Brake, int m4Brake)`  
Set brake for motor 1, 2,3 4.

- `unsigned int getM1CurrentMilliamps()`  
Returns current reading from motor 1 in milliamps.  See the notes in the "Current readings" section below.

- `unsigned int getM2CurrentMilliamps()`  
Returns current reading from motor 2 in milliamps.  See the notes in the "Current readings" section below.

- `unsigned int getM3CurrentMilliamps()`  
Returns current reading from motor 3 in milliamps.  See the notes in the "Current readings" section below.

- `unsigned int getM4CurrentMilliamps()`  
Returns current reading from motor 4 in milliamps.  See the notes in the "Current readings" section below.

- `unsigned char getM1Fault()`  
Returns 1 if there is a fault on motor driver 1, 0 if no fault.

- `unsigned char getM2Fault()`  
Returns 1 if there is a fault on motor driver 2, 0 if no fault.

- `unsigned char getM3Fault()`  
Returns 1 if there is a fault on motor driver 3, 0 if no fault.

- `unsigned char getM4Fault()`  
Returns 1 if there is a fault on motor driver 4, 0 if no fault.

### Current Readings

The current readings returned by `getM1CurrentMilliamps`, `getM2CurrentMilliamps`, `getM3CurrentMilliamps` and
`getM4CurrentMilliamps` will be noisy and unreliable if you are using a PWM frequency below about 5&nbsp;kHz.  We expect these readings to work fine if you haven't remapped the PWM pins and you are using a board based on the ATmega168, ATmega328P, ATmega328PB, ATmega32U4, ATmega1280, or ATmega2560 since this library uses 20&nbsp;kHz hardware PWM on those boards.

On other boards, this library uses `analogWrite` to generate PWM signals, which usually means that the PWM frequency will be too low to
get reliable current measurements.  If `analogWrite` uses a frequency of 490&nbsp;Hz or more on your board, you can add a 1&nbsp;&micro;F (or larger) capacitor between each current sense line you are using and GND.  To make `getM1CurrentMilliamps` work well, you would add the capacitor between M1CS and GND.  To make `getM2CurrentMilliamps` work well, you would add the capacitor between M2CS and GND. To make `getM3CurrentMilliamps` work well, you would add the capacitor between M3CS and GND. To make `getM4CurrentMilliamps` work well, you would add the capacitor between M4CS and GND.

Version History
---------------
-   3.2.0-dualshields (2019-11-09): adds PWM with a frequency of 7.8 kHz on timer 2 for Mega for the old pins. Thanks samascaro for the contribution.
-   3.1.0-dualshields (2019-10-13): Fixes a number of problems with PWM on Mega. More details in the release notes.
-   2019-03-28 Now officially in the Arduino Library Manager
-   3.0.2-dualshields (2018-12-02): Fix default pins for motor 2 _CS4
-   3.0.1-dualshields (2018-06-14): Fix Semver naming for Arduino Library Manager
-   3.0.0.dualshields (2018-05-12): Allow PWM remapping (use analogWrite if PWM pins remapped). Follows PWM remapping changes in source library pololu/dual-vnh5019-motor-shield, possibly backwards compatable change to allow use with old versions of the Arduino IDE 
-   2.0.0.dualshields (2016-08-20): Updated library to work with the Arduino Library Manager
-   1.3.5.dualshields (2016-08-10): Add continuous integration testing
-   1.2.5.dualshields (2015-04-18): Fixed a bug that was introduced in 1.2.4.dualshields
-   1.2.4.dualshields (2015-04-18): Fixed a bug that was introduced in 1.2.3.dualshields with incorrect defualt pin for M3
-   1.2.3.dualshields (2015-02-22): Custom library for running two DualVNH5019MotorShields on a Mega (4 motors total).
-   1.2.3 (2014-03-24): Added 20 kHz PWM support for ATmega32U4. Thanks blacksound.
-   1.2.2 (2014-03-18): Add keywords.txt file. Thanks eatonphil.
-   1.2.1 (2013-01-06): Fixed a bug in setM2Speed that was introduced in 1.2.0.
-   1.2.0 (2012-12-26): Changes the behavior of the library at speed 0 so that it makes the motor coast regardless of which direction the motor is spinning.
-   1.1.0 (2011-12-15): Arduino IDE 1.0 compatibility.
-   1.0.1 (2011-11-07): Adds support for Arduinos not based on ATmega168/328.
-   1.0.0 (2011-10-28): Original release.

### Notes about timers and conflicts:
-------------------

It is now recommended to use the PWMServo library with this library if you also need to use servos and encoders. Use of the PWMServo library will avoid the majority of timer and interupt conflicts you would have encountered with the standard Servo library. 

-   Timer0 is used by the functions millis(), delay(), micros() and delayMicroseconds(),
-   Timer1 is used by the servo.h library on Arduino Uno
-   Timer5 is used by the servo library on Arduino Mega
-   the Servo library uses timers and interrupts
    -   you can’t use the pwm pins used for servo timers
    -   UNO: when you use the Servo Library you can’t use PWM on Pin 9, 10
    -   MEGA: it is a bit more difficult
        -   For the first 12 servos timer 5 will be used (losing PWM on Pins 44,45,46)
        -   for 13-24 servos timer 5 and 1 will be used (losing PWM on Pins 11,12,44,45,46)
        -   for 25-36 servos timer 5, 1 and 3 will be used (losing PWM on Pins 2,3,5,11,12,44,45,46)
        -   For 37-48 servos all 16bit timers 5,1,3 and 4 will be used (losing all PWM pins).
-   timers for PWM underwrite the function analogWrite(). Manually setting up a timer will/may stop analogWrite() from working
    -   You can obtain more control than the analogWrite function provides By manipulating the chip’s timer registers directly (note this is very advanced).
    -   The PWM outputs generated on pins 5, 6 (uno) or Pins 4, 13 (mega) will have higher-than-expected duty cycles. This is because of interactions with the millis() and delay() functions, which share the same internal timer used to generate those PWM outputs. This will be noticed mostly on low duty-cycle settings (e.g 0 - 10) and may result in a value of 0 not fully turning off the output on pins 5, 6 (Uno) or pins 4,13 (mega).
-   on the Uno Pin 11 has shared functionality PWM and MOSI. MOSI is needed for the SPI interface, so you can’t use PWM on Pin 11 and the SPI interface at the same time.
    -   on the MEGA SPI related pins are 50 (MISO), 51 (MOSI), 52 (SCK), 53 (SS) so no conflict exists
-   the tone(), notone() functions uses timer2,
-   Timer 2 has a different set of prescale values from the other timers,
-   Timer 0 and 2 are 8bit timers while timer 1, 3, 4, and 5 are 16 bit timers;
-   Timer 3,4,5 are only available on Arduino Mega boards,
-   The digitalWrite() function turns off PWM output if called on a timer pin
-   The Uno has 3 Timers and 6 PWM output pins 3, 5, 6, 9, 10, and 11
    -   timer 0 —– Pins 5, 6 (time functions like millis(), and delay() )
    -   timer 1 —– Pins 9, 10 (servo library)
    -   timer 2 —– Pins 11, 3 (tone(), notone() functions)

| Uno Timer | Timer output OCRnx | Timer bit mode | PWM pin output |     Conflicts    |
|:---------:|:------------------:|:--------------:|:--------------:|:----------------:|
|  Timer 1  |        OCR1A       |     16 bit     |        9       |   servo library  |
|  Timer 1  |        OCR1B       |     16 bit     |       10       |   servo library  |
|  Timer 2  |        OCR2A       |      8 bit     |       11       | tone(), notone(), MOSI/SPI |
|  Timer 2  |        OCR2B       |      8 bit     |        3       | tone(), notone() |

-   The Arduino Mega has 6 timers and 15 PWM outputs pins 2 to 13 and 44 to 46
    -   timer 0 —– pin 4, 13 (time functions like millis(), and delay() )
    -   timer 1 —– pin 11, 12
    -   timer 2 —– pin 9, 10 (tone(), notone() functions)
    -   timer 3 —– pin 2, 3, 5
    -   timer 4 —– pin 6, 7, 8
    -   timer 5 —– pin 44, 45, 46 (servo library)

| Mega Timer | Timer output OCRnx | Timer bit mode | PWM pin output |     Conflicts    |
|:----------:|:------------------:|:-------------:|:--------------:|:----------------:|
|   Timer 1  |        OCR1A       |     16 bit    |       11       |         -        |
|   Timer 1  |        OCR1B       |     16 bit    |       12       |         -        |
|   Timer 2  |        OCR2A       |     8 bit     |       10       | tone(), notone() |
|   Timer 2  |        OCR2B       |     8 bit     |        9       | tone(), notone() |
|   Timer 3  |        OCR3A       |     16 bit    |        5       |         -        |
|   Timer 3  |        OCR3B       |     16 bit    |        2       |         -        |
|   Timer 3  |        OCR3C       |     16 bit    |        3       |         -        |
|   Timer 4  |        OCR4A       |     16 bit    |        6       |         -        |
|   Timer 4  |        OCR4B       |     16 bit    |        7       |         -        |
|   Timer 4  |        OCR4C       |     16 bit    |        8       |         -        |
|   Timer 5  |        OCR5A       |     16 bit    |       46       | servo library    |
|   Timer 5  |        OCR5B       |     16 bit    |       45       | servo library    |
|   Timer 5  |        OCR5C       |     16 bit    |       44       | servo library    |

-   The Arduino Leonardo has 4 timers and 7 PWM outputs 
    -   timer 0 —– Pins 3, 11 (time functions like millis(), and delay() )
    -   timer 1 —– Pins 9, 10 (servo library)
    -   timer 3 —– pin 5
    -   timer 4 —– pin 6,13
-   [You can manually implement a pseudo PWM on any digital pin by repeatedly turning the pin on and off for the desired times](http://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM)
