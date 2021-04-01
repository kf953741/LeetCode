/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
        {
            return head;
        }

        int size = 1;
        ListNode *pos = head;
        while (pos && pos->next != nullptr)
        {
            pos = pos->next;
            size++;
        }
        int startIndex = size - k % size;
        if (startIndex == size)
        {
            return head;
        }

        ListNode *startNode = head;
        for (int i = 1; i < startIndex; i++)
        {
            startNode = startNode->next;
        }
        ListNode *result = startNode->next;

        startNode->next = nullptr;
        pos->next = head;

        return result;
    }
};
// @lc code=end
