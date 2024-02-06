#include "../std_lib_facilities.h"
using namespace std;

#define STD_DAYS 3
#define FEE 1.5

struct clients
{
    int days;
    double charge;
};

typedef struct clients Clients;

double calculateCharges(int days)
{
    int extraDays = 0;
    double charge = 2;

    extraDays = days - STD_DAYS;
    if (extraDays > 0)
    {
        int tmp = (int)(extraDays);
        if (extraDays - tmp > 0)
        {
            extraDays = tmp + 1;
        }
        charge += extraDays * FEE;
    }
    if (days >= 14)
        charge = 17.5;

    return charge;
}

void printValues(Clients clients_book[])
{
    ofstream outputFile("out.txt");
    double sumOfCharges = 0;
    int sumOfDays = 0;
    outputFile << setprecision(2) << fixed;
    outputFile << "---------------------------------------------------" <<endl;
    outputFile << "\t\t Table_of_Clients:" <<endl;
    outputFile << "---------------------------------------------------" <<endl;
    outputFile << "\t\tCharge\t\tDays" <<endl;
    for (int i = 0; i < 5; i++)
    {   
        if(clients_book[i].days/10 == 0){
            outputFile << "Client_" << i+1 << "\t" << clients_book[i].charge << "\t\t0" << clients_book[i].days <<endl;
        }else{
            outputFile << "Client_" << i+1 << "\t" << clients_book[i].charge << "\t\t" << clients_book[i].days <<endl;
        }
        sumOfCharges += clients_book[i].charge;
        sumOfDays += clients_book[i].days;
    }
    outputFile << "---------------------------------------------------" <<endl;
    outputFile << "Sum:" <<"\t\t" << sumOfCharges << "\t\t" << sumOfDays <<endl;
    outputFile << "---------------------------------------------------" <<endl;
    outputFile.close();
}

int main()
{
    Clients clients_book[5];
    try
    {
        for (int i = 0; i < 5; i++)
        {
            int days;
            Clients client;
            string numOfClient;
            switch (i)
            {
            case 0:
                numOfClient = "first";
                break;
            case 1:
                numOfClient = "second";
                break;
            case 2:
                numOfClient = "third";
                break;
            case 3:
                numOfClient = "fourth";
                break;
            case 4:
                numOfClient = "fifth";
                break;
            default:
                break;
            }
            cout << "Please enter the number of days the " + numOfClient + " client lent their book" << endl;
            cin >> days;
            if (days < 0 || !cin)
                error("Wrong input entered\n");
            client.days = days;
            client.charge = calculateCharges(days);
            clients_book[i] = client;
        }
        printValues(clients_book);
    }
    catch (runtime_error error)
    {
        cerr << "---------------------------------------\n";
        cerr << error.what();
        return 0;
    }
    return 0;
}