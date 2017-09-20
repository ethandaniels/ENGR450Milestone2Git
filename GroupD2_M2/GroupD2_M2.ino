//Aidan J. Bradley and Ethan T. Daniels
// ENGR450  ... Group D ... MILESTONE 2
// Programmed by: Aidan J. Bradley

/*
 * The idea is to have the robot drive straight until a button click, dependant on how many button clicks the robot 
 * will act in different ways.. 
 * 
 * The goal is to have the robot reach each back wall and play a tune
 */
#include "pitches.h"

//pinouts:
const int leftA =  3; //Left Motor A pin
const int leftB =  4; //Left Motor B pin
const int rightA =  6;  //Right Motor A pin
const int rightB =  7;  //Right Motor B pin
const int buzz = 12;  //pin for buzzer
const int frontButton = 13; //pin for front bumper switch
const int topButton = 11; //pin for the top bumper switch

// Variables will change:
int currentState = 0; //will be used to switch states
int numClicks = 0; //will count how many times the front bumper has been clicked
int frontBump; //variable for front bumper switch
int topBump; //variable for top button
int motorState = 0;

void setup() 
{
  // set the digital pin as output:
  pinMode(leftA, OUTPUT);      
  pinMode(leftB, OUTPUT);      
  pinMode(rightA, OUTPUT);      
  pinMode(rightB, OUTPUT);    
  pinMode(buzz, OUTPUT);
  pinMode(frontButton, INPUT);  
  pinMode(topButton, INPUT);
}

void loop()
{
  //read the top button until someone clicks it
  topBump = debounceCheck(topButton);
  if(topBump == LOW)
  {
    currentState = 1;
  }
  switch(currentState)
  {
    case 0:
    {
      state0();
      break;
    }
    case 1:
    {
      state1();
      break;
    }
    case 2:
    {
      state2();
      break;
    }
    case 3:
    {
      state3();
      break;
    }
    case 4:
    {
      state4();
      break;
    }
    case 5:
    {
      state5();
      break;
    }
    case 6:
    {
      state6();
      break;
    }
  }
}
