/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> res;
        backtrack(res, 0,S);
        return res;
    }
    void backtrack(vector<string> &res, int level,string& S)
    {
        if (level==S.length())
        {
            res.push_back(S);
            return;
        }
        backtrack(res,level+1,S);
         if(isalpha(S[level]))
         {
            S[level] = S[level] ^ 32;
             backtrack(res,level+1,S);
        }
    }
};
// @lc code=end
