struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Time: O(n), space: O(1)
        // Runtime: 4ms
        ListNode *first, *second;
        first = new ListNode(0);
        second = new ListNode(0);
        ListNode *p1 = first, *p2 = second, *p = head;
        while (p) {
            if (p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        p1->next = second->next;
        p2->next = NULL;
        return first->next;
    }
};
