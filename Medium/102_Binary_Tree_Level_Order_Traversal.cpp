#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Time: O(n), space: O(2^h)
        // Runtime: 4ms
        vector<vector<int>> v;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 0));
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            if (!p.first)
                continue;
            if (p.second >= v.size())
                v.push_back(vector<int>());
            v[p.second].push_back((p.first)->val);
            q.push(pair<TreeNode*, int>((p.first)->left, p.second + 1));
            q.push(pair<TreeNode*, int>((p.first)->right, p.second + 1));
        }
        return v;
    }
};
