/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
 * TC => O(n)
 * SC => O(n)
*/

package leetcode.java.tree;

import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        Queue<Integer> indexQueue = new LinkedList<>();
        int ans = 0;
        queue.add(root);
        indexQueue.add(1);
        while (!queue.isEmpty()) {
            int level = queue.size();
            int leftIndex = 0, rightIndex = 0;
            for (int i = 0; i < level; ++i) {
                TreeNode curNode = queue.poll();
                int index = indexQueue.poll();
                if (i == 0) {
                    leftIndex = index;
                }
                if (i == level - 1) {
                    rightIndex = index;
                }
                if (curNode.left != null) {
                    queue.add(curNode.left);
                    indexQueue.add(index * 2);
                }
                if (curNode.right != null) {
                    queue.add(curNode.right);
                    indexQueue.add(index * 2 + 1);
                }
            }
            ans = Math.max(ans, rightIndex - leftIndex + 1);
            }
        return ans;
    }
}