/*
Author: Djazy Faradj
Problem: 69. Sqrt(x)
Description: 
 - Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
 - You must not use any built-in exponent function or operator.
 - For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Note: No notes
Time Complexity: ?
Space Complexity: ?

Relevent Topics: Math, Binary Search
*/

class Solution {
public:
    int mySqrt(int x) {
        for (uint i = 1; i <= x; i++)
        {
            if (i*i > x) return i-1;
            else if (i*i == x) return i;
        }
        return 0;
    }
};