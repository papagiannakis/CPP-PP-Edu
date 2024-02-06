#include "CovidMutation1.h"

CovidMutation1::CovidMutation1()
{
	mutationName = "CovidMutation1";
}

int CovidMutation1::AverageDaysDuration()
{
	int days = 10;

	if (symptoms.fever)
		days += 5;
	if (symptoms.breathingDifficulty)
		days += 7;
	if (symptoms.breathingDifficulty)
		days += 2;

	return days;
}

float CovidMutation1::TransmissionRate()
{
	float rate = 0;

	if (symptoms.fever)
		rate += 0.2;
	if (symptoms.breathingDifficulty)
		rate += 0.05;
	if (symptoms.breathingDifficulty)
		rate += 0.15;

	return rate;
}