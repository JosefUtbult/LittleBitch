#ifndef MIDI_LOGIC_H
#define MIDI_LOGIC_H

#include <frequencyToNote.h>
#include <MIDIUSB.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>

#include "PageRules.h"
#include "Constants.h"
#include "ButtonLogic.h"
#include "ExpressorLogic.h"
#include "LCD.h"

int midiValue[40];				// The values last sent for every banks button of every page
int midiValueHolder = 0;		// A temperal variable to hold the old midi value
int midiControll;				// A temperal variable to hold the controllvalue of the current bank

void initMidi(){
	for(int i = 0; i < 20; i++ ){		// Zeros out all the midi values
		midiValue[i] = 0;
	}
}

void controlChange(byte control, byte lastValue) {
   
   midiEventPacket_t event = {0x0B, 0xB1 | CHANNEL, control, lastValue};		// Creates a midi packet and sends it
   MidiUSB.sendMIDI(event);
   MidiUSB.flush();

	if(DEBUG){
		Serial.println("Controll change\t||\tcontroll: " + String(control) + "\t||\tvalue: " + String(lastValue));
	}
}

void updateMidi(){
	for(int i = 0; i < 4; i++ ){	// Goes through every button

		if(button[i].changed && button[i].state){		// If the buttons state has changed and the state is up

			if(PAGERULES[currentPage].bankRules[i].flip){	// If the bankrule for the current button is set to flip it invert the old midi value and sets the 
															// midicontroll to the primary midi controll for the butons bank

				midiValue[i + (currentPage * 4)] = midiValue[i + (currentPage * 4)] > 0 ? 0 : 127;
				midiControll = PAGERULES[currentPage].bankRules[i].primaryMidiControll;

			}

			else{

				midiValue[i + (currentPage * 4)] = 127;		// If the bankrule for the current button is not set to flip it only sends the value 127 every time

				if(PAGERULES[currentPage].bankRules[i].doubleClick && PAGERULES[currentPage].bankRules[i].secondaryMidiControll >= 0 && button[i].doubleClicked){

					midiControll = PAGERULES[currentPage].bankRules[i].secondaryMidiControll;		// If the current button was doubleclicked it sends the secondary midi controll signal.
																									// Otherwise it sends the primary one

				}
				else{
					midiControll = PAGERULES[currentPage].bankRules[i].primaryMidiControll;
				}

			}

			controlChange(midiControll, midiValue[i + (currentPage * 4)]);			// Sends the defined value to the midi controll
			lastMidiValue = midiControll;	// Sets the last sent midicontroll to to the new one

			updateLcd();	// Updates the lcd to make it display the last midicontroll sent

		}
	}

	for(int i = 0; i < 5; i++ ){
		if(expressor[i].changed){
			midiValueHolder = lastMidiValue;	// Stores the last midi value
			if(i < 4){
				controlChange(PAGERULES[currentPage].bankRules[i].expressionControll, expressor[i].lastValue);		// Goes through every expressor except the last vibrato expressor
				lastMidiValue = PAGERULES[currentPage].bankRules[i].expressionControll;								// Sends the midi value and updates the last midi value
			}
			else{
				controlChange(VIBRATOMIDICONTROLL, expressor[i].lastValue);		// Sends the midi value defined by VIBRATOMIDICONTROLL and the expressorvalue current value
				lastMidiValue = VIBRATOMIDICONTROLL;							// Sends the midi value and updates the last midi value
			}
			if(midiValueHolder != lastMidiValue){ // Update the lcd if there was a new value sent
				updateLcd();
			}
		}
	}


}

#endif