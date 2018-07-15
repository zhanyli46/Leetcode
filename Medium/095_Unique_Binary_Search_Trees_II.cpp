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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        else return generate(1, n);
    }
private:
    vector<TreeNode*> generate(int start, int end) {
        // Time: O(n^2), space: O(n)
        // Runtime: 8ms
        vector<TreeNode*> t;
        if (start > end) {
            t.push_back(NULL);
            return t;
        }
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generate(start, i - 1);
            vector<TreeNode*> right = generate(i + 1, end);
            for (TreeNode *l : left) {
                for (TreeNode *r : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    t.push_back(root);
                }
            }
        }
        return t;
    }
};
