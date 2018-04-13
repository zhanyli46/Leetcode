#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        /* Time: O(n), space: O(n) */
        /* Runtime: 4ms */
        int i, n = s.length();
        stack<char> stk;
        char ch;
        for (i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else {
                if (stk.empty()) return false;
                ch = stk.top();
                if (!((ch == '(' && s[i] == ')') ||
                      (ch == '[' && s[i] == ']') ||
                      (ch == '{' && s[i] == '}')))
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
