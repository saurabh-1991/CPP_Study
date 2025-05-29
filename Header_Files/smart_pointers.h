#pragma once
#include<iostream>

class smartPointers {
private:
	int x;
	double d;
public:
	smartPointers(int a,double b) : x{a},d{b}		//Custom Constructor: Intitializer list
	{
		std::cout << "[SmartPointers]Constructor called" << std::endl;
	}
	~smartPointers() {
		std::cout << "[SmartPointers]Destructor called" << std::endl;
	}
	const void get_data() { std::cout << "x =" << x << ", d =" << d << std::endl; }
	
};

void smart_pointer_tests();