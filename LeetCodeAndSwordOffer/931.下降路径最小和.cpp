/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (size_t i = 0; i < col; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for (size_t i = 1; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                dp[i][j] = dp[i - 1][j] + matrix[i][j];
                if (j > 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + matrix[i][j]);
                }
                if (j < col - 1)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + matrix[i][j]);
                }
            }
        }
        int result = INT_MAX;
        for (size_t i = 0; i < col; i++)
        {
            result = min(result, dp[row - 1][i]);
        }
        return result; 
    }
};
// @lc code=end
