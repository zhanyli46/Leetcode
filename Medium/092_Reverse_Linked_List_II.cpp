struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // Time: O(n), space: O(1)
        // Runtime: 0ms
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        for (int i = 1; i < m; ++i)
            p = p->next;
        ListNode *prev = p, *cur = p->next, *next;
        for (int i = m; i <= n; ++i) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        p->next->next = next;
        p->next = prev;
        return dummy->next;
    }
};
