// #==============================================#
// | 											  |
// |			Logic for the buttons 			  |
// |											  |
// #==============================================#


#ifndef BUTTONLOGIC_H
#define BUTTONLOGIC_H

#include <Arduino.h>
#include "Constants.h"
#include "PageRules.h"
#include "LCD.h"
#include "LED.h"

bool state;		// A temporary variable declared globaly to not force it to allocate every cycle

Button readButton(Button currentButton);
void mcpBegin();
void buttonBegin();
void readButtons();
Button readButton(Button currentButton);
void updatePage();
void clearButtonChanged();

void mcpBegin(){	// Initializes the MCP

	mcp.begin();

}


void buttonBegin(){

	mcpBegin();

	for(int i = 0; i < 4; i++ ){
		mcp.pinMode(button[i].pinOut, OUTPUT);			// Sets the pinMode for the buttons inputs and outputs on the mcp
		mcp.digitalWrite(button[i].pinOut, HIGH);

		mcp.pinMode(button[i].pinIn, INPUT);
		mcp.pullUp(button[i].pinIn, HIGH);

	}
}

void readButtons(){

	for(int i = 0; i < 4; i++ ){

		button[i] = readButton(button[i]);		// Goes through every button and page buttons and runs readButton() with it
		
	}

	buttonUp = readButton(buttonUp);
	buttonDown = readButton(buttonDown);
}

Button readButton(Button currentButton){

	mcp.digitalWrite(currentButton.pinOut, LOW);		// Writes the output pin for the button to LOW, allowing it to behave like a ground pin
	delayMicroseconds(5);								// Lets the mcp work its magic

	state = !mcp.digitalRead(currentButton.pinIn);		// Reads the input from the buttons input pin and stores it at the temporary variable state
	mcp.digitalWrite(currentButton.pinOut, HIGH);		// Sets the output pin for the button to HIGH, disable the ground-behavior

	if(state != currentButton.state){					// If the state for the button has changed, sets changed to true which is reset at the
		currentButton.changed = true;					// end of the cycle, and updates the state
		currentButton.state = state;

		if(currentButton.state){
			if(millis() - currentButton.lastOnTime < DOUBLECLICKINTERVAL){		// If the button has been activated twice in the intervall DOUBLECLICKINTERVAL,
				currentButton.doubleClicked = true;								// activates doubleclicked which is reset at the end of te cycle
			}

			currentButton.lastOnTime = millis();		// Updates the last red value
		}
	}


	return currentButton;

}

void updatePage(){

	if(buttonUp.changed && buttonUp.state){
		currentPage = (currentPage + 1) % 10;		// If the button up has been pressed, increments the page and updates the leds and the lcd
		updateLeds();
		updateLcd();
	}
	else if(buttonDown.changed && buttonDown.state){
		currentPage = currentPage - 1;

		while(currentPage < 0){						// If the button down has been pressed, decrements the page and updates the leds and the lcd
			currentPage += 10;
		}
		updateLeds();
		updateLcd();
	}
}


void clearButtonChanged(){
	for(int i = 0; i < 4; i++ ){
		button[i].changed = false;
		button[i].doubleClicked = false;		// Goes through every button ands sets changed and doubleCliced to false,
	}											// making sure it's only true the cycle the buttons has been updated

	buttonUp.changed = false;
	buttonUp.doubleClicked = false;
	buttonDown.changed = false;
	buttonDown.doubleClicked = false;
}
#endif