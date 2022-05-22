/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        auto num_prev = [](char x) -> char
        {
            return (x == '0' ? '9' : x - 1);
        };
        auto num_next = [](char x) -> char
        {
            return (x == '9' ? '0' : x + 1);
        };

        unordered_set<string> visited;
        for (auto &&i : deadends)
        {
            if (i == "0000")
                return -1;
            visited.insert(i);
        }
        int step = 0;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        while (!q.empty())
        {
            int size = q.size();
            for (size_t i = 0; i < size; i++)
            {
                string s = q.front();
                q.pop();

                if (s == target)
                {
                    return step;
                }
                for (size_t j = 0; j < 4; j++)
                {
                    char num = s[j];

                    s[j] = num_prev(num);
                    if (!visited.count(s))
                    {
                        visited.insert(s);
                        q.push(s);
                    }

                    s[j] = num_next(num);
                    if (!visited.count(s))
                    {
                        visited.insert(s);
                        q.push(s);
                    }
                    s[j] = num;
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end