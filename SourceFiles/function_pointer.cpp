#include"function_pointers.h"

int add(int x, int y) {
	return x + y;
}

int multiply(int x, int y) {
	return x * y;
}

void function_pointer_test() {
	std::cout << "Function Pointer Test " << std::endl;
	std::cout << "-----------------------" << std::endl;
	/*traditional way of implimenting FP*/
	int (*fp)(int, int);
	fp = multiply;
	std::cout << "[Old] Operation Result : " << fp(5, 2) << std::endl;
	/* Using STL */
	std::function<int(int, int)> fp_new;	// Modern Syntax for function pointer 
	int n;
	std::cout << "Enter Operation 1)Add 2)Multiply"<<std::endl;
	std::cin >> n;
	if (n == 1) {
		fp_new = add;
	}
	else if (n == 2) {
		fp_new = multiply;
	}
	std::cout << "[NEW] Operation Result : " << fp_new(5, 2) << std::endl;

}