/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        backtrack(n,k,cur,1);
        return res;
    }
    void backtrack(int n,int k,vector<int> cur,int level)
    {
        if (cur.size()==k)
        {
            res.push_back(cur);
            return;
        }
        for (int i = level; i <=n-(k-cur.size())+1; i++)
        {
            cur.push_back(i);
            backtrack(n,k,cur,i+1);
            cur.pop_back();
        }
    }
};
// @lc code=end

