//Motor Test Example
#define MEGA
#include <DualVNH5019MotorShieldMod3.h>
//#include <Encoder.h>

//set up the class dot names for the libraries and
// configure library pins
DualVNH5019MotorShieldMod3 md;//Use default pins

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  Serial.println("Starting 2X Dual VNH5019 Motor Shield - Mod3 LIB");
  //start the motor shields and motor pins
  md.init();

//stop if fault methods
void stopIfFault()
{
  if (getM1Fault())
  {
    Serial.println("M1 fault");
    while(1);
  }
  if (getM2Fault())
  {
    Serial.println("M2 fault");
    while(1);
  }
    if (getM3Fault())
  {
    Serial.println("M3 fault");
    while(1);
  }
    if (getM4Fault())
  {
    Serial.println("M4 fault");
    while(1);
  }
}

}

void loop()
{
  // loops endlessly; main loop goes here
 // the following code is a simple example:
 //motors 1-2
for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
  }
  
  for (int i = 400; i >= -400; i--)
  {
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
  }

  for (int i = 0; i <= 400; i++)
  {
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
  }
  
  for (int i = 400; i >= -400; i--)
  {
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
   }
//Motor 3-4
for (int i = 0; i <= 400; i++)
  {
    md.setM3Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M3 current: ");
      Serial.println(md.getM3CurrentMilliamps());
    }
    delay(2);
  }
  
  for (int i = 400; i >= -400; i--)
  {
    md.setM3Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M3 current: ");
      Serial.println(md.getM3CurrentMilliamps());
    }
    delay(2);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    md.setM3Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M3 current: ");
      Serial.println(md.getM3CurrentMilliamps());
    }
    delay(2);
  }

  for (int i = 0; i <= 400; i++)
  {
    md.setM4Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M4 current: ");
      Serial.println(md.getM4CurrentMilliamps());
    }
    delay(2);
  }
  
  for (int i = 400; i >= -400; i--)
  {
    md.setM4Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M4 current: ");
      Serial.println(md.getM4CurrentMilliamps());
    }
    delay(2);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    md.setM4Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      Serial.print("M4 current: ");
      Serial.println(md.getM4CurrentMilliamps());
    }
    delay(2);
  }
}
