#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        iterativeInorder(v, root);
        return v;
    }
private:
    void recursiveInorder(vector<int>& v, TreeNode* root) {
        // recursive method
        // Time: O(n), space: O(n)
        // Runtime: 0ms
        if (!root) return;
        recursiveInorder(v, root->left);
        v.push_back(root->val);
        recursiveInorder(v, root->right);
    }

    void iterativeInorder(vector<int>& v, TreeNode* root) {
        // iterative method
        // Time: O(n), space: O(n)
        // Runtime: 0ms
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                v.push_back(p->val);
                p = p->right;
            }
        }
    }

    void morrisInorder(vector<int>& v, TreeNode* root) {
        // Morris traversal
        // Time: O(n), space: O(1)
        // Runtime: 0ms
        TreeNode *cur = root, *pre;
        while (cur) {
            if (!cur->left) {
                // we reached the leftmost node
                v.push_back(cur->val);
                cur = cur->right;
            } else {
                // find the predecessor
                pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;
                if (!pre->right) {
                    // we reached the predecessor for the first time
                    // link the predecessor to its next node
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    // we reached the predecessor for the second time
                    // unlink the predecessor
                    pre->right = NULL;
                    v.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
    }
};
