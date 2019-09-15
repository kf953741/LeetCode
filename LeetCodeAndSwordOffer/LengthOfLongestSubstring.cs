using System;
using System.Collections.Generic;

namespace LeetCodeAndSwordOffer
{
    public class LengthOfLongestSubstring3
    {
        public int LengthOfLongestSubstring(string s)
        {
            if (s.Length==0)
            {
                return 0;
            }
            int i=0; 
            int j = 0;
            int l = int.MinValue;
            while (j<s.Length)
            {
                for (int k = i; k <=j-1; k++)
                {
                    if (s[k]==s[j])
                    {
                        i=k+1;
                    }
                }

                l = Math.Max(l, j - i);
                j++;
            }

            return l+1;
        }
        
        //sulution2
        public int LengthOfLongestSubstring2(string s)
        {
            HashSet<char> h = new HashSet<char>();
            int max = 0;
            int i = 0;
            for (int k = 0; k < s.Length;)
            {
                if (!h.Contains(s[k]))
                {
                    h.Add(s[k++]);
                    max = Math.Max(max, h.Count);
                }
                else
                {
                    h.Remove(s[i++]);
                }
            }

            return max;
        }
    }
}