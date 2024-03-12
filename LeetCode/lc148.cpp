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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;
        auto l = sortList(head);
        auto r = sortList(slow);

        return merge(l, r);
    }

    ListNode* merge(ListNode *p, ListNode *q)
    {
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        while (p && q)
        {
            if (p->val <= q->val)
            {
                cur->next = p;
                p = p->next;
            } 
            else
            {
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        }

        cur->next = (p ? p : q);
        return dummy->next;
    }
};
