#include "Constants.h"
#include "LCD.h"
#include "PageRules.h"
#include "ButtonLogic.h"
#include "LED.h"
#include "ExpressorLogic.h"
#include "MidiLogic.h"


int tempCheck(Button button, int press);

void setup()
{

	if(DEBUG){
		delay(2000);	// Wait for the program to exicute
	}
	
	buttonBegin();
	ledBegin();			// Run all the begin functions
	lcdBegin();
	expressorBegin();

	randomSeed(analogRead(A0));		// Set the random seed, for the penis calculations

	updateLcd();	// Write the begining screen to the LCD
}

void loop(){

	readButtons();	
	readExpressors();	// Reads all the input values

	updatePage();
	updateMidi();		// Updates the page and sends the midi if changed
	calculateErrection();	// Renderes the penis if it excists 
	
	writeLeds();		// Writes the leds to there correspondant buttons and expressors

	clearButtonChanged();		// Clears the changed tag, for it only to be active when the read functions has set it to it
	clearExpressorChanged();
}

