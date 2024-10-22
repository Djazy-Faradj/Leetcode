/*
Author: Djazy Faradj
Problem: 125. Valid Palindrome
Description: 
 - A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 - Given a string s, return true if it is a palindrome, or false otherwise.

Note: This solution beats 88.17% of solutions in runtime and 19.24% in memory. In solution2.cpp, I will try to speed it up and reduce its memory use by skipping the "Conversion" phase altogether and directly heading to the palindrome check. 
Time Complexity: ?
Space Complexity: ?

Relevent Topics: Two Pointers, String
*/

class Solution {
public:
    bool isPalindrome(string s) {
        string convertedStr = "";
        for (char c : s) // Manipulates "s" string so that it can be checked as palindrome
        {
            c = tolower(c);
            if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122)) convertedStr += c;
        }
        // Edge cases in which string is empty or length 1
        if (convertedStr.length() == 0 || convertedStr.length() == 1) return true; 

        // Compares end of string with begining slowly making its way through the middle if a comparaison fails return false
        for (int i = 0; i < convertedStr.length(); i++) 
        {
            if (convertedStr[i] - convertedStr[convertedStr.length()-1-i] != 0) return false;
        }
        // If all comparaisons passed, means its a palindrome, return true
        return true;
    }
};