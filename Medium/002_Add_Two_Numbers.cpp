struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /* Time O(n), space O(1) */
        /* Runtime: 64ms */
        ListNode dummy(0);
        ListNode *p1 = l1, *p2 = l2, *p = &dummy;
        int carry = 0;
        while (p1 || p2 || carry) {
            int sum = carry + (p1 ? p1->val : 0) + (p2 ? p2->val : 0);
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            p1 = p1 ? p1->next : NULL;
            p2 = p2 ? p2->next : NULL;
        }
        return dummy.next;
    }
};
