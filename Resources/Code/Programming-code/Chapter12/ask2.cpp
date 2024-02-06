/**
  * HY150
*/

#include "Simple_window.h"    // if we want that "Next" button
#include "Graph.h" 
//#include <std_lib_facilities.h>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <sstream>
using namespace Graph_lib;

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

namespace Graph_lib {
    
    //------------------------------------------------------------------------------
    string In_box::get_string()
    {
        Fl_Input& str = reference_to<Fl_Input>(pw);
        return str.value();
    }
}

//------------------------------------------------------------------------------

// The call to keep_window_open() is needed on some Windows machines to prevent
// them from closing the window before you have a chance to read the output. 
inline void keep_window_open()
{
    cin.get();
}

//------------------------------------------------------------------------------

inline void keep_window_open(const string& str)
{
    static int attempts = 10; // Maximum number of attempts before forceful exit
    
    while (--attempts)
    {
        cout << "Please enter " << str << " to exit" << endl;
        
        bool exit = true;
        
        for(string::const_iterator p = str.begin(); p != str.end(); ++p)
            if (*p != cin.get())
            {
                exit = false;
                break;
            }
        
        if (exit)
            break;
    }
}

//------------------------------------------------------------------------------
/*
// Helper function to show an error message
inline void error(const string& errormessage)
{
    cerr << errormessage << endl;
    throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------

inline void error(string s1, string s2)
{
    error(s1+s2);
}
*/
//------------------------------------------------------------------------------

template <typename Target, typename Source>
Target narrow_cast(Source src)
{
    Target tgt = (Target)src;
    
    if ((Source)tgt != src)
        error("Invalid narrowing conversion");
    
    return tgt;
}

//------------------------------------------------------------------------------

inline ios_base& general(ios_base& b)    // to complement fixed and scientific
{
    b.setf(ios_base::fmtflags(0), ios_base::floatfield);
    return b;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
std::stringstream in(std::stringstream::in | std::stringstream::out);
Fl_Input input1(345,200,180,40,"data:");
Fl_Output output1(345,240,180,40,"result:");
In_box str_box(Point (350,150), 80, 40, "str_box:");
//------------------------------------------------------------------------------

const char number = '8';    // t.kind==number means that t is a number Token
const char quit   = 'q';    // t.kind==quit means that t is a quit Token
const char print  = ';';    // t.kind==print means that t is a print Token
const char name   = 'a';    // name token
const char let    = 'L';    // declaration token
const string declkey = "let";// declaration keyword 
const string prompt  = "> ";
const string result  = "= "; // used to indicate that what follows is a result

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;      // for names: name itself
    Token(char ch)             : kind(ch), value(0)   {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string n)   : kind(ch), name(n)    {}
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);      // discard tokens up to an including a c
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get() // read characters from cin and compose a Token
{
    if (full) {         // check if we already have a Token ready
        full=false;
        return buffer;
    }  

    char ch;
    in >> ch;          // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case quit:
    case print:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/': 
    case '%':
    case '=':
        return Token(ch); // let each character represent itself
    case '.':             // a floating-point literal can start with a dot
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':    // numeric literal
    {
        in.putback(ch);// put digit back into the input stream
        double val;
        in >> val;     // read a floating-point number
        return Token(number,val);
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (in.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
            in.putback(ch);
            if (s == declkey) return Token(let); // keyword "let"
            return Token(name,s);
        }
		//error("Bad token");
    }
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
    // c represents the kind of a Token
{
    // first look in buffer:
    if (full && c==buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    // now search input:
    char ch = 0;
    while (in >> ch)
        if (ch==c)
			return;
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

class Variable {
public:
    string name;
    double value;
    Variable (string n, double v) :name(n), value(v) { }
};

//------------------------------------------------------------------------------

vector<Variable> var_table;

//------------------------------------------------------------------------------

double get_value(string s)
    // return the value of the Variable names s
{
    for (unsigned int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    error("get: undefined variable ", s);
	return 0;
}

//------------------------------------------------------------------------------

void set_value(string s, double d)
    // set the Variable named s to d
{
    for (unsigned int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) {
            var_table[i].value = d;
            return;
        }
    error("set: undefined variable ", s);
}

//------------------------------------------------------------------------------

bool is_declared(string var)
    // is var already in var_table?
{
    for (unsigned int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == var) return true;
    return false;
}

//------------------------------------------------------------------------------

double define_name(string var, double val)
    // add (var,val) to var_table
{
    if (is_declared(var)) error(var," declared twice");
    var_table.push_back(Variable(var,val));
    return val;
}

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':           // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case number:    
        return t.value;    // return the number's value
    case name:
        return get_value(t.name); // return the variable's value
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
	return 0;
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get(); // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        case '%':
            {    
                int i1 = narrow_cast<int>(left);
                int i2 = narrow_cast<int>(term());
                if (i2 == 0) error("%: divide by zero");
                left = i1%i2; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);        // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double declaration()
    // handle: name = expression
    // declare a variable called "name" with the initial value "expression"
{
    Token t = ts.get();
    if (t.kind != name) error ("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression();
    define_name(var_name,d);
    return d;
}

//------------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

//------------------------------------------------------------------------------

void clean_up_mess()
{ 
    ts.ignore(print);
}

//------------------------------------------------------------------------------

string calculate()
{
	std::stringstream buffer;
    while (in)
      try {
        //buffer << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get();    // first discard all "prints"
        if (t.kind == quit) return "";        // quit
        ts.putback(t);
		//buffer << result << statement() << endl;
		buffer << statement() << endl;
    }
    catch (exception& e) {
        //buffer << e.what() << endl;        // write error message
        clean_up_mess();
    }
    return buffer.str();
}

//------------------------------------------------------------------------------

void button_dot_cb(Address, Address pw)
{
	in << ".";
	input1.value(in.str().c_str());
}

void button_0_cb(Address, Address pw)
{
	in << "0";
	input1.value(in.str().c_str());
}

void button_1_cb(Address, Address pw)
{
	in << "1";
	input1.value(in.str().c_str());
}

void button_2_cb(Address, Address pw)
{
	in << "2";
	input1.value(in.str().c_str());
}

void button_3_cb(Address, Address pw)
{
	in << "3";
	input1.value(in.str().c_str());
}

void button_4_cb(Address, Address pw)
{
	in << "4";
	input1.value(in.str().c_str());
}

void button_5_cb(Address, Address pw)
{
	in << "5";
	input1.value(in.str().c_str());
}

void button_6_cb(Address, Address pw)
{
	in << "6";
	input1.value(in.str().c_str());
}

void button_7_cb(Address, Address pw)
{
	in << "7";
	input1.value(in.str().c_str());
}

void button_8_cb(Address, Address pw)
{
	in << "8";
	input1.value(in.str().c_str());
}

void button_9_cb(Address, Address pw)
{
	in << "9";
	input1.value(in.str().c_str());
}

void button_plus_cb(Address, Address pw)
{
	in << "+";
	input1.value(in.str().c_str());
}

void button_minus_cb(Address, Address pw)
{
	in << "-";
	input1.value(in.str().c_str());
}

void button_mul_cb(Address, Address pw)
{
	in << "*";
	input1.value(in.str().c_str());
}

void button_mod_cb(Address, Address pw)
{
	in << "%";
	input1.value(in.str().c_str());
}

void button_div_cb(Address, Address pw)
{
	in << "/";
	input1.value(in.str().c_str());
}

void button_assign_cb(Address, Address pw)
{
	in << "=";
	input1.value(in.str().c_str());
}

void button_l_par_cb(Address, Address pw)
{
	in << ")";
	input1.value(in.str().c_str());
}

void button_r_par_cb(Address, Address pw)
{
	in << "(";
	input1.value(in.str().c_str());
}

void button_colon(Address, Address pw)
{
	in << ";";
	input1.value(in.str().c_str());
}

void button_clear_cb(Address, Address pw)
{
	in.clear();
	in.str("");
	input1.value(in.str().c_str());
	output1.value("");
}

void button_clac_cb(Address, Address pw)
{
	in << ";";
	input1.value(in.str().c_str());
	string s(calculate());
	s = s.substr(0,s.size()-1);
	cout << s;
	output1.value(s.c_str());
}

void button_get_str_cb(Address, Address pw)
{
	in << str_box.get_string();
	input1.value(in.str().c_str());
}


int main()
try {
    // predefine names:
    define_name("pi",3.1415926535);
    define_name("e",2.7182818284);

	in.clear();
	in.str("");

    Point tl(300,300);

	Simple_window win(tl,600,400,"HY150 Calculator with FLTK exercise");
	//numbers
	Button n7(Point(40,40),40,40,"7",button_7_cb);
	Button n8(Point(80,40),40,40,"8",button_8_cb);
	Button n9(Point(120,40),40,40,"9",button_9_cb);
	Button n4(Point(40,80),40,40,"4",button_4_cb);
	Button n5(Point(80,80),40,40,"5",button_5_cb);
	Button n6(Point(120,80),40,40,"6",button_6_cb);
	Button n1(Point(40,120),40,40,"1",button_1_cb);
	Button n2(Point(80,120),40,40,"2",button_2_cb);
	Button n3(Point(120,120),40,40,"3",button_3_cb);
	Button n0(Point(80,160),40,40,"0",button_0_cb);
	Button dot(Point(120,160),40,40,".",button_dot_cb);
	win.attach(n0);
	win.attach(n1);win.attach(n2);win.attach(n3);
	win.attach(n4);win.attach(n5);win.attach(n6);
	win.attach(n7);win.attach(n8);win.attach(n9);
	win.attach(dot);
	// + - * % / = ; ( )
	Button bplus(Point(165,40),40,40,"+",button_plus_cb);
	Button bminus(Point(205,40),40,40,"-",button_minus_cb);
	Button bmul(Point(245,40),40,40,"*",button_mul_cb);
	Button bmod(Point(165,80),40,40,"%",button_mod_cb);
	Button bdiv(Point(205,80),40,40,"/",button_div_cb);
	Button bassign(Point(205,120),40,40,"=",button_assign_cb);
	Button bcolon(Point(245,120),40,40,";",button_colon);
	Button brpar(Point(245,80),40,40,"(",button_r_par_cb);
	Button blpar(Point(285,80),40,40,")",button_l_par_cb);
	win.attach(bplus);win.attach(bminus);win.attach(bmul);
	win.attach(bmod);win.attach(bdiv);win.attach(bassign);
	win.attach(brpar);win.attach(blpar);win.attach(bcolon);

	Button clear(Point(205,200),60,40,"clear",button_clear_cb);
	Button calc(Point(205,240),80,40,"calculate",button_clac_cb);
	win.attach(clear);
	win.attach(calc);
	
	Button bgstr(Point(440,150),40,40,"Get",button_get_str_cb);
	win.attach(bgstr);
	
	
	win.add(input1);
	win.add(output1);
	win.attach(str_box);
	
		
	win.wait_for_button();               // Display!
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
}

//------------------------------------------------------------------------------
