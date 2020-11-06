#include <iostream>
#include<time.h>
#include<vector>
using namespace std;

/*
TODO:

LIST
*/

//Node Structure used in the implementation of BST.
//Contains some data and a link to a left node and a right node.
struct node{
    int data;
    node* left;
    node* right;
};
node* newNode(int num){
    node* n = new node();
    n->data = num;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}
class List{
    private:
        vector<int> list;
        int size;
    public:
        List(int inputSize){
            size = inputSize;
        }
        int getSize(){
            return size;
        }
        void insert(int num){
            list.push_back(num);
        }
        void display(){
            for(int i = 0;i<size;i++){
                cout << list[i] << " ";
            }
            cout << "\n";
        }
        int getElement(int pos){
            return list[pos];
        }
        bool compare(List list2){
            for (int i =0; i < size ; i++)
                if(list[i] != list2.getElement(i))
                    return false;
            return true;
        }
};

class Heap{
    private:
        int currentsize{};
        int capacity;
        vector<int> array = {-999};
        
        int parent(int i){return i>>1;};
        int left (int i){return i << 1;};
        int right (int i){return (i<<1)+1;};

    public:
        Heap(int num){capacity = num;}
        bool isEmpty()const{ return currentsize == 0;};
        int getMax() const{return array[1];};
        void bubbleup(int i){
            if(i > currentsize)
                return;
            if (i == 1)
                return;
            if (array[i] > array[parent(i)])
                swap(array[parent(i)],array[i]);
            bubbleup(parent(i));
        }
        void bubbledown(int i){
            if(i > array.size())
                return;
            int tmp = i;
            if(left(i) <= currentsize && array[i] < array[left(i)])
                tmp = left(i);
            if(right(i) <= currentsize && array[tmp] < array[right(i)])
                tmp = right(i);
            if( tmp != i) {
                swap(array[i],array[tmp]);
                bubbledown(tmp);
            }
        }
        void insert(int num){
            if(currentsize +1 >= array.size())
                array.push_back(0);
            array[++currentsize] = num;
            bubbleup(currentsize);
            return;
        }
        int deleteHighest(){
            int top = array[1];
            swap(array[1],array[currentsize--]);
            bubbledown(1);
            return top;
        }
        void HeapSort(){
            while(currentsize != 0){
                swap(array[1],array[currentsize]);
                currentsize--;
                bubbledown(1);
            }
        }
        void heapToList(List& list){
            for (int i = 1; i < array.size();i++)
                list.insert(array[i]);
        }
        void print(){
            for(int i = 0;i <= currentsize;i++){
                cout << array[i] << " ";
            }
            cout << "\n";
        }
};
class Tree{
    private:
        node* root = nullptr;
        
    public:
        node* getRoot(){
            return root;
        }
        void insert(int num){recursiveInsert(num,root);}
            void recursiveInsert(int& num, node*& t){
            if (t == nullptr){
                t = newNode(num);
            }
            else if(num < t->data){
                
                recursiveInsert(num, t->left);
            }
            else if(num >= t->data){
                
                recursiveInsert(num , t->right);
            }
            
        }
        
        int deleteHighest(){
            int max = findMax(root)->data;
            recursiveRemove(nullptr,root);
            return max;
        }
        node* findMax(node* t){
            if (t != nullptr)
                while (t->right != nullptr)
                    t = t->right;
            return t;
        }
        node* findmin(node* t){
            if (t== nullptr)
                return nullptr;
            else if (t->left == nullptr)
                return t;
            return findmin(t->left);
        }
        // int remove(int num){
        //    recursiveRemove(num,nullptr,root);
        //    return num;
        // }
        void recursiveRemove(node* parentT, node*& t){
            if(t == nullptr)
                return;
            if (t->right != nullptr)
                recursiveRemove(t,t->right);
            if (t->left != nullptr){
                parentT->right = t->left;
                free(t);
            }
            else{
                free(t);
            }
        }
        void print(node* node){
            if(node){
                print(node->left);
                cout << node->data << " ";
                print (node->right);
            }
            else{return;}
        }
        bool isEmpty(){
            return (root == nullptr);
        }
        void inorder(List& list){inorder2(list, root);}
            void inorder2(List& list, node* n){
                if (n){
                    inorder2(list,n->left);
                    list.insert(n->data);
                    inorder2(list,n->right);
                }
            }
};


int main(){

    int n = 100;
    // Generating n rand numbers and storing them in List operations
    List operations (n); // an List object of size n
    srand(time(0));
    for (int i=0; i<n; i++){
        int number = rand() % 100;
        operations.insert(number % 100);
    }

    cout << "Random elements:" << endl;
    operations.display();

    Heap H(n); // Heap object of size n
    Tree T; // Tree object

    // Insert the random elements in the Heap and the Tree
    for (int i=0; i<n; i++){
        H.insert(operations.getElement(i));
        T.insert(operations.getElement(i));
    }

    List list1(n); // used to store the result of deleteHighest from Heap
    List list2(n); // used to store the result of deleteHighest from Tree
    int i = 0;
    // Applying deleteHighest on Heap and Tree
    while (!H.isEmpty())
        list1.insert(H.deleteHighest());
    
    while (!T.isEmpty()){
        //cout << "Removal #" << i << "\n";
        //i++;
        list2.insert(T.deleteHighest());
    }
    cout << "tree deleting sucessful\n";
    // Displaying and comparing the two lists
    cout << "Deleted from the Heap:" << endl;
    list1.display();
    cout << "Deleted from the tree:" << endl;
    list2.display();
    if (list1.compare(list2))
        cout << "Equal lists" << endl << endl;
    else 
        cout << "Not equal" << endl << endl;

    // Restoring the Heap and the Tree
    Heap H2(n);
    Tree T2;
    for (int i=0; i<n; i++){
        H2.insert(operations.getElement(i));
        T2.insert(operations.getElement(i));
    }

    // Sorting Heap and Tree and storing results in two lists
    List heapList(n);
    H2.HeapSort();
    H2.heapToList(heapList); // copy the Heap array into a list "heaplist"
    List treeList(n);
    T2.inorder(treeList); // stores inorder sequence in list "treelist"

    // Displaying and comparing the two sorted lists
    cout << "Heapsort Display:" << endl;
    heapList.display();
    cout << "Inorder Display:" << endl;
    treeList.display();
    if (list1.compare(list2))
        cout << "Equal lists" << endl << endl;
    else 
        cout << "Not equal" << endl << endl;
    return 0;
}



// int deleteHighest(){
//             int high = findMax(root)->data;
//             remove(high,root);
//             return high;
//         }
//         node* findMax(node* t){
//             if (t != nullptr)
//                 while (t->right != nullptr)
//                     t = t->right;
//             return t;
//         }
//         node* findmin(node* t){
//             if (t== nullptr)
//                 return nullptr;
//             else if (t->left == nullptr)
//                 return t;
//             return findmin(t->left);
//         }
//         void remove(int& num, node* t){
//             if ( t == nullptr){
//                 return;
//             }
//             if(num < t->data){
//                     remove(num, t->left);
//             if(num > t->data)
//                     remove(num, t-> right);
//             else if(t->left != nullptr && t->right!= nullptr){
//                     t->data = findmin(t->right)->data;
//                     remove(t->data, t->right);
//             }
//             else{
//                     node* oldNode = t;
//                     t = (t->left != nullptr)?t->left:t->right;
//                     delete(oldNode);
//             }
//             }
//         }