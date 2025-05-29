#pragma once
#include<iostream>
#include<thread>
#include<mutex>
#include<vector>

/*Singleton Pattern
* ------------------
The Singleton pattern is a creational design pattern that ensures a class has only one instance (object) throughout the program’s lifetime.
It provides a global access point to this single instance.
*/

/*Non Thread Safe Singleton */

class Singleton1 {
private:
	Singleton1() {		// Private constructor to prevent direct instantiation
		std::cout << "[Singleton]: Object Created" << std::endl;
	}
	Singleton1(const Singleton1&) = delete;	// Prevent copy constructor
	Singleton1& operator=(const Singleton1&) = delete;	// Prevent copy assignment
	static Singleton1* instance;		// Static pointer to the single instance

public:
	static Singleton1* getInstance() {
	// ======================================
	// This is critical section
		if (instance == nullptr) {	// race condition can happen here.
			instance = new Singleton1();	// Create the instance on first call
		}
		return instance;
	}
};
Singleton1* Singleton1::instance = nullptr;
/*The reason it’s not thread safe is because if two threads call getInstance() method at the same time(concurrently) 
  when instance is nullptr, both will proceed to create a new instance, violating the Singleton pattern.*/

class SingletonThreadSafe {
private:
	SingletonThreadSafe(){ std::cout << "[SingletonTS]: Object Created" << std::endl; }
	SingletonThreadSafe(const SingletonThreadSafe&) = delete;
	SingletonThreadSafe& operator=(const SingletonThreadSafe&) = delete;
	static std::mutex mx;		// Mutex for thread safety
	static SingletonThreadSafe* instance;
public:
	static SingletonThreadSafe* getInstance() {
		// Acquire lock before checking instance
		std::lock_guard<std::mutex> lock(mx);
		if (instance == nullptr) {
			instance = new SingletonThreadSafe();		// Create the instance only once
		}
		return instance;
	}
};
std::mutex SingletonThreadSafe::mx;
SingletonThreadSafe* SingletonThreadSafe::instance = nullptr;

/*In below version, call_once ensures that the function passed to it (in this case, a lambda function that creates a new Singleton instance)
is called only once, even in a multi-threaded environment. The once_flag object is used to control this behavior.
This will allows you to create a thread-safe Singleton without needing to manage locks manually.*/

class Singleton_wo_Lock {
private:
	Singleton_wo_Lock() { std::cout << "[TS_Singleton_W/O Lock]: Object Created" << std::endl; }			//Private constructor
	Singleton_wo_Lock(const Singleton_wo_Lock&) = delete;
	Singleton_wo_Lock& operator=(const Singleton_wo_Lock&) = delete;
	static Singleton_wo_Lock* instance;
	static std::once_flag flag;
public:
	static Singleton_wo_Lock* getInstance() {
		/*Lambda Function:
		[capture-clause] (parameters) -> return-type { 
		// definition
		}*/
		std::call_once(flag, []() {instance = new Singleton_wo_Lock(); });
		return instance;
	}
};
Singleton_wo_Lock* Singleton_wo_Lock::instance = nullptr;
std::once_flag Singleton_wo_Lock::flag;

// Function to be executed by multiple threads
void createSingletonInstance() {
	Singleton1* singleton = Singleton1::getInstance();
	std::cout << "Singleton instance address: " << singleton << std::endl;
}

void createThreadSafeSingletonInstance() {
	SingletonThreadSafe* singleton = SingletonThreadSafe::getInstance();
	std::cout << "Thread Safe Singleton instance address: " << singleton << std::endl;
}

void createThreadSafeSingletonInstance_WO_Lock() {
	Singleton_wo_Lock* singleton = Singleton_wo_Lock::getInstance();
	std::cout << "Thread Safe Singleton instance address: " << singleton << std::endl;
}

void runSimpleSingleton() {
	//createSingletonInstance();
	const int numThreads = 10;
	std::vector<std::thread> threads;
	for (int i = 0; i < numThreads;++i) {
		threads.emplace_back(createThreadSafeSingletonInstance_WO_Lock);
	}
	for (auto& thread : threads) {
		thread.join();
	}

}