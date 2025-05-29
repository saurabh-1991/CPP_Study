
#pragma once
#include<iostream>

class shallowcpy {
private:
	int* Data;
public:
	// Parmeterized constructor
	shallowcpy(int x) {
		Data = new int;
		*Data = x;
	}
	// setter
	void setData(int val) {
		*Data = val;
	}
	// getter
	int getData() {
		return *Data;
	}

	~shallowcpy() {
		delete Data;
	}
};
// the compiler would create its own hidden copy constructor
// as we have not created our own user defined copy constructor here
// shallow copy will happen i.e. objects variables etc will share memory

class DeepCpy {
private:
	
public:
	int Data;
	// Parmeterized constructor
	DeepCpy(int x) {
		Data = x;
	}
	// Overriding default copy constructor 
	// with user defind copy contructor
	DeepCpy(DeepCpy& obj) {
		Data = obj.Data;
	}
};

/*
* Copy Constructor :
* ------------------
A copy constructor is a constructor which can be called with an argument of the same class type and copies the content of the argument
without mutating the argument.
*-------------------
* Syntax : 
* class-name ﻿(parameter-list ﻿);	(1)	
* class-name ﻿(parameter-list ﻿) function-body	(2)	
* class-name ﻿(single-parameter-list ﻿) = default;	(3)	(since C++11)
* class-name ﻿(parameter-list ﻿) = delete;	(4)	(since C++11)
*/
class copy_constructor {
	int num1{ 1 };
	int num2{ 2 };
public:
	//Default Constructor
	copy_constructor(int x, int y) : num1(x), num2(y) {
		std::cout << "Default Constructor" << std::endl;
	}
	//copy constructor
	copy_constructor(copy_constructor& ref_copy) : num1{ref_copy.num1}, num2{ref_copy.num2} {
		std::cout << "Custom Copy Constructor" << std::endl;
		/*Normal Way of Initialization */
		//num1 = ref_copy.num1;
		//num2 = ref_copy.num2;

	}
	void print_num() {
		std::cout << "num1 : " << num1 << " num2 : " << num2 << std::endl;
	}
};

void copy_constructor_tests();
void shallowCpy_deepCpy_test();
void test_shallow_cpy();
void test_deep_cpy();