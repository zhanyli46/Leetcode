#include <stack>

class MyQueue {
    /* Space: O(n) */
    stack<int> s_in;
    stack<int> s_out;

    /* Time: O(n) worst-case */
    void transfer() {
        while (!s_in.empty()) {
            s_out.push(s_in.top());
            s_in.pop();
        }
    }
public:
    /* Time: O(1) */
    void push(int x) {
        s_in.push(x);
    }

    /* Time: O(1) in average, O(n) worst-case */
    int pop() {
        if (s_out.empty()) transfer();
        int data = s_out.top();
        s_out.pop();
        return data;
    }

    /* Time: O(1) */
    int peek() {
        if (s_out.empty()) transfer();
        return s_out.top();
    }

    /* Time: O(1) */
    bool empty() {
        return s_in.empty() && s_out.empty();
    }
};
