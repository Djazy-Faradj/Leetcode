/*
Author: Djazy Faradj
Problem: 191. Number of 1 Bits
Description: 
 - Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

Note: This problem thought me two nice concepts:    1. The existance of bitwise operators, to perform bitwise AND (&) and bitwise OR (|)
                                                    2. The meaning of "Hamming weight" which is the number of set bits in a binary number.
      This solution beats 100% in terms of runtime and 76% in terms of memory.

Time Complexity: O(n) where n is the number of bits in the binary representation of the number
Space Complexity: O(1)

Relevent Topics: Divide and conquer, Bit Manipulation
*/

class Solution {
public:
    int hammingWeight(int n) {
        uint8_t count = 0;
        while (n)
        {
            n &= (n-1);
            count ++;
        }
        return count;
    }
};

// 1011     n       (11)
// 1010     n-1     (10)

// 1010     n       (10)    count = 1
// 1001     n-1     (9)     

// 1000     n       (8)     count = 2
// 0111     n-1     (7) 

// 0000     n       (0)     count = 3

// STOPS


