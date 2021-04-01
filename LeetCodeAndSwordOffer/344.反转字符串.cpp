/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        helper(s,0,s.size()-1);
    }
    void helper(vector<char>& s,int l,int r)
    {
        if (l>=r)
        {   
            return;
        }
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        helper(s,l+1,r-1);
    }
};
// @lc code=end

