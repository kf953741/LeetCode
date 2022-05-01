/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0 || prices.size() == 1)
        {
            return 0;
        }

        vector<int> hold(prices.size());
        vector<int> unhold(prices.size());
        hold[0] = -prices[0];
        hold[1] = max(-prices[0], -prices[1]);
        unhold[0] = 0;
        unhold[1] = max(prices[1] - prices[0], 0);

        if (prices.size() == 2)
        {
            return unhold[1];
        }

        int ret = INT_MIN;

        for (size_t i = 2; i < prices.size(); i++)
        {
            hold[i] = max(hold[i - 1], unhold[i - 2] - prices[i]);
            unhold[i] = max(unhold[i - 1], hold[i - 1] + prices[i]);
            int curMax = max(hold[i],unhold[i]);
            ret = max(curMax,ret);
        }
        return ret;
    }
};
// @lc code=end
