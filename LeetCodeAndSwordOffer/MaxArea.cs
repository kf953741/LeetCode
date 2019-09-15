using System;

namespace LeetCodeAndSwordOffer
{
    public class MaxArea11
    {
        public int MaxArea(int[] height)
        {
            int i = 0;
            int j = height.Length-1;
            int max = int.MinValue;
            while (i<j)
            {
                int value=Math.Min(height[i],height[j])*(j-i);
                if (value>max)
                {
                    max = value;
                   
                }
                if (height[i]>height[j])
                {
                    j--;
                }
                else
                {
                    i++;
                }
            }

            return max;
        }
    }
}