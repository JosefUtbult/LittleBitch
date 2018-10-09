#ifndef EXPRESSORLOGIC_H
#define EXPRESSORLOGIC_H


const int EXPRESSORADRESSPINS[3] = {7, 6, 5};			// The adresspins for the analog multiplexer

int readExpressor(Expressor currentExpressor);

void expressorBegin(){

	pinMode(A0, INPUT);									// Sets A0 to input and the adresspins to output

	for(int i = 0; i < 3; i++ ){
		pinMode(EXPRESSORADRESSPINS[i], OUTPUT);
		digitalWrite(EXPRESSORADRESSPINS[i], LOW);
	}

	for(int i = 0; i < 5; i++ ){
		expressor[i].lastValue = readExpressor(expressor[i]);
	}

}

void readExpressors(){

	int currentValue;

	for(int i = 0; i < 5; i++ ){		// Goes through the expressors
		
		currentValue = readExpressor(expressor[i]);		// Stores the read value to a temperal variable

		if(abs(currentValue - expressor[i].lastValue) > EXPRESSIONTHREASHOLD){		// Check if the difference between the new and the old value is more then the threashold EXPRESSIONTHREASHOLD

			expressor[i].changed = true;
			expressor[i].lastUpdateTime = millis();				// Sets changed to true, update the last time the value changed and sets the stored value to the new one

			expressor[i].lastValue = currentValue;

		}

	}

}

int readExpressor(Expressor currentExpressor){

	for(int j = 0; j < 3; j++ ){
		digitalWrite(EXPRESSORADRESSPINS[j], bitRead(currentExpressor.pinAdress, j));		// Writes the binary values to the adresspins acording to the binary representation of the 
																							// integer pinAdress to define what inputPin that A0 shall read from

	delay(1);

	return map(analogRead(A0), 0, 1023, 0, 127);			// Reads the analog value from the adressed inpurPin  and maps it to a standard midi scale

}

void clearExpressorChanged(){
	for(int i = 0; i < 5; i++ ){
		expressor[i].changed = false;					// Goes through every expressor and sets changed to false
	}
}


#endif