
import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode id=1161 lang=java
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */
// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

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

    public int maxLevelSum(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        int maxS = Integer.MIN_VALUE, level = 1, curLevel = 1;
        q.add(root);
        while (!q.isEmpty()) {
            int sz = q.size(), curS = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode top = q.poll();
                curS += top.val;
                if (top.left != null) {
                    q.add(top.left);
                }
                if (top.right != null) {
                    q.add(top.right);
                }
            }
            if(curS > maxS){
                maxS = curS;
                level = curLevel;
            }
            curLevel++;
            maxS = Math.max(curS, maxS);
        }
        return level;
    }
}
// @lc code=end

