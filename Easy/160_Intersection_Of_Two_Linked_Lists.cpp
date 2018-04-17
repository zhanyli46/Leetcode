#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /* Two Pointers */
        /* m: length of headA */
        /* n: length of headB */
        /* Time: O(m + n), space: O(1) */
        /* Runtime: 36ms */
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return p1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /* Brute force */
        /* m: length of headA */
        /* n: length of headB */
        /* Time: O(nm^2), space: O(m) */
        /* Runtime: 536ms */
        vector<ListNode*> v;
        while (headA) {
            v.push_back(headA);
            headA = headA->next;
        }
        while (headB) {
            if (find(v.begin(), v.end(), headB) != v.end())
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};
