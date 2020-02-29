#include<iostream>

using namespace std;

//node of a link list , Has a integer data value 
//and a pointer to the next node in the list
struct node
{
    int data;
    node* next;
};
//Class of LinkedList structures based of nodes that point to each other,
// implements various methods to enable mergesort to be performed on the list
// includes print method.
class LinkedList{
private:
node* head ;
public:
    //constructor
    LinkedList(){
        head = nullptr;
        
    }
    //getter
    node* getHead(){
        return head;
    }
    //setter
    void setHead(node* h){
        head = h;
    }
    //creates node , changes to head , assigns old node to next in list
    void insertFirst(int d){
        node* n = new node;
        n->data = d;
        n->next = head;
        head = n;
    }
    //loop to print all elements in the list.
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
        cout << "\n";
    }
    //Method for mergesort, iterates 2 pointers , one at 1 node per iteration other at 2.
    //first node will return midpoint of the list when 2nd reaches the end.
    void splitList( node** front , node** back){
        node* s = head;         //single iterating pointer
        node* d = head->next;   //double iterating pointer

        while (d!= nullptr){
            d = d->next;
            if(d != nullptr){
                d = d->next;
                s = s->next;
            }
        }
        *front = head;
        *back = s->next;
        s->next = nullptr;
    }
    //merges two sorted lists ,
    // returns the smaller node and recursively calls for the next node.
    node* merge(node* n1 , node* n2){
        node* result = nullptr;
        if(n1 == nullptr)
            return n2;
        else if (n2 == nullptr) 
            return n1;

        if (n1->data >= n2 ->data){
            result = n2;
            result->next = merge(n1 , n2->next);
        }
        else{
            result = n1;
            result->next = merge(n1->next,n2);
        }
        return result;
    }
    //mergesort method , recursively called on the two split lists.
    // until only one element remains the calls merge. 
    void mergesort(){
        node* h;
        node* m;

        if (head == nullptr || head->next ==nullptr)
            return;

        splitList(&h, &m);
        
        LinkedList first;
        LinkedList second;
        first.setHead(h);
        second.setHead(m);

        first.mergesort();
        second.mergesort();
        head = merge(first.getHead(),second.getHead());
    }
};
//Driver Function.
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