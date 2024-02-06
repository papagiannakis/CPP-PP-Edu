#include "std_lib_facilities.h"
#include "CovidMutation1.h"
#include "CovidMutation2.h"
#include "Covid19Virus.h"

Symptoms ReadSymptoms()
{
	
	Symptoms s;
	string user_input;
	cout << "Do you have fever? (y/n)" << endl;
	cin >> user_input;
	s.fever = user_input == "y" ? true : false;

	cout << "Do you have breathing difficulty? (y/n)" << endl;
	cin >> user_input;
	s.breathingDifficulty = user_input == "y" ? true : false;

	cout << "Do you have loss of taste or smell? (y/n)" << endl;
	cin >> user_input;
	s.lossOfTasteOrSmell = user_input == "y" ? true : false;
	return s;
}


void main()
{
	CovidMutation1 c;
	vector<Covid19Virus*> v;

	string mutation_type;
	do
	{
		cout << "Type 1 for Muation1, 2 for Muation2 or quit" << endl;
		cin >> mutation_type;
		if (mutation_type == "quit")
		{
			break;
		}

		if (mutation_type != "1" &&
			mutation_type != "2" )
		{
			cout << "Bad input!" << endl;
			continue;
		}

		Symptoms s = ReadSymptoms();
		if (mutation_type == "1")
		{
			CovidMutation1 *c = new CovidMutation1();
			c->SetSymptoms(s);
			v.push_back(c);
		}
		else if (mutation_type == "2")
		{
			CovidMutation2 *c = new CovidMutation2();
			c->SetSymptoms(s);
			v.push_back(c);
		}		

	} while (mutation_type != "quit");

	ofstream  file_out; 
	file_out.open("results.txt"); 
	if (file_out.is_open())
	{
		for (int i = 0; i < v.size(); i++)
		{
			file_out << v.at(i)->GetInfo() << endl;
		}
	}
	file_out.close();

}