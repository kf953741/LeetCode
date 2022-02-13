/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y;
        int ret = 0;
        while (s)
        {
            ret += s & 1;
            s >>= 1;
        }
        return ret;
    }
};
// @lc code=end

