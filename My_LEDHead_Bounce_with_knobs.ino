#include <SoftPWM.h>

//#define DELAY 50
uint8_t leds[13] = {2,3,4,5,6,7,8,9,10,11,12,A0,A1};

void setup()
{
  SoftPWMBegin();

  for (int i = 0; i < 13; i++)
    SoftPWMSet(leds[i], 0);

  
}

void loop()
{
  int KNOB1 = analogRead(A2);
  int KNOB2 = analogRead(A3);
  int DELAY = map(KNOB1, 0, 1024, 30, 200);
  int DELAY2 = map(KNOB1, 0, 1024, 30, 400);
  int Brightness = map(KNOB2, 0, 1024,1,255);
  int fadeUP = map(KNOB1,0,1024,10, 100);
  int fadeDN = map(KNOB1, 0,1024,75,800);
  SoftPWMSetFadeTime(ALL, fadeUP, fadeDN);
  int i;

  for (i = 0; i < 12; i++)
  {
    SoftPWMSet(leds[i+1], Brightness);
    SoftPWMSet(leds[i], 0);
    delay(DELAY);
  }
  
  delay(DELAY2);
  
  for (i = 12; i > 0; i--)
  {
    SoftPWMSet(leds[i-1], Brightness);
    SoftPWMSet(leds[i], 0);
    delay(DELAY);
  }

  delay(DELAY2);

}
