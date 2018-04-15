using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        /* Naive recursion */
        /* Time: O(n^2), space: O(1) */
        /* Runtime: 18ms */
        if (!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) &&
            (abs(depth(root->left) - depth(root->right)) <= 1);
    }

    bool isBalanced(TreeNode* root) {
        /* Recursion without repetition */
        /* Time: O(n), space: O(1) */
        /* Runtime: 9ms */
        return validDepth(root) != -1;
    }

private:
    /* Helper */
    int validDepth(TreeNode* root) {
        if (!root) return 0;
        int left = validDepth(root->left);
        int right = validDepth(root->right);
        if (left == -1 || right == -1)
            return -1;
        int diff = abs(left - right);
        return (diff > 1) ? -1 : max(left, right) + 1;
    }

    int depth(TreeNode* root) {
        if (!root) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};
