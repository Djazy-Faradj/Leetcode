/*
Author: Djazy Faradj
Problem: 58. Length of Last Word
Description: 
 - Given a string s consisting of words and spaces, return the length of the last word in the string.
 - A word is a maximal substring consisting of non-space characters only.

Note: Beats 100% in runtime and 43% in memory

Time Complexity: O(n) # Where n is size of haystack
Space Complexity: O(1)

Relevent Topics: Two Pointers, String, String Matching
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;
        int j = haystack.length()-1;
        for (int i = 0; i < (haystack.length()-needle.length()+1); i++, j--)
        {
            if (haystack[i] == needle[0])
            {
                if (haystack.substr(i, needle.length()) == needle) return i;
            }
        }
        return -1;
    }
};