/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int max = INT_MIN;
        dfs(root, max);
        return max;
    }

    int dfs(TreeNode *root, int &maxSum)
    {
        if (root==nullptr) return 0;
        int maxLeft = max(dfs(root->left, maxSum), 0);
        int maxRight = max(dfs(root->right, maxSum), 0);
        maxSum = max(maxSum, maxLeft + maxRight + root->val);
        return max(maxLeft, maxRight) + root->val;
    }
};
// @lc code=end
