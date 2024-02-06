
//
// This is example code from Chapter 12.7.11 "And much more" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

// The NOGDI below is needed to prevent Windows from including wingdi.h which has a duplicate
// declaration of 'Polygon' and throws ambiguous error.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define NOGDI
#endif

#include "Simple_window.h"    // if we want that "Next" button
#include "Graph.h" 
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main ()
try
{ 
    Point tl(100,100);    // top-left corner of our window

    Simple_window win(tl,600,400,"Canvas");
    // screen coordinate tl for top-left corner
    // window size(600*400)
    // title: Canvas

    Axis xa(Axis::x, Point(20,300), 280, 10, "x axis"); // make an Axis
    // an axis is a kind of Shape
    // Axis::x means horizontal
    // starting at (20,300)
    // 280 pixels long
    // 10 "notches"
    // label the axis "x axis"
    win.attach(xa);                      // attach xa to the window, win

    Axis ya(Axis::y, Point(20,300), 280, 10, "y axis");
    ya.set_color(Color::cyan);           // choose a color
    ya.label.set_color(Color::dark_red); // choose a color for the text
    win.attach(ya);

    Function sine(sin,0,100,Point(20,150),1000,50,50);    // sine curve
    // plot sin() in the range [0:100) with (0,0) at (20,150)
    // using 1000 points; scale x values *50, scale y values *50
    win.attach(sine);
    sine.set_color(Color::blue);         // we changed our mind about sine's color

    Polygon poly;                        // a polygon, a Polygon is a kind of Shape
    poly.add(Point(300,200));            // three points makes a triangle
    poly.add(Point(350,100));
    poly.add(Point(400,200));

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);

    Rectangle r(Point(200,200), 100, 50);// top-left corner, width, height
    win.attach(r);
    
    Closed_polyline poly_rect;
    poly_rect.add(Point(100,50)); 
    poly_rect.add(Point(200,50));
    poly_rect.add(Point(200,100));
    poly_rect.add(Point(100,100));
    poly_rect.add(Point(50,75));
    win.attach(poly_rect);

    r.set_fill_color(Color::yellow);     // color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dash,4)); 
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::green);

    Text t(Point(150,150), "Welcome to Olympics 2012! ");
    win.attach(t);
    t.set_font(Graph_lib::Font::times_bold);
    t.set_font_size(20);

    Image ii(Point(100,50),"image.jpg"); // 400*212 pixel jpg
    win.attach(ii);
    ii.move(500,200);
    Circle c(Point(100,200),50);
    c.set_color(Color::dark_red);
    Circle c2(Point(150,250),50);
    c2.set_color(Color::dark_blue);
    Circle c3(Point(200,200),50);
    c3.set_color(Color::dark_yellow);
    Circle c4(Point(250,250),50);
    c4.set_color(Color::dark_green);
    Circle c5(Point(300,200),50);
    c5.set_color(Color::black);
 
    Ellipse e(Point(350,200), 75,25); 
    e.set_color(Color::dark_red);
    Mark m(Point(100,200),'*');
    
    Text t1(Point(101,201), "x");
    Text t2(Point(102,202), ".");

    t1.set_color(Color::black);
    t2.set_color(Color::black);
    t1.set_font(Graph_lib::Font::times_bold);
    t1.set_font_size(20);
    t2.set_font(Graph_lib::Font::times_bold);
    t2.set_font_size(20);
    win.attach(t1);
    win.attach(t2);
    // n;
    
    for (int i =0; i<100;++i)
    {
      Mark*  n = new Mark(Point(500,500+5*i),'*');
        win.attach(*n);
    }
    

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes(Point(100,20),oss.str());

    Image cal(Point(225,225),"snow_cpp.gif"); // 320*240 pixel gif
    cal.set_mask(Point(40,40),200,150);       // display center part of image

    win.attach(c);
    win.attach(c2);
    win.attach(c3);
    win.attach(c4);
    win.attach(c5);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);
    cal.move(500,50);
    
    Text graph(Point(200,225), "Graph code");
    graph.set_color(Color::black);
    graph.set_font_size(18);
    graph.set_font(Graph_lib::Font::times_bold);
    //graph.set_font(Font::times_bold);
    win.attach(graph);


    win.set_label("Canvas #12");
    win.wait_for_button();               // Display!
} 
catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}

//------------------------------------------------------------------------------
