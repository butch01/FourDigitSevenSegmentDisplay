/*
 * FourDigitSevenSegmentDisplay.h
 *
 *  Created on: 23.05.2018
 *      Author: butch
 */

#ifndef FOURDIGITSEVENSEGMENTDISPLAY_H_
#define FOURDIGITSEVENSEGMENTDISPLAY_H_

#include "ShiftRegisterFactory.h"

class FourDigitSevenSegmentDisplay {
public:
	FourDigitSevenSegmentDisplay(ShiftRegisterFactory &shiftRegisterPointer, char regA, char regAPin, char regB, char regBPin, char regC, char regCPin, char regD, char regDPin, char regE, char regEPin, char regF, char regFPin, char regG, char regGPin, char regDot, char regDotPin, char regDigit0, char regDigit0Pin, char regDigit1, char regDigit1Pin, char regDigit2, char regDigit2Pin, char regDigit3, char regDigit3Pin);
	virtual ~FourDigitSevenSegmentDisplay();

	// writes a digit number
	void writeCharToDigit(int digitNumber, char valueToWrite);

private:
	ShiftRegisterFactory myShiftRegisterPointer;
	char myRegA;
	char myRegAPin;
	char myRegB;
	char myRegBPin;
	char myRegC;
	char myRegCPin;
	char myRegD;
	char myRegDPin;
	char myRegE;
	char myRegEPin;
	char myRegF;
	char myRegFPin;
	char myRegG;
	char myRegGPin;
	char myRegDot;
	char myRegDotPin;
	char myRegDigit0;
	char myRegDigit0Pin;
	char myRegDigit1;
	char myRegDigit1Pin;
	char myRegDigit2;
	char myRegDigit2Pin;
	char myRegDigit3;
	char myRegDigit3Pin;


};

#endif /* FOURDIGITSEVENSEGMENTDISPLAY_H_ */
