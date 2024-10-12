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