/*
Author: Djazy Faradj
Problem: 151. Reverse Words in a String
Description: 
 - Given an input string s, reverse the order of the words.
 - A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
 - Return a string of the words in reverse order concatenated by a single space.
 - Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Note: This solution was very bad though I expected it. This is my brute force attempt and it only beats 6% in runtime and 30% in memory. Also the code looks ugly.
Better solution will be covered in solution2.cpp
Time Complexity: O(N)
Space Complexity: O(N)

Relevent Topics: Two pointers, String
*/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string sOut = "";
        string word = "";
        for (char c : s+=' ')
        {
            if (c != ' ') 
            {
                word += c;
            }
            else
            { 
                if (word != "")
                {
                    words.insert(words.begin(), word);
                    word = "";
                }
            }
        }
        for (int i = 0; i < words.size(); i++)
        {
            if (i != 0) sOut += " ";
            sOut += words[i];
        }
        return sOut;
    }
};

