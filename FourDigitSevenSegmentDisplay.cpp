/*
 * FourDigitSevenSegmentDisplay.cpp
 *
 *  Created on: 23.05.2018
 *      Author: butch
 */

#include "FourDigitSevenSegmentDisplay.h"
#include "ShiftRegisterFactory.h"
#include "arduino.h"

#define DEBUGLOG 1

FourDigitSevenSegmentDisplay::FourDigitSevenSegmentDisplay(ShiftRegisterFactory &shiftRegister, char regA, char regAPin, char regB, char regBPin, char regC, char regCPin, char regD, char regDPin, char regE, char regEPin, char regF, char regFPin, char regG, char regGPin, char regDot, char regDotPin, char regDigit0, char regDigit0Pin, char regDigit1, char regDigit1Pin, char regDigit2, char regDigit2Pin, char regDigit3, char regDigit3Pin)
{
	myShiftRegisterPointer = shiftRegister;
	myRegA=regA;
	myRegAPin=regAPin;
	myRegB=regB;
	myRegBPin=regBPin;
	myRegC=regC;
	myRegCPin=regCPin;
	myRegD=regD;
	myRegDPin=regDPin;
	myRegE=regE;
	myRegEPin=regEPin;
	myRegF=regF;
	myRegFPin=regFPin;
	myRegG=regG;
	myRegGPin=regGPin;
	myRegDot=regDot;
	myRegDotPin=regDotPin;
	myRegDigit0=regDigit0;
	myRegDigit0Pin=regDigit0Pin;
	myRegDigit1=regDigit1;
	myRegDigit1Pin=regDigit1Pin;
	myRegDigit2=regDigit2;
	myRegDigit2Pin=regDigit2Pin;
	myRegDigit3=regDigit3;
	myRegDigit3Pin=regDigit3Pin;
}


void FourDigitSevenSegmentDisplay::writeCharToDigit(int digitNumber, char charToWrite)
{
	// write the character
	switch (charToWrite)
	{

	case '0':
		myShiftRegisterPointer.setNewValueBit(myRegA, myRegAPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegB, myRegBPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegC, myRegCPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegD, myRegDPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegE, myRegEPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegF, myRegFPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegG, myRegGPin, 0);
		break;

	case '1':
		myShiftRegisterPointer.setNewValueBit(myRegA, myRegAPin, 0);
		myShiftRegisterPointer.setNewValueBit(myRegB, myRegBPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegC, myRegCPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegD, myRegDPin, 0);
		myShiftRegisterPointer.setNewValueBit(myRegE, myRegEPin, 0);
		myShiftRegisterPointer.setNewValueBit(myRegF, myRegFPin, 0);
		myShiftRegisterPointer.setNewValueBit(myRegG, myRegGPin, 0);
		break;

	case '2':
		myShiftRegisterPointer.setNewValueBit(myRegA, myRegAPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegB, myRegBPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegC, myRegCPin, 0);
		myShiftRegisterPointer.setNewValueBit(myRegD, myRegDPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegE, myRegEPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegF, myRegFPin, 1);
		myShiftRegisterPointer.setNewValueBit(myRegG, myRegGPin, 1);
		break;

	default:
		// do if no match
		break;
	}


	// link to the digit (enable only one, disable the other 3 digits)
	switch (digitNumber)
	{
		case 0:
			myShiftRegisterPointer.setNewValueBit(myRegDigit0, myRegDigit0Pin, 1);
			myShiftRegisterPointer.setNewValueBit(myRegDigit1, myRegDigit1Pin, 0);
			myShiftRegisterPointer.setNewValueBit(myRegDigit2, myRegDigit2Pin, 0);
			myShiftRegisterPointer.setNewValueBit(myRegDigit3, myRegDigit3Pin, 0);
			break;
		case 1:
			myShiftRegisterPointer.setNewValueBit(myRegDigit0, myRegDigit0Pin, 0);
			myShiftRegisterPointer.setNewValueBit(myRegDigit1, myRegDigit1Pin, 1);
			myShiftRegisterPointer.setNewValueBit(myRegDigit2, myRegDigit2Pin, 0);
			myShiftRegisterPointer.setNewValueBit(myRegDigit3, myRegDigit3Pin, 0);
			break;

		case 2:
			myShiftRegisterPointer.setNewValueBit(myRegDigit0, myRegDigit0Pin, 0);
			myShiftRegisterPointer.setNewValueBit(myRegDigit1, myRegDigit1Pin, 0);
			myShiftRegisterPointer.setNewValueBit(myRegDigit2, myRegDigit2Pin, 1);
			myShiftRegisterPointer.setNewValueBit(myRegDigit3, myRegDigit3Pin, 0);
			break;

		case 3:
			myShiftRegisterPointer.setNewValueBit(myRegDigit0, myRegDigit0Pin, 0);
			myShiftRegisterPointer.setNewValueBit(myRegDigit1, myRegDigit1Pin, 0);
			myShiftRegisterPointer.setNewValueBit(myRegDigit2, myRegDigit2Pin, 0);
			myShiftRegisterPointer.setNewValueBit(myRegDigit3, myRegDigit3Pin, 1);
			break;
	}
}

FourDigitSevenSegmentDisplay::~FourDigitSevenSegmentDisplay() {
	// TODO Auto-generated destructor stub
}


