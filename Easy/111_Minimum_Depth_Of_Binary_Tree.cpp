#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        /* DFS, recursion */
        /* Time: O(n), space: O(1) */
        /* Runtime: 15ms */
        return shortestDepth(root);
    }

    int minDepth(TreeNode* root) {
        /* Recursion without helper */
        /* Time: O(n), space: O(1) */
        /* Runtime: 9ms */
        if (!root)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0 && right == 0)
            return 1;
        else if (left == 0)
            return right + 1;
        else if (right == 0)
            return left + 1;
        else
            return min(left, right) + 1;
    }

private:
    int shortestDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left)
            return shortestDepth(root->right) + 1;
        else if (!root->right)
            return shortestDepth(root->left) + 1;
        return min(shortestDepth(root->left), shortestDepth(root->right)) + 1;
    }
};
