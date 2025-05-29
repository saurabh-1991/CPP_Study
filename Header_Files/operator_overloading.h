#pragma once
#include<iostream>
/*Customizes the C++ operators for operands of user-defined types.*/
class vector3f {
public:
	float x;
	float y;
	float z;
	/*
	vector3f() {		//Default Constructor
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	*/
	vector3f(float x =0,float y =0,float z = 0) : x(x),y(y),z(z){}
	~vector3f(){}
	/*Normal Way */
	/*
	vector3f operator+(const vector3f& rhs) {
		vector3f result;
		result.x = x + rhs.x;
		result.y = x + rhs.y;
		result.z = x + rhs.z;
		return result;
	}
	*/
	/* other way*/
	vector3f operator+(const vector3f& rhs) {
		return vector3f(x + rhs.x, y + rhs.y, z + rhs.z);
	}
};

void test_operatorOverloading();