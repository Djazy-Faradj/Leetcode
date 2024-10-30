/*
Author: Djazy Faradj
Problem: 88. Merge Sorted Array
Description: 
 - You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 - Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 - The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Note: This solution beats 100% in runtime and 66.74% in memory. Though I think a better solution might exist because leetcode challenges us to find an O(m+n) solution whereas
mine is O((M+N)Log(M+N)). Might cover in solution2.cpp

Time Complexity: O((M+N)Log(M+N))
Space Complexity: O(1)

Relevent Topics: Array, Two Pointers, Sorting
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return; // Case where size of second array is 0, so return the nums1 array untouched
        for (int i = m; i < (m+n); i++) nums1[i] = nums2[i-m]; // Place nums2 elements in nums1
        sort(nums1.begin(), nums1.end()); // Sort nums1
    }
};