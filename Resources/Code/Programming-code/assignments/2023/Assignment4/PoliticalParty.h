#include <string>
#include <vector>

using namespace std;

struct Info{
    int foundedYear;
    string chairmanName;
    string Ideology;
};

struct Nominee{
    string Name;
    int Votes;
};

class PoliticalParty{
    protected:
        Info partyInfo;
        string Name;
        vector<Nominee> Nominees;

    public:
        virtual int GetTotalScore() =0;
        virtual vector<string> GetNomineesVotes() = 0;

        Info GetPartInfo(){
            return partyInfo;
        }

        void SetPartyInfo(Info partyInfo){
            this->partyInfo = partyInfo;
        }

        void SetNominees(vector<Nominee> noms){
            Nominees = noms;
        }

        void IncreaseVote(int idx){
            Nominees[idx].Votes++;
        }

        

        string GetAllInfo(){
            //Add code here
        }

};


string s="";
            s+= "Political Party: " + Name +'\n';
            s+= "Founded: " + to_string(partyInfo.foundedYear) +'\n';
            s+= "ChairManName: " + partyInfo.chairmanName +'\n';
            s+= "Ideology: " + partyInfo.Ideology +'\n';
            s+= "Score: " + to_string(GetTotalScore()) +'\n';
            s+= "Nominees:\n";
            vector<string> MyNominees = GetNomineesVotes();
            for(int i=0;i<MyNominees.size();i++){
                s+= "[" + to_string(i) + "]:" + MyNominees[i] + "\n";
            }

            return s;