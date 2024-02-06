#include "../std_lib_facilities.h"

int checkParentheses(string s){
    
    int parenthesis=0;
    vector<int> parenthesisPos;
    
    for (size_t i=0; i<s.length();i++){
        if(s[i] =='(') {
            parenthesis++;
            parenthesisPos.push_back(i);
        }
        if(s[i] == ')') {
            
            if(parenthesis == 0) return -2;
            else {
                parenthesis--;
                parenthesisPos.pop_back();
            }
        }
    }
    
    if(parenthesis==0) return -1;
    else {
        return parenthesisPos[0];
    }

}
int main(){
    string sentence;
    cout << "Please give a sentence with parentheses to check if valid:";
    cin >> sentence;

    int result = checkParentheses(sentence);
    if( result == -1){
        cout << "Input sentence is valid." <<endl;
    }else if(result == -2){
        cout << "An extra closing parentheses exists." <<endl;
    }else{
        cout << "There is an extra opening parentheses at position: "<< result << endl;
    }
}