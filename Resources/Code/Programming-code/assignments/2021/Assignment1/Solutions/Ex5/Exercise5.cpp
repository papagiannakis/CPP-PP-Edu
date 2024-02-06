#include "../std_lib_facilities.h"

int main(){
    vector<int> coins;
    double cost = 0;
    int total_payment=0;
    int current_payment=0;
    cout<<"Please insert the available currency coins: ";
    for(int i=0;i<3;i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    
    sort(coins.begin(), coins.end(), greater<int>()); 

    while(true){
        cout<<"Please insert the cost of the product (insert -1 to stop) :";
        cin>>cost;

        if(cost==-1) break;
        cost= cost*100;
        total_payment = 0;
        while(total_payment < cost){
            
            cout<<"Please pay using a 200 500 or 1000 bill : ";
            cin >> current_payment;
            total_payment+=current_payment;
        }

        int final_left =0, noCoins1=0,noCoins2=0,noCoins3=0;
        int exhange = (int) (total_payment - cost);
        for(int i=0;i<3;i++){
            noCoins1 = exhange/coins[0];
            int tmp1 = exhange%coins[0];

            noCoins2 = tmp1/coins[1];
            int tmp2 = tmp1%coins[1];

            noCoins3 = tmp2/coins[2];
            final_left = tmp2%coins[2];
        }
        
        if(final_left !=0 ) cout<< "The vending maching cannot give you the following change " << final_left<<endl;

        cout << "Your change is " << coins[0] << "x"<< noCoins1 << " , "<<coins[1] << "x"<< noCoins2 << " , "<<coins[2] << "x"<< noCoins3<<endl;
    }
}