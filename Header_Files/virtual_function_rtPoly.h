#pragma once
#include<iostream>
#include<string_view>

/* Virtual Function 
A virtual function is a special type of member function that, when called,
resolves to the most-derived version of the function for the actual type of the object being referenced or pointed to.

A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const)
and return type as the base version of the function.Such functions are called overrides.

To make a function virtual, simply place the “virtual” keyword before the function declaration.*/

/*
**string_view C++17***
* The modern C++ solution for read-only access of string data.
* std::string_view makes it easier to write generic code that can accept read-only references to character sequences,
regardless of the underlying container that holds that data. String parsing and tokenization workflows may improve performance
by avoiding unnecessary copies.
*/
class virtual_func_base {
public:
	virtual_func_base() { std::cout << "Base Class Constructor Called" << std::endl; }
	virtual ~virtual_func_base() { std::cout << "Base Class Destructor Called" << std::endl; }
	/*Member in base class with Same name or Signature */
	std::string_view getName() const {
		return "Base Class getName() called";
	}
	/**/
	virtual void MemberFunc() { std::cout << "Base Class MemberFunc() Called" << std::endl; }
};

class Derived : public virtual_func_base {
public:

	Derived(){ std::cout << "Derived Class Constructor Called" << std::endl; }
	~Derived() { std::cout << "Derived Class Destructor Called" << std::endl; }
	/*Member in Derived class with Same name or Signature as in Base Class */
	std::string_view getName() const {
		return "Derived Class getName() called";
	}
	void MemberFunc() override { std::cout << "Derived Class MemberFunc() Called" << std::endl; }
};

/* Abstract Class / Function
In programming, an abstract class in C++ has at least one pure virtual function by definition.
In other words, a function that has no definition. The abstract class's descendants must define the pure virtual function;
otherwise, the subclass would become an abstract class in its own right.
*/

class Graphics_Render {
public:
	virtual void Draw() = 0;	//Pure Virtual Function
	virtual void Update() = 0;	//Pure Virtual Function

};

class OpenGL : public Graphics_Render {
	void Draw() override {
		std::cout << "OpenGL::Draw()" << std::endl;
	}
	void Update() override {
		std::cout << "OpenGL::Update()" << std::endl;
	}
};

class Vulkan : public Graphics_Render {
	void Draw() override {
		std::cout << "Vulkan::Draw()" << std::endl;
	}
	void Update() override {
		std::cout << "Vulkan::Update()" << std::endl;
	}
};

void test_abstract_class() {
	std::cout << "*** Abstract Class Test (Using Pure Virtual Function) ***"<<std::endl;
	Graphics_Render* render{ new Vulkan };		// base class 
	render->Draw();
	render->Update();
	render =  new OpenGL ;
	render->Draw();
	render->Update();
	/* Cannot Create instance of Base Class (Abstract class) */
	//Graphics_Render renderBase ;
	//std::cout << "Error In Creating Instance of Base class in Abstract Class\n";
}

void test_virtual_function() {
	std::cout << "*** Virtual Function Test ***" << std::endl;
	std::cout << "Expt 1 : BaseClass Pointer Pointing BaseClass" << std::endl;
	virtual_func_base* BaseClassObj = new virtual_func_base;
	std::cout<<BaseClassObj->getName()<<std::endl;
	delete BaseClassObj;
	std::cout << "Expt 2 : BaseClass Pointer Pointing DerivedClass" << std::endl;
	virtual_func_base* BaseClassObj2 = new Derived;
	std::cout << BaseClassObj2->getName() << std::endl;
	delete BaseClassObj2;
	std::cout << "Result:" << std::endl<<"------------------------"<<std::endl;
	std::cout << "as observed in above getname() function defined in both class (base & Derived) \ncompiler executes everytime from Base Class"<< std::endl;
	std::cout << "Expt 3 [Using Virtual] : BaseClass Pointer Pointing Base Class" << std::endl;
	virtual_func_base* BaseClassObj3 = new virtual_func_base;
	BaseClassObj3->MemberFunc();
	delete BaseClassObj3;
	std::cout << "Expt 4 [Using Virtual] : BaseClass Pointer Pointing Derived Class" << std::endl;
	virtual_func_base* BaseClassObj4 = new Derived;
	BaseClassObj4->MemberFunc();
	delete BaseClassObj4;
}