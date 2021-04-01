/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int res = 0;
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        return dfs(root, low, high);
    }

    int dfs(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int sum = 0;
        if (root->val < low)
        {
            sum = dfs(root->right, low, high);
        }
        else if (root->val > high)
        {
            sum = dfs(root->left, low, high);
        }
        else
        {
            sum = dfs(root->left, low, high) + dfs(root->right, low, high) + root->val;
        }
        return sum;
    }
};
// @lc code=end
