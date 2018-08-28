struct TreeLinkNode {
     int val;
     TreeLinkNode *left, *right, *next;
     TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Time: O(n), space: O(1) stack
        // Runtime: 20ms
        while (root) {
            TreeLinkNode *next = new TreeLinkNode(0);
            TreeLinkNode *cur = next;
            while (root) {
                if (root->left) {
                    cur->next = root->left;
                    cur = cur->next;
                }
                if (root->right) {
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = next->next;
        }
    }
};
