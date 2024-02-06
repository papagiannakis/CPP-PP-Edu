#include "../std_lib_facilities.h"
#include "Rectangle.h"

Rectangle::Rectangle(): length(1.0), width(1.0){}

Rectangle::Rectangle(double length, double width) {
    setLength(length);
    setWidth(width);
}

double Rectangle::perimeter() {
    return (2 * (length + width)); 
}

double Rectangle::area() {
    return (length * width);
}

double Rectangle::getWidth() {
    return width; 
}

double Rectangle::getLength() {
    return length; 
}

void Rectangle::setLength(double len) {
    length = len;                        
}

void Rectangle::setWidth(double wid) {
    width = wid;                          
}
int main()
{
    double user_length;
    double user_width;
    Rectangle rect;        

    
    while (true) {
    cout << "Provide the rectangle's length:" << endl;
    cin.clear();
        try {
            if (cin >> user_length) {
                if (user_length <= 0.0 || user_length >= 30.0) {
                    throw invalid_argument("Length Out Of Range!");
                }   
                else {
                    rect.setLength(user_length); 
                    cout << "Length set to " << rect.getLength() << endl;
                    break; 
                }
            } else {
                // First clear the stream status
                cin.clear();
                // Then skip the bad input
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw invalid_argument("Length not a double!");
            }
        } catch (const std::invalid_argument& ia) {
            std::cerr << "Invalid argument: " << ia.what() << '\n';
        }
    }
    while (true) {
    cout << "Provide the rectangle's width:" << endl;
    cin.clear();
        try {
            if (cin >> user_width) {
                if (user_width <= 0.0 || user_width >= 30.0) {
                    throw invalid_argument("Width Out Of Range!");
                }   
                else {
                    rect.setWidth(user_width); 
                    cout << "Width set to " << rect.getWidth() << endl;
                    break; 
                }
            } else {
                // First clear the stream status
                cin.clear();
                // Then skip the bad input
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw invalid_argument("Width not a double!");
            }
        } catch (const std::invalid_argument& ia) {
            std::cerr << "Invalid argument: " << ia.what() << '\n';
        }
    }
    cout << "Rectangle's perimeter is: " << rect.perimeter() << endl; 
    cout << "Rectangle's area is: " << rect.area() << endl;
    return 0;
}