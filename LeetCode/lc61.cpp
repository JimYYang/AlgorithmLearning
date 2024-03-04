/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k)
            return head;
        int n = 0;
        ListNode *p = head;
        while (p)
        {
            ++n;
            p = p->next;
        }

        k %= n;
        p = head;
        ListNode *q = head;
        for (int i = 0; i < k; i++)
        {
            q = q->next;
        }

        while (q->next)
        {
            p = p->next;
            q = q->next;
        }

        q->next = head;
        ListNode *ans = p->next;
        p->next = nullptr;
        return ans;
    }
};
