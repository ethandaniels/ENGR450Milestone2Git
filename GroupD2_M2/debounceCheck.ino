int lastState;

boolean debounceCheck(int pin)
{
  int currState = digitalRead(pin);

  if(currState != lastState)
  {
    if(lastState == LOW)
    {
      return true;
    }
  }
  lastState = currState;
  return false;
}


