/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class UnionFind
{
private:
    vector<int> parent;
    int count = 0;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        for (size_t i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int GetCount()
    {
        return count;
    }
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int p, int q)
    {
        parent[find(p)] = find(q);
        count--;
    }

    bool conented(int p, int q)
    {
        return find(p) == find(q);
    }
};
class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        UnionFind uf(26);
        for (const string &str : equations)
        {
            if (str[1] == '=')
            {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                uf.unite(index1, index2);
            }
        }
        for (const string &str : equations)
        {
            if (str[1] == '!')
            {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                if (uf.conented(index1, index2))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
