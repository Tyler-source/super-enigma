#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/*
Polynomial class represents the mathematical polynomial of the form Ax^2 + Bx + C 
aswell as higher degree polynomials.
The polynomial class contains a vector of the constants for each degree.
the following functions have been defined:
 -- add : adds two polynomials 
 -- sub : subtracts two polynomials
 -- mult : multiplys two polynomials
 -- evaluate : returns the value of the polynomial for a given x.
 -- find roots : finds the roots of an degree 2 or less polynomial via
                the quadratic formula.
 -- display : Prints the polynomial with its respective constants.   
*/
class polynomial {
public:
    //Contructor , assigns passed vector as the constants object
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
    // adds the vectors of a polynomial and returns it in a new polynomial
    polynomial add(polynomial& p){
        vector<double> v1 = this->constants;
        vector<double> v2 = p.getConstants();
        vector<double> v3(v1.size());
        for (int i = 0; i < v2.size();i++ )
            v3[i] = v1[i] + v2[i];
        polynomial p3 (v3);
        return p3;
    }
    // subtracts the vectors of a polynomial and returns it in a new polynomial
    polynomial sub( polynomial p){
        vector<double> v1 = this->constants;
        vector<double> v2 = p.getConstants();
        vector<double> v3(v1.size());
        for (int i = 0; i < v2.size();i++ )
            v3[i] = v1[i] - v2[i];
        polynomial p3 (v3);
        return p3;
    }
    //multiplies the vector of the passed polynomial by all elements of the called and returns the result.
    polynomial mult(polynomial p){
        vector<double> v1 = this->constants;
        vector<double> v2 = p.getConstants();
        vector<double> v3(v1.size()+v2.size());
        for (int i = 0; i < v1.size();i++ ){
            for(int j = 0; j < v2.size();j++){
                v3[i+j] = v1[i]+v2[j];
            }
        }
        polynomial p3 (v3);
        return p3;
    }
    // Applies the math of the constant multiplied by the given x to the power of its degree , tallied and returned
    double evaluate(double x){
        double result = 0;
        for (int i = 0 ; i < this->constants.size();i++){
            result += constants[i] * pow(x,i);
        }
        return result;
    }
    //calculate the discriminant of a degree 2 polynomial and returns the roots found by th quadratic equation.
    void findRoots(){
        polynomial p = *this;
        if(p.getConstants().size() <= 3){
            vector<double>  v = p.getConstants();
            //variables for the quadratic formula
            double c = v.at(0);
            double b = v.at(1);
            double a = v.at(2);
            double descriminant = sqrt(pow(b,2) - (4*a*c));
            //if descriminant < 0 then no roots. 
            if(descriminant < 0){
                cout << "Roots are Imaginary";
            }
            else{
                double root1 = (-b - descriminant) / (2 * a) ;
                double root2 = (-b + descriminant) / (2 * a) ;
                cout << "The roots are x1=" << root1 << " and x2=" << root2;
            }
        }
        else{
            cout << "Cannot find the root of a polynomial of degree 3 or more.";
        }
        cout << "\n";
    }
    //prints the constants with variable x and assosiated degrees to form a polynomial
    polynomial display(){
        polynomial p = *this;
        vector<double> v = p.getConstants();
        for (int i = 0; i < v.size(); i++){
            if(i+1 >= v.size()){
                if (i == 0)
                    cout << v[i];
                else
                    cout << v[i] <<"x^" << i;
            }
            else {
                if (i == 0)
                    cout << v[i] << " + ";
                else
                    cout << v[i] <<"x^" << i << " + ";
            } 
        }
        cout << "\n";
    }
private:
    const vector<double> constants;  
};
int main(){
    // test cases 
    vector<double> array1 = {5, 0, 3.5, 16, -2};
    vector<double> array2 = {3, 7, 4};
    polynomial P1 (array1);
    polynomial P2 (array2);
    polynomial newP = P1.add (P2);
    P1.display();
    P2.findRoots();
    cout << "the value of the polynomial is" << newP.evaluate(5) << endl;
    return 0;
}