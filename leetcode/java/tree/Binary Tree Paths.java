/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/binary-tree-paths/
 * TC => O(n)
 * SC => O(h)
*/

package leetcode.java.tree;

import java.util.ArrayList;
import java.util.List;

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

    public List<String> dfs(TreeNode root, List<String> paths, String str) {
        if (root == null) {
            return paths;
        }
        if (root.left == null && root.right == null) {
            str += root.val;
            paths.add(str);
            return paths;
        }
        str += root.val + "->";
        dfs(root.left, paths, str);
        dfs(root.right, paths, str);
        return paths;
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<>();
        if (root == null) {
            return paths;
        }
        String str = "";
        return dfs(root, paths, str);
    }
}
