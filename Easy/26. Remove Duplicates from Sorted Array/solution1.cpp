/*
Author: Djazy Faradj
Problem: 26. Remove Duplicates from Sorted Array
Description: 
 - Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
 - Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
 - Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
 - Return k.

Note: No notes
Time Complexity: ?
Space Complexity: ?

Relevent Topics: Array, Two Pointers
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nextInt = -101;
        vector<int> newVector;

        for (int i : nums)
        {
            if (i != nextInt)
            {
                nextInt = i;
                newVector.push_back(nextInt);
            }
        }
        nums = newVector;
        return newVector.size();
    }
};