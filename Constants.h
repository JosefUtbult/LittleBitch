
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Arduino.h"
#include <LiquidCrystal.h>
#include <Adafruit_MCP23017.h>

#define DEBUG false                            // True if you are debugging the program, allowing the Serial protocol
#define EXPRESSORAFTERTOUCH 300               // The time after an expressor has been changed that the correspondant led should be lit
#define CHANNEL 3                             // The midi chanel
#define VIBRATOMIDICONTROLL 100               // The controll controll for the vibrato
#define EXPRESSIONTHREASHOLD 2                // The threashold for the analog read to change the midi signal, decreasing the fluctiation
#define DOUBLECLICKINTERVAL 500               // The intervall between button presses that counts as a double click

#define WELCOMEMESSAGETOP     "   |Fuck off|" // The first line of the welcome message
#define WELCOMEMESSAGEBOTTOM  "   | Alfred |" // The second line of the welcome message
#define ERRECTIONTIME 10000                   // The display time for the penis
#define ERRECTIONRATE 360000                  // The chance for the penis to appear. The percente chance for it to activate is 1 / ERRECTIONTIME 
                                              // for every time calculateErrection() is called

Adafruit_MCP23017 mcp;    // The multiplexer chip used for ButtonLogic.h and LED.h
int lastMidiValue = -1;   // The last midi value to be sent

// A struct dedicated to the buttons, holding:
//    - pinOut and pinIn : The out- and input pins of the mcp used for the multiplexed buttons. Enables a button by setting the 
//                         output to LOW, making it behave like a ground, and reads the digital value from pinIn
//
//    - ledOut: The output for the buttons corresponging led on the mcp
//
//    - changed: True if the button has changed this program cycle
//
//    - state: The current state of the button. True if the button is pressed
//
//    - doubleClicked: True if the button has been activated twice within the intervall DOUBLECLICKINTERVAL, 
//                     used to signal a doubleclick
//
//    - lastOnTime: The last time the button was turned on, used to determinate if it has been doubleclicked

struct Button{  
  
  int pinOut;
  int pinIn;
  int ledOut;
  bool changed;
  bool state;
  bool doubleClicked;
  uint32_t lastOnTime;

};

// A struct dedicated to expressors, holding:
//    - pinAdress: The adress of the analog input pin on the analog multiplexer, used to choose input pin
//
//    - ledOut: The output for the expressors corresponding led, none-existing if ledOut is -1
//
//    - changed: True if the expressor has changed this program cycle
//
//    - lastValue: The last value read from the expressor
//
//    - lastUpdateTime: The last time the lastValue was updated

struct Expressor{
  
  uint8_t pinAdress;
  int ledOut;
  bool changed;
  int lastValue;
  uint32_t lastUpdateTime;

};

// Four controllbuttons

Button button[4]= { {6, 12, 0, false, false, false, 0}, 
                    {6, 13, 1, false, false, false, 0},
                    {6, 14, 2, false, false, false, 0},
                    {7, 12, 3, false, false, false, 0}
                  };

// Two page selection buttons

Button buttonUp = {7, 14, 5, false, false, 0};
Button buttonDown = {7, 13, 4, false, false, 0};

// Five expressors, where four of them have corresponding leds

Expressor expressor[5] = {
  {3, 8, false, 0, 0},
  {2, 9, false, 0, 0},
  {1, 10, false, 0, 0},
  {0, 11, false, 0, 0},
  {4, -1, false, 0, 0}
};

#endif