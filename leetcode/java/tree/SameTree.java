/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/same-tree/description/
 * TC => O(n)
 * SC => O(h)
*/

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    private boolean dfs(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if ((p == null && q != null) || (p != null && q == null)) {
            return false;
        }
        if (p.val == q.val && dfs(p.left, q.left) && dfs(p.right, q.right)) {
            return true;
        }
        return false;
    }

    public boolean isSameTree(TreeNode p, TreeNode q) {
        return dfs(p, q);
    }
}