/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
        int leftSubtree = dfs(root.left);
        int rightSubtree = dfs(root.right);
        if (leftSubtree == 0) {
            return rightSubtree + 1;
        } else if (rightSubtree == 0) {
            return leftSubtree + 1;
        }
        return Math.min(leftSubtree, rightSubtree) + 1;
    }

    public int minDepth(TreeNode root) {
        return dfs(root);
    }
}
