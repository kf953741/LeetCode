/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> curPath;
        unordered_set<int> used;
        backtrack(nums, curPath,used);
        return result;
    }
    void backtrack(vector<int> &nums, vector<int> &curPath, unordered_set<int> &used)
    {
        if (curPath.size() == nums.size())
        {
            result.push_back(curPath);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (used.find(i)==used.end())
            {
                curPath.push_back(nums[i]);
                used.insert(i);
                backtrack(nums, curPath, used);
                curPath.pop_back();
                used.erase(i);
            }
        }
    }
};
// @lc code=end
