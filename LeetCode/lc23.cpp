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
    struct cmp{
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for (auto &list : lists) if (list) heap.push(list);

        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while (heap.size())
        {
            auto cur = heap.top();
            heap.pop();

            tail->next = cur;
            tail = tail->next;
            if (cur->next) heap.push(cur->next);
        }
        return dummy->next;
    }
};
