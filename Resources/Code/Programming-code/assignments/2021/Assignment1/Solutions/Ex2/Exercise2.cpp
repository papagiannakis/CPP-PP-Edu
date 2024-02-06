#include "../std_lib_facilities.h"

string mergeStrings(string s1, string s2);

int main(void){

    string s1,s2;
    cout<< "Please give me 2 strings:";
    cin >> s1;
    cin >> s2;
    cout << "Merged string: " + mergeStrings(s1,s2) <<endl;
}

string mergeStrings(string s1, string s2){
    
    size_t length;
    string newstring = "";
    cout << s1.length() <<endl;
    cout << s2.length()<<endl;
    if (s1.length() > s2.length()) length = s2.length();
    else length = s1.length();
    
    for(int i=0; i<length;i++){
        newstring.append(string(1, s1.at(i)));
        newstring.append(string(1, s2.at(i)));
    }

    if(s1.length() > s2.length()){
        newstring += ""+ s1.substr(length);
    }else{
        newstring += ""+ s2.substr(length);
    }
    
    return newstring;
}