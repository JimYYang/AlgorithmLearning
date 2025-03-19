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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        int n = 0;
        ListNode *a = head;
        while(a)
        {
            a = a->next;
            n++;
        }

        a = head;
        for (int i = 0; i < (n + 1) / 2 - 1; i++) a = a->next;
        auto b = a->next;
        for (int i = 0; i < n / 2; i++)
        {
            auto bNext = b->next;
            b->next = a;
            a = b;
            b = bNext;
        }

        auto p = head, q = a;
        bool res = true;
        cout << a->val << endl;
        for (int i = 0; i < n / 2; i++)
        {
            if (p->val != q->val)
            {
                res = false;
                break;
            }
            p = p->next;
            q = q->next;
        }
        auto tail = a;
        b = a->next;
        for (int i = 0; i < n / 2; i++)
        {
            auto bNext = b->next;
            b->next = a;
            a = b;
            b = bNext;
        }
        tail->next = nullptr;
        return res;
    }
};
