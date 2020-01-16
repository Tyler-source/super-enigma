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
    //Setters
    
    polynomial add(polynomial p1 , polynomial p2){
        vector<double> v1= p1.getConstants();
        vector<double> v2=p2.getConstants();

        vector<double> sum;
        for(int i = 0; i < count; i++)
        {
            /* code */
        }
        polynomial p3(sum);

        return p3

       
       
    }
private:
    const vector<double> constants;
        
}poly;

int main(){

    return 0;
}