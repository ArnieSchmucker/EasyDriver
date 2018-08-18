#include "EasyDriver.h"

EasyDriver::EasyDriver(int stp, int dir, int MS1, int MS2, int en) {
  _stp = stp;
  _dir = dir;
  _MS1 = MS1;
  _MS2 = MS2;
  _en = en;
}

void EasyDriver::begin()
{
  pinMode(_stp, OUTPUT);
  pinMode(_dir, OUTPUT);
  pinMode(_MS1, OUTPUT);
  pinMode(_MS2, OUTPUT);
  pinMode(_en, OUTPUT);
}

//Reset Easy Driver pins to default states
void EasyDriver::resetEDPins()
{
  setSTPLow();
  setDIRLow();
  setMS1Low();
  setMS2Low();
  setENHigh();
}

void EasyDriver::setENLow()
{
  digitalWrite(_en, LOW);
}

void EasyDriver::setENHigh()
{
  digitalWrite(_en, HIGH);
}

void EasyDriver::setDIRLow()
{
  digitalWrite(_dir, LOW);
}

void EasyDriver::setDIRHigh()
{
  digitalWrite(_dir, HIGH);
}

void EasyDriver::setSTPLow()
{
  digitalWrite(_stp, LOW);
}

void EasyDriver::setSTPHigh()
{
  digitalWrite(_stp, HIGH);
}

void EasyDriver::setMS1Low()
{
  digitalWrite(_MS1, LOW);
}

void EasyDriver::setMS1High()
{
  digitalWrite(_MS1, HIGH);
}

void EasyDriver::setMS2Low()
{
  digitalWrite(_MS2, LOW);
}

void EasyDriver::setMS2High()
{
  digitalWrite(_MS2, HIGH);
}


//Default microstep mode function
void EasyDriver::StepForwardDefault()
{
  Serial.println("Moving forward at default step mode.");
  //Pull direction pin low to move "forward"
  setDIRLow();
  for(int x= 1; x<1000; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    //Trigger one step forward
    setSTPHigh();
    delay(1);
    //Pull step pin low so it can be triggered again
    setSTPLow();
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}

//Reverse default microstep mode function
void EasyDriver::ReverseStepDefault()
{
  Serial.println("Moving in reverse at default step mode.");
  //Pull direction pin high to move in "reverse"
  setDIRHigh();
  for(int x= 1; x<1000; x++)  //Loop the stepping enough times for motion to be visible
  {
    //Trigger one step
    setSTPHigh();
    delay(1);
    //Pull step pin low so it can be triggered again
    setSTPLow();
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}

// 1/8th microstep foward mode function
void EasyDriver::SmallStepMode()
{
  Serial.println("Stepping at 1/8th microstep mode.");
  //Pull direction pin low to move "forward"
  setDIRLow();
  //Pull MS1, and MS2 high to set logic to 1/8th microstep resolution
  setMS1High();
  setMS2High();
  for(int x= 1; x<1000; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    //Trigger one step forward
    setSTPHigh();
    delay(1);
    //Pull step pin low so it can be triggered again
    setSTPLow();
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}

//Forward/reverse stepping function
void EasyDriver::ForwardBackwardStep()
{
  int state;
  Serial.println("Alternate between stepping forward and reverse.");
  for(int x= 1; x<5; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    //Read direction pin state and change it
    state=digitalRead(_dir);
    if(state == HIGH)
    {
      setDIRLow();
    }
    else if(state ==LOW)
    {
      setDIRHigh();
    }

    for(int y=1; y<1000; y++)
    {
      //Trigger one step
      setSTPHigh();
      delay(1);
      //Pull step pin low so it can be triggered again
      setSTPLow();
      delay(1);
    }
  }
  Serial.println("Enter new option:");
  Serial.println();
}


