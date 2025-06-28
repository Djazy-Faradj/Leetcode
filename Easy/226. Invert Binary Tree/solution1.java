/*
Author: Djazy Faradj
Problem: 226. Invert Binary Tree
Description: 
 - Given the root of a binary tree, invert the tree, and return its root.

Note: This is the solution I provided to my Data Structure and Algorithms class question.
Time Complexity: O(i) where i represents number of internal nodes
Space Complexity: ?

Relevent Topics: Tree, DFS, BFS, Binary Tree
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public boolean isExternal(TreeNode v) {
        if (v == null) return false;
        return (v.left == null && v.right == null);
    }

    public TreeNode invertTree(TreeNode root) {
        if (root == null) return null;

        if (!isExternal(root.left)) {
            invertTree(root.left);
        }

        if (!isExternal(root.right)) {
            invertTree(root.right);
        }

        TreeNode temp = root.left == null ? null : new TreeNode(root.left.val, root.left.left, root.left.right);
        root.left = root.right;
        root.right = temp;
        return root;
    }
}