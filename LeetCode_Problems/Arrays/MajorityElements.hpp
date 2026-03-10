/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/
#include<iostream>
#include<vector>
#include<unordered_map>

class MajorityElements
{
private:
    /* data */
public:
    MajorityElements(/* args */);
    int majorityElement_sol1(std::vector<int>& nums);
    int majorityElement_sol2(std::vector<int>& nums);
    ~MajorityElements();
};

MajorityElements::MajorityElements(/* args */)
{
}

MajorityElements::~MajorityElements()
{
}

/*Solution 1 - Hash Map Approach: O(n) time complexity, O(n) space complexity
1) Create a hash map to store the frequency of each element
2) Iterate through the array and update the frequency in the hash map
3) Find the element with the maximum frequency (n/2) and return it
*/

int MajorityElements::majorityElement_sol1(std::vector<int>& nums) 
{
    std::unordered_map<int,int> frequencyMap;
    // Traverse the array and count the frequency of each element
    for (int num : nums){
        frequencyMap[num] = frequencyMap[num] + 1;
        if (frequencyMap[num] > nums.size()/2){
            return num;
        }
    } 
    return -1; // This line should never be reached since a majority element always exists
}
    
   