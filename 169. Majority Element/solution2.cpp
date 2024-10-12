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