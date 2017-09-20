//This tab will declare movement for the robot..

//have the robot stop
void state0()
{
  platformStop();
}

//move to EAST wall from starting square
void state1()
{
  frontBump = debounceCheck(frontButton);
  if(frontBump == HIGH)
  {
     platformForward();
  }
  if(frontBump == LOW)
  {
    platformBackward();
    delay(500);
    platformSpinLeft();
    delay(400);
    
    currentState = 2;
  }
}
//turn to left and drive twoard the FIRST GOAL wall (NORTH)
void state2()
{
  frontBump = debounceCheck(frontButton);
  if(frontBump == HIGH)
  { 
    platformForward();
  }
  if(frontBump == LOW)
  {
    tone(buzz,NOTE_B7,300);

    platformBackward();
    delay(500);
    platformSpinLeft();
    delay(850);
    
    currentState = 3;
  }
  
}
//drive straight until the SOUTH starting wall
void state3()
{
  frontBump = debounceCheck(frontButton);
  if(frontBump == HIGH)
  { 
    platformForward();
  }
  if(frontBump == LOW)
  {
    platformBackward();
    delay(500);
    platformSpinRight();
    delay(400);
    
    currentState = 4;
  }
}
//Drive straight until hitting WEST wall
void state4()
{
  frontBump = debounceCheck(frontButton);
  if(frontBump == HIGH)
  { 
    platformForward();
  }
  if(frontBump == LOW)
  {
    platformBackward();
    delay(500);
    platformSpinRight();
    delay(400);
    
    currentState = 5;
  }
}
//Drive straight until hitting WEST wall
void state5()
{
  frontBump = debounceCheck(frontButton);
  if(frontBump == HIGH)
  { 
    platformForward();
  }
  if(frontBump == LOW)
  {
    tone(buzz,NOTE_C7,300);
    tone(buzz,NOTE_D4,300);
    
    platformBackward();
    delay(500);
    platformSpinRight();
    delay(800);
    
    currentState = 6;
  }
}
//Drive staright until hitting SOUTH wall again
void state6()
{
  frontBump = debounceCheck(frontButton);
  if(frontBump == HIGH)
  { 
    platformForward();
  }
  if(frontBump == LOW)
  {
    
    platformBackward();
    delay(300);
    platformSpinLeft();
    delay(450);
    platformForward();
    delay(400);
    platformStop();
    delay(200);
    
    currentState = 0;
    
    int melody[] = {
      NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
    };

     // note durations: 4 = quarter note, 8 = eighth note, etc.:
     int noteDurations[] = {
      4, 8, 8, 4, 4, 4, 4, 4
     };
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzz, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzz);
    }
  }
}


