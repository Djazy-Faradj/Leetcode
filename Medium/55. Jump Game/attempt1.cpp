/*
Author: Djazy Faradj
Problem: 55. Jump Game
Description: 
 - You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
 - Return true if you can reach the last index, or false otherwise.

Note: Completely failed attempt. After looking at the optimal solutions proposed by the leetcode community. I realized that my code (which I didn't get to work in under an hour) was 
overly complex. This file will therefore be named only attempt1.cpp with solution1.cpp covering the solution.

Time Complexity: ?
Space Complexity: ?

Relevent Topics: Array, Dynamic Programming, Greedy
*/

class Solution {
public:

    class Path {
        public:
            int valueIndex;
            int jumpLen;
            vector<int> nextIndexes;
            bool isTrue = false;
            Path(vector<int> nums, int currentIndex){
                valueIndex = currentIndex;
                jumpLen = nums[valueIndex];
                for (int x = jumpLen; x > 0; x--)
                {
                    if (valueIndex + x == nums.size()-1 || valueIndex - x == nums.size()-1)
                    {
                        isTrue = true;
                        break;
                    }
                    if ((valueIndex + (x)) >= 0 && (valueIndex + (x)) < nums.size()) nextIndexes.push_back((valueIndex + x)); 
                    if ((valueIndex + (x*-1)) >= 0 && (valueIndex + (x*-1)) < nums.size()) nextIndexes.push_back((valueIndex + (x*-1))); 
                }
            }
            
        vector<Path*> CalculateNextStep(vector<int> nums)
        {
            vector<Path*> returnPaths;
            for (int j : nextIndexes)
            {
                Path* path = new Path (nums, j);
                returnPaths.push_back(path);
            }
            return returnPaths;
        }
    };

    vector<Path*> paths;

    void calculatePaths(vector<int> nums)
    {
            for (Path* q : paths)
            {
                //cout << "(NextIndexes): " << j << endl;
                for (Path* p : q->CalculateNextStep(nums)){
                    paths.push_back(p);
                }
            }
    }

    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true; // Edge case
        Path* path = new Path (nums, 0);
        paths.push_back(path);
        //cout << "(valueIndex): " << paths[0]->valueIndex << endl;
        //cout << "(jumpLen): " << paths[0]->jumpLen << endl;

        for (int i = 0; i < 1; i++)
        {
            calculatePaths(nums);
        }

        for (Path* p : paths)
        {
            cout << p->valueIndex << endl;
            if (p->isTrue == true) return true;
        }
        cout << "Number of paths: " << paths.size();
        return false;
    }
};