/*
 * @lc app=leetcode.cn id=340 lang=cpp
 *
 * [340] 至多包含 K 个不同字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int windowStart = 0;
        int maxLength = 0;
        unordered_map<char, int> charFrequencyMap;
        for (int i = 0; i < s.length(); i++)
        {
            char rightChar = s[i];
            charFrequencyMap[rightChar]++;
            while (charFrequencyMap.size() > k)
            {
                char leftChar = s[windowStart];
                charFrequencyMap[leftChar]--;
                if (charFrequencyMap[leftChar] == 0)
                {
                    charFrequencyMap.erase(leftChar);
                }
                windowStart++;
            }
            maxLength = max(maxLength,i-windowStart+1);
        }
        return maxLength;
    }
};
// @lc code=end