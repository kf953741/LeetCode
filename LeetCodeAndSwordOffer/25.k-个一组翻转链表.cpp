/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *next = dummy;
        ListNode *start = head;
        ListNode *end = dummy;
        while (end->next != nullptr)
        {
            for (int i = 0; end != nullptr && i < k; i++)
            {
                end = end->next;
            }
            if (end == nullptr)
            {
                break;
            }
            next = end->next;
            end->next = nullptr;
            start = pre->next;
            pre->next = reverse(start);
            start->next = next;
            pre = start;
            end = start;
        }

        return dummy->next;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end
