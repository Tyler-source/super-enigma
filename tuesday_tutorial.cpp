
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

/*
insertion sort pseudocode
for j=2 to length(A)
f    key = A[j]
    i = j-1
    while i > 0 and A[i] > key
        A[i+1] = A[i]
        i=i-l
    A[i+1] = key
*/


/*
Functions
In c++ a function consists of: return type, name, list of zero or more parameters, and a body
Functions are executed through the call operator – a pair or parentheses following the function name
Example: function to print foo n times
Passing arguments to functions:
When the argument that we pass to the function is a reference, we are passing or calling by reference
When the argument value is copied, the parameter and argument are different value, passing or calling by value
Give example where you pass an int to foo (By value) and decrement foo
Passing a pointer to a function – passed by value, but the value is an address. Can use the address to change value
Passing arguments by reference:
Reminder: operations on a reference are operations on the object to which the reference refers
When we pass a reference to a function, the function can modify the value the reference points to
(the compiler implements references as pointers), but references have extra constraints
Two main reasons to use references when calling functions:
1)	Avoid copying – inefficient to copy large objects, containers when passing to function. String example
2)	Allow function to modify underlying object
When/why should you use references instead of pointers?
Rule of thumb: use references when parameter MUST refer to existing object, pointers when a NULL value is ok
You can always assume a reference will be non-null in c++, whereas this is not the case for pointers
*/
template <typename T> 
void insertionSort(vector<T>& A) {
    for (int j = 1; j < A.size(); j++) {
        T key = A[j];
        int i = j - 1;
        while (i > -1 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

int foo(int& input) {

    input++; 

    return input; 

}

/*
in C++, we use classes to define our own data types. we can create types to model concepts in problems we try to solve
a c++ class consists of its members – member variables, and member functions (Also called methods)
member functions and variables have privacy or visibility levels: public, private
every class has a constructor – a method that describes how an instance of a class is constructed // constructor
it is recommended to use the initialization list in the constructor // Student initializer list
initialization list is used to initialize the data members directly, to save time, and initialize const member variables
member functions have two types: accessor and mutators
accessor – examines but does not change state of its object: int getId()const{return value;}
mutator – mutates (Changes) the state of its object: void setId(int value){id=};
separation of interface and implementation – a separate .h files for declarations and a .cpp file for implementations
(for this course, we’ll just declare everything in a single .cpp file) – if you want you can use a .h but you aren’t required

Rule of 3: if a class defines one or more of the following, it should define all 3:
1)	Destructor – destroy the object (freeing the memory it occupies)
2)	Copy constructor – construct all the object’s members from corresponding members of cc. argument
3)	Copy assignment operator – assign all the object’s members from corresponding members of assignment operator’s argument

Rule of 5  - Move constructor - Move assignment operator
read more here: https://en.cppreference.com/w/cpp/language/rule_of_three

*/
class Student {
public:
    Student(string nm, int id, float avg) // constructor with initializer list and empty body
        : name(nm), studentID(id), overallAverage(avg) {
    }
    // copy constructor - used when a 'student' object is initialized with an existing student
    // ex: Student s = existingStudent; 
    Student(const Student& rhs) 
        :name(rhs.getName()),studentID(rhs.getStudentID()),overallAverage(rhs.getOverallAverage())
    {}

    // assignment operator. used when existing student is assigned using another existing student
    // ex: 
    // Student s(name,id,avg); 
    // Student t(name,id,avg); 
    // s = t; 
    Student& operator=(const Student& rhs) {
        // cannot re-assign name or studentID, because they are const
       // name = rhs.getName(); 
       // studentID = rhs.getStudentID(); 

        //can re-assign overall average, because it isn't const
        overallAverage = rhs.getOverallAverage(); 

        return *this; 
    };

    ~Student() {
        //destructor - here, you would delete objects you allocated on the 'heap' using 'new' 
        //for this simple class, we don't need to
    }

    //comparison operator, so we can sort students
    bool operator>(const Student& rhs) {
        if (rhs.getOverallAverage() > overallAverage)
            return false;
        else return true; 
    }

    //accessor function
    string getName()const { return name; }

    //accessor function - does not change value! 
    int getStudentID() const{
        return studentID; 
    }
    //accessor function - does not change value! 
    float getOverallAverage() const { return overallAverage;  }

    // mutator function - updates value
    void updateAverage(float newAverage) {
        overallAverage = newAverage; 
    }

private: // private fields of student
    const string name; 
    const int studentID; 
    float overallAverage; 
};



/*
Memory leaks, scope, and new - use Smart pointers! (unique_ptr, shared_ptr)
If you’re coming from java you may be tempted to use new
This is because new allocates memory on the heap, whereas if you don’t use new it goes on stack with local vars
Also, if you must use new, avoid using delete. Instead wrap the object in a smart pointer (will call delete automatically)
However, if you want to return a pointer to your object from the function, you must use new (use smart pointer)
*/
void createMemoryLeaks() {
    int* i = new int(10); // bad, will leak
    //unique_ptr<int> i (new int(25)); // good, will not leak 
    return; 
}


int main()
{
    // long 'for' loop to leak memory (use ctrl-alt-delete to watch RAM as this executes!)
    for (int i = 0; i < 100000000; i++)
        createMemoryLeaks(); 
    
    // we can create a list of students and sort them as we would with integers
    vector<Student> list = {Student("Asdf",1234,92),Student("Asdf2",1234,98),Student("Asdf3",1234,90)}; 
    insertionSort(list); 

    // an Object is a region of memory that can contain data and has a type

    /*

    Compound types
    A compound type is a type that is defined in terms of another type.
    Two important compound types in C++ are pointers and references
    A reference defines an alternative name for an object. A reference type refers to another type.
    Define a reference type using the ampersand symbol ‘&’
    int val = 100; int &refval = val; int & refval2; //error
    Ordinarily when we initialize a variable, the value of the initializer is copied into the object we are creating
    When we define a reference, instead of copying initializer’s value we bind the reference to its initializer
    Bind – associate a name with a given entity, so that uses of the name are uses of the name = use of underlying entity
    Int &refval2 = val; int &refval3 = val, etc. once initialized, reference remains bound to its initial object.
    Cannot rebind reference to different object, so references must be initialized.
    a reference is an alias. All operations on a reference are operations on the object to which it is bound.
    refval = 2; // assigns to the object to which refval refers to (val). int ii = refval; // same as ii = val;
    When we assign to a reference, we assign to the object to which the reference is bound. Same for fetching value of ref.
    int &refval4 = refval; // refval4 is bound to val, the object that refval is itself bound to.
    Reference type and object type to which reference refers must be the same:
    double pi = 3.14; int &piref = dval; // error, initializer must be an int object
    int &myref = 1; //error – initial value of reference to non-const must be an lvalue;

    An lvalue or “locator value” occupies some identifiable location in memory (ie, has an address)
    An rvalue is anything that isn’t an lvalue – something without an identifiable location in memory (Address)
    Example: int var; var = 4; assignment operation expects lvalue as left operand, var works because has address
    On the other hand, cannot do: 4 = var; (Expression must be a modifiable lvalue)
    In this case ‘4’ is just temporary result of an expression, has no memory address, (Resides in temporary cpu register

    Pointers 
    A pointer is a compound type that points to another type
    Like references, pointers are used for indirect access to other objects
    Unlike references, a pointer is an object in its own right. Pointers can be assigned and copied, and 
    A single pointer can point to several different objects throughout its lifetime. 
    Pointers need not be initialized at time of creation. 
    Use the ‘*’ symbol to declare pointer: int* p1, int* p2; double d1, *d2; //d1 is double, d2 pointer to double
    A pointer holds the address of another object. We get the address using the ‘&’ operator 
    int ival = 42; int* p = &ival; 
    Using pointers, can change either: 1) value at the address the pointer holds or 2) address the pointer holds
    1)	*pi = 0; 2) pi = &ival2; 
    */

    int val = 1; 
    int val2 = 2;
    int& refval = val; 
    int* valptr = &val; 
    *valptr = 2; 
    
    /*
    vector<float> A = { 21.1,2.5,6.6,3.2,1.4,6.2,1.4,3.2,2.4,1.1 };
    vector<float>& Aref = A; 
    insertionSort(Aref); 

    for (int i = 0; i < Aref.size(); i++)
        cout << Aref[i] << ",";
    cout << endl; 
    */
   
}
