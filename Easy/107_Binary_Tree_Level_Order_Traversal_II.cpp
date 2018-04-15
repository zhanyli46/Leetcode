#include <vector>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        /* Level-wise queue addition and reversion */
        /* Time: O(n), space: O(n) */
        /* Runtime: 6ms */
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if (!root) return v;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            queue<TreeNode*> cur_level;
            while (!q.empty()) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur) {
                    level.push_back(cur->val);
                    cur_level.push(cur->left);
                    cur_level.push(cur->right);
                }
            }
            if (!level.empty()) v.push_back(level);
            q = cur_level;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
