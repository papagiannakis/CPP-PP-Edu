#include "Parties.h"
#include <algorithm>

bool CmpString(string s1, string s2){
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    else {
        return s1.size() < s2.size();
    }
}

bool CompVotes(const Nominee &nom1, const Nominee &nom2){
    if(nom2.Votes > nom1.Votes)
        return 1;
    if(nom2.Votes == nom1.Votes){
        if(nom2.Name > nom1.Name)
            return 1;
    }

    
    return 0;
}

bool CompNames(const Nominee &nom1, const Nominee &nom2){
    if(nom2.Name >= nom1.Name)
        return 1;
    
    return 0;
}

RedParty::RedParty(Info inf, string s, vector<Nominee> noms){
    partyInfo = inf;
    Name = s;
    Nominees = noms;
}


int RedParty::GetTotalScore(){
    int totalVotes=0;
    for(int i=0; i<Nominees.size();i++){
        totalVotes += Nominees[i].Votes;
    }
    return totalVotes;
}

vector<string> RedParty::GetNomineesVotes(){
    vector<string> Result;
    
    sort(Nominees.begin(), Nominees.end(), CompVotes);

    for (int i=0;i<Nominees.size();i++){
        Result.push_back(Nominees[i].Name +" " + to_string(Nominees[i].Votes));
    }
    return Result;
}

BlueParty::BlueParty(Info inf, string s, vector<Nominee> noms){
    partyInfo = inf;
    Name = s;
    Nominees = noms;
}


int BlueParty::GetTotalScore(){
    int totalVotes=0;
        for(int i=0; i<Nominees.size();i++){
            totalVotes += Nominees[i].Votes;
        }
        return totalVotes/Nominees.size();
}

vector<string> BlueParty::GetNomineesVotes(){
    vector<string> Result;
    
    sort(Nominees.begin(), Nominees.end(), CompNames);

    for (int i=0;i<Nominees.size();i++){
        Result.push_back(Nominees[i].Name +" " + to_string(Nominees[i].Votes));
    }
    return Result;
}
