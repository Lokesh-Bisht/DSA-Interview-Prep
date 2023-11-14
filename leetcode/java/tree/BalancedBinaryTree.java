/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/balanced-binary-tree/
 * TC => O(n)
 * SC => O(h)
*/

package leetcode.java.tree;

class Solution {

    public int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 1;
        }
        int leftSubtree = dfs(root.left);
        int rightSubtree = dfs(root.right);
        int diff = Math.abs(leftSubtree - rightSubtree);
        if (leftSubtree == - 1 || rightSubtree == -1 || diff > 1) {
            return -1;
        }
        return Math.max(leftSubtree, rightSubtree) + 1;
    }

    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        return dfs(root) != -1;
    }
}
