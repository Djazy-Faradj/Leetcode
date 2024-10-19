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

Note: Floyd's Cycle detection algorithm (Tortoise and the Hare Algorithm) a faster algorithm is explored in solution4.cpp

Time Complexity: ?
Space Complexity: ?

Relevent Topics: Hash Table, Math, Two Pointers
*/

class Solution {
public:
    int next(int n)
    {
        int sum = 0;
        
        while(n != 0)
        {
            sum += pow(n % 10,2);
            n = n / 10;
        }
        
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));
        
        while(slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        
        return fast == 1 ;
    }
};