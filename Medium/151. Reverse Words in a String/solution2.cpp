/*
Author: hiepit
Problem: 151. Reverse Words in a String
Description: 
 - Given an input string s, reverse the order of the words.
 - A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
 - Return a string of the words in reverse order concatenated by a single space.
 - Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Note: This solution is better in terms of performance. (52% runtime - 52% memory) The approach is to basically split the words from the original string first and then rejoin them
in the reverse order. This approach is the same one I applied in solution1, just executed better. This solution, however, does not offer a O(1) space complexity as challenged by
Leetcode. O(1) will be covered in solution3.cpp.
From this solution, I learned about stringstream and its use, how it works and how to use it.
Time Complexity: O(N) where N is size of string
Space Complexity: O(N) where N is size of string

Relevent Topics: Two pointers, String
*/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
            words.push_back(tmp);

        string ans;
        for (int i = words.size() - 1; i >= 0; --i) {
            if (i != words.size() - 1) ans += " ";
            ans += words[i];
        }
        return ans;
    }
};
