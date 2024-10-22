/*
Author: Djazy Faradj
Problem: 125. Valid Palindrome
Description: 
 - A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 - Given a string s, return true if it is a palindrome, or false otherwise.

Note: This solution is very bad runtime-wise, but large improvement in terms of memory. It only beats 5% of submissions in terms of runtime but over 92% of submissions in terms
of memory. I believe the runtime is bad because of all the lengthy conditions I used, which I believe could be easily further optimized. Might be covered in solution3.cpp or might
also cover a solution from the community.

Time Complexity: ?
Space Complexity: ?

Relevent Topics: Two Pointers, String
*/

class Solution {
public:
    bool isPalindrome(string s) {
        // Edge cases in which string is empty or length 1
        if (s.length() == 0 || s.length() == 1) return true; 

        // Compares end of string with begining slowly making its way through the middle if a comparaison fails return false
        int j = s.length()-1;
        for (int i = 0; i < s.length() && j >= 0; i++, j--) 
        { 
            while ((s[i] < 48 || s[i] > 57) && (tolower(s[i]) < 97 || tolower(s[i]) > 122) && i < s.length()-1) i++;
            while ((s[j] < 48 || s[j] > 57) && (tolower(s[j]) < 97 || tolower(s[j]) > 122) && j > 0) j--;
            cout << s[i] << " " << s[j] << endl;
            if (tolower(s[i]) - tolower(s[j]) != 0 && ((s[i] >= 48 && s[i] <= 57) || (tolower(s[i]) >= 97 && tolower(s[i]) <= 122)) && ((s[j] >= 48 && s[j] <= 57) || (tolower(s[j]) >= 97 && tolower(s[j]) <= 122))) return false;
        }
        // If all comparaisons passed, means its a palindrome, return true
        return true;
    }
};