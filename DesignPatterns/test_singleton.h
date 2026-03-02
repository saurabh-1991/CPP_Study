#pragma once
#include "singleton.h"
#include <cassert>
#include <iostream>

// Test: Singleton1 returns the same instance on multiple calls
inline void test_Singleton1_SingleInstance() {
    Singleton1* s1 = Singleton1::getInstance();
    Singleton1* s2 = Singleton1::getInstance();
    assert(s1 == s2 && "Singleton1 should return the same instance on multiple calls");
    std::cout << "[Test] Singleton1 returns the same instance: PASSED" << std::endl;
}

// Test: Singleton1 instance is not null
inline void test_Singleton1_InstanceNotNull() {
    Singleton1* s = Singleton1::getInstance();
    assert(s != nullptr && "Singleton1 instance should not be null");
    std::cout << "[Test] Singleton1 instance is not null: PASSED" << std::endl;
}

// Test: Singleton1 cannot be copied or assigned (compile-time check)
// Uncommenting the following lines should cause compilation errors
/*
inline void test_Singleton1_NoCopyOrAssign() {
    Singleton1* s1 = Singleton1::getInstance();
    // Singleton1 s2(*s1); // Should not compile
    // Singleton1 s3 = *s1; // Should not compile
    // Singleton1* s4;
    // s4 = s1; // Should not compile
}
*/

// Run all Singleton1 tests
inline void run_Singleton1_tests() {
    test_Singleton1_SingleInstance();
    test_Singleton1_InstanceNotNull();
    // test_Singleton1_NoCopyOrAssign(); // Uncomment to verify compile-time errors
}