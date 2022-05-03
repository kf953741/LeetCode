/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        int n = digits.size();
        vector<string> ret;
        if (n == 0)
        {
            return ret;
        }

        vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string curString;
        dfs(digits, board, ret, 0, curString);
        return ret;
    }
    void dfs(const string &digits, const vector<string> &board, vector<string> &ret, int index, string &curString)
    {
        if (curString.size() == digits.size())
        {
            ret.push_back(curString);
            return;
        }
        int num = digits[index] - '0';
        const string &letter = board[num];
        for (size_t i = 0; i < letter.size(); i++)
        {
            curString.push_back(letter[i]);
            dfs(digits, board, ret, index + 1, curString);
            curString.pop_back();
        }
    }
};
// @lc code=end
