#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <unordered_map>
/*
 Longest Substring Without Repeating Characters
Medium
Topics
Companies
Hint
Given a string s, find the length of the longest substring without duplicate characters.



Example 1:

Input: s = "abcabcbb"
Output : 3
Explanation : The answer is "abc", with the length of 3.
Example 2 :

	Input : s = "bbbbb"
	Output : 1
	Explanation : The answer is "b", with the length of 1.
	Example 3 :

	Input : s = "pwwkew"
	Output : 3
	Explanation : The answer is "wke", with the length of 3.
	Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		std::unordered_map<char,int> charCountMap;
		int index = 0;
		std::string temp;
		int cnt = 1;
		std::vector<std::string> substr_array;
		//if (s.find(s[0], 1))
		for(int i = 0;i < s.size();i++)
		 {
			index = s.find(s[i], cnt);
			if (index > 0) {
				//index = s.find(s[i], cnt);
				temp = s.substr(i, index);
				substr_array.push_back(temp);
				//charCountMap.insert({ temp, temp.size() });
				for (const char c : temp) { std::cout << c; }
			}
			cnt += 1;
			//index = s.find(s[i], 1);
			//temp = s.substr(0, index);
			//for (const char c : temp) { std::cout << c ; }
		}
		std::cout<<"\n"<< temp.size();
		return temp.size();
	}
};

void execute_problem1() {
	Solution sol;
	std::string s = "abcabcbb";
	std::string s2 = "bbbbb";
	std::string s3 = "pwwkew";
	sol.lengthOfLongestSubstring(s);
}