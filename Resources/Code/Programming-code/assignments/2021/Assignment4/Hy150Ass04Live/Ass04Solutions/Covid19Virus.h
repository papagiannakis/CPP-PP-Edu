#ifndef COVIDHEADER
#define COVIDHEADER

#include "std_lib_facilities.h"

struct Symptoms {
	bool fever;
	bool breathingDifficulty;
	bool lossOfTasteOrSmell;
};

class Covid19Virus
{
protected :
	Symptoms symptoms;
	string mutationName;

public:
	virtual int AverageDaysDuration() = 0;
	virtual float TransmissionRate() = 0;
	
	Symptoms GetSymptoms()
	{
		return symptoms;
	}

	void SetSymptoms(Symptoms s) {
		symptoms = s;
	}

	string GetInfo()
	{
		return "Mutation: " + mutationName +
			" Fever: " + (symptoms.fever == true ? "true" : "false") +
			" BreathingDifficulty: " + (symptoms.breathingDifficulty == true ? "true" : "false") +
			" LossOfTasteOrSmell: " + (symptoms.lossOfTasteOrSmell == true ? "true" : "false") +
			" AverageDaysDuration: " + to_string(AverageDaysDuration()) + " days" +
			" TransmissionRate:: " + to_string(TransmissionRate());
	}

};

#endif