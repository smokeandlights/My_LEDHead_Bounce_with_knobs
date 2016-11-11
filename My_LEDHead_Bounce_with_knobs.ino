#include <SoftPWM.h>


uint8_t leds[13] = {2,3,4,5,6,7,8,9,10,11,12,A0,A1};

void setup()
{
  int KNOB1 = A2;
  int KNOB2 = A3;
  pinMode(KNOB1, INPUT);
  pinMode(KNOB2,INPUT);
    SoftPWMBegin();

  for (int i = 0; i < 13; i++)
    SoftPWMSet(leds[i], 0);

 
}

void loop()
{
 
  int DELAY = map(KNOB1,0,1023,1,500);
  int BRIGHTNESS = map(KNOB2,0,1024,1,255);

   SoftPWMSetFadeTime(ALL, (DELAY/8), DELAY);
  
  int i;

  for (i = 0; i < 12; i++)
  {
    SoftPWMSet(leds[i+1], BRIGHTNESS);
    SoftPWMSet(leds[i], 0);
    delay(DELAY);
  }
  
  delay(DELAY);
  
  for (i = 12; i > 0; i--)
  {
    SoftPWMSet(leds[i-1], BRIGHTNESS);
    SoftPWMSet(leds[i], 0);
    delay(DELAY);
  }

  delay(DELAY);

}
