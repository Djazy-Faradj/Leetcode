/*
Author: Djazy Faradj
Problem: 55. Jump Game
Description: 
 - You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
 - Return true if you can reach the last index, or false otherwise.

Note: This solution was taken from the community page and slightly modified by me. The original solution (commented) was designed such that it went through the entire array nums each
time it is run even if it found a solution earlier than by the end. I improved it by checking the condition at the beginning of the for loop so that as soon as the reach extends to the
end of the array. It returns true. This solution beats 100% of other solutions in terms of runtime and 42% in terms of memory. In solution2.cpp, I will try to better optimize 
solution memory.

Time Complexity: O(n)
Space Complexity: O(1)

Relevent Topics: Array, Dynamic Programming, Greedy
*/

/* **SOLUTION TAKEN FROM COMMUNITY (User: Alexander7)**
    bool canJump(int A[], int n) {
        int i = 0;
        for (int reach = 0; i < n && i <= reach; ++i)
            reach = max(i + A[i], reach);
        return i == n;
    }
*/

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int i = 0;
        for (int reach = 0; i < n && i <= reach; ++i) {
            if (reach >= n-1) return true;
            reach = max(i + nums[i], reach);
        }
        return false;
    }
};