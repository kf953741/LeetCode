/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> memo;
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int row = dungeon.size();
        int col = dungeon[0].size();
        memo.resize(row, vector<int>(col, 0));
        return dfs(dungeon, 0, 0);
    }

    int dfs(vector<vector<int>> &dungeon, int i, int j)
    {
        int row = dungeon.size();
        int col = dungeon[0].size();
        if (i >= row || j >= col)
        {
            return INT_MAX;
        }

        if (i == row - 1 && j == col - 1)
        {
            return max(0, -dungeon[i][j]) + 1;
        }
        if (memo[i][j] != 0)
        {
            return memo[i][j];
        }
        int a = dfs(dungeon, i, j + 1);
        int b = dfs(dungeon, i + 1, j);
        memo[i][j] = max(1, min(a, b) - dungeon[i][j]);
        return memo[i][j];
    }
};
// @lc code=end
