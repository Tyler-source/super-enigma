#include <iostream>
#include <vector>

using namespace std;

class polynomial {
public:
    //Contructor
    polynomial(vector<double> constArray)
        : constants(constArray){
        }
    //Copy Constructor
    polynomial(const polynomial& rhs)
        : constants(rhs.getConstants())
    {};
    //Getters
    vector<double> getConstants()const {
        return constants;
    }
    //Setters - not working
    void setConstants(vector<double> v){
       // constants = v;
    }
    void add(polynomial p){
        vector<double> v1 = constants;
        vector<double> v2 = p.getConstants();
        
        for (int i=0; i < v2.size();i++){
            v1[i] += v2[i];
        }
        
    }
    polynomial sub( polynomial p){

    }
    polynomial mult(polynomial p){

    }
    polynomial display(){

    }
    polynomial evaluate(double x){

    }
    polynomial findRoots(){


    }

private:
    const vector<double> constants;
        
}poly;

int main(){

    return 0;
}