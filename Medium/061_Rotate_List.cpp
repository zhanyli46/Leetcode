struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /* Time: O(n), space: O(1) */
    /* Runtime: 7ms */
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode *end = head;
        int count = 0;
        while (end && end->next) {
            ++count;
            p = p->next;
        }
        ++count;
        k %= count;
        end->next = head;
        for (int i = 0; i < count - k; ++i)
            end = end->next;
        ListNode *new_head = end->next;
        end->next = NULL;
        return new_head;
    }
};
