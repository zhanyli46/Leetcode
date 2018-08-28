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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Time: O(nlogn), space: O(logn) stack
        // Runtime: 4ms
        if (inorder.size() != postorder.size() || inorder.empty())
            return nullptr;
        int n = inorder.size();
        return buildTree(inorder, postorder, 0, n - 1, 0, n - 1);
    }
private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int in1, int in2, int post1, int post2) {
        TreeNode *root = nullptr;
        if (in1 > in2)
            return root;
        root = new TreeNode(postorder[post2]);
        if (in1 == in2)
            return root;
        int pivot = in2;
        while (pivot >= in1 && inorder[pivot] != postorder[post2])
            --pivot;
        root->left = buildTree(inorder, postorder, in1, pivot - 1, post1, post2 - in2 + pivot - 1);
        root->right = buildTree(inorder, postorder, pivot + 1, in2, post2 - in2 + pivot, post2 - 1);
        return root;
    }
};
