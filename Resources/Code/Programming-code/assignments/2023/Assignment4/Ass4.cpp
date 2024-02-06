#include "Parties.h"
#include <iostream>
#include <fstream>


vector <Nominee> ReadFile(string Path){
    vector<Nominee> fileNoms;
    ifstream partyFile(Path);
    string lastName="", firstName="";
    int votes =0;
    while(partyFile >> lastName>>firstName >> votes){
        Nominee newNom;
        newNom.Name=lastName +" "+ firstName;
        newNom.Votes = votes;

        fileNoms.push_back(newNom);
    }
    return fileNoms;
}

int main(void){
    Info RedPartyInfo;
    RedPartyInfo.chairmanName = "RedPartyChairman";
    RedPartyInfo.Ideology = "RedPartyIdeology";
    RedPartyInfo.foundedYear = 1685;
    RedParty rp(RedPartyInfo,"RedParty",ReadFile("RedParty.txt"));

    Info BluePartyInfo;
    BluePartyInfo.chairmanName = "BluePartyChairman";
    BluePartyInfo.Ideology = "BluePartyIdeology";
    BluePartyInfo.foundedYear = 1685;


    BlueParty bp(BluePartyInfo,"BlueParty",ReadFile("BlueParty.txt"));

    int selectComma=0;
    
    while (selectComma>-1){
        cout<<"Select 1 for blue. Select 2 for red. -1 to quit."<<endl;
        cin >> selectComma;
        
        if(selectComma==1){
            cout<<bp.GetAllInfo();
            int nomineeIDX=-1;
            cin >> nomineeIDX;
            if(nomineeIDX<0) return 0;
            else bp.IncreaseVote(nomineeIDX);
        }else{
            cout<<rp.GetAllInfo();
            int nomineeIDX=-1;
            cin >> nomineeIDX;
            if(nomineeIDX<0) return 0;
            else rp.IncreaseVote(nomineeIDX);
        }
    }

    
}

