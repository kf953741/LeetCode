/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        path.push_back(0);
        traverse(graph, 0, graph.size() - 1);
        return result;
    }
    void traverse(vector<vector<int>> &graph, int x, int n)
    {
        if (x == n)
        {
            result.push_back(path);
            return;
        }
        for (auto &&i : graph[x])
        {
            path.push_back(i);
            traverse(graph, i, n);
            path.pop_back();
        }
    }
};
// @lc code=end
