#include"operator_overloading.h"

void test_operatorOverloading() {
	std::cout << "Operator Overloading Test" << std::endl;
	vector3f v1{1.0,2.0,3.0};
	std::cout << "V1 :x =" << v1.x << " V1:y =" << v1.y << " V1:z =" << v1.z << std::endl;
	vector3f v2{ 3.0,2.0,1.0 };
	std::cout << "V2 :x =" << v2.x << " V2:y =" << v2.y << " V2:z =" << v2.z << std::endl;
	vector3f v3 = v1 + v2;
	std::cout << "V3 :x =" << v3.x << " V3:y =" << v3.y << " V3:z =" << v3.z << std::endl;
}