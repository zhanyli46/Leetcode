/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // Time: O(nlogn), space: O(logn) stack
        // Runtime: 4ms
        vector<vector<int>> v;
        vector<int> path;
        pathSum(v, path, root, sum);
        return v;
    }

private:
    void pathSum(vector<vector<int>> &v, vector<int> &path, TreeNode* root, int sum) {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            v.push_back(path);
        } else {
            pathSum(v, path, root->left, sum - root->val);
            pathSum(v, path, root->right, sum - root->val);
        }
        path.pop_back();
    }
};
