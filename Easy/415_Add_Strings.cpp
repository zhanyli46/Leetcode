#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        // Time: O(n), space: O(1)
        // Runtime: 4ms
        string str;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int len = max(num1.length(), num2.length());
        int carry = 0;
        for (int i = 0; i < len; ++i) {
            int sum = i < num1.length() ? num1[i] - '0' : 0;
            sum += i < num2.length() ? num2[i] - '0' : 0;
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            str += sum + '0';
        }
        if (carry) str += carry + '0';
        reverse(str.begin(), str.end());
        return str;
    }
};
