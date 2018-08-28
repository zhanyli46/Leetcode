struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Time: O(nlogn), space: O(logn) stack
        // Runtime: 16ms
        return sortedListToBST(head, NULL);
    }

    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if (head == tail)
            return nullptr;
        if (head->next == tail) {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head, slow);
        root->right = sortedListToBST(slow->next, tail);
        return root;
    }
};
