/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> edges;
    vector<bool> visited;
    vector<bool> path;
    bool bOK = true;
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        path.resize(numCourses);
        for (auto &&info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }
        for (size_t i = 0; i < numCourses; i++)
        {
            traverse(i);
        }
        return bOK;
    }
    void traverse(int v)
    {
        if (path[v])
        {
            bOK = false;
        }
        if (visited[v] || !bOK)
        {
            return;
        }
        visited[v] = true;
        path[v] = true;
        for (auto &&i : edges[v])
        {
            traverse(i);
        }
        path[v] = false;
    }
};
// @lc code=end
