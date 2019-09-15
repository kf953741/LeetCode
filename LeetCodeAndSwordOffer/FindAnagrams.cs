using System;
using System.Collections.Generic;

namespace LeetCodeAndSwordOffer
{
    public class FindAnagrams438
    {
        public IList<int> FindAnagrams(string s, string p) {
            IList<int> result = new List<int>();
            HashSet<char> pChar = new HashSet<char>(p.ToCharArray());
            int j = 0;
            while (j<s.Length)
            {
                bool include = true;
                for (int k = j; k < j+p.Length; k++)
                {
                   
                    if (k<s.Length&&!pChar.Contains(s[k]))
                    {
                        include = false;
                    }
                }

                if(include)
                {
                    result.Add(j);
                }

                j++;
            }

            return result;
        }
    }
}