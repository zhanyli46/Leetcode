#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 9ms */
        vector<string> v;
        if (!root) return v;
        recursivePaths(root, v, to_string(root->val));
        return v;
    }

private:
    void recursivePaths(TreeNode *root, vector<string> &v, string path) {
        if (!root->left && !root->right) v.push_back(path);
        if (root->left) recursivePaths(root->left, v, path + "->" + to_string(root->left->val));
        if (root->right) recursivePaths(root->right, v, path + "->" + to_string(root->right->val));
    }
};
