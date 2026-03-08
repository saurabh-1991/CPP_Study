//
// Created by Saurabh Kulkarni on 17/01/26.
//
/*What is Big O?
 * Big O is a mathematical way to describe how the performance of an algorithm changes as the size of the input grows.
* Instead, it gives you a high-level growth trend — how fast the number of operations increases relative to the input size.

For example: if your input doubles, does your algorithm take twice as long? Ten times as long? Or does it barely change at all?
 */

//-------------------------------------------------------
/*1) Constant Time – O(1)
This is the fastest and most efficient time complexity.

An algorithm is O(1) if it performs a fixed number of operations meaning the execution time does not depend on the size of the input.

A classic example is accessing an element in an array by index

int a[] = {10, 20, 30, 40};

int x = a[3];

cout << x << endl;

It doesn’t matter if the array has 10 elements…or 10 million, the time it takes to access an element stays exactly the same.

There’s no looping, no scanning. You jump directly to the value using its index.
 */

#include <iostream>
#include <vector>
//#include <ncurses.h>
//------------------------------------------------------
/* 2) Logarithmic Time – O(log n)
An algorithm runs in O(log n) time when every step reduces the problem size by a constant factor most often, by half.

This means the amount of work grows very slowly, even when the input becomes massive.

The most common example is Binary Search.
 */
int binarySearch(std::vector<int> &a, int key) {
 /*Binary Search Functionality
 * Look at the middle element
   If it’s not the target, eliminate half the array in one step
   Repeat on the remaining half*/
 int low = 0;
 int high = a.size() - 1;
 while (low <= high) {
  int mid = (low + high)/2;
  if (a[mid] == key) {
   return mid;
  }
  if (a[mid] < key) {
   low = mid + 1;
  }
  else {
   high = mid - 1;
  }
 }
 return -1;
}

void run_binarySearch() {
 std::vector <int> input_data;
 const int ESC=27;
 int temp;
 std::cout<<"Running binary search"<<std::endl;
 std::cout<<"Enter the number in Vector:(Press Esc to finish Input process)"<<std::endl;
 while (true) {
  std::cin>>temp;
  if (temp==ESC) {break;}
  input_data.push_back(temp);
 }
 std::cout<<"vector content :"<<std::endl;
 for (int i =0; i<input_data.size();i++){std::cout<<input_data[i]<<" ";}
 std::cout<<std::endl;
 int key = 0;
 std::cout<<"Enter the key K ="<<std::endl;
 std::cin>>key;
 std::cout<<"Executing binary search"<<std::endl;
 int index = binarySearch(input_data, key);
 std::cout<<index<<" ";

}