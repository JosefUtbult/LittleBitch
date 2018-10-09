#ifndef LCD_h
#define LCD_h

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Constants.h"
#include "PageRules.h"

byte line0[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b11111     // The bytes for displaying the lines on the LCD
};

byte line1[8] = {
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000
};

byte line2[8] = {
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000
};

byte line3[8] = {
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000
};

byte penis0[8] = {
  0b00000,
  0b10000,
  0b01100,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000     // The bytes for displaying the penis on the LCD
};

byte penis1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b01111,
  0b11000
};

byte penis2[8] = {
  0b00000,
  0b00000,
  0b01110,
  0b10011,
  0b00001,
  0b01110,
  0b10001,
  0b00001
};

byte penis3[8] = {
  0b10000,
  0b10000,
  0b01000,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte penis4[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte penis5[8] = {
  0b00001,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

String buffer = "";                         // A output-buffer used as a temporal holder
uint32_t lastCalculatedTime = 0;            // Last time the calculation if the penis should be displayed accured, to make sure it dosn't update more the once every second
uint32_t lastErrection = 0;                 // Last time the errection began to display, for it to know when it should be removed
int penisPosition = 0;                      // The x position offsett of the penis on the LCD
bool errect = false;                        // Wheater the penis is displayed at the moment ot not


LiquidCrystal lcd(15, 14, 16, 10, 8, 9);    // The LCD named lcd

void writeLcd(String upper, String lower);
void generateWaves(int nr, String upper, String lower);
String mergeStrings(String upper, String lower);
void clearLcd();
void generatePenis(int xOffset);

void lcdBegin(){                            // Begins the lcd, clears it


  lcd.begin(16, 2);
	clearLcd();

	lcd.createChar(0, line0);                 // Loads the line bytes and renderes the welcome message
	lcd.createChar(1, line1);
	lcd.createChar(2, line2);
	lcd.createChar(3, line3);

	writeLcd(WELCOMEMESSAGETOP, WELCOMEMESSAGEBOTTOM);
	
	for(int i = 0; i < 16; i++ ){
		generateWaves(i % 8, WELCOMEMESSAGETOP, WELCOMEMESSAGEBOTTOM);
		delay(200);
	}

	clearLcd();

  lcd.createChar(0, penis0);
  lcd.createChar(1, penis1);                // Loads the penis bytes
  lcd.createChar(2, penis2);
  lcd.createChar(3, penis3);
  lcd.createChar(4, penis4);
  lcd.createChar(5, penis5);

  lastCalculatedTime = millis();

}

void writeLcd(String upper, String lower){    // Writes the lcd with upper on the first line and lower on the second
	lcd.setCursor(0, 0);
	lcd.print(upper);        

	lcd.setCursor(0, 1);
	lcd.print(lower);
}

void generateWaves(int nr, String upper, String lower){   // Generates the lines on the welcome message
	String output = upper;

	for(int row = 0; row < 2; row++ ){

		for(int i = 0; i < 4; i++ ){
			lcd.setCursor(i, row);
			lcd.write(byte((i + nr) % 4));                      // Writes the line with the offset i + nr

			lcd.setCursor(15 - i, row);                         // Mirrors the lines
			lcd.write(byte((i + nr) % 4));	
		}

	}
}

void updateLcd(){
  
  buffer = String(lastMidiValue, HEX);                    // Parses the lastMidiValue to an uppercase hex value with two digits
  buffer.toUpperCase();

  if(lastMidiValue < 0xF){
    buffer = "0" + buffer;
  }

  clearLcd();
  writeLcd("   Page: " + PAGERULES[currentPage].title, "   Midi: " + (lastMidiValue >= 0 ? "0x" + buffer : "-"));     // Writes the current page and the lastMidiValue 
                                                                                                                      // if there has been any, otherwise only prints a line
  if(errect){
    generatePenis(penisPosition);         // Writes the penis if errect is true
  }
}

void clearLcd(){    // Clear the lcd
	lcd.clear();
}


void generatePenis(int xOffset){

  for(int posY = 0; posY < 2; posY++ ){
    for(int posX = 0; posX < 3; posX++ ){           // Displays the penis bytes at the corresponding position with an x offcet
      lcd.setCursor(posX + xOffset, posY);
      lcd.write(byte((posY * 3) + posX));

    }
  }

}

void calculateErrection(){

  if(!errect && millis() - lastCalculatedTime > 1000){      // Runs the randomized function every one second, and checks if it should generate the penis
    lastCalculatedTime = millis();
    if(random() % ERRECTIONRATE == 0){
      errect = true;
      penisPosition = random() % 2 == 0 ? 0 : 13;           // Randomizes the penis position between being on the left or the right side of the menu
      lastErrection = millis();
      updateLcd();

    }
  }
  else if(errect && millis() - lastErrection > ERRECTIONTIME){    // Turns of the errection after ERRECTIONTIME
    errect = false;
    updateLcd();
  }
}



#endif