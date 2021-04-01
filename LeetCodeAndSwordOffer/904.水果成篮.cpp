/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int windowStart = 0;
        int maxLength = 0;
        unordered_map<int, int> charFrequencyMap;
        for (int i = 0; i < tree.size(); i++)
        {
            int rightChar = tree[i];
            charFrequencyMap[rightChar]++;
            while (charFrequencyMap.size() > 2)
            {
                int leftChar = tree[windowStart];
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

