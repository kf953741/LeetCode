/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int result = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    dfs(grid,i,j);
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n)
        {
            return;
        }
        if (grid[row][col] == '0')
        {
            return;
        }
        grid[row][col] = '0';
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }
};
// @lc code=end
