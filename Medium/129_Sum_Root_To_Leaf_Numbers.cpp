struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        // Time: O(n), space: O(1)
        // Runtime: 0ms
        updateTree(0, root);
        return sumLeaves(root);
    }

private:
    int sumLeaves(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        int sum = 0;
        sum += (root->left) ? sumLeaves(root->left) : 0;
        sum += (root->right) ? sumLeaves(root->right) : 0;
        return sum;
    }

    void updateTree(int parent, TreeNode *root) {
        if (!root)
            return;
        root->val += parent * 10;
        updateTree(root->val, root->left);
        updateTree(root->val, root->right);
    }
};
