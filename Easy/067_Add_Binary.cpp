#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        /* Add to the front */
        /* Time: O(n^2), space: O(1) */
        /* Runtime: 5ms */
        int i = a.length() - 1, j = b.length() - 1, carry = 0, base = 2;
        string sum;
        while (i >= 0 || j >= 0 || carry) {
            int s = (i >= 0) ? a[i] - '0' : 0;
            s += (j >= 0) ? b[j] - '0' : 0;
            s += carry;
            carry = s / base;
            s %= base;
            sum = char(s + '0') + sum;
            i--, j--;
        }
        return sum;
    }

    string addBinary(string a, string b) {
        /* Add to back and reverse */
        /* Time: O(n), space: O(1) */
        /* Runtime: 5ms */
        int i = a.length() - 1, j = b.length() - 1, s, carry = 0, base = 2;
        string sum;
        while (i >= 0 || j >= 0 || carry) {
            s = (i >= 0) ? a[i] - '0' : 0;
            s += (j >= 0) ? b[j] - '0' : 0;
            s += carry;
            carry = s / base;
            s %= base;
            sum += char(s + '0');
            i--, j--;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
