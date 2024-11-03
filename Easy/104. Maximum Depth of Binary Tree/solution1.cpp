/*
Author: Djazy Faradj
Problem: 104. Maximum Depth of Binary Tree
Description: 
 - Given the root of a binary tree, return its maximum depth.
 - A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: This is a genius solution which I had to look up, I knew recursion was to be used 
but I simply did not have enough experience dealing with recursion and binary trees to be able
to solve this on my own. Though I now understand the execution behind such a process, I still think I need
to get my brain used to these types of solution.
This solution beats 100% in runtime and 44% in memory.
Time Complexity: O(N)
Space Complexity: O(N)

Relevent Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }
};