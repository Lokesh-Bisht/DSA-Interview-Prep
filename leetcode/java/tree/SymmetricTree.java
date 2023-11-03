/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/symmetric-tree/description/
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
public class SymmetricTree {

    private boolean dfs(TreeNode root, TreeNode root2) {
        if (root == null && root2 == null) {
            return true;
        }
        if ((root == null && root2 != null) || (root != null && root2 == null)) {
            return false;
        }
        if (root.val == root2.val && dfs(root.left, root2.right) && dfs(root.right, root2.left)) {
            return true;
        }
        return false;
    }

    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return dfs(root.left, root.right);
    }
}