/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        backtrack(root, sum);
        return res;
    }
    void backtrack(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return;
        }
        cur.push_back(root->val);
        if (root->val == sum && root->left == nullptr && root->right == nullptr)
        {
            res.push_back(vector<int>(cur));
            cur.pop_back();
            return;
        }
        backtrack(root->left,sum-root->val);
        backtrack(root->right,sum-root->val);
        cur.pop_back();
    }
};
// @lc code=end
