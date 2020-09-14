/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    vector<string> res;
    string path;
    vector<string> generateParenthesis(int n)
    {
        backtrack(n, 0, 0);
        return res;
    }
    void backtrack(int n, int l, int r)
    {
        if (path.size() == 2 * n)
        {
            res.push_back(string(path));
            return;
        }
        if (r > l)
        {
            return;
        }
        if (l < n)
        {
            path.append("(");
            backtrack(n, l + 1, r);
            path.pop_back();
        }
        if (r < n)
        {
            path.append(")");
            backtrack(n, l, r + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
