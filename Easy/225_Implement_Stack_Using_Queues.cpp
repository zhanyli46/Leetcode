#include <queue>

using namespace std;

class MyStack {
    /* Space: O(n) */
    /* Runtime: 3ms */
    queue<int> q;
public:
    /* Time: O(n) */
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    /* Time: O(1) */
    int pop() {
        int data = q.front();
        q.pop();
        return data;
    }

    /* Time: O(1) */
    int top() {
        return q.front();
    }

    /* Time: O(1) */
    bool empty() {
        return q.empty();
    }
};
