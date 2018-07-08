using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // Time: O(log_2(n)), space: O(log_2(n))
        // Runtime: 0ms
        if (!root) return 0;
        int sum = 0;
        if (root->left && !root->left->left && !root->left->right) {
            sum += root->left->val;
            sum += sumOfLeftLeaves(root->right);
        } else {
            sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};
