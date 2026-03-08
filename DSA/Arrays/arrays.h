//
// Created by Saurabh Kulkarni on 17/01/26.
//

#ifndef CPP_STUDY_ARRAYS_H
#define CPP_STUDY_ARRAYS_H
#include <iostream>
#include <vector>

/* Common Array Interview Patterns
 * --------------------------------
*Arrays show up in almost every coding interview. But the questions don’t just ask you to “loop and print”. Instead, they are often based on problem-solving patterns that use arrays in clever ways.
 Here are the most common array patterns you should know
 */
/*1)Two Pointer Technique:
 This pattern works especially well for sorted arrays or problems where you compare values from both ends.
You place one pointer at the start and another at the end, then move them inward based on certain logic.
Common use cases include:

  * Checking if a number pair sums to a target
  * Removing duplicates in a sorted array
  * Checking if a string is palindrome
*/
//**************************************************************
// Leetcode Problem 283
/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Input = [0,1,0,3,12]
Output = [1,3,12,0,0]
Note that you must do this in-place without making a copy of the array.*/
//*************************************************************
class array_pattern_lc_problem1 {
 public:
 // Solution 1 : BruteForce Way
 /*Time Complexity: O(n), where n is the length of the array.
   Space Complexity: O(n), due to the use of additional array.*/
 static void move_zeros(std::vector<int>& nums) {
  std::vector<int> output(nums.size(),0);
  int cnt = 0;
  for(const int num : nums){
   if(num!= 0){
    output[cnt++] = num;
   }
   //output.push_back(nums[i]);
  }

  for(int i = 0; i < nums.size();i++){
   nums[i] = output[i];
  }
 }
 // Solution 2 : Two Pointer Way Two Pass
 /*A more efficient approach to solve this problem is using the two-pointer technique.

 Use two indices:

 writePos points to the next position to place a non-zero.
 i scans the array.
 First pass: copy every non-zero to nums[writePos] and advance writePos.
 Second pass: fill the remaining positions with zeros.
 This preserves the relative order of non-zeros.*/
 void move_zeros_twoPointer_twoPass(std::vector<int>& nums) {
  int writePos = 0;
  // First Pass : copy every non-zero to nums[writePos]
  for(int i = 0; i < nums.size();i++) {
   if (nums[i] != 0) {
    nums[writePos++] = nums[i];
   }
  }
 // Second Pass :
  while(writePos < nums.size()) {
   nums[writePos++] = 0;
  }
 }
};

static array_pattern_lc_problem1 lc_array_problem1;

void run_array_leetcode_problems_1() {
 std::cout<<"Running array leetcode problems 1"<< std::endl;
 std::
}
#endif //CPP_STUDY_ARRAYS_H