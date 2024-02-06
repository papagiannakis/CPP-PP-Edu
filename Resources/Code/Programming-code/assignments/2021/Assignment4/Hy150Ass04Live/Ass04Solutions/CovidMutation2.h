#ifndef MUT2HEADER
#define MUT2HEADER

#include "Covid19Virus.h"
#include "std_lib_facilities.h"

class CovidMutation2 : public Covid19Virus
{
public:
	CovidMutation2();

	virtual int AverageDaysDuration();
	virtual float TransmissionRate();

	virtual int AverageDuration()
	{
		return 0;
	}

private:

};
#endif

