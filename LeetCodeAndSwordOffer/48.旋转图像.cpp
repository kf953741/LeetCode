/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (size_t i = 0; i < n / 2; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
            
        }
    }
};
// @lc code=end

