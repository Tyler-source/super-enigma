#include <iostream>
#include <cmath>

using namespace std;
//node class to be used to build tree , data is the char of the oper(ator/and),
//left and right are pointers to nodes to make tree connections.
struct node {
    char data;
    node* left;
    node* right;
};

class ExpressionTree{
    private:
        string prefix;
        node* root;
        //function to check is a character is an expression operator
        bool isOperator(char c){
            switch(c){
                case '+':case '-':case '*':case '/': return true;break;
                default: return false;break;
            }
        }
        //utility function to create a new node
        node* newNode(char ch){
            node* n = new node;
            n->data = ch;
            n->left = nullptr;
            n->right = nullptr;
            return n;
        }
    public:
        //constructor for the class
        ExpressionTree(string& expr){
            prefix = expr;
            root = nullptr;
        }
        //getter
        node* getRoot(){
            return root;
        }
        //recursive function taking a string of characters
        //and distributing into an expression tree depending what the character is
        node* createtree(string& expr){
            node* x;
            //create root of empty tree, since expr is a prefix ,
            // first char is always an operator.
            if( root == nullptr){
                x = newNode(expr.at(0));
                root = x;
                expr = expr.substr(1);
                x->left = createtree(expr);
                x->right = createtree(expr);
                return x;
                
           }
           //return an operand as leaf of a (sub)tree
           if (!isOperator(expr.at(0))){
               x= newNode(expr.at(0));
               expr = expr.substr(1);
               return x;
           }
           //return operator as a subtree , recursively to the left and right
           else{
                x= newNode(expr.at(0));
                expr = expr.substr(1);
                x->left = createtree(expr);
                x->right = createtree(expr);
                return x;
           }
        }
        // prefix-traversing the expression tree
        void preTraverse(node* n){
            if (n){
                cout << n->data;
                preTraverse(n->left);
                preTraverse(n->right);
            }
        }
        // infix-traversing the expression tree
        void inTraverse(node* n){
            if (n){
              
                inTraverse(n->left);
                /*
                if (!isOperator(n->data))
                    cout << "(";
                */
                cout << n->data;
                inTraverse(n->right);
                /*
                if (!isOperator(n->data))
                    cout << ")";
                */
            }
        }
        // postfix-traversing the expression tree
        void postTraverse(node* n){
            if (n){
                postTraverse(n->left);
                postTraverse(n->right);
                cout << n->data;
            }
        }
};
//driver program. 
int main(){
    string expr = "/*+914+53";
    ExpressionTree exTree = ExpressionTree(expr);
    exTree.createtree(expr);
    cout << "PREFIX  : ";
    exTree.preTraverse(exTree.getRoot());
    cout << "\n";
    cout << "INFIX   : ";
    exTree.inTraverse(exTree.getRoot());
    cout << "\n";
    cout << "POSTFIX : ";
    exTree.postTraverse(exTree.getRoot());
    cout << "\n";
    return 0;
}