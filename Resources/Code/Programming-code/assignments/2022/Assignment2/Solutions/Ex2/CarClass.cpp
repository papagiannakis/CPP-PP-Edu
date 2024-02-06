#include "std_lib_facilities.h"

class Car {

private:
	
	int TiresNumber, PaintedPercentage, GoodLights;
	

public:
	int GetTiresNumber();
	void SetTiresNumber(int);

	int GetPaintedPercentage();
	void SetPaintedPercentage(int);

	int GetGoodLights();
	void SetGoodLights(int);


	void PrintCarStatus();
	float CalculateRepairCosts(float, float, float);

	Car();
	Car(int, int, int);
};

int Car::GetTiresNumber()
{
	return TiresNumber;
}

void Car::SetTiresNumber(int tires)
{
	TiresNumber = tires;
}

int Car::GetPaintedPercentage()
{
	return PaintedPercentage;
}

void Car::SetPaintedPercentage(int Percent)
{
	PaintedPercentage = Percent;
}

int Car::GetGoodLights()
{
	return GoodLights;
}

void Car::SetGoodLights(int Lights)
{
	GoodLights = Lights;
}

void Car::PrintCarStatus()
{
	cout << "CAR" << endl << "Percentage paint: " << PaintedPercentage<< endl;
	cout << "It has " << TiresNumber << " bad tires." << endl;
	cout << "And " << GoodLights << " lights are bad." << endl;
}

float Car::CalculateRepairCosts(float TireCosts, float PaintCost, float LightsCost)
{
	float totalCost = 0;
	if (PaintedPercentage < 70) {
		totalCost += PaintCost;
	}

	return totalCost + (TiresNumber * TireCosts) + (LightsCost * GoodLights);
}

Car::Car()
{
	TiresNumber = 0;
	PaintedPercentage = 0;
	GoodLights = 0;
}

Car::Car(int Tires, int Percent, int Lights)
{
	TiresNumber = Tires;
	PaintedPercentage = Percent;
	GoodLights = Lights;

}



int main() {
	float TCost, PCost, LCost;

	cout << "Please give me the cost for one tire, one repaint, and one light." << endl;
	cin >> TCost;
	cin >> PCost;
	cin >> LCost;

	Car car1;
	car1.SetTiresNumber(2);
	car1.SetGoodLights(1);
	car1.SetPaintedPercentage(70);
	car1.PrintCarStatus();
	cout << "Cost for car1 is :" << car1.CalculateRepairCosts(TCost, PCost, LCost)<<endl<<endl;

	Car car2(1,50,3);
	car2.PrintCarStatus();
	cout << "Cost for car2 is :" << car2.CalculateRepairCosts(TCost, PCost, LCost) << endl << endl;

}