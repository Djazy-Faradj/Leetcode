/*
Author: Djazy Faradj
Problem: 9. Palindrome Number
Description: 
 - Given an integer x, return true if x is a palindrome, and false otherwise.

Note: No notes
Time Complexity: ?
Space Complexity: ?

Relevent Topics: Math
*/

class Solution {
public:
    bool isPalindrome(int x) {
        string xString = to_string(x);
        int xStringSize = xString.size();

        for (int i = 0; i < xStringSize; i++)
        {
            if(xString[i] != xString[(xStringSize-1)-i]) return false;
        }

        return true;
    }
};