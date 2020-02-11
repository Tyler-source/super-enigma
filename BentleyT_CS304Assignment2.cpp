#include <iostream>
#include <string.h>
#include <stack>
#include <cmath>

using namespace std;

class Expression {
    public:
        //contructor class
        Expression(string& input, int dir){
            if (dir == 1){ 
                infix = input;
                postfix = "";
            }
            else if (dir == 2){
                postfix = input;
                infix = "";
            }
        }   
        //Denote Hiearchy of Operators.
        int priority(char ch){
            if(ch == '+' || ch == '-') return 1;
            else if (ch == '*' || ch == '/') return 2;
            else if (ch == '^') return 3;
            else return 0;
        }
        string inToPost(){
            stack<char> stk;        //create a char stack to place operators in the form of chars
            stk.push('#');          //sentinel value             
            string postfix = "";        
            string::iterator it;    //iterator to go through every char of a the string 

            for(it = infix.begin(); it!=infix.end(); it++) {
                if(isalnum(char(*it)))
                    postfix += *it;      
                else if(*it == '(')
                    stk.push('(');
                else if(*it == '^')
                    stk.push('^');
                else if(*it == ')') {       //put all values from stack into postfix until matching brace.
                    while(stk.top() != '#' && stk.top() != '(') {
                        postfix += stk.top(); 
                        stk.pop();
                    }
                    stk.pop();          //remove the '(' from stack
                }else {                 //push based on priority.
                    if(priority(*it) > priority(stk.top()))
                        stk.push(*it); 
                    else {           //store and pop until higher priority is found
                        while(stk.top() != '#' && priority(*it) <= priority(stk.top())) {
                        postfix += stk.top();       
                        stk.pop();
                        }
                        stk.push(*it);
                    }
                }
            }
                //pop and store the rest , until sentinel is found.
            while(stk.top() != '#') {
                postfix += stk.top();        
                stk.pop();
            }
            return postfix;
        }
        //Postfix to Infix
        string PostToIn(){
            stack<string> stk;      //create string stack , since we will be storing string sub expressions
            for(int i = 0 ;postfix[i]!= '\0'; i++) {
                    //if number , push to stack
                if (isalnum(char(postfix[i]))){
                    string str(1,postfix[i]);
                    stk.push(str);
                }
                    //if not , pop 2 values off stack and push value1 "operand" value2.
                else{
                    string x = stk.top();
                    stk.pop();
                    string y = stk.top();
                    stk.pop();
                    stk.push("(" + x + postfix[i] + y + ")" );
                } 
            }
            //whats left on the stack is our infix
            return stk.top();
        }
        //Evaluate Function is not working, error when calling stod.
        double evaluate(){
            //Evaluate using postfix , so convert if currently infix 
            if (postfix.empty()){
                Expression expr(infix,1);
                postfix = expr.inToPost();
            } 
            //stack for variables
            stack<double> Dstk;
            double i;
            for(int i = 0 ;postfix.length()-1; i++) {
                //if its a number , push to stack 
                if (isalnum(char(postfix[i]))){
                    string str(1,postfix[i]);
                    double d = stod(str);
                    Dstk.push(d);
                }
                else{
                    //if an operator , pop 2 , perform the operation and push back to stack
                    double x = Dstk.top();
                    Dstk.pop();
                    double y = Dstk.top();
                    Dstk.pop();
                    switch(char(postfix[i])){
                        case '+': 
                            i = x+y;
                            Dstk.push(i);
                            break;
                        case '-': 
                            i = x-y;
                            Dstk.push(i);
                            break;
                        case '*': 
                            i = x*y;
                            Dstk.push(i);
                            break;
                        case '/': 
                            if (y == 0)
                                return -99;
                            i = x/y;
                            Dstk.push(i);
                            break;
                        case '^': 
                            i = pow(x,y);
                            Dstk.push(i);
                            break;
                    }
                }
            }
            //remaining value will be result of the expression
            return Dstk.top();
        }

        

    private:
        string infix;
        string postfix;
};

//driver code
int main(){
    cout << "Are you entering an infix or postfix expression? (1 = infix / 2 = postfix) : ";
    int dir;
    cin >> dir;
    cout << "Please Enter Expression (Ex: \" xyzw +-*/^ () \") :";
    string input;
    cin >> input;
    Expression expr = Expression(input , dir);
    string result;
    if(dir == 1)
       result = expr.inToPost();
    else
        result = expr.PostToIn();
    cout << result << "\n";
    //cout << "Expression result is : " << expr.evaluate();
    return 0;
}