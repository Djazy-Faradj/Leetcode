/*
Author: Djazy
Problem: 242. Valid Anagram
Description: 
 - Write an algorithm to determine if a number n is happy.
 - A happy number is a number defined by the following process:
 - Starting with any positive integer, replace the number by the sum of the squares of its digits.
 - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 - Those numbers for which this process ends in 1 are happy.
 - Return true if n is a happy number, and false if not.

Note: Doesnt work for testcases like s = "ac", t = "bb" where the components average out and become equal. I have an idea of instead of taking the sum of each char composing the
string. I would instead take the sum of the char values SQUARED as this would fix the problematic test case. (Could also work by doing 1/charvalue but would take require turning the ints to floats)
I know I could simply do a unordered_map and keeping track of character occurences but im trying to do something different. (UPDATE: didnt work, will just use unorderedmap lol)

Time Complexity: ?
Space Complexity: ?

Relevent Topics: Hash Table, String, Sorting
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        if (accumulate(s.begin(), s.end(), 0) - accumulate(t.begin(), t.end(), 0) == 0) return true;
        else return false;
    }
};