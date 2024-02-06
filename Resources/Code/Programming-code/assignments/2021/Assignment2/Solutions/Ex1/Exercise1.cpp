#include "../std_lib_facilities.h"

void initializeVector(vector<int> & x)
{
	for (int i = 0; i <= 150; i+=2)
		x.push_back(i);
}

int recusrsiveLinearSearch(int key, int pos, vector<int> & v, int size)
{
	if (pos + 1 > size)
		return -1;
	else if (v[pos] == key)
		return pos;
	pos++;
	return recusrsiveLinearSearch(key, pos, v, size);
}

int main()
{
	int start_pos;
	int key;
	int element_pos;
	unsigned int vectorSize;
	vector<int> evenNums;

	initializeVector(evenNums);

	try 
	{
		cout << "Enter the start position and the key for the linear search\n";
		cin >> start_pos >> key;
		if(!cin || start_pos < 0)
			error("Wrong input!\n");

		vectorSize =  evenNums.size();

		element_pos = recusrsiveLinearSearch(key, start_pos,  evenNums, vectorSize);
		if (element_pos < 0)
		{
			cout << element_pos << endl;
			cout << "Element not found!\n";
		}
		else
			printf("Element %d located in position %d\n", key, element_pos);
	}
	catch (runtime_error error)
	{
		cerr << "~~~~~~~~~~~~~~~~~~\n";
		cerr << error.what();
		return 0;
	}
	return 0;
}
