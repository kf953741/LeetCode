/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(nums,cur,res);
        return res;
    }
    void backtrack(vector<int>& nums,vector<int>& cur,vector<vector<int>>& res)
    {
        if (cur.size()==nums.size())
        {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            auto have = std::find(cur.begin(),cur.end(),nums[i]);
            if (have==cur.end())
            {
                cur.push_back(nums[i]);
                backtrack(nums,cur,res);
                cur.pop_back();
            }
            
        }
        
        
    }
};
// @lc code=end

