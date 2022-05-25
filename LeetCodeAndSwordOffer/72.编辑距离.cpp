/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
        for (size_t i = 0; i <= size1; i++)
        {
            dp[i][0] = i;
        }
        for (size_t i = 0; i <= size2; i++)
        {
            dp[0][i] = i;
        }
        for (size_t i = 1; i <= size1; i++)
        {
            for (size_t j = 1; j <= size2; j++)
            {
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min3(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[size1][size2];
    }
    int min3(int a, int b, int c)
    {
        return min(a, min(b, c));
    }
};
// @lc code=end
