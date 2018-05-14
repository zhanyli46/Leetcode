struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 6ms */
        if (!head || !head->next) return head;
        ListNode dummy(0), *p = head;
        dummy.next = head->next;
        while (p && p->next) {
            ListNode *temp = p->next->next;
            p->next->next = p;
            p->next = (temp && temp->next) ? temp->next : temp;
            p = temp;
        }
        return dummy.next;
    }
};
