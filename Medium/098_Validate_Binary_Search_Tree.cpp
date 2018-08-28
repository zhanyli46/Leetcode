class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Time: O(nh^2), space: O(1)
        // Runtime: 8ms
        if (!root)
            return true;
        TreeNode *left = root->left, *right = root->right;
        while (left && left->right)
            left = left->right;
        while (right && right->left)
            right = right->left;
        bool left_property = left ? left->val < root->val : true;
        bool right_property = right ? root->val < right->val : true;
        return left_property && right_property && isValidBST(root->left) && isValidBST(root->right);
    }
};
