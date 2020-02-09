#include <iostream>
#include <string.h>
#include<stack>

using namespace std;

class Expression {
    public:
        Expression(string& input, int dir){
            if (dir == 1)   
                input = infix;
            else if (dir == 2)
                input = postfix;
        }   
        //Denote Hiearchy of Operators.
        int preced(string oper){
            if(oper == "+" || oper == "-") return 1;
            else if (oper == "*" || oper == "/") return 2;
            else if (oper =="^") return 3;
            else return 0;
        }
        string inToPost(string& input){
            cout << "Converting in to Post \n";
            stack<string> stk;                      //Create Stack
            stk.push("#");                          //Place Holder
            string postfix ="";                     //Create Output

            //Loop to continue until input string is empty,
            //everything will be on stack or in the output
            while (!input.empty()){
                cout << "the string is not empty \n";                
                int pos = input.find(" ");
                string str = input.substr(0, pos);

                if (isdigit(str.front()))
                    postfix += str;
                else if(str == "(")
                    stk.push(str);
                else if(str == "^")
                    stk.push(str);
                else if(str == ")"){
                    while(stk.top() != "#" && stk.top() != "(") {
                    postfix += stk.top(); //store and pop until matching (
                    stk.pop();
                    }
                }
                else{
                    if (preced(str) > preced(stk.top()))
                        stk.push(str);
                    else{
                        while(stk.top() != "#") {
                            postfix += stk.top();
                            stk.pop();
                        }
                        stk.push(str);
                    }
                    stk.push(str);
                } 
            }
            while(stk.top() != "#"){
                postfix += stk.top();
                stk.pop();
            }
            //ERROR: POSTFIX SEEMS TO BE empty
            //FOLLOW WORKFLOW TO ID Issue.
            return postfix;
        }
        string PostToIn();
        double evaluate();



    private:
        string infix;
        string postfix;
};


int main(){
    cout << "Please Enter Expression seperated by spaces (Ex: \"x y + ( z ^ w ) \")";
    string input;
    cin >> input;
    Expression string = Expression(input , 1);
    string.inToPost(input);
    cout << input;
    return 0;
}