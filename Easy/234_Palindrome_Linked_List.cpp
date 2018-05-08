// INCOMPLETE: TRY SPACE O(1)
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        /* Time: O(n), space: O(n) */
        /* Runtime: 24ms */
        vector<int> v;
        ListNode *p = head;
        while (p) {
            v.push_back(p->val);
            p = p->next;
        }
        for (int i = 0, j = v.size() - 1; i < j; ++i, --j) {
            if (v[i] != v[j]) return false;
        }
        return true;
    }
};
