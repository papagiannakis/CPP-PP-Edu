#include "../std_lib_facilities.h"

double vector_magnitude(double a, double b, double c){
    try{
        double inside_sqrt = a*a + b*b+ c*c;
        if(inside_sqrt!=0) return sqrt(inside_sqrt);
        else throw 0;
    }catch(int e){
        return e;
    }
}

double vector_magnitude(double a, double b){
    try{
        double inside_sqrt = a*a + b*b;
        if(inside_sqrt!=0) return sqrt(inside_sqrt);
        else throw 0;
    }catch(int e){
        return e;
    }
}

int main(){
    int dims;
    double a,b,c;
    cout <<"Please enter dimensions of vector: ";
    try{
        cin >> dims;
        if(!cin) throw -1;
        if(dims ==2){
            try{
                cout <<"Please enter values of vector: ";
                cin >> a >> b;
                if(!cin) throw -1;
                cout<< "The magnitude of the vector is : " << vector_magnitude(a,b)<< endl;
            }catch(int e) {
                cerr<< "Bad number input ("<< e<< ")."<<endl;
            }
        }else if(dims ==3){
            try{
                cout <<"Please enter values of vector: ";
                cin >> a >> b >> c;
                if(!cin) throw -1;
                cout<< "The magnitude of the vector is : " << vector_magnitude(a,b,c)<< endl;
            }catch(int e) {
                cerr<< "Bad number input ("<< e<< ")."<<endl;
            }
        }else throw -1;
    }catch(int e){
         cerr<< "Only dimension 2 and 3 are supported ("<< e<< ")."<<endl;
    }

    return 0;
    
}


