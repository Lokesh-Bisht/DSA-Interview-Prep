/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * TC => O(n)
 * SC => O(1)
*/

package leetcode.java.tree;

class Solution {

    private int ans, count;

    public void dfs(TreeNode root, int k) {
        if (root == null) {
            return;
        }
        dfs(root.left, k);
        count++;
        if (count == k) {
            ans = root.val;
            return;
        }
        dfs(root.right, k);
    }

    public int kthSmallest(TreeNode root, int k) {
        ans = 0;
        count = 0;
        dfs(root, k);
        return ans;
    }
}
