using System;

namespace LeetCodeAndSwordOffer
{
    public class MinSubArrayLen209
    {
        public int MinSubArrayLen(int s, int[] nums)
        {
            int i = 0;
            int j = 0;
            int sum = 0;
            int min = int.MaxValue;
            while (j<nums.Length)
            {
                sum += nums[j++];
                while (sum>=s)
                {
                    sum -= nums[i];
                    min = Math.Min(min, j - i);
                    i++;
                }
            }

            if (min==int.MaxValue)
            {
                min = 0;
            }
            return min;
        }
    }
}