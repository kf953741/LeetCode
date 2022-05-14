/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution
{
public:
    vector<bool> color;
    vector<bool> visited;
    bool bOk = true;
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        visited.resize(n);
        color.resize(n);
        for (size_t node = 0; node < n; node++)
        {
            if (!visited[node])
            {
                traverse(graph, node);
            }
        }
        return bOk;
    }
    void traverse(vector<vector<int>> &graph, int node)
    {
        if (!bOk)
        {
            return;
        }
        visited[node] = true;
        for (auto &&neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                color[neighbor] = !color[node];
                traverse(graph, neighbor);
            }
            else
            {
                if (color[neighbor] == color[node])
                {
                    bOk = false;
                }
            }
        }
    }
};
// @lc code=end
