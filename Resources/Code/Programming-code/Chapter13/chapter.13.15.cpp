
//
// This is example code from Chapter 13.15 "Marks" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// modified for Sierpinski gasket by George Papagiannakis, UoC & FORTH
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities
#include "vec2.h"

const int NumPoints=5000;
//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Simple_window win(Point(100,100),600,400,"Marks");
    
    vec2 v1(100,100);
    vec2 v2(10,10);
    vec2 v3=v2+v1;
    std::cout<<"v3=v2+v1 is: "<<v3<<std::endl;
    
    
    vec2 points[NumPoints];
    // Specifiy the vertices for a triangle
    
    /*
                (200,50)
                *     *
             *          *
           *              *
         *                  *
    (100,300) * * * * * * * (300,300)
     
     */
    
    vec2 vertices[3] = {
        vec2( 100.0, 300.0 ), vec2( 200.0, 50.0 ), vec2( 300.0, 300.0 )
    };
    
    std::cout<<"Original triangle vertices[0] is: "<<vertices[0]<<std::endl;
    std::cout<<"Original triangle vertices[1] is: "<<vertices[1]<<std::endl;
    std::cout<<"Original triangle vertices[2] is: "<<vertices[2]<<std::endl;

    
    // Select an arbitrary initial point inside of the triangle
    points[0] = vec2( 200, 100 );
    
    // compute and store N-1 new points
    for ( int i = 1; i < NumPoints; ++i ) {
        int j = rand() % 3;   // pick a vertex at random
        
        // Compute the point halfway between the selected vertex
        //   and the previous point
        //points[i] = ( points[i - 1] + vertices[j] ) / 2.0;
        points[i] = ( points[i - 1] + vertices[j] ) * 0.5;
    }

    Marks pp("x");
    Marks sp(".");
/*
    pp.add(Point(100,100));
    pp.add(Point(150,200));
    pp.add(Point(250,250));
    pp.add(Point(300,200));
 */
    for(int i=0; i<3; ++i)
    {
        pp.add(Point(vertices[i].x, vertices[i].y));
    }
    
    for(int i=0; i<NumPoints; ++i)
    {
        sp.add(Point(points[i].x, points[i].y));
    }
    
    win.attach(pp);
    win.attach(sp);

    win.wait_for_button();       // Display!
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
