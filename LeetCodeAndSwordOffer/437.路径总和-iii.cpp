/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode *root, int sum)
    {
        vector<int> curPath;
        backtrack(root, sum, curPath);
        return res;
    }
    void backtrack(TreeNode *root, int sum, vector<int> &curPath)
    {
        if (!root)
        {
            return;
        }
        curPath.push_back(root->val);
        int all = 0;
        for (vector<int>::reverse_iterator itr = curPath.rbegin();
             itr != curPath.rend(); ++itr)
        {
            all += *itr;
            if (all == sum)
            {
                res++;
            }
        }

        backtrack(root->left, sum, curPath);
        backtrack(root->right, sum, curPath);
        curPath.pop_back();
    }
};
// @lc code=end
