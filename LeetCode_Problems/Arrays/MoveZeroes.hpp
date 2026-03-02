/*Problem: Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zeroes.
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]
Constraints:
1 <= nums.length <= 104

*/
#include <vector>
#include <iostream>
using namespace std;

class MoveZeroes
{
private:
    /* data */
public:
    MoveZeroes(/* args */);
    vector<int> movezeros_sol1(vector<int>& nums);
    vector<int> movezeros_sol2(vector<int>& nums);
    ~MoveZeroes();
};

MoveZeroes::MoveZeroes(/* args */)
{
}

MoveZeroes::~MoveZeroes()
{
}

// Brute Force Approach: O(n^2) time complexity
/*
1)Create a temporary array of the same size
2)Iterate through the original array and copy all non-zero elements to the temp array
3)Fill the remaining positions in temp array with zeros
4)Copy the temp array back to the original array
*/
vector<int> MoveZeroes::movezeros_sol1(vector<int>& nums) 
{
// Brute Force Approach: O(n^2) time complexity
int n = nums.size();
vector<int> tempData(n, 0);
int index = 0;
// Traverse the original array and copy non-zero elements to tempData
for (int i = 0 ; i < n; ++i){
    cout << "Input Array: " << nums[i] << " ";
    cout << endl;
    if(nums[i] != 0){
        tempData[index++] = nums[i];
    }
    
    }
    // print the modified array
    for (int i = 0; i < n; ++i) {
        nums[i] = tempData[i];
        cout << "Modified Array: " << nums[i] << " ";
        cout << endl;
    }
    return nums;
}

//Optimal Two-Pointer with Swapping: O(n) time complexity
/*
1) Initialize two pointers, left and right, both pointing to the start of the array
2) Iterate through the array with the right pointer
3) If the element at right is non-zero, swap it with the element at left and increment left
4) Continue until right reaches the end of the array
*/
vector<int> MoveZeroes::movezeros_sol2(vector<int>& nums){
    int writeIndex = 0;
    // Pass-1 - Move non-zero elements to the front
    for (int i = 0;i < nums.size(); ++i){
        cout << "Input Array: " << nums[i] << " ";
        cout << endl;
        if (nums[i] != 0){
            nums[writeIndex++] = nums[i];
        }
    }
    while(writeIndex < nums.size()){
        nums[writeIndex++] = 0;
    }
    // print the modified array
    for (int i = 0; i < nums.size(); ++i) {
        cout << "Modified Array: " << nums[i] << " ";
        cout << endl;
    }
    return nums;
}