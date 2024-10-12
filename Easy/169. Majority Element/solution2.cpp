/*
Author: Djazy Faradj
Problem: 169. Majority Element
Description: 
 - Given an array nums of size n, return the majority element.
 - The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Note: 
Optimal solution (Moore Voting Algorithm)

Time Complexity: O(n)
Space Complexity: ?

Relevent Topics: Array, Hash Table, Divide and Conquer, Sorting, Counting
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {  // Trying to implement Moore Voting Algorithm
        int count = 0;
        int candidate = 0;
        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }
            switch(num == candidate)
            {
                case true:
                    count++;
                    break;
                default:
                    count--;
            }
        }
        return candidate;
    }
};