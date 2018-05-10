struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /* Time: O(log n), space: O(1) */
        /* Runtime: 26ms */
        if (!root || !p || !q) return root;
        TreeNode *cur = root;
        int low = min(p->val, q->val);
        int high = max(p->val, q->val);
        while (cur) {
            if (cur->val < low)
                cur = cur->right;
            else if (cur->val > high)
                cur = cur->left;
            else break;
        }
        return cur;
    }
};
