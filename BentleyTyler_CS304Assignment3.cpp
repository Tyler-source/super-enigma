#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};
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
        node* n = new node;
        n->data = d;
        n->next = head;
        head = n;
    }
    void displayList(){
        if(head == nullptr)
            cout << "The list is empty\n";
        else{
            node* n = new node;
            n = head;
            while(n != nullptr){
                cout << n->data << " , ";
                n = n->next;
            }
        }
    }
    void mergesort();
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
 //theList.mergesort();
 theList.displayList();
} 