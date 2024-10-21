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

Note: This solution is the best for memory though is slightly slower. (79% runtime, 93% memory)

Time Complexity: O (nlogn)
Space Complexity: O (1)

Relevent Topics: Hash Table, String, Sorting
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t){
            return true;
        }
        return false;
        
    }
};