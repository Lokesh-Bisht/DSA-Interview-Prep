package leetcode.java.tree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * TC => O(n)
 * SC => O(n)
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

public class BinaryTreeZigzagLevelOrderTraversal {

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int level = 0;
        while (!queue.isEmpty()) {
            int n = queue.size();
            Stack<Integer> stack = new Stack<>();
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                TreeNode node = queue.peek();
                queue.poll();
                if (level % 2 == 0) {
                    list.add(node.val);
                } else {
                    stack.add(node.val);
                }
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            while (!stack.isEmpty()) {
                list.add(stack.peek());
                stack.pop();
            }
            ans.add(list);
            level++;
        }
        return ans;
    }
}
