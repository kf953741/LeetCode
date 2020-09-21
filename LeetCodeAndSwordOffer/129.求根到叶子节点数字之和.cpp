/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int res = 0;
    int sumNumbers(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return;
        }
        sum = sum * 10 + root->val;
        if (!root->left && !root->right)
        {
            res += sum;
        }

        dfs(root->left, sum);
        dfs(root->right, sum);
    }
};
// @lc code=end
