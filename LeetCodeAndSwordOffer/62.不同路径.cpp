/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for (size_t i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (size_t i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }
        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            
        }
        return dp[m-1][n-1];
        
    }
};
// @lc code=end

