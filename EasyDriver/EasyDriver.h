#ifndef EasyDriver_h
#define EasyDriver_h

#include "Arduino.h"

class EasyDriver
{
  public:
  EasyDriver(int std, int dir, int MS1, int MS2, int en);
  void begin();
  void resetEDPins();
  void setENLow();
  void setENHigh();
  void setDIRLow();
  void setDIRHigh();
  void setSTPLow();
  void setSTPHigh();
  void setMS1Low();
  void setMS1High();
  void setMS2Low();
  void setMS2High();
  void StepForwardDefault();
  void ReverseStepDefault();
  void SmallStepMode();
  void ForwardBackwardStep();
  private:
  int _stp;
  int _dir;
  int _MS1;
  int _MS2;
  int _en;
  
};

#endif
