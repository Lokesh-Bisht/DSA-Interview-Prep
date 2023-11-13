/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * TC => O(n)
 * SC => O(h)
*/

package leetcode.java.tree;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    public int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 1;
        }
        int leftSubTree = dfs(root.left);
        int rightSubTree = dfs(root.right);
        return Math.max(leftSubTree, rightSubTree) + 1;
    }

    public int maxDepth(TreeNode root) {
        return dfs(root);
    }
}