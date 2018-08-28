
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Time: O(n), space: O(1) stack
        // Runtime: 20ms
        if (!root)
            return;
        TreeLinkNode *next = root, *cur = nullptr;
        while (next->left) {
            cur = next;
            next = next->left;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
        }
    }
};
