// cpp_testapp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"function_pointers.h"
#include"smart_pointers.h"
#include"copy_constructors.h"
#include"operator_overloading.h"
//#include"problem1.h"
#include"rule_of_five.h"
#include"virtual_function_rtPoly.h"
#include"singleton.h"

int main()
{
    std::cout << "Hello World!\n";
    //function_pointer_test();
    //smart_pointer_tests();
    //shallowCpy_deepCpy_test();
    //copy_constructor_tests();
    //test_operatorOverloading();
    //execute_problem1();
    //test_rule_of_five();
    //test_virtual_function();
    //test_abstract_class();
    runSimpleSingleton();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
