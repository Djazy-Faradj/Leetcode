class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output(2, 0);

        int numsSize = nums.size();
        int diff;
        std::unordered_map<int, int> seen;

        for (int i = 0; i < numsSize; i++) {
            diff = target - nums[i];            // Finds the difference needed to complete the sum 
        
            if (seen.find(diff) == seen.end()) seen[nums[i]] = i;      // If no match found in hashtable, add current number to table and repeat loop
            else // Match is found
            {
                return {seen.at(diff), i};
            }

        }
        std::cout << "No solution";
        return {0, 0};
    }
};