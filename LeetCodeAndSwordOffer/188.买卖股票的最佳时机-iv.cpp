/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0 || n == 1)
        {
            return 0;
        }
        k = k + 1;
        vector<vector<int>> hold(n, vector<int>(k));
        vector<vector<int>> unhold(n, vector<int>(k));

        for (size_t i = 0; i < n; i++)
        {
            hold[i][0] = 0;
            unhold[i][0] = 0;
        }
        for (size_t i = 1; i < k; i++)
        {
            hold[0][i] = -prices[0];
            unhold[0][i] = 0;
        }

        int ret = 0;
        for (size_t i = 1; i < n; i++)
        {
            for (size_t j = 1; j < k; j++)
            {
                hold[i][j] = max(hold[i - 1][j], unhold[i - 1][j - 1] - prices[i]);
                unhold[i][j] = max(unhold[i - 1][j], hold[i - 1][j] + prices[i]);
                int curMax = max(hold[i][j], unhold[i][j]);
                ret = max(ret, curMax);
            }
        }
        return ret;
    }
};
// @lc code=end
