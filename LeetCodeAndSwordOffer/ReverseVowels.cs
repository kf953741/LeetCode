using System.Collections.Generic;
using System.Collections.Immutable;

namespace LeetCodeAndSwordOffer
{
    public class ReverseVowels345
    {
        private HashSet<char> Vowels = new HashSet<char>()
        {
            'a','e','i','o','u',
            'A','E','I','O','U'
        };
        public string ReverseVowels(string s)
        {
            char[] result = s.ToCharArray();
            int i = 0;
            int j = s.Length-1;
            while (i<j)
            {
                if (!Vowels.Contains(result[i]))
                {
                    i++;
                }
                else if (!Vowels.Contains(result[j]))
                {
                    j--;
                }
                else
                {
                    Swap(i++,j--,result);
                }
            }

            return new string(result);
        }

        private void Swap(int i,int j,char[] nums)
        {
            char temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}