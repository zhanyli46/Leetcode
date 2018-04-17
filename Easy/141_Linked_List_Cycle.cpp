#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        /* STL Hashset */
        /* Time: O(n), space: O(n) */
        /* Runtime: 15ms */
        unordered_set<ListNode*> s;
        while (head) {
            if (s.count(head) != 0)
                return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }

    bool hasCycle(ListNode *head) {
        /* Two Pointers: slow + fast */
        /* Time: O(n), space: O(1) */
        /* Runtime: 10ms */
        if (!head) return false;
        ListNode *slow, *fast;
        slow = head;
        fast = head->next;
        while (fast && fast->next) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
