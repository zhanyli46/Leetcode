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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Time: O(nlogn), space: O(logn) stack
        // Runtime: 12ms
        if (preorder.size() != inorder.size() || preorder.empty())
            return nullptr;
        int n = preorder.size();
        return buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre1, int pre2, int in1, int in2) {
        TreeNode *root = nullptr;
        if (pre1 > pre2)
            return root;
        root = new TreeNode(preorder[pre1]);
        int pivot = in1;
        for ( ; pivot <= in2; ++pivot) {
            if (inorder[pivot] == preorder[pre1])
                break;
        }
        root->left = buildTree(preorder, inorder, pre1 + 1, pre1 + pivot - in1, in1, pivot - 1);
        root->right = buildTree(preorder, inorder, pre1 + pivot - in1 + 1, pre2, pivot + 1, in2);
        return root;
    }
};
