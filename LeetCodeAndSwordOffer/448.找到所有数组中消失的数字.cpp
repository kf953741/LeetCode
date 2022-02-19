/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
using namespace std;
#include <vector>
// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto &&num : nums)
        {
            int x = (num-1) % n;
            nums[x] += n;
        }

        vector<int> ret;
        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] <= n)
            {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};
// @lc code=end

