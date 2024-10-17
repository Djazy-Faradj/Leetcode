/*
Author: Djazy Faradj
Problem: 55. Jump Game
Description: 
 - You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
 - Return true if you can reach the last index, or false otherwise.

Note: By replacing the int by uint16_t, this solution now beats 100% in runtime and 93% in memory which indicates it to be the optimal solution. Important to note that because of this
conversion of data type, I had to replace the max() function previously used by an if statement as the max has to take in a regular int which didn't work anymore. Also before using
the if conditions, I first opted for the switch case. But the switch case had slowed the program by 6ms and also utilized slightly more memory than before.

Time Complexity: O(n)
Space Complexity: O(1)

Relevent Topics: Array, Dynamic Programming, Greedy
*/

class Solution {
public:
    bool canJump(vector<int> &nums) {
        //int n = nums.size();
        uint16_t i = 0;
        for (uint16_t reach = 0; i < nums.size() && i <= reach; ++i) {
            if (reach >= nums.size()-1) return true;
            if (reach > (i + nums[i])) reach = reach;
            else reach = i + nums[i];
        }
        return false;
    }
};