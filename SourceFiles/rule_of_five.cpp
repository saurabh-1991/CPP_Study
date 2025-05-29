#include"rule_of_five.h"

void test_rule_of_five() {
	std::cout << "*** Rule Of Five Test ***" << std::endl;
	rule_of_five obj1{ "Rule_of_five" };		// Default Constructor
	obj1.printValue();
	rule_of_five obj2 = obj1;					// Copy Constructor
	obj2.printValue();
	rule_of_five obj3{ std::move(obj1) };
	obj3.printValue();
	rule_of_five obj4{ "Modified Value" };
	obj4.printValue();
	obj4 = obj3;
	obj4.printValue();
	rule_of_five obj5{ "Move Assignment Operator" };
	obj5.printValue();
	obj5 = std::move(obj4);
	obj5.printValue();
	//rule_of_five obj3{ obj2 };

}