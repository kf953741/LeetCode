/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
using namespace std;
#include <unordered_map>
#include <vector>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counts;
        int max=0;
        int ret =0;
        for (auto &&n : nums)
        {
            counts[n]++;
            if (counts[n]>max)
            {
                max = counts[n];
                ret = n;
            }
            
        }
        return ret;

        
    }
};
// @lc code=end

