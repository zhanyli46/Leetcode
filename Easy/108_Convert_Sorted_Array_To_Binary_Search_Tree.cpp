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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int i, int j) {
        /* Recursion */
        /* Time: O(n), space: O(1) */
        /* Runtime: 14ms */
        if (i > j) return NULL;
        int mid = (i + j) / 2;
        TreeNode *n = new TreeNode(nums[mid]);
        n->left = sortedArrayToBST(nums, i, mid - 1);
        n->right = sortedArrayToBST(nums, mid + 1, j);
        return n;
    }
};
