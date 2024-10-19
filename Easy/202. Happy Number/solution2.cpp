/*
Author: ajlichuan
Problem: 202. Happy Number
Description: 
 - Write an algorithm to determine if a number n is happy.
 - A happy number is a number defined by the following process:
 - Starting with any positive integer, replace the number by the sum of the squares of its digits.
 - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 - Those numbers for which this process ends in 1 are happy.
 - Return true if n is a happy number, and false if not.

Note: 

Time Complexity: ?
Space Complexity: ?

Relevent Topics: Hash Table, Math, Two Pointers
*/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> tmp;
        
        while(n != 1)
        {
            if(tmp.find(n) == tmp.end())
                tmp.insert(n);
            else
                return false;
            
            int sum = 0;
            while(n != 0)
            {
                sum += pow(n % 10,2);
                n = n / 10;
            }
            
            n = sum;
        }
        
        return true;
    }
};