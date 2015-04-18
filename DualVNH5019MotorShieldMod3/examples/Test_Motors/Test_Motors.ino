//Motor Test Example
#define MEGA
#include <DualVNH5019MotorShieldMod3.h>
//#include <Encoder.h>

// configure library with pins as remapped for single-channel operation
// this lets the single motor be controlled as if it were "motor 1"
DualVNH5019MotorShieldMod3 md;//Use default pins


void stopIfFault()
{
  if (md.getM1Fault())
  {
    Serial.println("M1 fault");
    while(1);
  }
  if (md.getM2Fault())
  {
    Serial.println("M2 fault");
    while(1);
  }
    if (md.getM3Fault())
  {
    Serial.println("M3 fault");
    while(1);
  }
    if (md.getM4Fault())
  {
    Serial.println("M4 fault");
    while(1);
  }
}

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
