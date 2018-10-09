#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include "ButtonLogic.h"
#include "ExpressorLogic.h"
#include "PageRules.h"
#include "Constants.h"
#include "MidiLogic.h"

void ledBegin();
void writeLeds();
void updateLeds();

void ledBegin(){			// Initializes the leds

	for(int i = 0; i < 4; i++ ){
		mcp.pinMode(button[i].ledOut, OUTPUT);			// Goes through the buttons and sets the outputLeds pinMode the output
		mcp.digitalWrite(button[i].ledOut, LOW);
	}

	mcp.pinMode(buttonUp.ledOut, OUTPUT);			// Goes through the up and down buttons and sets the outputLeds pinMode to output
	mcp.digitalWrite(buttonUp.ledOut, LOW);

	mcp.pinMode(buttonDown.ledOut, OUTPUT);
	mcp.digitalWrite(buttonDown.ledOut, LOW);

	for(int i = 0; i < 5; i++ ){									// Goes through every expressor and checks if it has a defined outputLed
		if(expressor[i].ledOut >= 0){
			mcp.pinMode(expressor[i].ledOut, OUTPUT);				// Sets the outputLed of the expressor to output
			mcp.digitalWrite(expressor[i].ledOut, LOW);
		}
	}
}

void writeLeds(){

	for(int i = 0; i < 4; i++ ){		// Goes through the buttons and check if there status has changed
		if(button[i].changed){
			if(PAGERULES[currentPage].bankRules[i].flip){
				mcp.digitalWrite(button[i].ledOut, midiValue[i + (currentPage * 4)] > 0);			// If the rule for the current bank states that the button should be a flip button
			}																						// it sets the ouptuLed to the last MidiValue it sent out, HIGH every second click 
																									// and LOW every other
			else{

				mcp.digitalWrite(button[i].ledOut, button[i].state);								// If the rule for the current bank dosn't state that the button should be flip, it
			}																						// sets the outputLed to the same value as the buttons state
		}
	}

	if(buttonUp.changed){
		mcp.digitalWrite(buttonUp.ledOut, buttonUp.state);							// sets the outputLed to the same value as the buttonUp and Downs state			
	}

	if(buttonDown.changed){
		mcp.digitalWrite(buttonDown.ledOut, buttonDown.state);
	}

	for(int i = 0; i < 5; i++ ){			// Goes through the expressors

		if(expressor[i].changed){
			mcp.digitalWrite(expressor[i].ledOut, HIGH);							// Turns the led on if the expressor changed and turns it of when there hasn't 
																					// ocurred a change for the intervall EXPRESSORAFTERTOUCH
		}

		else if(expressor[i].ledOut > 0 && millis() - expressor[i].lastUpdateTime > EXPRESSORAFTERTOUCH){
			mcp.digitalWrite(expressor[i].ledOut, LOW);
		}
	}

}

void updateLeds(){				// Update the leds to the corresponding pages values after a page shift

	for(int i = 0; i < 4; i++ ){
		mcp.digitalWrite(button[i].ledOut, PAGERULES[currentPage].bankRules[i].flip ? (midiValue[i + (currentPage * 4)] > 0) : 0);
	}

}

#endif