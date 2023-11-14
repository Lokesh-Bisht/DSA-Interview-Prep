/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/
 * TC => O(n)
 * SC => O(h)
*/

package leetcode.java.tree;

class Solution {

    private int ans;

    public int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 1;
        }
        int leftSubtree = dfs(root.left);
        int rightSubtree = dfs(root.right);
        ans = Math.max(ans, leftSubtree + rightSubtree);
        return Math.max(leftSubtree, rightSubtree) + 1;
    }

    public int diameterOfBinaryTree(TreeNode root) {
        ans = 0;
        dfs(root);
        return ans;
    }
}
