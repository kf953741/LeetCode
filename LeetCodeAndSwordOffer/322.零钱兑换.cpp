/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int result = INT_MAX;
        for (int i = 1; i <= amount; i++)
        {
            for (auto &&coin : coins)
            {
                if (i - coin < 0)
                {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        result = dp[amount] > amount ? -1 : dp[amount];
        return result;
    }
};
// @lc code=end
