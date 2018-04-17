#include <stack>

using namespace std;

class MinStack {
    /* MinStack of int */
    /* Runtime: 30ms */
public:
    void push(int x) {
        /* Time: O(1), depends on base container */
        s.push(x);
        if (min.empty() || x <= getMin())
            min.push(x);
    }

    void pop() {
        /* Time: O(1) */
        if (s.top() == getMin())
            min.pop();
        s.pop();
    }

    int top() {
        /* Time: O(1) */
        return s.top();
    }

    int getMin() {
        /* Time: O(1) */
        return min.top();
    }

private:
    stack<int> s;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
