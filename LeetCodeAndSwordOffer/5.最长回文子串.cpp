/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int max = -1;
        int left = 0;
        int right = 0;
        vector<vector<int>> dp(n, vector<int>(n, false));
    }
};
// @lc code=end
