#pragma once
#include "std_lib_facilities.h"

//Get Input for each racer.
void GetRacerInput(int racer, double& speed, double& distance, double& accel);

//Calculate remaing time.
double CalculateTime(double speed, double distance, double accel);

//Helper function to find discriminant.
double CalculateDiscriminant(double a, double b, double c);

//Find which racer has the time we pass as argument.
int FindRacerIDX(vector<double>,double);

int main() {
	int racers; 
	double* speed, *distance, *accel, totalDistance;
	vector<double> times;
	
	//Ask how many racers and initialize the corresponding arrays.
	cout << "How many racers are in the race?" << endl;
	cin >> racers;

	speed = new double[racers];
	distance = new double[racers];
	accel = new double[racers];
	
	try {
		for (int i = 0; i < racers; i++) {

			cout << endl;
			GetRacerInput(i, speed[i], distance[i], accel[i]);
			cout << "--------" << endl<<endl;
		}

		cout << "What is the total distance of the race: " ;
		cin >> totalDistance;
		if (cin.fail() || totalDistance <= 0) {
			throw runtime_error("Please provide a valid total distance.");
		}

		//Calculate time and keep it in vector
		for (int i = 0; i < racers; i++) {
			if (totalDistance - distance[i] < 0) throw runtime_error("Some racers have already finished");
			times.push_back(CalculateTime(speed[i], totalDistance - distance[i], accel[i]));
		}

		//sort vector
		vector<double> TimesUnsorted = times;
		sort(begin(times), end(times));

		//Print the results but with the initial indexing of racers.
		for (int i = 0; i < racers; i++) {
			int racerIDX = FindRacerIDX(TimesUnsorted, times[i]);
			cout << "Racer " << racerIDX << ": will need t: " << times[i] << " (s) to finish." << endl;;
		}
	}
	catch (exception e) {
		cout << "Caught exception \"" << e.what() << "\"" << endl;
	}
}

void GetRacerInput(int racer, double& speed, double& distance, double& accel)
{
	//Get input and check for errors.
	cout << "Initial Speed of racer " << racer+1 << ": ";
	cin >> speed;
	if (cin.fail() || speed<0 ) {
		throw runtime_error("Please provide a valid speed.");
	}

	cout << "Distance traveled of racer " << racer + 1 << ": ";
	cin >> distance;
	if (cin.fail()|| distance <= 0) {
		throw runtime_error("Please provide a valid distance.");
	}

	cout << "Acceleration " << racer + 1 << ": ";
	cin >> accel;
	if (cin.fail()|| accel <= 0) {
		throw runtime_error("Please provide a valid acceleration.");
	}
}


double CalculateTime(double speed, double distance, double accel) {
	//Solve the equation to find time
	double dicrim = CalculateDiscriminant(accel / 2, speed, -distance);
	double solution1 = (-speed + sqrt(dicrim)) / (accel);
	double solution2 = (-speed - sqrt(dicrim)) / (accel);

	//Keep only the positive solution. It will always be one of them, or it will be 0.
	if (solution1 > 0) {
		return solution1;
	}
	else if (solution2 > 0)
		return solution2;

	return 0;
}

double CalculateDiscriminant( double a, double b, double c) {
	return pow(b, 2) - 4 * a * c;
}

int FindRacerIDX(vector<double> racers, double time)
{
	//In order to print racers with the initial ordering find the racer with the time we passed as argument.
	for (int i = 0; i < racers.size(); i++) {
		//Just to avoid precision errors from c++. (1st year students don't need to do sth like this)
		if (fabs(racers[i] - time) < DBL_EPSILON) return i;
	}
	return 0;
}