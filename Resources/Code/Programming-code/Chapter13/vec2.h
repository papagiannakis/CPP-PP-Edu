//
//  vec2.h
//  
//
//  Created by George Papagiannakis on 29/4/14.
//
//

#ifndef ____vec2__
#define ____vec2__

#include <iostream>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
//
//  vec2.h - 2D vector
//

struct vec2 {
    
    float  x;
    float  y;
    
    //
    //  --- Constructors and Destructors ---
    //
    
    vec2( float s = float(0.0) ) :
	x(s), y(s) {}
    
    vec2( float xx, float yy ) :
	x(xx), y(yy) {}
    
    vec2( const vec2& v )
	{ x = v.x;  y = v.y;  }
    
    //
    //  --- Indexing Operator ---
    //
    
    //float& operator [] ( int i ) { return *(&x + i); }
    //const float operator [] ( int i ) const { return *(&x + i); }
    
    //
    //  --- (non-modifying) Arithematic Operators ---
    //
    
    vec2 operator - () const // unary minus operator
	{ return vec2( -x, -y ); }
    
    vec2 operator + ( const vec2& v ) const
	{ return vec2( x + v.x, y + v.y ); }
    
    vec2 operator - ( const vec2& v ) const
	{ return vec2( x - v.x, y - v.y ); }
    
    vec2 operator * ( const float s ) const
	{ return vec2( s*x, s*y ); }
    
    vec2 operator * ( const vec2& v ) const
	{ return vec2( x*v.x, y*v.y ); }
/*
    vec2 operator / ( const float s ) const
    {
        float r = float(1.0) / s;
        return (*this) * r;
    }
*/
    
    /* 
     //as they don't know the friend specifier yet, better define it outside
     // as it is also in the Date example in 10.8.cpp exercise
    friend std::ostream& operator << ( std::ostream& os, const vec2& v )
    {
        return os << "( " << v.x << ", " << v.y <<  " )";
    }
     */
};

std::ostream& operator << ( std::ostream& os, const vec2& v )
{
    return os << "( " << v.x << ", " << v.y <<  " )";
}

#endif /* defined(____vec2__) */
