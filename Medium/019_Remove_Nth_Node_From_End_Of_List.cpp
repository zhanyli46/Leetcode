struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 10ms */
        ListNode dummy(0);
        ListNode *p1, *p2;
        dummy.next = head;
        p1 = p2 = &dummy;
        for (int i = 0; i < n; ++i) {
            p2 = p2->next;
        }
        while (p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return dummy.next;
    }
};
