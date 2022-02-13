/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> bits(n + 1);
        for (size_t i = 0; i <= n; i++)
        {
            bits[i] = GetOnes(i);
        }
        return bits;
    }

    int GetOnes(int x)
    {
        int ones = 0;
        while (x)
        {
            x &= (x-1);
            ones++;
        }
        return ones;
    }
};
// @lc code=end

