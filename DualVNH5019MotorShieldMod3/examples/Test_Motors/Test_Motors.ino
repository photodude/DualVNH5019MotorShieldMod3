//Motor Test Example
//#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#include <DualVNH5019MotorShieldMod3.h>
//#include <Encoder.h>

// configure library with pins as remapped for single-channel operation
// this lets the single motor be controlled as if it were "motor 1"
DualVNH5019MotorShieldMod3 md;//Use default pins

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  md.init();

}

void loop()
{
// loops endlessly; main loop goes here

// the following code is a simple example:
//
md.setM1Speed(400); // single-channel motor full-speed "forward"

delay(2000); // wait for 2 seconds

md.setM1Speed(0); // single-channel motor stop (coast)

delay(500); // wait for 0.5 s

md.setM2Speed(400); // single-channel motor full-speed "reverse"

delay(2000); // wait for 2 seconds

md.setM2Speed(0); // single-channel motor stop (coast)

delay(500); // wait for 0.5 s

md.setM3Speed(400); // single-channel motor full-speed "forward"

delay(2000); // wait for 2 seconds

md.setM3Speed(0); // single-channel motor stop (coast)

delay(500); // wait for 0.5 s

md.setM4Speed(400); // single-channel motor full-speed "forward"

delay(2000); // wait for 2 seconds

md.setM4Speed(0); // single-channel motor stop (coast)

delay(500); // wait for 0.5 s

md.setM1Speed(0); // single-channel motor stop (coast)
md.setM2Speed(0); // single-channel motor stop (coast)
md.setM3Speed(0); // single-channel motor stop (coast)
md.setM4Speed(0); // single-channel motor stop (coast)

// the following code is a simple example:
//
md.setM1Speed(-400); // single-channel motor full-speed "forward"

delay(2000); // wait for 2 seconds

md.setM1Speed(0); // single-channel motor stop (coast)

delay(500); // wait for 0.5 s

md.setM2Speed(-400); // single-channel motor full-speed "reverse"

delay(2000); // wait for 2 seconds

md.setM2Speed(0); // single-channel motor stop (coast)

delay(500); // wait for 0.5 s

md.setM3Speed(-400); // single-channel motor full-speed "forward"

delay(2000); // wait for 2 seconds

md.setM3Speed(0); // single-channel motor stop (coast)

delay(500); // wait for 0.5 s

md.setM4Speed(-400); // single-channel motor full-speed "forward"

delay(2000); // wait for 2 seconds

md.setM4Speed(0); // single-channel motor stop (coast)

delay(500); // wait for 0.5 s

md.setM1Speed(0); // single-channel motor stop (coast)
md.setM2Speed(0); // single-channel motor stop (coast)
md.setM3Speed(0); // single-channel motor stop (coast)
md.setM4Speed(0); // single-channel motor stop (coast)

}
