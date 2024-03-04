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
    ListNode* partition(ListNode* head, int x) {
        ListNode *le = new ListNode(-1), *gre = new ListNode(-1);
        ListNode *less = le, *greater = gre;

        ListNode *p = head;
        while (p)
        {
            if (p->val < x)
            {
                // ListNode *tmp = new ListNode(p->val);
                less->next = p;
                less = less->next;
            }
            else
            {
                // ListNode *tmp = new ListNode(p->val);
                greater->next = p;
                greater = greater->next;
            }
            p = p->next;
        }
        greater->next = nullptr;
        less->next = gre->next;
        return le->next;
    }
};
