/*
My approach was to use an unordered map (hash map) to keep track of each element in the array and then check which one appears for more than n/2 times. O (n)
Another, more optimal approach would have been to sort the array, guarenteeing the wanted element to be found at index n/2. O (n log n)
*/

class Solution {
public:
    unordered_map<int, int> umap;

    int majorityElement(vector<int>& nums) {
        int majorityThreshold = (nums.size()/2)+1;
        for (int num : nums)
        {
            if (umap.find(num) == umap.end())
            {
                umap[num] = 1;
            }
            else
            {
                umap[num]++;
            }
            unordered_map<int, int>::iterator itr;
            for (itr = umap.begin(); itr != umap.end(); itr++)
            {
                if (itr->second >= majorityThreshold) return itr->first; 
            }
        }
        return 0;
    }
};