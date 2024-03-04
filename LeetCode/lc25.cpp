i/**
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy;

        while (true)
        {
            ListNode *q = p;
            for (int i = 0; i < k && q; i++)
            {
                q = q->next;
            }
            if (q == nullptr)
                break;
            ListNode *a = p->next, *b = a->next;
            for (int i = 0; i < k - 1; i++)
            {
                ListNode *bNext = b->next;
                b->next = a;
                a = b;
                b = bNext;
            }
            ListNode *pNext = p->next;
            p->next = a;
            pNext->next = b;
            p = pNext;
        }
        return dummy->next;
    }
}
