using System;

namespace LeetCodeAndSwordOffer
{
    public class CoinChange322
    {
        public int CoinChange(int[] coins, int amount) 
        {
            int[] dp = new int[amount+1];
            Array.Fill(dp,amount+1);
            dp[0] = 0;
            for (int i = 1; i <= amount; i++)
            {
                foreach (var coin in coins)
                {
                    if (coin<=i)
                    {
                        dp[i] = Math.Min(dp[i], dp[i - coin] + 1);
                    }
                }
            }

            return dp[amount] == amount + 1 ? -1 : dp[amount];
        }
    }
}