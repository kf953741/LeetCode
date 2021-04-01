/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> memo;
        int left= 0;
        int right= 0;
        int maxStr= 0;
        for (int i = 0; i < s.size(); i++)
        {
            while (memo.find(s[i]) != memo.end())
            {
                memo.erase(s[left]);
                left++;
            }
            memo.insert(s[i]);
            maxStr= max(maxStr,i-left+1);            
        }
        return maxStr;
    }
};
// @lc code=end
