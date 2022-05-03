/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode *root)
    {
        vector<int> ret = robTree(root);
        return max(ret[0], ret[1]);
    }
    vector<int> robTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return vector<int>{0, 0};
        }
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        int rob = root->val + left[0] + right[0];
        int noRob = max(left[0], left[1]) + max(right[0], right[1]);
        return {noRob,rob};
    }
};
// @lc code=end
