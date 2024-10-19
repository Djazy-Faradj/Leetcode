/*
Author: Djazy Faradj
Problem: 202. Happy Number
Description: 
 - Write an algorithm to determine if a number n is happy.
 - A happy number is a number defined by the following process:
 - Starting with any positive integer, replace the number by the sum of the squares of its digits.
 - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 - Those numbers for which this process ends in 1 are happy.
 - Return true if n is a happy number, and false if not.

Note: This beats 100% in runtime but only 5% in memory. Looking at solutions I learned about the existence of unordered_set (solution2.cpp) which would be a better option. There are better memory solutions 
which I will look into because I am not entirely sure on how they work. (solution3.cpp)

Time Complexity: ?
Space Complexity: ?

Relevent Topics: Hash Table, Math, Two Pointers
*/

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> umap = {
            {n, true}
        };

        while (true)
        {
            string nStr = to_string(n);
            n = 0;
            for (char c : nStr)
            {
                n += (c-'0')*(c-'0');
            }
            if (n == 1) return true;
            if (umap.find(n) == umap.end()) umap[n] = true;
            else return false;
        }
        return false;
    }
};