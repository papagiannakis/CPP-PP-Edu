#include "../std_lib_facilities.h"

double calculate_time(double height){
    double height_meters = height * 1000;
    return sqrt(2*height_meters/9.80665);
}

double calculate_distance(double velocity, double time){
    return velocity*time;
}

int main(){
    double height,velocity;
    
    cout<<"Please give initial velocity of vehicle in m/s: ";
    cin>> velocity;
    
    cout<<"Please give the height of wall in km: ";
    cin>> height;
    
    double time = calculate_time(height);
    double distance = calculate_distance(velocity, time)/1000;    
    cout<<"The ball will reach the ground after travelling: "<< distance<< " km and will fall for "<< time<< " seconds.";

}