/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> ret;
        while (!st.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            ret.push_back(root->val);

            root = root->right;
        }

        return ret;
    }
};
// @lc code=end
