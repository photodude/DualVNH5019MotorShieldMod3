#pragma once

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || \
    defined(__AVR_ATmega328PB__) || defined (__AVR_ATmega32U4__) || \
    defined(__AVR_ATmega16U4__) || defined(__AVR_ATmega1280__) || \
    defined(__AVR_ATmega2560__)
  // Timers generally available for all boards.
  #define DUALVNH5019MOTORSHIELD_TIMER1_AVAILABLE
#endif

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  // Additional timers for an Arduino Mega.
  #define DUALVNH5019MOTORSHIELD_TIMER3_AVAILABLE
  #define DUALVNH5019MOTORSHIELD_TIMER4_AVAILABLE
  #define DUALVNH5019MOTORSHIELD_TIMER5_AVAILABLE
#endif

//#if !defined(__AVR_ATmega1280__) || !defined(__AVR_ATmega2560__)
//  #error "This library only supports Arduino Mega boards."
//#endif

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class DualVNH5019MotorShieldMod3
{
  public:
    // CONSTRUCTORS
    DualVNH5019MotorShieldMod3();

    // Default pin selection.
    DualVNH5019MotorShieldMod3(unsigned char INA1,
                               unsigned char INB1,
                               unsigned char EN1DIAG1,
                               unsigned char CS1,
                               unsigned char INA2,
                               unsigned char INB2,
                               unsigned char EN2DIAG2,
                               unsigned char CS2,
                               unsigned char INA3,
                               unsigned char INB3,
                               unsigned char EN3DIAG3,
                               unsigned char CS3,
                               unsigned char INA4,
                               unsigned char INB4,
                               unsigned char EN4DIAG4,
                               unsigned char CS4);

    // User-defined pin selection. 
    DualVNH5019MotorShieldMod3(unsigned char INA1,
                               unsigned char INB1,
                               unsigned char EN1DIAG1,
                               unsigned char CS1,
                               unsigned char INA2,
                               unsigned char INB2,
                               unsigned char EN2DIAG2,
                               unsigned char CS2,
                               unsigned char INA3,
                               unsigned char INB3,
                               unsigned char EN3DIAG3,
                               unsigned char CS3,
                               unsigned char INA4,
                               unsigned char INB4,
                               unsigned char EN4DIAG4,
                               unsigned char CS4,
                               unsigned char PWM1,
                               unsigned char PWM2,
                               unsigned char PWM3,
                               unsigned char PWM4);

    // User-defined pin selection for only remapped motor shield 2.
    DualVNH5019MotorShieldMod3(unsigned char INA3,
                               unsigned char INB3,
                               unsigned char EN3DIAG3,
                               unsigned char CS3,
                               unsigned char PWM3,
                               unsigned char INA4,
                               unsigned char INB4,
                               unsigned char EN4DIAG4,
                               unsigned char CS4,
                               unsigned char PWM4);
   
    // PUBLIC METHODS
    void init(); // Initialize TIMERS, set the PWM to 20kHZ.

    void setM1Speed(int speed); // Set speed for M1.

    void setM2Speed(int speed); // Set speed for M2.

    void setM3Speed(int speed); // Set speed for M3.

    void setM4Speed(int speed); // Set speed for M4.

    void setSpeeds(int m1Speed,
                   int m2Speed,
                   int m3Speed,
                   int m4Speed); // Set speed for M1, M2, M3 and M4.

    void setM1Brake(int brake); // Brake M1.

    void setM2Brake(int brake); // Brake M2.

    void setM3Brake(int brake); // Brake M3.

    void setM4Brake(int brake); // Brake M4.

    void setBrakes(int m1Brake,
                   int m2Brake,
                   int m3Brake,
                   int m4Brake); // Brake M1, M2, M3 and M4.

    unsigned int getM1CurrentMilliamps(); // Get current reading for M1.

    unsigned int getM2CurrentMilliamps(); // Get current reading for M2.

    unsigned int getM3CurrentMilliamps(); // Get current reading for M3.

    unsigned int getM4CurrentMilliamps(); // Get current reading for M4.

    unsigned char getM1Fault(); // Get fault reading from M1.

    unsigned char getM2Fault(); // Get fault reading from M2.

    unsigned char getM3Fault(); // Get fault reading from M3.

    unsigned char getM4Fault(); // Get fault reading from M4.

  private:
    unsigned char _INA1;
    unsigned char _INB1;
    unsigned char _PWM1;
    #if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || \
        defined(__AVR_ATmega328PB__) || defined (__AVR_ATmega32U4__) || \
        defined(__AVR_ATmega16U4__)
        // Code in here will only be compiled if an Arduino Uno (or older), or Arduino Leonardo is used.
        static const unsigned char _PWM1_TIMER1_PIN = 9;
    #endif
    #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        // Code in here will only be compiled if an Arduino Mega is used.
        static const unsigned char _PWM1_TIMER1_PIN = 11;
    #endif
    unsigned char _EN1DIAG1;
    unsigned char _CS1;
    unsigned char _INA2;
    unsigned char _INB2;
    unsigned char _PWM2;
    #if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || \
        defined(__AVR_ATmega328PB__) || defined (__AVR_ATmega32U4__) || \
        defined(__AVR_ATmega16U4__)
        // Code in here will only be compiled if an Arduino Uno (or older), or Arduino Leonardo is used.
        static const unsigned char _PWM2_TIMER1_PIN = 10;
    #endif
    #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        // Code in here will only be compiled if an Arduino Mega is used.
        static const unsigned char _PWM2_TIMER1_PIN = 12;
    #endif
    unsigned char _EN2DIAG2;
    unsigned char _CS2;
    unsigned char _INA3;
    unsigned char _INB3;
    unsigned char _PWM3;
    #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        // Code in here will only be compiled if an Arduino Mega is used.
        static const unsigned char _PWM3_TIMER5_PIN = 45;
    #endif
    unsigned char _EN3DIAG3;
    unsigned char _CS3;
    unsigned char _INA4;
    unsigned char _INB4;
    unsigned char _PWM4;
    #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        // Code in here will only be compiled if an Arduino Mega is used.
        static const unsigned char _PWM5_TIMER5_PIN = 46;
    #endif
    unsigned char _EN4DIAG4;
    unsigned char _CS4;
};
