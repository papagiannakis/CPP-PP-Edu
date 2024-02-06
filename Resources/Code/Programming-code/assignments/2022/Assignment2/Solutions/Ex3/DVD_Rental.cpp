#include "std_lib_facilities.h"
using namespace std;


void PrintMovies(vector<string>, vector<int>, vector<float>);
void WriteMovies(vector<string> Movies, vector<int> Status, vector<float> Prices, string Filename);

int main()
{
    vector<string> Movies;
    vector<int> MoviesStatus;
    vector<float> MoviesPrices;
    
    string filename;

    string currentName = "";
    int currentStatus = 0;
    float currentPrice = 0;
    int selectedIDX=0, buy_rent = 0;

    float total_cost = 0;
    std::cin >> filename;

    ifstream inputfile(filename);
    while (!inputfile.eof()) {
        inputfile >> currentName;
        inputfile >> currentStatus;
        inputfile >> currentPrice;

        Movies.push_back(currentName);
        MoviesStatus.push_back(currentStatus);
        MoviesPrices.push_back(currentPrice);
    }

    while (selectedIDX != -1) {
        PrintMovies(Movies, MoviesStatus, MoviesPrices);

        cout << "Which movie would you like to buy or rent? (-1 for exiting)" << endl;
        cin >> selectedIDX;

        if (selectedIDX == -1) {
            WriteMovies(Movies, MoviesStatus, MoviesPrices, filename);
            cout << "Total cost is: " << total_cost << endl;
            return 0;
        }

        cout << "Would you like to buy it or rent? (0: Buy , 1: Rent)" << endl;
        cin >> buy_rent;

        if (buy_rent == 0) {
            total_cost+=MoviesPrices[selectedIDX];
            MoviesStatus[selectedIDX] = 2;
        }
        else {
            total_cost += 3;
            MoviesStatus[selectedIDX] = 1;
        }

        cout << endl << "-------" << endl;
    }


    return 0;
}


void PrintMovies(vector<string> Movies, vector<int> Status, vector<float> Prices) {
    for (int i = 0; i < Movies.size(); i++) {
        if (Status[i] == 0) {
            cout << "[" << i << "]" << Movies[i] + " Not Owned " << Prices[i] << endl;
        }
        else if (Status[i] == 1) {
            cout << "[" << i << "]" << Movies[i] + " Rent " << Prices[i] << endl;
        }
        else {
            cout << "[" << i << "]" << Movies[i] + " Bought " << Prices[i] << endl;
        }
    }
}

void WriteMovies(vector<string> Movies, vector<int> Status, vector<float> Prices, string Filename) {
    ofstream outFile(Filename);

    for (int i = 0; i < Movies.size(); i++) {
        outFile << Movies[i] << " " << Status[i] << " " << Prices[i] << endl;
    }
}