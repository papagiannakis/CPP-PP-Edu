#include "PoliticalParty.h"

class RedParty: public PoliticalParty{

public:    
    RedParty();
    RedParty(Info, string, vector<Nominee>);
    
    int GetTotalScore();
    vector<string> GetNomineesVotes();

};

class BlueParty: public PoliticalParty{
    
public:
    BlueParty();
    BlueParty(Info, string, vector<Nominee>);
    
    int GetTotalScore();
    vector<string> GetNomineesVotes();

};