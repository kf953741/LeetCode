/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> map;
        for (auto &&str : strs)
        {
            string temp = str;
            sort(temp.begin(),temp.end());
            map[temp].emplace_back(str);
        }
        for (auto &&i : map)
        {
            ans.emplace_back(i.second);
        }
        return ans;
        
    }
};
// @lc code=end

