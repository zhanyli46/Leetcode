struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        /* Time: O(1), space: O(1) */
        /* Runtime: 13ms */
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
