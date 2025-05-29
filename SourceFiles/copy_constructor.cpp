#include"copy_constructors.h"

/*
* Shallow Copy:
Mechanism:
A shallow copy creates a new object and copies the values of the original object's member variables into the new object. 
Pointers:
If the original object contains pointers to dynamically allocated memory, the shallow copy will simply copy the pointers themselves, not the data they point to. 
Consequences:
This means that the original and copied objects will both point to the same memory locations for dynamically allocated data. Changes to the data through one object will affect the other, as they are both manipulating the same underlying data. 
Default Copy Constructor:
The default copy constructor in C++ performs a shallow copy. 
*/
void test_shallow_cpy() {
    using namespace std;
	// calling the normal constructor
	shallowcpy obj1(10);
	// calling default copy constructor of compiler (Shallow Copy)
	shallowcpy obj2 = obj1;
    cout << "Before value change - " << endl;

    // printing the values, assigned by constructors
    cout << "obj1.var = " << obj1.getData() << endl;
    cout << "obj2.var = " << obj2.getData() << endl;

    obj1.setData(20);

    cout << "\nAfter value change - " << endl;

    // printing the values, assigned by constructors
    cout << "obj1.var = " << obj1.getData() << endl;
    cout << "obj2.var = " << obj2.getData() << endl;

    // since we did shallow copy as we didnt make any
    // user defined copy constructor
    // change in obj1 is reflected in obj2

}

/*
Deep Copy:
Mechanism:
A deep copy creates a new object and recursively copies all member variables, including dynamically allocated memory, into the new object.
Pointers:
For pointers to dynamically allocated memory, the deep copy allocates new memory and copies the data from the original object's memory into this new memory.
Consequences:
The original and copied objects are completely independent. Changes to one object's data will not affect the other object, as they now have separate memory allocations for all data, including dynamically allocated data.
Custom Copy Constructor:
To achieve deep copy, you need to define your own copy constructor and assignment operator.
*/
void test_deep_cpy() {
    using namespace std;
    cout << "Deep Copy Test " << endl;
    // calling the normal constructor
    DeepCpy obj1(10);
    // calling user defined copy constructor (Deep Copy)
    DeepCpy obj2 = obj1;
    cout << "Before value change - " << endl;

    // printing the values, assigned by constructors
    cout << "obj1.var = " << obj1.Data << endl;
    cout << "obj2.var = " << obj2.Data << endl;

    obj1.Data = 20;

    cout << "\nAfter value change - " << endl;

    // printing the values, assigned by constructors
    cout << "obj1.var = " << obj1.Data << endl;
    cout << "obj2.var = " << obj2.Data << endl;

    // since we did deep copy using user defined copy constructor
    // change in obj1 is not reflected in obj2

}

/*
* Copy Constructor
*/
void copy_constructor_tests() {
    std::cout << "copy constructor test " << std::endl;
    copy_constructor cpy_obj1(20,30);
    cpy_obj1.print_num();
    copy_constructor cpy_obj2 = cpy_obj1;
    cpy_obj2.print_num();
}
void shallowCpy_deepCpy_test() {
    test_shallow_cpy();
    test_deep_cpy();
}