
//
// This is example code from Chapter 16.5 "An example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include "Graph.h"         // get access to our graphics library facilities
#include "GUI.h"
#include "Simple_Window.h"

using namespace Graph_lib;
using namespace std;

// Read CSV Files
void read_train_set(string filename, vector<int>& house_size, vector<int>& price)
{
    ifstream csv(filename);
    if(!csv.is_open()) throw std::runtime_error("Could not open file");
  
    vector<string> row;
    string line, word, temp;

    // Skip headers
    getline(csv, line);
    int val;
    while(std::getline(csv, line))
    {
        std::stringstream ss(line);
        int i = 0;
        // Extract each integer
        while(ss >> val){
            if (i == 0) house_size.push_back(val);
            if (i == 1) price.push_back(val);            

            if(ss.peek() == ',') ss.ignore();
            i++;
        }
    }
    csv.close();
}

void estimate_coef_simple(std::vector<int> indep_var, std::vector<int> dep_var, float& b_1, float& b_0)
{
    const size_t n = indep_var.size();
    float s_x = 0.f;
    float s_y = 0.f;
    float s_xx = 0.f;
    float s_xy = 0.f;

    for (int i = 0; i < n; i++) {
        s_x += indep_var[i]; // sum x
        s_y += dep_var[i]; // sum y

        s_xx += indep_var[i] * indep_var[i]; // inner product xx
        s_xy += indep_var[i] * dep_var[i]; // inner product xy
    }

    b_1 = (n * s_xy - s_x * s_y) / (n * s_xx - s_x * s_x);
    b_0 = (s_y - b_1 * s_x) / n;
}

int main()
try {
    vector<int> X; // house size -> independent variable | explanatory variable
    vector<int> Y; // price -> dependent variable
    float B_1 = 0.0f;
    float B_0 = 0.0f;

    // Load csv.
    read_train_set("train_set.csv", X, Y);

    // Estimate coefficients (Y = b + aX)
    estimate_coef_simple(X, Y, B_1, B_0);
    cout << "Slope - B_1: " << B_1 << endl;
    cout << "Constant - B_0: " << B_0 << endl;

    // Create Window
    Point tl(100,100);    // top-left corner of our window
    Simple_window win(tl,600,600,"Linear Regression");

    // Create Axes
    Axis xa(Axis::x, Point(40,560), 560, 40, "House Size in Square Meters"); // make an Axis
    xa.set_color(Color::black);
    xa.label.set_color(Color::black);
    Axis ya(Axis::y, Point(40,560), 560, 40, "Price Sold");
    ya.set_color(Color::black);           // choose a color
    ya.label.set_color(Color::black); // choose a color for the text

    // Scale the points
    const int x_origin = 40;
    const int y_origin = 560;
    for (int i = 0; i < X.size(); i++)
    {
        Mark*  m = new Mark(Point((X[i] + x_origin), y_origin - Y[i]), '*');
        win.attach(*m);
    }

    // Add prediction line
    Point x0(x_origin, y_origin);
    Point x1(500, 560 - (500*B_1) + B_0);
    Line line(x0, x1);
    line.set_color(Color::red);

    // Attach everything to window
    win.attach(xa);
    win.attach(ya);
    win.attach(line);
    
    win.wait_for_button();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}

