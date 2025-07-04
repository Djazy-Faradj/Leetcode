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
    public TreeNode searchBST(TreeNode root, int val) {
        TreeNode subtree = null;

        if (root.val == val) {
            return root;
        }
        else if (root.val > val) { // visit left
            if (root.left != null) {
                subtree = searchBST(root.left, val);
            }
        } else { // visit right
            if (root.right != null) {
                subtree = searchBST(root.right, val);
            }
        }
        return subtree;
    }
}