using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /* m: number of nodes in l1 */
        /* n: number of nodes in l2 */
        /* Time: O(m + n), space: O(1) */
        /* Runtime: 14ms */
        ListNode dummy(0);
        ListNode *p1 = l1, *p2 = l2, *cur = &dummy;
        while (p1 || p2) {
            if (!p1) {
                cur->next = p2;
                break;
            }
            if (!p2) {
                cur->next = p1;
                break;
            }
            if (p1->val <= p2->val) {
                cur->next = p1;
                cur = cur->next;
                p1 = p1->next;
            } else {
                cur->next = p2;
                cur = cur->next;
                p2 = p2->next;
            }
        }
        return dummy.next;
    }
};
