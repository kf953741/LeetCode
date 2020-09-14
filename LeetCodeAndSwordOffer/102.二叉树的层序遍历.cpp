/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int levelNum = q.size();
            vector<int> curLevel;
            for (int i = 0; i < levelNum; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                curLevel.push_back(node->val);
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            res.push_back(curLevel);
        }
        return res;
    }
};
// @lc code=end
