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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        auto oh = head, ot = oh;
        auto eh = head->next, et = eh;
        for (auto p = head->next->next; p;)
        {
            ot->next = p;
            ot = ot->next;
            p = p->next;
            if (p)
            {
                et->next = p;
                et = et->next;
                p = p->next;
            }
        }
        ot->next = eh;
        et->next = nullptr;
        return oh;
    }
};
