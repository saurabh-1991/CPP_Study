/*String Compression Problem - LeetCode 443
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Note: The characters in the array beyond the returned length do not matter and should be ignored.

Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: 6, chars = ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
*/

/*Solution -
using two pointers approach */
#include<iostream>
#include<vector>
#include<string>

int StringCompression(std::vector<char>& chars){
    int write = 0; // Pointer to write compressed char
    int read = 0; // Pointer to read original char
    if (chars.size()==0) return 0;
    for(read = 0; read < chars.size(); read++){
        int count = 1; // count of chars in array
        for (int j = read +1; j < chars.size(); j++){
            if (chars[read] == chars[j]){
                count ++;
            } else {
                break;
            }
            
        }
        chars[write] = chars[read]; // write the char to the write pointer
        write++;
        if(count <=1) continue; // if count is 1, we just write the char and move on
        else{
            // convert count to string and write each digit to the chars array
            std::string countstr = std::to_string(count);
            for(char c : countstr){
                chars[write] = c;
                write++;
            }
            read += count -1;
        }
        // print the chars array after each group is processed
        std::cout << "After processing group: ";
        for (int i = 0; i < write; i++) {
            std::cout << chars[i];
        }
        std::cout << std::endl;
    }

    return chars.size() > 0 ? write : 0; // return the new length of the compressed array
}