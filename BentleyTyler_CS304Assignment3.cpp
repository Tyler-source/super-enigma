#include<iostream>

using namespace std;

class LinkedList{
private:
node* head ,* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    //TODO
    void insertFirst(int d){
        if( head == nullptr){
            head-> data = d;
        }
        else{
            
        }
    }
    void displayList();
    void mergesort();
};
struct node
{
    int data;
    node* next;
};


int main() {
 LinkedList theList;
 theList.insertFirst(44);
 theList.insertFirst(88);
 theList.insertFirst(66);
 theList.insertFirst(22);
 theList.insertFirst(55);
 theList.insertFirst(11);
 theList.insertFirst(33);
 theList.insertFirst(99);
 theList.displayList();
 theList.mergesort();
 theList.displayList();
} 