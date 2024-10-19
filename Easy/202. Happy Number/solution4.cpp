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

Note: Brent's Cycle detection algorithm

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
        int slow = n;
        int fast = next(n);
        int cnt = 1;
        int lim = 2;
        
        while(slow != fast)
        {
            if(cnt == lim)
            {
                cnt = 1;
                lim = lim*2;
                slow = fast;
            }
            else
                cnt ++;
        
            fast = next(fast);
        }
        
        return fast == 1 ;
    }
};