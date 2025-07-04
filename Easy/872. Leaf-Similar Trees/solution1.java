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
    public boolean isInternal(TreeNode n) {
        return (n.left != null || n.right != null);
    }

    public boolean isExternal(TreeNode n) {
        return !isInternal(n);
    }

    public LinkedList<Integer> getLeafSequence(TreeNode root) {
        LinkedList<Integer> leafSequence = new LinkedList<>();

        if (root == null) return leafSequence;
        else if (isExternal(root)) {
            leafSequence.add(root.val);
            return leafSequence;
        }

        TreeNode left = root.left;
        TreeNode right = root.right;

        leafSequence.addAll(getLeafSequence(left));
        leafSequence.addAll(getLeafSequence(right));
        return leafSequence;
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        LinkedList<Integer> seq1 = getLeafSequence(root1);
        LinkedList<Integer> seq2 = getLeafSequence(root2);
        return (seq1.equals(seq2));
    }
}