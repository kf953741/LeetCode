using System;

namespace LeetCode
{
    public class l322
    {

        public static void Main(string[] args)
        {
           
            Console.WriteLine(CoinChange(new int[]{ 1 }, 1));
        }


        public static int CoinChange(int[] coins, int amount)
        {
            int[] dp = new int[amount + 1];
            if (amount <= 0)
            {
                return 0;
            }
            for (int i = 1; i <= amount; i++)
            {
                dp[i] = int.MaxValue;
            }

            for (int i = 1; i <= amount; i++)
            {
                for (int j = 0; j < coins.Length; j++)
                {
                    if (coins[j] <= i)
                    {
                        int num = dp[i - coins[j]];
                        if (num != int.MaxValue)
                        {
                            dp[i] = Math.Min(num + 1, dp[i]);
                        }

                    }
                }
            }
            return dp[amount] < int.MaxValue ? dp[amount] : -1;
        }
    }
}

