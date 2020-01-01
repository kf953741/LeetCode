using System;
using System.Collections.Generic;

namespace LeetCodeAndSwordOffer
{
    public class LengthOfLIS300
    {
        //动态规划 O(n2)
        public int LengthOfLIS(int[] nums)
        {
            if (nums.Length==0)
            {
                return 0;
            }
            //memo[i]表示以nums[i]为结尾的最长上升子序列
            List<int> memo = new List<int>(nums.Length);
            for (int i = 0; i < nums.Length; i++)
            {
                memo.Add(1);
            }

            for (int i = 1; i < nums.Length; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[j]<nums[i])
                    {
                        memo[i] = Math.Max(memo[i], 1 + memo[j]);
                    }
                   
                }
            }

            int result = 1;
            for (int i = 0; i < memo.Count; i++)
            {
                result = Math.Max(result, memo[i]);
            }
            return result;
        }
    }
}