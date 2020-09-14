/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool left2right = true;
        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> curLevel(levelSize);
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (left2right)
                {
                    curLevel[i] = node->val;
                }
                else
                {
                    curLevel[levelSize - 1 - i] = node->val;
                }

                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            left2right = !left2right;
            res.push_back(curLevel);
        }
        return res;
    }
};
// @lc code=end
