/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        int index = 0;
        ListNode *cur = head;
        ListNode *pre = nullptr;
        for (int i = 1; cur != nullptr && i < m; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        ListNode *next = nullptr;
        ListNode *lastPre = pre;
        ListNode *lastCur = cur;
        for (int i = 0; cur != nullptr && i <= n - m; i++)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if (lastCur != nullptr)
        {
            lastCur->next = cur;
        }

        if (lastPre != nullptr)
        {
            lastPre->next = pre;
        }
        else 
        {
            head = pre;
        }

        return head;
    }
};
// @lc code=end
