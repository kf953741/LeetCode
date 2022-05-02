/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n == 0 || n == 1)
        {
            return 0;
        }
        vector<int> hold(n);
        vector<int> unhold(n);
        hold[0] = -prices[0];
        unhold[0] = 0;
        int ret = INT_MIN;
        for (size_t i = 1; i < n; i++)
        {
            hold[i] = max(hold[i - 1], unhold[i - 1] - prices[i]);
            unhold[i] = max(unhold[i - 1], hold[i - 1] + prices[i] - fee);
            int curMax = max(hold[i], unhold[i]);
            ret = max(ret, curMax);
        }
        return ret;
    }
};
// @lc code=end
