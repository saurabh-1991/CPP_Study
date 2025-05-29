#pragma once
#include<iostream>
#include<string>

/*explicit:-
The explicit keyword in C++ is used to prevent implicit type conversions when calling constructors.
It ensures that the constructor can only be called with an explicit cast or direct initialization.
This can help prevent unintended behavior and make code more readable.*/

class rule_of_five {
private:
	std::string name;
	int value;
public:
	/*[1] Default Parameterized Constructor */
	explicit rule_of_five(std::string n) : name{ n }, value{0} {
		std::cout << "[0]Default Constructor Called" << std::endl;
	};
	/*[2] Custom Copy Constructor*/
	rule_of_five(const rule_of_five& rhsObj) : name{rhsObj.name}, value{rhsObj.value} {
		std::cout << "[1]Copy Constructor Called" << std::endl;
	}
	/*[3] Copy Assignment Operator*/
	rule_of_five& operator=(const rule_of_five& rhsObj) {
		name = rhsObj.name;
		value = rhsObj.value;
		std::cout << "[2] Copy Assignment Operator = Called" << std::endl;
		return *this;
	}
	/*[4] Move Constructor */
	rule_of_five(rule_of_five&& mvConstructorObj) noexcept : name{ std::move(mvConstructorObj.name) }, value{0} {
		std::cout << "[3] Move Constructor Called" << std::endl;
	}
	/*[5] Move Assignment Operator */
	rule_of_five& operator=(rule_of_five&& mvOperatorObj) noexcept {
		name = std::move(mvOperatorObj.name);
		value = mvOperatorObj.value;
		mvOperatorObj.value = 0;
		std::cout << "[4] Move assignment operator called" << std::endl;
		return *this;
	}
	void printValue() const {
		std::cout << "Name: " << name << std::endl;
		std::cout << "value : " << value << std::endl;
	}
	~rule_of_five() {
		std::cout << "[5] Destructor Called" << std::endl;
	}
};

void test_rule_of_five();