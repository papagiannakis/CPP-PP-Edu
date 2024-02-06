
//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// HY150 Exactly the same program (that 'eats' two input values) as the one shown in slides

#include <iostream>
#include <string>
#include "std_lib_facilities.h"


//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
    
    cout<<"\t\t@get_token() Read char:"<<ch<<endl;
    
    switch (ch) {
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cout<<"\t\t\t@get_token(): 'ch' is number:"<<ch<<endl;
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            cout<<"\t\t\t@get_token(): 'val' double is:"<<val<<endl;

            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}


//------------------------------------------------------------------------------

double expression();  // read and evaluate a primary


//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    cout<<"\t\t@primary():(): before calling  t = get_token();"<<endl;
    Token t = get_token();
    switch (t.kind) {
        case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = get_token();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case '8':            // we use '8' to represent a number
            return t.value;  // return the number's value
        default:
            error("primary expected");
    }
}


//------------------------------------------------------------------------------

double term()
{
    cout<<"\t@term():(): before calling left = primary();"<<endl;
    double left = primary();
    cout<<"\t@term(): 'left' primary is:"<<left<<endl;
    
    while(true) {
        Token t = get_token();     // get the next token
        
        switch (t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                break;
            }
            default: 
                return left;
        }
    }
}


//------------------------------------------------------------------------------

double expression()
{
    cout<<"@expression(): before calling double left = term(); "<<endl;
    double left = term();      // read and evaluate a Term
    cout<<"@expression(): 'left' term is:"<<left<<endl;
    
    while(true) {
         cout<<"@expression(): before calling t = get_token(); "<<endl;
        Token t = get_token();     // get the next token
        cout<<"@expression(): after calling t = get_token(); "<<endl;
        switch(t.kind) {
            case '+':
                 cout<<"@expression(): after finding a '+' "<<endl;
                left += term();    // evaluate Term and add
                cout<<"@expression(): afer calling left += term();"<<endl;
                break;
            case '-':
                left -= term();    // evaluate Term and subtract
                break;
            default:
                return left;       // finally: no more + or -: return the answer
        }
    }
}
//------------------------------------------------------------------------------



int main()

try {
     
    while (cin)
    {
        cout<<"main: before calling expression()"<<endl;
        cout << expression() << '\n';
        cout<<"main: after calling expression()"<<endl;
        }
    keep_window_open();
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        keep_window_open ();
        return 1;
    }
    catch (...) {
        cerr << "exception \n";
        keep_window_open ();
        return 2;
    }
    //------------------------------------------------------------------------------
    
