#ifndef MUT1HEADER
#define MUT1HEADER


#include "Covid19Virus.h"
#include "std_lib_facilities.h"

class CovidMutation1 : public Covid19Virus
{
public:
	CovidMutation1();

	virtual int AverageDaysDuration();
	virtual float TransmissionRate();

	virtual int AverageDuration()
	{
		return 0;
	}

private:

};
#endif

