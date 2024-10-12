/*
Author: Djazy Faradj
Problem: 27. Remove Element
Description: 
 - Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
 - Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
 - Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
 - Return k.

Note: No notes
Time Complexity: ?
Space Complexity: ?

Relevent Topics: Array, Two Pointers
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> returnVector;
        int k = 0;

        for (int i : nums)
        {
            if(i != val) 
            {
                returnVector.push_back(i);
                k++;
            }
        }

        nums = returnVector;
        return k;
    }
};