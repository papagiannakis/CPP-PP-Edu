#include "CovidMutation2.h"

CovidMutation2::CovidMutation2()
{
	mutationName = "CovidMutation2";
}

int CovidMutation2::AverageDaysDuration()
{
	int days = 5;

	if (symptoms.fever)
		days += 8;
	if (symptoms.breathingDifficulty)
		days += 2;
	if (symptoms.breathingDifficulty)
		days += 1;

	return days;
}

float CovidMutation2::TransmissionRate()
{
	float rate = 0;

	if (symptoms.fever)
		rate += 0.25;
	if (symptoms.breathingDifficulty)
		rate += 0.08;

	return rate;
}