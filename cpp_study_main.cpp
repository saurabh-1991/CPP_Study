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
#include"Arrays/MoveZeroes.hpp"
#include"Arrays/MajorityElements.hpp"
#include"string/stringCompression_433.hpp"
#include "DSA/BigONotation/big_o_notation.h"

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
    //runSimpleSingleton();

    // Test MoveZeroes
    // MoveZeroes mz;
    // vector<int> nums = {0, 1, 0, 3, 12};
    // //mz.movezeros_sol1(nums);
    // mz.movezeros_sol2(nums);
    // Test MajorityElements
    // MajorityElements me;
    // std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    // int majority = me.majorityElement_sol1(nums);
    // std::cout << "Majority element: " << majority << std::endl;
    // Test Compress String
    std::vector<char> chars = {'a','a','b','b','c','c','c'};
    int newLength = StringCompression(chars);
    std::cout << "Compressed length: " << newLength << std::endl;
}

