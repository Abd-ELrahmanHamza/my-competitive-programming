/*
 * @lc app=leetcode id=865 lang=java
 *
 * [865] Smallest Subtree with all the Deepest Nodes
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
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

    TreeNode resNode;
    int resLevel = 1;
    int cntDLNodes = 0;
    int dl = 0;

    private int deepestLevel(TreeNode root) {
        if (root == null) {
            return 0;
        }

        return 1 + Math.max(deepestLevel(root.left), deepestLevel(root.right));
    }

    private void countDLNodes(TreeNode root, int level) {
        if (root == null) {
            return;
        }

        if (level == dl) {
            cntDLNodes++;
            return;
        }

        countDLNodes(root.left, level + 1);
        countDLNodes(root.right, level + 1);
    }

    private int solve(TreeNode root, int level) {
        if (root == null) {
            return 0;
        }

        if (level == dl) {
            if (cntDLNodes == 1) {
                resLevel = level;
                resNode = root;
            }
            return 1;
        }

        int s = solve(root.left, level + 1) + solve(root.right, level + 1);
        if (s == cntDLNodes) {
            if (level > resLevel) {
                resNode = root;
                resLevel = level;
            }
        }
        return s;
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        dl = deepestLevel(root);
        countDLNodes(root, 1);

        resNode = root;
        solve(root, 1);
        return resNode;
    }
}
// @lc code=end

