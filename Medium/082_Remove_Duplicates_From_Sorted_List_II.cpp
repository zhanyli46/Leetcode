struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Time: O(n), space: O(1)
        // Runtime: 4ms
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *slow = head, *fast = head;
        while (fast) {
            while (fast->next && fast->next->val == slow->val)
                fast = fast->next;
            if (slow == fast) {
                prev = slow;
                slow = slow->next;
                fast = slow;
            } else {
                fast = fast->next;
                prev->next = fast;
                slow = fast;
            }
        }
        return dummy->next;
    }
};
