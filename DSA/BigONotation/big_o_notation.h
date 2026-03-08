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
#include <algorithm>
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
 std::vector<int> input_data;
 std::cout << "Running binary search\n";
 std::cout << "Enter integers (type any non-number like q to finish):\n";

 int temp;
 while (std::cin >> temp) {
  input_data.push_back(temp);
 }

 // clear fail state and bad token so we can read key
 std::cin.clear();
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // flush rest of line [web:33]

 if (input_data.empty()) {
  std::cout << "No data entered\n";
  return;
 }

 std::sort(input_data.begin(), input_data.end());  // required for binary search correctness [web:4]

 std::cout << "vector content:\n";
 for (int x : input_data) std::cout << x << " ";
 std::cout << "\n";

 int key = 0;
 std::cout << "Enter the key K = ";
 std::cin >> key;

 std::cout << "Executing binary search\n";
 int index = binarySearch(input_data, key);
 std::cout << index << "\n";
}