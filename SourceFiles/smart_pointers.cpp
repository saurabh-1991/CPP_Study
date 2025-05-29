#include<memory>	/*Smart Pointers (Unique , Shared , Weak) */
#include"smart_pointers.h"

/*Unique Pointers
std::unique_ptr should completely own the object it manages, not share that ownership with other classes.
std::unique_ptr lives in the <memory> header
*/
void smart_pointer_tests() {

	/* C++ 11 Syntax*/
	std::cout << "Uinque Pointer Test " << std::endl;
	std::cout << "-------------------- " << std::endl;
	std::unique_ptr <smartPointers> unique_prt = std::unique_ptr<smartPointers>(new smartPointers(3,3.1432));
	unique_prt->get_data();
	/* C++ 14 Features */
	/*C++14 comes with an additional function named std::make_unique().
	This templated function constructs an object of the template type and initializes it with the arguments passed into the function.*/
	std::unique_ptr <smartPointers> unique_ptr_2 = std::make_unique<smartPointers>(4, 9.99999345);
	unique_ptr_2->get_data();

	/* Shared Pointers - C++11, C++14 */
	std::cout << "Shared Pointer Test " << std::endl;
	std::cout << "-------------------- " << std::endl;
	/*
	Unlike std::unique_ptr, which is designed to singly own and manage a resource, std::shared_ptr is meant to solve the case where you need multiple smart pointers co-owning a resource.
	This means that it is fine to have multiple std::shared_ptr pointing to the same resource. Internally, std::shared_ptr keeps track of how many std::shared_ptr are sharing the resource.
	As long as at least one std::shared_ptr is pointing to the resource, the resource will not be deallocated 
	*/
	std::cout << "[sharedPointer] P1 Scope" << std::endl;
	std::shared_ptr<smartPointers> SharedPointer1 = std::make_shared<smartPointers>(44, 88.1962);
	std::cout << "[sharedPointer] P1 Usecount = " << SharedPointer1.use_count() << std::endl;
	SharedPointer1->get_data();
	{
		std::cout << "[SharedPointer] P2 Scope" << std::endl;
		std::shared_ptr<smartPointers> SharedPointer2 = SharedPointer1;
		std::cout << "[SharedPointer] P2 Usecount = " << SharedPointer2.use_count() << std::endl;
		std::cout << "[SharedPointer] P1 Usecount = " << SharedPointer1.use_count() << std::endl;
		SharedPointer2->get_data();
		std::cout << "[SharedPointer] P2 Scope - End" << std::endl;
	}
	std::cout << "[SharedPointer] P1 Usecount = " << SharedPointer1.use_count() << std::endl;
	std::cout << "[SharedPointer] P1 Scope - End" << std::endl;

	/* Weak Pointers C++11
	----------------------
	*/
}